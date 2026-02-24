#ifndef VALIDATION_PASSENGER_H
#define VALIDATION_PASSENGER_H

// Headers utilizados
#include "Config.h"

/**
 * @brief Verifica se uma string `representa um número de documento`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa um número de documento`.
 */
Boolean validadeDocumentNumber (const char *string);

/**
 * @brief Verifica se uma string `representa um género`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa um género`.
 */
Boolean validateGender (const char *string);

/**
 * @brief Verifica se uma string `representa um email`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa um email`.
 */
Boolean validateEmail (const char *string);

#endif