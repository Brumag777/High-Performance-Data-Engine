// Headers utilizados
#include "Manager/Database.h"
#include "Manager/Aircraft.h"
#include "Manager/Airline.h"
#include "Manager/Airport.h"
#include "Manager/Flight.h"
#include "Manager/Nationality.h"
#include "Manager/Passenger.h"
#include "Manager/Reservation.h"

// Bibliotecas utilizadas
#include <stdlib.h>

/**
 * @brief `Estrutura de gestão` da `base de dados`.
 */
typedef struct database_manager {
    AircraftManager *aircrafts;
    AirlineManager *airlines;
    AirportManager *airports;
    FlightManager *flights;
    NationalityManager *nationalities;
    PassengerManager *passengers;
    ReservationManager *reservations;
} DatabaseManager;

/**
 * @brief `Cria` um `gestor de base de dados`.
 * @param dataset_type `Tipo de dadaset`.
 * @return `Ponteiro` para o gestor de base de dados criado.
 */
DatabaseManager *createDatabaseManager (DatasetType dataset_type) {

    // Aloca memória para a estrutura
    DatabaseManager *dm = malloc (sizeof (DatabaseManager));

    // Define as componentes da estrutura
    dm -> aircrafts = createAircraftManager (dataset_type);
    dm -> airlines = createAirlineManager (dataset_type);
    dm -> airports = createAirportManager (dataset_type);
    dm -> flights = createFlightManager (dataset_type);
    dm -> nationalities = createNationalityManager (dataset_type);
    dm -> passengers = createPassengerManager (dataset_type);
    dm -> reservations = createReservationManager (dataset_type);

    // Devolve o ponteiro
    return dm;
}

/**
 * @brief `Elimina` um `gestor de base de dados`.
 * @param dm `Ponteiro` para o gestor de base de dados.
 */
void destroyDatabaseManager (DatabaseManager *dm) {

    // Liberta a memória alocada para as componentes da estrutura
    destroyAircraftManager (dm -> aircrafts);
    destroyAirlineManager (dm -> airlines);
    destroyAirportManager (dm -> airports);
    destroyFlightManager (dm -> flights);
    destroyNationalityManager (dm -> nationalities);
    destroyPassengerManager (dm -> passengers);
    destroyReservationManager (dm -> reservations);

    // Liberta a memória alocada para a estrutura
    free (dm);
}

/**
 * @brief Devolve o `gestor de aeronaves` de um `gestor de base de dados`.
 * @param dm `Ponteiro` para o gestor de base de dados.
 * @return `Ponteiro` para o gestor de aeronaves.
 */
AircraftManager *getDatabaseAircrafts (DatabaseManager *dm) {
    return dm -> aircrafts;
}

/**
 * @brief Devolve o `gestor de companhias` de um `gestor de base de dados`.
 * @param dm `Ponteiro` para o gestor de base de dados.
 * @return `Ponteiro` para o gestor de companhias.
 */
AirlineManager *getDatabaseAirlines (DatabaseManager *dm) {
    return dm -> airlines;
}

/**
 * @brief Devolve o `gestor de aeroportos` de um `gestor de base de dados`.
 * @param dm `Ponteiro` para o gestor de base de dados.
 * @return `Ponteiro` para o gestor de aeroportos.
 */
AirportManager *getDatabaseAirports (DatabaseManager *dm) {
    return dm -> airports;
}

/**
 * @brief Devolve o `gestor de voos` de um `gestor de base de dados`.
 * @param dm `Ponteiro` para o gestor de base de dados.
 * @return `Ponteiro` para o gestor de voos.
 */
FlightManager *getDatabaseFlights (DatabaseManager *dm) {
    return dm -> flights;
}

/**
 * @brief Devolve o `gestor de nacionalidades` de um `gestor de base de dados`.
 * @param dm `Ponteiro` para o gestor de base de dados.
 * @return `Ponteiro` para o gestor de nacionalidades.
 */
NationalityManager *getDatabaseNationalities (DatabaseManager *dm) {
    return dm -> nationalities;
}

/**
 * @brief Devolve o `gestor de passageiros` de um `gestor de base de dados`.
 * @param dm `Ponteiro` para o gestor de base de dados.
 * @return `Ponteiro` para o gestor de passageiros.
 */
PassengerManager *getDatabasePassengers (DatabaseManager *dm) {
    return dm -> passengers;
}

/**
 * @brief Devolve o `gestor de reservas` de um `gestor de base de dados`.
 * @param dm `Ponteiro` para o gestor de base de dados.
 * @return `Ponteiro` para o gestor de reservas.
 */
ReservationManager *getDatabaseReservations (DatabaseManager *dm) {
    return dm -> reservations;
}

/**
 * @brief Prepara um `gestor de base de dados` para as queries.
 * @param m `Ponteiro` para o gestor de base de dados.
 */
void prepareDatabase (DatabaseManager *dm) {
    prepareAircrafts (dm -> aircrafts);
    prepareAirlines (dm -> airlines);
    prepareAirports (dm -> airports);
    prepareFlights (dm -> flights);
    prepareNationalities (dm -> nationalities);
    preparePassengers (dm -> passengers);
    prepareReservations (dm -> reservations);
}