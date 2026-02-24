#ifndef MANAGER_AIRLINE_H
#define MANAGER_AIRLINE_H

typedef struct airline Airline;

// Headers utilizados
#include "Config.h"

/**
 * @brief `Estrutura de gestão` das `companhias`.
 */
typedef struct airline_manager AirlineManager;

/**
 * @brief `Cria` um `gestor de companhias`.
 * @param dataset_type `Tipo de dataset`.
 * @return `Ponteiro` para o gestor de companhias criado.
 */
AirlineManager *createAirlineManager (DatasetType dataset_type);

/**
 * @brief `Elimina` um `gestor de companhias`.
 * @param m `Ponteiro` para o `gestor de companhias`.
 */
void destroyAirlineManager (AirlineManager *m);

/**
 * @brief `Regista uma companhia` num `gestor de companhias`.
 * @param m `Ponteiro` para o `gestor de companhias`.
 * @param name `Nome` da companhia.
 * @param delay `Atraso` da companhia.
 */
void registerAirline (AirlineManager *m, const char *name, int delay);

/**
 * @brief `Obtém um registo` de uma companhia de um `gestor de companhias`.
 * @param m `Ponteiro` para o `gestor de companhias`.
 * @param name `Nome` da companhia
 * @return `Ponteiro` para a companhia.
 */
Airline *getAirlineById (AirlineManager *m, const char *name);

/**
 * @brief Prepara um `gestor de companhias` para as queries.
 * @param m `Ponteiro` para o gestor de companhias.
 */
void prepareAirlines (AirlineManager *m);

/**
 * @brief Determinas as `N companhias com maior tempo de atraso médio por voo`.
 * @param m `Ponteiro` para o gestor de companhias.
 * @param N `Número de companhias` pretendido.
 * @param airlines `Companhias` encontradas serão escritas neste ponteiro.
 * @return `Número de companhias encontradas`.
 */
int getTopNMostDelayedAirlines (AirlineManager *m, int N, Airline *airlines []);

#endif