// Headers utilizados
#include "Validation/Aircraft.h"

// Bibliotecas utilizadas
#include <ctype.h>

/**
 * @brief Verifica se uma string `representa um número de documento`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa um número de documento`.
 */
Boolean validadeDocumentNumber (const char *string) {
    
    // Verifica se o formato é válido
    for (int i = 0; i < 9; i++) if (!isdigit (string [i])) return FALSE;

    // Verifica se a string terminou
    return string [9] ? FALSE : TRUE;
}

/**
 * @brief Verifica se uma string `representa um género`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa um género`.
 */
Boolean validateGender (const char *string) {
    return (string [0] == 'M' || string [0] == 'F' || string [0] == 'O') && string [1] == 0 ? TRUE : FALSE;
}

/**
 * @brief Verifica se uma string `representa um email`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa um email`.
 */
Boolean validateEmail (const char *string) {

    // Verifica se o username é válido
    int i; for (i = 0; string [i] && string [i] != '@'; i++)
        if (!isdigit (string [i]) && !islower (string [i]) && string [i] != '.') return FALSE;

    // Verifica se a string terminou
    if (i == 0 || string [i++] == 0) return FALSE;

    // Verifica se o primeiro caractere do domínio é válido
    if (!islower (string [i])) return FALSE;

    // Verifica se o domínio é válido (antes do ponto)
    for (i++; string [i] && string [i] != '.'; i++) if (!islower (string [i])) return FALSE;

    // Verifica se a string terminou
    if (string [i++] == 0) return FALSE;

    // Verifica se o domínio é válido (depois do ponto)
    if (!islower (string [i]) || !islower (string [i + 1])) return FALSE;

    // Verifica se a string terminou
    if (string [i + 2] == 0) return TRUE;

    // Verifica se o último caractere é válido
    if (!islower (string [i + 2])) return FALSE;

    // Verifica se a string terminou
    return string [i + 3] == 0 ? TRUE : FALSE;
}