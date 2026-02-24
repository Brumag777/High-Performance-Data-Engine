// Headers utilizados
#include "Parser/Utility.h"

/**
 * @brief `Separa uma string` por `um caractere`
 * @param string `Ponteiro` para a string a separar.
 * @param c `Caractere de paragem`.
 * @return `Endereço inicial` da string.
 */
static inline char *seperateString (char **string, char c) {

    // Guarda o endereço inicial
    char *r = *string;

    // Avança na string até ao caractere de paragem ou ao fim da string
    while ((*string) [0] && (*string) [0] != c) (*string)++;

    // Avança o caractere de paragem
    if ((*string) [0] == c) {
        (*string) [0] = 0;
        (*string)++;
    }

    // Retorna o endereço inicial
    return r;
}

/**
 * @brief `Separa uma string` por `um caractere` e avança até à sua `próxima ocorrência`.
 * @param string `Ponteiro` para a string a separar.
 * @param c `Caractere de paragem`.
 * @return Endereço da `ocorrência do caractere de paragem`.
 */
char *separateBlock (char **string, char c) {

    // Avança a primeira vez
    seperateString (string, c);

    // Avança a segunda vez
    char *r = seperateString (string, c);

    // Retorna o endereço da ocorrência do caractere de paragem
    return r;
}