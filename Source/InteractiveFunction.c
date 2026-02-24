// Headers utilizados
#include "InteractiveFunction.h"
#include "Manager/Database.h"
#include "Query/Query1.h"
#include "Query/Query2.h"
#include "Query/Query3.h"
#include "Query/Query4.h"
#include "Query/Query5.h"
#include "Query/Query6.h"
#include "Parser/MainParser.h"

// Bibliotecas utilizadas
#include <stdio.h>
#include <string.h>

/**
 * @brief Verifica se uma string `corresponde a uma resposta válida`.
 * @param answers Array de `respostas válidas`.
 * @param nanswers `Número de respostas` válidas.
 * @param string `String`.
 * @return `Índice no array` onde foi encontrada a resposta ou `NO_VALUE` se não foi encontrada nenhuma.
 */
static int checkUserAnswer (const char *answers [], int nanswers, const char *string) {

    // Procura uma resposta coincidente do array
    for (int i = 0; i < nanswers; i++) if (strcmp (answers [i], string) == 0) return i;

    // Nenhuma resposta foi encontrada
    return NO_VALUE;
}

/**
 * @brief Obtém uma resposta do utilizador de entre certas opções.
 * @param initial_message `Mensagem inicial` opcional (deve ser `NULL` caso não for pretendida).
 * @param answers Array de `respostas válidas`.
 * @param nanswers `Nuḿero de respostas` válidas.
 * @param invalid_message `Mensagem a imprimir` caso a resposta seja inválida.
 * @param `Índice no array` onde foi encontrada a resposta.
 */
int getUserAnswer (const char *initial_message, const char *answers [], int nanswers, const char *invalid_message) {

    // Imprime a mensagem inicial
    if (initial_message) printf ("%s", initial_message);

    // Declara o índice
    int index;

    // Inicializa o buffer
    char buffer [BUFFER_SIZE] = {0};

    // Repete o ciclo até o utilizador escrever um input válido
    while ((index = checkUserAnswer (answers, nanswers, buffer)) == NO_VALUE) {

        // Verifica se a resposta é inválida
        if (buffer [0]) printf ("%s", invalid_message);

        // Obtém o input do utilizador
        if (fgets (buffer, BUFFER_SIZE, stdin)) buffer [strcspn (buffer, "\n")] = 0;
    }

    // Devolve o índice
    return index;
}

/**
 * @brief Corre o `programa interativo`.
 * @param dataset_directory `Diretoria` dos datasets.
 * @param type `Tipo de dataset`.
 * @return `False`.
 */
Boolean runInteractiveProgram (const char *dataset_directory, DatasetType type) {

    // Indica que o programa iniciou
    printf ("\n--- Program started ---\n");

    // Cria o gestor da base de dados
    DatabaseManager *dm = createDatabaseManager (type);

    // Indica que o parsing iniciou
    printf ("\n--- Parsing started ---\n");

    // Carrega os datasets
    parseDatasets (dm, dataset_directory);

    // Indica que o parsing terminou
    printf ("\n--- Parsing finished ---\n");

    // Indica que a preparação iniciou
    printf ("\n--- Preparing started ---\n");

    // Prepara a base de dados
    prepareDatabase (dm);

    // Indica que o parsing terminou
    printf ("\n--- Preparing finished ---\n");

    // Indica que o programa interativo iniciou
    printf ("\n--- Interactive program started ---\n\n");

    // Declara as respostas do utilizador
    const char *answers [] = {"Quit", "1", "2", "3", "4", "5", "6"};

    // Declara o input do utilizador
    char input [BUFFER_SIZE];

    // Query pedida pelo utilizador
    int query;

    // Mantém o programa a correr até o utilizador sair
    while ((query = getUserAnswer ("-> ", answers, 7, "\nPlease type in 'Quit', '1', '2', '3', '4', '5' or '6'.\n\n-> "))) {

        // Recebe os argumentos da query
        switch (query) {
            case 1: if (getArgumentsQuery1 (input) == FALSE) continue; break;
            case 2: if (getArgumentsQuery2 (input) == FALSE) continue; break;
            case 3: if (getArgumentsQuery3 (input) == FALSE) continue; break;
            case 4: if (getArgumentsQuery4 (input) == FALSE) continue; break;
            case 5: if (getArgumentsQuery5 (input) == FALSE) continue; break;
            case 6: if (getArgumentsQuery6 (input) == FALSE) continue; break;
        }

        // Imprime uma linha
        putchar ('\n');

        // Realiza a query
        switch (query) {
            case 1: executeQuery1 (dm, input, stdout); break;
            case 2: executeQuery2 (dm, input, stdout); break;
            case 3: executeQuery3 (dm, input, stdout); break;
            case 4: executeQuery4 (dm, input, stdout); break;
            case 5: executeQuery5 (dm, input, stdout); break;
            case 6: executeQuery6 (dm, input, stdout); break;
        }

        // Imprime uma linha
        putchar ('\n');
    }

    // Indica que o programa interativo terminou
    printf ("\n--- Interactive program finished ---\n");

    // Elimina o gestor da base de dados
    destroyDatabaseManager (dm);

    // Indica que o programa terminou
    printf ("\n--- Program finished ---\n\n");

    // Devolve falso
    return FALSE;
}