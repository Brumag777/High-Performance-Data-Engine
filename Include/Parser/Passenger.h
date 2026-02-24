#ifndef MANAGER_PASSENGER_H
#define MANAGER_PASSENGER_H

typedef struct database_manager DatabaseManager;

// Headers utilizados
#include "Config.h"

/**
 * @brief Realiza o `parsing` de uma `linha dos passageiros`.
 * @param line `Linha` do dataset.
 * @param dm `Ponteiro` para o `gestor da base de dados`.
 * @return `Booleano` que indica se a linha era válida.
 */
Boolean parseLinePassenger (char *line, DatabaseManager *dm);

#endif