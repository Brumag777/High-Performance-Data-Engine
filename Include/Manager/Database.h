#ifndef MANAGER_DATABASE_H
#define MANAGER_DATABASE_H

typedef struct aircraft_manager AircraftManager;
typedef struct airline_manager AirlineManager;
typedef struct airport_manager AirportManager;
typedef struct flight_manager FlightManager;
typedef struct nationality_manager NationalityManager;
typedef struct passenger_manager PassengerManager;
typedef struct reservation_manager ReservationManager;

// Headers utilizados
#include "Config.h"

/**
 * @brief `Estrutura de gestão` da `base de dados`.
 */
typedef struct database_manager DatabaseManager;

/**
 * @brief `Cria` um `gestor de base de dados`.
 * @param dataset_type `Tipo de dadaset`.
 * @return `Ponteiro` para o gestor de base de dados criado.
 */
DatabaseManager *createDatabaseManager (DatasetType dataset_type);

/**
 * @brief `Elimina` um `gestor de base de dados`.
 * @param dm `Ponteiro` para o gestor de base de dados.
 */
void destroyDatabaseManager (DatabaseManager *dm);

/**
 * @brief Devolve o `gestor de aeronaves` de um `gestor de base de dados`.
 * @param dm `Ponteiro` para o gestor de base de dados.
 * @return `Ponteiro` para o gestor de aeronaves.
 */
AircraftManager *getDatabaseAircrafts (DatabaseManager *dm);

/**
 * @brief Devolve o `gestor de companhias` de um `gestor de base de dados`.
 * @param dm `Ponteiro` para o gestor de base de dados.
 * @return `Ponteiro` para o gestor de companhias.
 */
AirlineManager *getDatabaseAirlines (DatabaseManager *dm);

/**
 * @brief Devolve o `gestor de aeroportos` de um `gestor de base de dados`.
 * @param dm `Ponteiro` para o gestor de base de dados.
 * @return `Ponteiro` para o gestor de aeroportos.
 */
AirportManager *getDatabaseAirports (DatabaseManager *dm);

/**
 * @brief Devolve o `gestor de voos` de um `gestor de base de dados`.
 * @param dm `Ponteiro` para o gestor de base de dados.
 * @return `Ponteiro` para o gestor de voos.
 */
FlightManager *getDatabaseFlights (DatabaseManager *dm);

/**
 * @brief Devolve o `gestor de nacionalidades` de um `gestor de base de dados`.
 * @param dm `Ponteiro` para o gestor de base de dados.
 * @return `Ponteiro` para o gestor de nacionalidades.
 */
NationalityManager *getDatabaseNationalities (DatabaseManager *dm);

/**
 * @brief Devolve o `gestor de passageiros` de um `gestor de base de dados`.
 * @param dm `Ponteiro` para o gestor de base de dados.
 * @return `Ponteiro` para o gestor de passageiros.
 */
PassengerManager *getDatabasePassengers (DatabaseManager *dm);

/**
 * @brief Devolve o `gestor de reservas` de um `gestor de base de dados`.
 * @param dm `Ponteiro` para o gestor de base de dados.
 * @return `Ponteiro` para o gestor de reservas.
 */
ReservationManager *getDatabaseReservations (DatabaseManager *dm);

/**
 * @brief Prepara um `gestor de base de dados` para as queries.
 * @param m `Ponteiro` para o gestor de base de dados.
 */
void prepareDatabase (DatabaseManager *dm);

#endif