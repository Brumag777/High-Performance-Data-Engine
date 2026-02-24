// Headers utilizados
#include "Query/Query3.h"
#include "Entity/Airport.h"
#include "Manager/Airport.h"
#include "Manager/Database.h"
#include "Structure/Date.h"
#include "Validation/Date.h"

// Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>

/**
 * @brief Obtém os `argumentos da query 3`.
 * @param input `Input` do utilizador.
 * @return `Booleano` que indica se os argumentos são válidos.
 */
Boolean getArgumentsQuery3 (char *input) {

    // Indica ao utilizador que deve indicar a primeira data
    printf ("\nType in the first date (type 'None' if you do not with to filter): ");

    // Obtém o input
    if (fgets (input, BUFFER_SIZE, stdin)) input [strcspn (input, "\n")] = 0;

    // Verifica se a data dada é 'None'
    if (strcmp (input, "None") == 0) {

        // Apaga a string
        *input = 0;

        // O argumento é válido
        return TRUE;
    }

    // Declara uma data auxiliar
    int date [3];

    // Valida a data dada
    if (validateDate (input, FALSE, date) == FALSE) {

        // Indica ao utilizador que o argumento é inválido
        printf ("\nError: the dates must be in the format 'YYYY-MM-DD'.\n\n");

        // O argumento é inválido
        return FALSE;
    }

    // Indica ao utilizador que deve indicar a segunda data
    printf ("\nType in the second date: ");

    // Calcula o tamanho da string
    int n = strlen (input); input [n] = ' ';

    // Obtém o input
    if (fgets (input + n + 1, BUFFER_SIZE - 1, stdin)) input [strcspn (input, "\n")] = 0;

    // Valida a data dada
    if (validateDate (input + n + 1, FALSE, date) == FALSE) {

        // Indica ao utilizador que o argumento é inválido
        printf ("\nError: the dates must be in the format 'YYYY-MM-DD'.\n\n");

        // O argumento é inválido
        return FALSE;
    }

    // Os argumentos são válidos
    return TRUE;
}

/**
 * @brief Determina os argumentos para a `query 3`.
 * @param input `Input` para a query.
 * @param first_date `Primeira data`.
 * @param second_date `Segunda data`.
 * @return `Número de aeronaves` prentedido.
 */
static void determineArgumentsQuery3 (const char *input, int first_date [], int second_date []) {

    // Verifica se não foi dada uma data
    if (strlen (input) == 0) {
        
        // Define a primeira data como 01-01-2025
        first_date [YEAR] = 2025;
        first_date [MONTH] = 1;
        first_date [DAY] = 1;

        // Define a segunda data como 30-09-2025
        second_date [YEAR] = 2025;
        second_date [MONTH] = 9;
        second_date [DAY] = 30;

        // Termina a função
        return;
    }

    // Determina a primeira data
    first_date [YEAR] = atoi (input);
    first_date [MONTH] = atoi (input + 5);
    first_date [DAY] = atoi (input + 8);

    // Determina a segunda data
    second_date [YEAR] = atoi (input + 11);
    second_date [MONTH] = atoi (input + 16);
    second_date [DAY] = atoi (input + 19);
}

/**
 * @brief `Executa a query 3`.
 * @param dm `Ponteiro` para o gestor da base de dados.
 * @param input `Input` para a query.
 * @param file `Ficheiro` de output.
 */
void executeQuery3 (DatabaseManager *dm, const char *input, FILE *file) {

    // Declara as datas
    int first_date [3], second_date [3];

    // Determina as datas
    determineArgumentsQuery3 (input, first_date, second_date);

    // Declara o número de visitas do aeroporto
    int number_visits;

    // Determina o aeroporto mais visitado
    Airport *a = getMostVisitedAirportBetweenDates (getDatabaseAirports (dm), first_date, second_date, &number_visits);

    // Verifica se nenhum aeroporto foi encontrado
    if (a == NULL) {

        // Indica que nenhum aeroporto foi encontrado
        fprintf (file, "No airport found.\n");

        // Termina a função
        return;
    }

    // Obtém as componentes do aeroporto
    char *code = intToCode (getAirportCode (a));
    const char *name = getAirportName (a);
    const char *city = getAirportCity (a);
    const char *country = getAirportCountry (a);

    // Revela o aeroporto pretendido
    fprintf (file, "Code: %s, Name: %s, City: %s, Country: %s, Number of visits: %d\n", code, name, city, country, number_visits);

    // Liberta a memória alocada para o código
    free (code);
}