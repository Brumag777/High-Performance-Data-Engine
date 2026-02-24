// Headers utilizados
#include "Parser/Reservation.h"
#include "Parser/Utility.h"
#include "Validation/Reservation.h"
#include "Entity/Airport.h"
#include "Entity/Flight.h"
#include "Entity/Passenger.h"
#include "Manager/Database.h"
#include "Manager/Airport.h"
#include "Manager/Flight.h"
#include "Manager/Nationality.h"
#include "Manager/Passenger.h"
#include "Manager/Reservation.h"

// Bibliotecas utilizadas
#include <stdlib.h>

/**
 * @brief Verifica se uma string representa uma `lista de voos de uma reserva`.
 * @param string `String`.
 * @param flight_manager `Ponteiro` para o gestor de voos.
 * @param flight_outbound `Ponteiro duplo` para o voo de ida.
 * @param flight_return `Ponteiro duplo` para o voo de volta.
 * @return `Booleano` que indica se a string representa uma `lista de voos de uma reserva`.
 */
static Boolean validateReservationFlights (char *string, FlightManager *m, Flight **flight_outbound, Flight **flight_return) {

    // Verifica se o primeiro caractere do bloco não é o início da lista - '['
    if (string [0] != '[') return FALSE;

    // Carrega o primeiro id de voo
    *flight_outbound = getFlightById (m, separateBlock (&string, 39));

    // Verifica se o primeiro voo não existe
    if (*flight_outbound == NULL) return FALSE;

    // Verifica se o último caractere do bloco é o fim da lista - ']'
    if (string [0] == ']') return TRUE;

    // Lê o segundo id de voo
    *flight_return = getFlightById (m, separateBlock (&string, 39));

    // Verifica se o último caractere do bloco não é o fim da lista - ']'
    return (string [0] != ']') ? FALSE : TRUE;
}

/**
 * @brief Atualiza o `gestor dos aeroportos` e o `gestor de nacionalidades` durante o registo de uma reserva.
 * @param am `Ponteiro` para o gestor dos aeroportos.s
 * @param flight_outbound `Ponteiro` para o voo de ida da reserva.
 * @param flight_return `Ponteiro` para o voo de volta da reserva.
 * @param nationality `Índice da nacionalidade do passageiro` da reserva.
 */
static void updateReservation (AirportManager *m, Flight *flight_outbound, Flight *flight_return, int nationality) {

    // Atualiza os aeroportos e a nacionalidade do voo de ida
    if (getFlightStatus (flight_outbound) != 'C') {
        incAirportDepartureCount (getAirportById (m, getFlightOrigin (flight_outbound)));
        incAirportArrivalCount (getAirportById (m, getFlightDestination (flight_outbound)));
        incAirportNationalityCount (m, nationality, getFlightDestination (flight_outbound));
    }

    // Atualiza os aeroportos e a nacionalidade do voo de volta
    if (flight_return && getFlightStatus (flight_return) != 'C') {
        incAirportDepartureCount (getAirportById (m, getFlightOrigin (flight_return)));
        incAirportArrivalCount (getAirportById (m, getFlightDestination (flight_return)));
        incAirportNationalityCount (m, nationality, getFlightDestination (flight_return));
    }
}

/**
 * @brief Realiza o `parsing` de uma `linha das reservas`.
 * @param line `Linha` do dataset.
 * @param m `Ponteiro` para o `gestor dos aeroportos`.
 * @return `Booleano` que indica se a linha era válida.
 */
Boolean parseLineReservation (char *line, DatabaseManager *dm) {

    // Carrega o id da reserva
    char *block = separateBlock (&line, '"');
    if (validateReservationId (block) == FALSE) return FALSE;
    int reservation_id = atoi (block + 1);

    // Carrega os voos
    Flight *flight_outbound, *flight_return = NULL;
    if (validateReservationFlights (separateBlock (&line, '"'), getDatabaseFlights (dm), &flight_outbound, &flight_return) == FALSE) return FALSE;

    // Carrega o número de documento
    int document_number = atoi (separateBlock (&line, '"'));
    Passenger *p = getPassengerById (getDatabasePassengers (dm), document_number);
    if (p == NULL) return FALSE;

    // Carrega o preço
    separateBlock (&line, '"');
    float price = atof (separateBlock (&line, '"'));

    // Verifica se os aeroportos não correspodem
    if (flight_return && getFlightDestination (flight_outbound) != getFlightOrigin (flight_return)) return FALSE;

    // Adiciona o registo do id da reserva
    if (registerReservation (getDatabaseReservations (dm), reservation_id) == FALSE) return FALSE;

    // Atualiza a base de dados
    updateReservation (getDatabaseAirports (dm), flight_outbound, flight_return, getPassengerNationality (p));

    // Regista o gasto do passageiro
    registerPassengerSpending (getDatabasePassengers (dm), document_number, price, getFlightWeek (flight_outbound));

    // O aeroporto é válido
    return TRUE;
}