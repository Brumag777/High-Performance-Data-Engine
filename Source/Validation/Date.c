// Headers utilizados
#include "Validation/Aircraft.h"
#include "Structure/Date.h"

// Bibliotecas utilizadas
#include <ctype.h>
#include <stdlib.h>

/**
 * @brief Verifica se uma string `representa um tempo`.
 * @param string `String`.
 * @return `Booleano` que indica se a string `representa um tempo`.
 */
static inline Boolean validateTime (const char *string) {

    // Verifica se a hora não está bem representada
    if (!isdigit (string [0]) || !isdigit (string [1]) || string [2] != ':') return FALSE;

    // Verifica se o minuto não está bem representado
    return !isdigit (string [3]) || !isdigit (string [4]) || string [5] ? FALSE : TRUE;
}

/**
 * @brief Verifica se uma string `representa uma data`.
 * @param string `String`.
 * @param time_counts `Booleano` que indica se o tempo conta.
 * @param date `Data` em vetor.
 * @return `Booleano` que indica se a string `representa uma data`.
 */
Boolean validateDate (const char *string, Boolean time_counts, int date []) {

    // Verifica se o ano não está bem representado
    if (!isdigit (string [0]) || !isdigit (string [1]) || !isdigit (string [2]) || !isdigit (string [3]) || string [4] != '-') return FALSE;

    // Verifica se o mês não está bem representado
    if (!isdigit (string [5]) || !isdigit (string [6]) || string [7] != '-') return FALSE;

    // Verifica se o dia não está bem representado
    if (!isdigit (string [8]) || !isdigit (string [9]) || (!time_counts && string [10]) || (time_counts && string [10] != ' ')) return FALSE;

    // Verifica se o tempo está bem definido
    if (time_counts && validateTime (string + 11) == FALSE) return FALSE;

    // Calcula as componentes da data
    date [YEAR] = (string [0] - '0') * 1000 + (string [1] - '0') * 100 + (string [2] - '0') * 10 + (string [3] - '0') * 1;
    date [MONTH] = (string [5] - '0') * 10 + (string [6] - '0') * 1;
    date [DAY] = (string [8] - '0') * 10 + (string [9] - '0') * 1;

    // Verifica se a data é válida
    if (date [YEAR] > 2025 || (date [YEAR] == 2025 && date [MONTH] > 9) || (date [YEAR] == 2025 && date [MONTH] == 9 && date [DAY] > 30)) return FALSE;
    if (date [MONTH] == 0 || date [MONTH] > 12 || date [DAY] == 0 || date [DAY] > 31) return FALSE;

    // Calcula as componentes do tempo
    if (time_counts) {
        date [HOUR] = atoi (string + 11);
        date [MINUTE] = atoi (string + 14);
    }

    // A data é válida
    return TRUE;
}