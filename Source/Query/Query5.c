// Headers utilizados
#include "Query/Query5.h"
#include "Entity/Airline.h"
#include "Manager/Airline.h"
#include "Manager/Database.h"

// Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Obtém os `argumentos da query 5`.
 * @param input `Input` do utilizador.
 * @return `Booleano` que indica se os argumentos são válidos.
 */
Boolean getArgumentsQuery5 (char *input) {

    // Indica ao utilizador que deve indicar o número de companhias pretendido
    printf ("\nType in the number of airlines: ");

    // Obtém o input
    if (fgets (input, BUFFER_SIZE, stdin)) input [strcspn (input, "\n")] = 0;

    // Valida o número de companhias dado
    for (int i = 0; input [i]; i++) if (!isdigit (input [i])) {

        // Indica ao utilizador que o argumento é inválido
        printf ("\nError: you must give a natural number.\n\n");

        // O argumento é inválido
        return FALSE;
    }

    // Os argumentos são válidos
    return TRUE;
}

/**
 * @brief `Executa a query 5`.
 * @param dm `Ponteiro` para o gestor da base de dados.
 * @param input `Input` para a query.
 * @param file `Ficheiro` de output.
 */
void executeQuery5 (DatabaseManager *dm, const char *input, FILE *file) {

    // Determina o número de companhias pretendido
    int N = atoi (input);

    // Declara o array de companhias
    Airline *airlines [N];

    // Procura o top N
    int number_found = getTopNMostDelayedAirlines (getDatabaseAirlines (dm), N, airlines);

    // Verifica se nenhuma companhia foi encontrada
    if (number_found == 0) {

        // Indica que nenhuma companhia foi encontrada
        fprintf (file, "No airline found.\n");

        // Termina a função
        return;
    }

    // Percorre o array para formar o output
    for (int i = 0; i < number_found; i++) {

        // Obtém as componentes da companhia
        const char *name = getAirlineName (airlines [i]);
        int delay_count = getAirlineDelayCount (airlines [i]);
        int total_delay = getAirlineTotalDelay (airlines [i]);
        double avg_delay = ((double) (total_delay)) / ((double) delay_count);

        // Revela a companhia
        fprintf (file, "Top %d - Name: %s, Number of delays: %d, Average delay: %.3f\n", i + 1, name, delay_count, avg_delay);
    }
}