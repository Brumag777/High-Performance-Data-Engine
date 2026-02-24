#ifndef QUERY_MAIN_QUERY_H
#define QUERY_MAIN_QUERY_H

typedef struct database_manager DatabaseManager;

/**
 * @brief `Executa as queries` pré-definidas.
 * @param dm `Ponteiro` para o gestor da base de dados.
 * @param write_file_name `Nome` do ficheiro de escrita.
 */
void executeQueries (DatabaseManager *dm, const char *write_file_name);

#endif