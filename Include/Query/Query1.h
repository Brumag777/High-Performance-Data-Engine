#ifndef QUERY_QUERY1_H
#define QUERY_QUERY1_H

typedef struct database_manager DatabaseManager;

// Headers utilizados
#include "Config.h"

// Bibliotecas utilizadas
#include <stdio.h>

/**
 * @brief Obtém os `argumentos da query 1`.
 * @param input `Input` do utilizador.
 * @return `Booleano` que indica se os argumentos são válidos.
 */
Boolean getArgumentsQuery1 (char *input);

/**
 * @brief `Executa a query 1`.
 * @param dm `Ponteiro` para o gestor da base de dados.
 * @param input `Input` para a query.
 * @param file `Ficheiro` de output.
 */
void executeQuery1 (DatabaseManager *dm, const char *input, FILE *file);

#endif