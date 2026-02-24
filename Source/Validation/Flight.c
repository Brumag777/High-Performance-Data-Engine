// Headers utilizados
#include "Validation/Aircraft.h"
#include "Structure/Date.h"

// Bibliotecas utilizadas
#include <ctype.h>
#include <string.h>

/**
 * @brief Verifica se uma string `representa um id de voo`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa um id de voo`.
 */
Boolean validateFlightId (const char *string) {

    // Verifica se os dois primeiros caracteres não são letras maiúsculas
    if (!isupper (string [0]) || !isupper (string [1])) return FALSE;

    // Conta o número de dígitos
    int i = 2; while (isdigit (string [i])) i++;

    // Verifica se existem 5 ou 6 dígitos
    if (i != 7 && i != 8) return FALSE;

    // Verifica se a string terminou
    return string [i] == 0 ? TRUE : FALSE;
}

/**
 * @brief Verifica se uma string `representa 'N/A'`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa 'N/A'`.
 */
Boolean validateNotApplicable (const char *string) {
    return strcmp (string, "N/A") == 0 ? TRUE : FALSE;
}

/**
 * @brief Verifica se as `datas de um voo são válidas`.
 * @param status `Estado` do voo.
 * @param departure `Data de partida prevista` do voo.
 * @param actual_departure `Data de partida real` do voo.
 * @param arrival `Data de chegada prevista` do voo.
 * @param actual_arrival `Data de chegada real` do voo.
 * @return `Booleano` que indica se as `datas do voo são válidas`.
 */
Boolean validateFlightDates (char status, const int departure [], const int actual_departure [], const int arrival [], const int actual_arrival []) {

    // Verifica se o voo foi cancelado
    if (status == 'C' && (actual_departure [YEAR] || actual_arrival [YEAR])) return FALSE;

    // Compara as datas previstas
    if (compareDatetimes (departure, arrival) == 1) return FALSE;
    if (compareDatetimes (actual_departure, actual_arrival) == 1) return FALSE;

    // Verifica se o voo foi atrasado
    if (status == 'D' && (compareDatetimes (departure, actual_departure) == 1 || compareDatetimes (arrival, actual_arrival) == 1)) return FALSE;

    // As datas são válidas
    return TRUE;
}