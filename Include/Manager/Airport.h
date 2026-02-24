#ifndef MANAGER_AIRPORT_H
#define MANAGER_AIRPORT_H

typedef struct airport Airport;

// Headers utilizados
#include "Config.h"

/**
 * @brief `Estrutura de gestão` dos `aeroportos`.
 */
typedef struct airport_manager AirportManager;

/**
 * @brief `Cria` um `gestor de aeroportos`.
 * @param dataset_type `Tipo de dataset`.
 * @return `Ponteiro` para o gestor de aeroportos criado.
 */
AirportManager *createAirportManager (DatasetType dataset_type);

/**
 * @brief `Elimina` um `gestor de aeroportos`.
 * @param m `Ponteiro` para o `gestor de aeroportos`.
 */
void destroyAirportManager (AirportManager *m);

/**
 * @brief `Regista um aeroporto` num `gestor de aeroportos`.
 * @param m `Ponteiro` para o `gestor de aeroportos`.
 * @param code `Código` do aeroporto.
 * @param name `Nome` do aeroporto.
 * @param city `Cidade` do aeroporto.
 * @param type `Tipo` do aeroporto.
 * @param country `País` do aeroporto.
 */
void registerAirport (AirportManager *m, const char *code, const char *name, const char *city, const char *type, const char *country);

/**
 * @brief `Obtém um registo` de um aeroporto de um `gestor de aeroportos`.
 * @param m `Ponteiro` para o `gestor de aeroportos`.
 * @param code `Código` do aeroporto.
 * @return `Ponteiro` para o aeroporto.
 */
Airport *getAirportById (AirportManager *m, int code);

/**
 * @brief Incrementa o `contador de visitas` de um aeroporto de um `gestor de aeroportos`.
 * @param m `Ponteiro` para o `gestor de aeroportos`.
 * @param day `Dia normalizado` da visita.
 * @param code `Código` do aeroporto.
 */
void incAirportFlightCount (AirportManager *m, int day, int code);

/**
 * @brief Incrementa o `contador de visitas` de um aeroporto de um `gestor de aeroportos`.
 * @param m `Ponteiro` para o `gestor de aeroportos`.
 * @param nationality `Índice da nacionalidade` da visita.
 * @param code `Código` do aeroporto.
 */
void incAirportNationalityCount (AirportManager *m, int nationality, int code);

/**
 * @brief Prepara um `gestor de aeroportos` para as queries.
 * @param m `Ponteiro` para o gestor de aeroportos.
 */
void prepareAirports (AirportManager *m);

/**
 * @brief Determina o `aeroporto mais visitado` num dado intervalo de tempo.
 * @param m `Ponteiro` para o gestor de aeroportos.
 * @param min_date `Início do intervalo` de tempo.
 * @param max_date `Fim do intervalo` de tempo.
 * @param number_visits O `número de visitas` do aeroporto será escrito neste ponteiro.
 * @return `Aeroproto mais visitado` no intervalo de tempo.
 */
Airport *getMostVisitedAirportBetweenDates (AirportManager *m, const int min_date [], const int max_date [], int *number_visits);

/**
 * @brief Determina o `aeroporto mais visitado` num dado intervalo de tempo.
 * @param m `Ponteiro` para o gestor de aeroportos.
 * @param nationality `Índice da nacionalidade` pretendida.
 * @param number_visits O `número de visitas` do aeroporto será escrito neste ponteiro.
 * @return `Aeroproto mais visitado` no intervalo de tempo.
 */
Airport *getMostVisitedAirportByNationality (AirportManager *m, int nationality, int *number_visits);

#endif