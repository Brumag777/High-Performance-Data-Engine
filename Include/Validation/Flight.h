#ifndef VALIDATION_FLIGHT_H
#define VALIDATION_FLIGHT_H

// Headers utilizados
#include "Config.h"

/**
 * @brief Verifica se uma string `representa um id de voo`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa um id de voo`.
 */
Boolean validateFlightId (const char *string);

/**
 * @brief Verifica se uma string `representa 'N/A'`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa 'N/A'`.
 */
Boolean validateNotApplicable (const char *string);

/**
 * @brief Verifica se as `datas de um voo são válidas`.
 * @param status `Estado` do voo.
 * @param departure `Data de partida prevista` do voo.
 * @param actual_departure `Data de partida real` do voo.
 * @param arrival `Data de chegada prevista` do voo.
 * @param actual_arrival `Data de chegada real` do voo.
 * @return `Booleano` que indica se as `datas do voo são válidas`.
 */
Boolean validateFlightDates (char status, const int departure [], const int actual_departure [], const int arrival [], const int actual_arrival []);

#endif