#ifndef PARSER_UTILITY_H
#define PARSER_UTILITY_H

/**
 * @brief `Separa uma string` por `um caractere` e avança até à sua `próxima ocorrência`.
 * @param string `Ponteiro` para a string a separar.
 * @param c `Caractere de paragem`.
 * @return Endereço anterior à `ocorrência do caractere de paragem`.
 */
char *separateBlock (char **string, char c);

#endif