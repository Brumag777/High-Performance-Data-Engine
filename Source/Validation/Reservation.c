// Headers utilizados
#include "Validation/Aircraft.h"

// Bibliotecas utilizadas
#include <ctype.h>

/**
 * @brief Verifica se uma string `representa um id de reserva`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa um id de reserva`.
 */
Boolean validateReservationId (const char *string) {

    // Verifica se o primeiro caractere não é um R
    if (string [0] != 'R') return FALSE;

    // Verifica se os caracteres seguintes são dígitos
    int i; for (i = 1; i < 10; i++) if (!isdigit (string [i])) return FALSE;

    // Verifica se a string terminou
    return string [i] == 0 ? TRUE : FALSE;
}