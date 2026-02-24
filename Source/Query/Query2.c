// Headers utilizados
#include "Query/Query2.h"
#include "Entity/Aircraft.h"
#include "Manager/Aircraft.h"
#include "Manager/Database.h"

// Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Obtém os `argumentos da query 2`.
 * @param input `Input` do utilizador.
 * @return `Booleano` que indica se os argumentos são válidos.
 */
Boolean getArgumentsQuery2 (char *input) {

    // Indica ao utilizador que deve indicar o número de aeronaves pretendido
    printf ("\nType in the number of aircrafts: ");

    // Obtém o input
    if (fgets (input, BUFFER_SIZE, stdin)) input [strcspn (input, "\n")] = 0;

    // Valida o número de aeronaves dado
    for (int i = 0; input [i]; i++) if (!isdigit (input [i])) {

        // Indica ao utilizador que o argumento é inválido
        printf ("\nError: you must give a natural number.\n\n");

        // O argumento é inválido
        return FALSE;
    }

    // Calcula o tamanho da string
    int n = strlen (input); input [n] = ' ';

    // Indica ao utilizador que deve indicar o fabricante pretendido
    printf ("\nType in the manufacturer (type 'None' if you do not wish to filter): ");

    // Obtém o input
    if (fgets (input + n + 1, BUFFER_SIZE - 1, stdin)) input [strcspn (input, "\n")] = 0;

    // Valida o fabricante dado
    for (int i = n + 1; input [i]; i++) if (!isalpha (input [i])) {

        // Indica ao utilizador que o argumento é inválido
        printf ("\nError: the manufacturer is a simple name.\n\n");

        // O argumento é inválido
        return FALSE;
    }

    // Verifica se o utilizador não pretende filtrar por fabricante
    if (strcmp (input + n + 1, "None") == 0) input [n] = 0;

    // Os argumentos são válidos
    return TRUE;
}

/**
 * @brief Determina os argumentos para a `query 2`.
 * @param input `Input` para a query.
 * @param  manufacturer`Ponteiro` para o `fabricante` dado.
 * @return `Número de aeronaves` prentedido.
 */
static int determineArgumentsQuery2 (const char *input, char **manufacturer) {

    // Determina o número de aeronaves a encontrar
    int N = atoi (input);

    // Avança no input
    while (*input && *input != ' ') input++;

    // Verifica se foi dado um fabricante
    *manufacturer = *input ? strdup (input + 1) : NULL;

    // Retorna o número de aeronaves a encontrar
    return N;
}

/**
 * @brief `Executa a query 2`.
 * @param dm `Ponteiro` para o gestor da base de dados.
 * @param input `Input` para a query.
 * @param file `Ficheiro` de output.
 */
void executeQuery2 (DatabaseManager *dm, const char *input, FILE *file) {

    // Determina os argumentos
    char *wanted_manufacturer; int N = determineArgumentsQuery2 (input, &wanted_manufacturer);

    // Declara o array de aeronaves
    Aircraft *aircrafts [N];

    // Procura o top N
    int number_found = getTopNMostFlownAircrafts (getDatabaseAircrafts (dm), wanted_manufacturer, N, aircrafts);

    // Liberta a memória alocada para o fabricante
    if (wanted_manufacturer) free (wanted_manufacturer);

    // Verifica se nenhuma aeronave foi encontrada
    if (number_found == 0) {

        // Indica que nenhuma aeronave foi encontrada
        fprintf (file, "No aircraft found.\n");

        // Termina a função
        return;
    }

    // Percorre o array para formar o output
    for (int i = 0; i < number_found; i++) {

        // Obtém as componentes da aeronave
        const char *identifier = getAircraftIdentifier (aircrafts [i]);
        const char *manufacturer = getAircraftManufacturer (aircrafts [i]);
        const char *model = getAircraftModel (aircrafts [i]);
        int flight_count = getAircraftFlightCount (aircrafts [i]);

        // Revela a aeronave
        fprintf (file, "Top %d - Identifier: %s, Manufacturer: %s, Model: %s, Number of flights: %d\n", i + 1, identifier, manufacturer, model, flight_count);
    }
}