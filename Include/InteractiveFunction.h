#ifndef INTERACTIVE_FUNCTION_H
#define INTERACTIVE_FUNCTION_H

// Headers utilizados
#include "Config.h"

/**
 * @brief Obtém uma resposta do utilizador de entre certas opções.
 * @param initial_message `Mensagem inicial` opcional (deve ser `NULL` caso não for pretendida).
 * @param answers Array de `respostas válidas`.
 * @param nanswers `Nuḿero de respostas` válidas.
 * @param invalid_message `Mensagem a imprimir` caso a resposta seja inválida.
 * @param `Índice no array` onde foi encontrada a resposta.
 */
int getUserAnswer (const char *initial_message, const char *answers [], int nanswers, const char *invalid_message);

/**
 * @brief Corre o `programa interativo`.
 * @param dataset_directory `Diretoria` dos datasets.
 * @param type `Tipo de dataset`.
 * @return `False`.
 */
Boolean runInteractiveProgram (const char *dataset_directory, DatasetType type);

#endif