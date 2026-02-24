// Headers utilizados
#include "Parser/Flight.h"
#include "Parser/Utility.h"
#include "Validation/Airport.h"
#include "Validation/Flight.h"
#include "Validation/Date.h"
#include "Structure/Date.h"
#include "Entity/Aircraft.h"
#include "Entity/Airport.h"
#include "Manager/Database.h"
#include "Manager/Aircraft.h"
#include "Manager/Airline.h"
#include "Manager/Airport.h"
#include "Manager/Flight.h"

// Bibliotecas utilizadas
#include <stdlib.h>

/**
 * @brief Realiza o `parsing` de uma `linha dos voos`.
 * @param line `Linha` do dataset.
 * @param dm `Ponteiro` para o `gestor da base de dados`.
 * @return `Booleano` que indica se a linha era válida.
 */
Boolean parseLineFlight (char *line, DatabaseManager *dm) {

    // Carrega o id de voo
    char *flight_id = separateBlock (&line, '"');
    if (validateFlightId (flight_id) == FALSE) return FALSE;

    // Declara as datas
    int departure [5] = {0}, actual_departure [5] = {0};
    int arrival [5] = {0}, actual_arrival [5] = {0};

    // Carrega a data de partida prevista
    if (validateDate (separateBlock (&line, '"'), TRUE, departure) == FALSE) return FALSE;

    // Carrega a data de partida real
    char *block = separateBlock (&line, '"');
    if (validateDate (block, TRUE, actual_departure) == FALSE && validateNotApplicable (block) == FALSE) return FALSE;

    // Carrega a data de chegada prevista
    if (validateDate (separateBlock (&line, '"'), TRUE, arrival) == FALSE) return FALSE;

    // Carrega a data de chegada real
    block = separateBlock (&line, '"');
    if (validateDate (block, TRUE, actual_arrival) == FALSE && validateNotApplicable (block) == FALSE) return FALSE;

    // Carrega o estado do voo
    separateBlock (&line, '"');
    char status = *separateBlock (&line, '"');

    // Verifica as restrições associadas às datas
    if (validateFlightDates (status, departure, actual_departure, arrival, actual_arrival) == FALSE) return FALSE;

    // Carrega a origem
    char *origin = separateBlock (&line, '"');
    if (validateCode (origin) == FALSE) return FALSE;

    // Carrega o destino
    char *destination = separateBlock (&line, '"');
    if (validateCode (destination) == FALSE) return FALSE;

    // Converte os códigos em inteiros
    int origin_int = codeToInt (origin);
    int destination_int = codeToInt (destination);

    // Verifica se a origem e o destino são iguais
    if (origin_int == destination_int) return FALSE;

    // Carrega a aeronave
    Aircraft *a = getAircraftById (getDatabaseAircrafts (dm), separateBlock (&line, '"'));
    if (a == NULL) return FALSE;

    // Carrega a companhia aérea
    if (status == 'D') registerAirline (getDatabaseAirlines (dm), separateBlock (&line, '"'), dateDiff (departure, actual_departure));

    // Verifica se o voo não foi cancelado
    if (status != 'C') {

        // Incrementa o número de voos da aeronave
        incAircraftFlightCount (a);

        // Incrementa o número de ocorrências do aeroporto para o dia
        incAirportFlightCount (getDatabaseAirports (dm), daysSinceJanFirst (actual_departure), origin_int);
    }

    // Regista o voo
    registerFlight (getDatabaseFlights (dm), flight_id, origin_int, destination_int, dateWeekIndex (departure), status);

    // A aeronave é válida
    return TRUE;
}