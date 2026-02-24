#ifndef MANAGER_PASSENGER_H
#define MANAGER_PASSENGER_H

typedef struct passenger Passenger;

// Headers utilizados
#include "Config.h"

/**
 * @brief `Estrutura de gestão` dos `passageiros`.
 */
typedef struct passenger_manager PassengerManager;

/**
 * @brief `Cria` um `gestor de passageiros`.
 * @param dataset_type `Tipo de dataset`.
 * @return `Ponteiro` para o gestor de passageiros criado.
 */
PassengerManager *createPassengerManager (DatasetType dataset_type);

/**
 * @brief `Elimina` um `gestor de passageiros`.
 * @param m `Ponteiro` para o `gestor de passageiros`.
 */
void destroyPassengerManager (PassengerManager *m);

/**
 * @brief `Regista um passageiro` num `gestor de passageiros`.
 * @param m `Ponteiro` para o `gestor de passageiros`.
 * @param document_number `Número de documento` do passageiro.
 * @param first_name `Primeiro nome` do passageiro.
 * @param last_name `Último nome` do passageiro.
 * @param dob `Data de nascimento` do passageiro.
 * @param nationality `Identificador da nacionalidade` do passageiro.
 */
void registerPassenger (PassengerManager *m, int document_number, const char *first_name, const char *last_name, unsigned short dob, short nationality);

/**
 * @brief `Obtém um registo` de um passageiro de um `gestor de passageiros`.
 * @param m `Ponteiro` para o `gestor de passageiros`.
 * @param document_number `Número de documento` do passageiro.
 * @return `Ponteiro` para o passageiro.
 */
Passenger *getPassengerById (PassengerManager *m, int document_number);

/**
 * @brief `Regista o gasto de um passageiro` num `gestor de passageiros`.
 * @param m `Ponteiro` para o `gestor de passageiros`.
 * @param document_number `Número de documento` do passageiro.
 * @param price `Preço do gasto` do passageiro.
 * @param week `Semana do gasto` do passageiro.
 */
void registerPassengerSpending (PassengerManager *m, int document_number, float price, int week);

/**
 * @brief Devolve o `índice de um passageiro`.
 * @param m `Ponteiro` para o `gestor de passageiros`.
 * @param document_number `Número de documento` do passageiro.
 * @return `Ponteiro` para o passageiro.
 */
int getPassengerIndex (PassengerManager *m, int document_number);

/**
 * @brief Prepara um `gestor de passageiros` para as queries.
 * @param m `Ponteiro` para o gestor de passageiros.
 */
void preparePassengers (PassengerManager *m);

/**
 * @brief Determina o passageiro que `ficou no top 10 semanal mais vezes` num dado intervalo de tempo.
 * @param m `Ponteiro` para o gestor de passageiros.
 * @param min_date `Início do intervalo` de tempo.
 * @param max_date `Fim do intervalo` de tempo.
 * @param number_appearences O `número de aparições` no top 10 será escrito neste ponteiro.
 * @return Ponteiro para o passageiro que `ficou no top 10 semanal mais vezes`.
 */
Passenger *getMostExpensivePassenger (PassengerManager *m, const int min_date [], const int max_date [], int *number_appearences);

#endif