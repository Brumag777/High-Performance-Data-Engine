#ifndef VALIDATION_AIRPORT_H
#define VALIDATION_AIRPORT_H

// Headers utilizados
#include "Config.h"

/**
 * @brief Verifica se uma string representa um `código de aeroporto`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa um código de aeroporto`.
 */
Boolean validateCode (const char *string);

/**
 * @brief Verifica se uma string representa uma `latitude`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa uma latitude`.
 */
Boolean validateLatitude (const char *string);

/**
 * @brief Verifica se uma string representa uma `longitude`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa uma longitude`.
 */
Boolean validateLongitude (const char *string);

/**
 * @brief Verifica se uma string representa um `tipo de aeroporto`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa um tipo de aeroporto`.
 */
Boolean validateType (const char *string);

#endif