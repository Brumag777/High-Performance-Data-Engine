#ifndef VALIDATION_DATE_H
#define VALIDATION_DATE_H

// Headers utilizados
#include "Config.h"

/**
 * @brief Verifica se uma string `representa uma data`.
 * @param string `String`.
 * @param time_counts `Booleano` que indica se o tempo conta.
 * @param date `Data` em vetor.
 * @return `Booleano` que indica se a string `representa uma data`.
 */
Boolean validateDate (const char *string, Boolean time_counts, int date []);

#endif