// Headers utilizados
#include "Validation/Aircraft.h"

// Bibliotecas utilizadas
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Verifica se uma string representa um `código de aeroporto`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa um código de aeroporto`.
 */
Boolean validateCode (const char *string) {
    return isupper (string [0]) && isupper (string [1]) && isupper (string [2]) && string [3] == 0 ? TRUE : FALSE;
}

/**
 * @brief Verifica se uma string representa uma `latitude`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa uma latitude`.
 */
Boolean validateLatitude (const char *string) {

    // Verifica se é negativo
    if (string [0] == '-') string++;

    // Verifica se o primeiro caractere não é um dígito
    if (!isdigit (string [0])) return FALSE;

    // Verifica se o formato não é válido (antes do ponto)
    int i; for (i = 1; string [i] && string [i] != '.'; i++) if (i == 2 || !isdigit (string [i])) return FALSE;

    // Verifica se a string terminou
    if (string [i] == 0) return FALSE;

    // Verifica se o formato não é válido (depois do ponto)
    for (int j = 1; string [i + j]; j++) if (j == 9 || !isdigit (string [i + j])) return FALSE;

    // Verifica a validade do valor
    return atof (string) > 90 ? FALSE : TRUE;
}

/**
 * @brief Verifica se uma string representa uma `longitude`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa uma longitude`.
 */
Boolean validateLongitude (const char *string) {

    // Verifica se é negativo
    if (string [0] == '-') string++;

    // Verifica se o primeiro caractere não é um dígito
    if (!isdigit (string [0])) return FALSE;

    // Verifica se o formato não é válido (antes do ponto)
    int i; for (i = 1; string [i] && string [i] != '.'; i++) if (i == 3 || !isdigit (string [i])) return FALSE;

    // Verifica se a string terminou
    if (string [i] == 0) return FALSE;

    // Verifica se o formato não é válido (depois do ponto)
    for (int j = 1; string [i + j]; j++) if (j == 9 || !isdigit (string [i + j])) return FALSE;

    // Verifica a validade do valor
    return atof (string) > 180 ? FALSE : TRUE;
}

/**
 * @brief Verifica se uma string representa um `tipo de aeroporto`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa um tipo de aeroporto`.
 */
Boolean validateType (const char *string) {
    return (strcmp (string, "small_airport") &&
            strcmp (string, "medium_airport") &&
            strcmp (string, "large_airport") &&
            strcmp (string, "heliport") &&
            strcmp (string, "seaplane_base")) ? FALSE : TRUE;
}