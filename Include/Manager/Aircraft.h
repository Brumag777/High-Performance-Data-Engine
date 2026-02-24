#ifndef MANAGER_AIRCRAFT_H
#define MANAGER_AIRCRAFT_H

typedef struct aircraft Aircraft;

// Headers utilizados
#include "Config.h"

/**
 * @brief `Estrutura de gestão` das `aeronaves`.
 */
typedef struct aircraft_manager AircraftManager;

/**
 * @brief `Cria` um `gestor de aeronaves`.
 * @param dataset_type `Tipo de dataset`.
 * @return `Ponteiro` para o gestor de aeronaves criado.
 */
AircraftManager *createAircraftManager (DatasetType dataset_type);

/**
 * @brief `Elimina` um `gestor de aeronaves`.
 * @param m `Ponteiro` para o `gestor de aeronaves`.
 */
void destroyAircraftManager (AircraftManager *m);

/**
 * @brief `Regista uma aeronave` num `gestor de aeronaves`.
 * @param m `Ponteiro` para o `gestor de aeronaves`.
 * @param manufacturer `Fabricante` da aeronave.
 * @param identifier `Identificador` da aeronave.
 * @param model `Modelo` da aeronave.
 */
void registerAircraft (AircraftManager *m, const char *manufacturer, const char *model, const char *identifier);

/**
 * @brief `Obtém um registo` de uma aeronave de um `gestor de aeronaves`.
 * @param m `Ponteiro` para o `gestor de aeronaves`.
 * @param identifier `Identificador` da aeronave.
 * @return `Ponteiro` para a aeronave.
 */
Aircraft *getAircraftById (AircraftManager *m, const char *identifier);

/**
 * @brief Prepara um `gestor de aeronaves` para as queries.
 * @param m `Ponteiro` para o gestor de aeronaves.
 */
void prepareAircrafts (AircraftManager *m);

/**
 * @brief Determinas as `N aeronaves com mais voos`. Opcionalmente, pode ser dado um `filtro por fabricante`.
 * @param m `Ponteiro` para o gestor de aeronaves.
 * @param manufacturer `Fabricante` pretendido. Pode ser `NULL` caso não seja pretendido um filtro.
 * @param N `Número de aeronaves` pretendido.
 * @param aircrafts `Aeronaves` encontradas serão escritas neste ponteiro.
 * @return `Número de aeronaves encontradas`.
 */
int getTopNMostFlownAircrafts (AircraftManager *m, const char *manufacturer, int N, Aircraft *aircrafts []);

#endif