// Headers utilizados
#include "Query/Query1.h"
#include "Entity/Airport.h"
#include "Manager/Airport.h"
#include "Manager/Database.h"
#include "Validation/Airport.h"

// Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>

/**
 * @brief Obtém os `argumentos da query 1`.
 * @param input `Input` do utilizador.
 * @return `Booleano` que indica se os argumentos são válidos.
 */
Boolean getArgumentsQuery1 (char *input) {

    // Indica ao utilizador que deve indicar o código do aeroporto
    printf ("\nType in the airport code: ");

    // Obtém o input
    if (fgets (input, BUFFER_SIZE, stdin)) input [strcspn (input, "\n")] = 0;

    // Valida o código do aeroporto
    if (validateCode (input) == FALSE) {

        // Indica ao utilizador que o argumento é inválido
        printf ("\nError: the airport code must be in the format 'XYZ'.\n\n");

        // O argumento é inválido
        return FALSE;
    }

    // Os argumentos são válidos
    return TRUE;
}

/**
 * @brief `Executa a query 1`.
 * @param dm `Ponteiro` para o gestor da base de dados.
 * @param input `Input` para a query.
 * @param file `Ficheiro` de output.
 */
void executeQuery1 (DatabaseManager *dm, const char *input, FILE *file) {

    // Procura o aeroporto
    Airport *a = getAirportById (getDatabaseAirports (dm), codeToInt (input));

    // Verifica se o aeroporto não existe
    if (a == NULL) {

        // Indica que nenhum aeroporto foi encontrado
        fprintf (file, "No airport found.\n");

        // Termina a função
        return;
    }

    // Obtém as componentes do aeroporto
    const char *name = getAirportName (a);
    const char *city = getAirportCity (a);
    const char *country = getAirportCountry (a);
    const char *type = getAirportType (a);
    int arrival_count = getAirportArrivalCount (a);
    int departure_count = getAirportDepartureCount (a);

    // Revela o aeroporto pretendido
    fprintf (file, "Code: %s, Name: %s, City: %s, Country: %s, Type: %s, Number of arrivals: %d, Number of departures: %d\n", input, name, city, country, type, arrival_count, departure_count);
}