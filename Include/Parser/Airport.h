#ifndef PARSER_AIRPORT_H
#define PARSER_AIRPORT_H

typedef struct database_manager DatabaseManager;

// Headers utilizados
#include "Config.h"

/**
 * @brief Realiza o `parsing` de uma `linha dos aeroportos`.
 * @param line `Linha` do dataset.
 * @param dm `Ponteiro` para o `gestor da base de dados`.
 * @return `Booleano` que indica se a linha era válida.
 */
Boolean parseLineAirport (char *line, DatabaseManager *dm);

#endif