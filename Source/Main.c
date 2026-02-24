#define _POSIX_C_SOURCE 199309L

// Headers utilizados
#include "Config.h"
#include "Manager/Database.h"
#include "Parser/MainParser.h"
#include "Query/MainQuery.h"
#include "Query/Query1.h"
#include "Query/Query2.h"
#include "Query/Query3.h"
#include "Query/Query4.h"
#include "Query/Query5.h"
#include "Query/Query6.h"
#include "InteractiveFunction.h"

// Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/**
 * @brief Calcula o `tempo decorrido` entre dois intervalos de tempo.
 * @param start `Tempo inicial`.
 * @param end `Tempo final`.
 */
static inline double elapsedTime(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

/**
 * @brief Determina a `utilização de RAM no momento`.
 * @return `Utilização de RAM` no momento.
 */
static long getCurrentRAM() {

    // Abre o ficheiro
    FILE *fp = fopen ("/proc/self/status", "r");

    // Declara o buffer
    char buffer [BUFFER_SIZE];

    // Declara a RAM
    long ram_kb = 0.0;

    // Procura o uso de RAM atual
    while (fgets (buffer, sizeof (buffer), fp)) {
        if (strncmp (buffer, "VmRSS:", 6) == 0) {
            sscanf (buffer + 6, "%ld", &ram_kb);
            break;
        }
    }

    // Fecha o ficheiro
    fclose(fp);

    // Retorna o uso de RAM
    return ram_kb;
}

/**
 * @brief Imprime os `recursos utilizados` durante a execução do programa.
 * @param ram_start `Uso de memória` após o início do programa.
 * @param ram_parsing `Uso de memória` após o parsing do programa.
 * @param ram_preparing `Uso de memória` após a preparação do programa.
 * @param ram_queries `Uso de memória` após a execução das queries do programa.
 * @param program_time `Tempo total` do programa.
 * @param parser_time `Tempo de parsing` do programa.
 * @param prepare_time `Tempo de preparação` do programa.
 * @param query_time `Tempo de execução das queries` do programa.
 */
static void printResources (long ram_start, long ram_parsing, long ram_preparing, long ram_queries, double program_time, double parser_time, double prepare_time, double query_time) {
    printf ("--- RAM usage review ---\n\n");
    printf ("RAM after beginning: %.3fMB\n", ram_start / 1024.0f);
    printf ("RAM after parsing: %.3fMB\n", ram_parsing / 1024.0f);
    printf ("RAM after preparing: %.3fMB\n", ram_preparing / 1024.0f);
    printf ("RAM after queries: %.3fMB\n\n", ram_queries / 1024.0f);
    printf ("--- Runtime review ---\n\n");
    printf ("Parsing runtime: %.3fs\n", parser_time);
    printf ("Preparing time: %.3fs\n", prepare_time);
    printf ("Query execution time: %.3fs\n", query_time);
    printf ("Program runtime: %.3fs\n", program_time);
}

/**
 * @brief `Corre` o programa.
 * @return `False`.
 */
int main () {

    // Obtém a versão e o tipo do dataset
    DatasetVersion version = getUserAnswer ("Do you the dataset to have errors? ", (const char * []) {"y", "n"}, 2, "Please answer 'y' or 'n'. ") == 0 ? DATASET_WITH_ERRORS : DATASET_WITHOUT_ERRORS;
    DatasetType type = getUserAnswer ("Do you want the dataset to be large? ", (const char * []) {"y", "n"}, 2, "Please answer 'y' or 'n'. ") == 0 ? DATASET_LARGE : DATASET_NORMAL;

    // Indica as escolhas do utilizador
    printf ("\nProgram version: %s\n", version == DATASET_WITH_ERRORS ? "With errors" : "Without errors");
    printf ("Program type: %s\n\n", type == DATASET_NORMAL ? "Normal" : "Large");

    // Cria a diretoria do dataset
    char dataset_directory [BUFFER_SIZE]; sprintf (dataset_directory, "Datasets/%s/%s/", version == DATASET_WITH_ERRORS ? "WithErrors" : "WithoutErrors", type == DATASET_NORMAL ? "Normal" : "Large");

    // Pergunta ao utilizador se pretende utilizador o modo interativo
    if (getUserAnswer ("Do you want to use the interactive program? ", (const char * []) {"y", "n"}, 2, "Please answer 'y' or 'n'. ") == 0) return runInteractiveProgram (dataset_directory, type);

    // Indica que o programa iniciou
    printf ("\n--- Program started ---\n");

    // Declara as utilizações de RAM
    long ram_start, ram_parsing, ram_preparing, ram_queries;

    // Declara os temporizadores
    struct timespec start_program, end_program;
    struct timespec start_parsing, end_parsing;
    struct timespec start_preparing, end_preparing;
    struct timespec start_queries, end_queries;

    // Inicializa o tempo do programa
    clock_gettime (CLOCK_MONOTONIC, &start_program);

    // Cria o gestor da base de dados
    DatabaseManager *dm = createDatabaseManager (type);

    // Obtém o uso de memória
    ram_start = getCurrentRAM ();

    // Indica que o parsing iniciou
    printf ("\n--- Parsing started ---\n");

    // Inicializa o tempo do parsing
    clock_gettime (CLOCK_MONOTONIC, &start_parsing);

    // Carrega os datasets
    parseDatasets (dm, dataset_directory);

    // Obtém o uso de memória
    ram_parsing = getCurrentRAM ();

    // Termina o tempo do parsing
    clock_gettime (CLOCK_MONOTONIC, &end_parsing);

    // Indica que o parsing terminou
    printf ("\n--- Parsing finished ---\n");

    // Indica que a preparação iniciou
    printf ("\n--- Preparing started ---\n");

    // Inicializa o tempo da preparação
    clock_gettime (CLOCK_MONOTONIC, &start_preparing);

    // Prepara a base de dados
    prepareDatabase (dm);

    // Obtém o uso de memória
    ram_preparing = getCurrentRAM ();

    // Termina o tempo da preparação
    clock_gettime (CLOCK_MONOTONIC, &end_preparing);

    // Indica que o parsing terminou
    printf ("\n--- Preparing finished ---\n");

    // Indica que a execução das queries iniciou
    printf ("\n--- Query execution started ---\n");

    // Inicializa o tempo da execução das queries
    clock_gettime (CLOCK_MONOTONIC, &start_queries);

    // Executa as queries
    executeQueries (dm, type == DATASET_NORMAL ? "DefinedInputs/Normal.txt" : "DefinedInputs/Large.txt");

    // Obtém o uso de memória
    ram_queries = getCurrentRAM ();

    // Termina o tempo da execução das queries
    clock_gettime (CLOCK_MONOTONIC, &end_queries);

    // Indica que a execução das queries terminou
    printf ("\n--- Query execution finished ---\n");

    // Elimina o gestor da base de dados
    destroyDatabaseManager (dm);

    // Termina o tempo do programa
    clock_gettime (CLOCK_MONOTONIC, &end_program);

    // Indica que o programa terminou
    printf ("\n--- Program finished ---\n\n");

    // Imprime a informação dos recursos
    printResources (ram_start, ram_parsing, ram_preparing, ram_queries, elapsedTime (start_program, end_program), elapsedTime (start_parsing, end_parsing), elapsedTime (start_preparing, end_preparing), elapsedTime (start_queries, end_queries));

    // Devolve falso
    return FALSE;
}
