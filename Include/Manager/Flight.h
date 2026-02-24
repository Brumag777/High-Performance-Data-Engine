#ifndef MANAGER_FLIGHT_H
#define MANAGER_FLIGHT_H

typedef struct flight Flight;

// Headers utilizados
#include "Config.h"

/**
 * @brief `Estrutura de gestão` dos `voos`.
 */
typedef struct flight_manager FlightManager;

/**
 * @brief `Cria` um `gestor de voos`.
 * @param dataset_type `Tipo de dataset`.
 * @return `Ponteiro` para o gestor de voos criado.
 */
FlightManager *createFlightManager (DatasetType dataset_type);

/**
 * @brief `Elimina` um `gestor de voos`.
 * @param m `Ponteiro` para o `gestor de voos`.
 */
void destroyFlightManager (FlightManager *m);

/**
 * @brief `Regista um voo` num `gestor de voos`.
 * @param m `Ponteiro` para o `gestor de voos`.
 * @param id `Id` do voo.
 * @param origin `Identificador do aeroporto de origem` do voo.
 * @param destination `Identificador do aeroporto de destino` do voo.
 * @param week `Semana de partida prevista` do voo.
 * @param status `Estado` do voo.
 */
void registerFlight (FlightManager *m, const char *id, short origin, short destination, char week, char status);

/**
 * @brief `Obtém um registo` de um voo de um `gestor de voos`.
 * @param m `Ponteiro` para o `gestor de voos`.
 * @param id `Id` do voo.
 * @return `Ponteiro` para o voo.
 */
Flight *getFlightById (FlightManager *m, const char *id);

/**
 * @brief Prepara um `gestor de voos` para as queries.
 * @param m `Ponteiro` para o gestor de voos.
 */
void prepareFlights (FlightManager *m);

#endif