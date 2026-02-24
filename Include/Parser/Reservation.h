#ifndef PARSER_RESERVATION_H
#define PARSER_RESERVATION_H

typedef struct database_manager DatabaseManager;

// Headers utilizados
#include "Config.h"

/**
 * @brief Realiza o `parsing` de uma `linha das reservas`.
 * @param line `Linha` do dataset.
 * @param dm `Ponteiro` para o `gestor da base de dados`.
 * @return `Booleano` que indica se a linha era válida.
 */
Boolean parseLineReservation (char *line, DatabaseManager *dm);

#endif