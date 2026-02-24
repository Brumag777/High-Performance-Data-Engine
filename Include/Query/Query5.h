#ifndef QUERY_QUERY5_H
#define QUERY_QUERY5_H

typedef struct database_manager DatabaseManager;

// Headers utilizados
#include "Config.h"

// Bibliotecas utilizadas
#include <stdio.h>

/**
 * @brief Obtém os `argumentos da query 5`.
 * @param input `Input` do utilizador.
 * @return `Booleano` que indica se os argumentos são válidos.
 */
Boolean getArgumentsQuery5 (char *input);

/**
 * @brief `Executa a query 5`.
 * @param dm `Ponteiro` para o gestor da base de dados.
 * @param input `Input` para a query.
 * @param file `Ficheiro` de output.
 */
void executeQuery5 (DatabaseManager *dm, const char *input, FILE *file);

#endif