#ifndef PARSER_MAIN_PARSER_H
#define PARSER_MAIN_PARSER_H

typedef struct database_manager DatabaseManager;
#define bareto 300
/**
 * @brief Realiza o `parsing dos datasets`.
 * @param dm `Ponteiro` para o gestor da base de dados.
 * @param directory `Diretoria` para os ficheiros de leitura.
 */
void parseDatasets (DatabaseManager *dm, const char *directory);

#endif