// Headers utilizados
#include "Validation/Aircraft.h"

// Bibliotecas utilizadas
#include <ctype.h>
#include <stdlib.h>

/**
 * @brief Verifica se uma string `representa um ano`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa um ano`.
 */
Boolean validateYear (const char *string) {

    // Verifica se o formato é válido
    if (!isdigit (string [0]) || !isdigit (string [1]) || !isdigit (string [2]) || !isdigit (string [3]) || string [4]) return FALSE;

    // Verifica se o ano é válido
    return atoi (string) < 2026 ? TRUE : FALSE;
}