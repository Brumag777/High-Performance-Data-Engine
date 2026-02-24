// Headers utilizados
#include "Query/Query6.h"
#include "Entity/Airport.h"
#include "Manager/Airport.h"
#include "Manager/Nationality.h"
#include "Manager/Database.h"

// Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>

/**
 * @brief Obtém os `argumentos da query 6`.
 * @param input `Input` do utilizador.
 * @return `Booleano` que indica se os argumentos são válidos.
 */
Boolean getArgumentsQuery6 (char *input) {

    // Indica ao utilizador que deve indicar a nacionalidade
    printf ("\nType in the nationality: ");

    // Obtém o input
    if (fgets (input, BUFFER_SIZE, stdin)) input [strcspn (input, "\n")] = 0;

    // Os argumentos são válidos
    return TRUE;
}

/**
 * @brief `Executa a query 6`.
 * @param dm `Ponteiro` para o gestor da base de dados.
 * @param input `Input` para a query.
 * @param file `Ficheiro` de output.
 */
void executeQuery6 (DatabaseManager *dm, const char *input, FILE *file) {

    // Número de visitas do aeroporto
    int number_visits;

    // Determina o aeroporto mais visitado
    Airport *a = getMostVisitedAirportByNationality (getDatabaseAirports (dm), getNationalityIndex (getDatabaseNationalities (dm), input), &number_visits);

    // Verifica se nenhum aeroporto foi encontrado
    if (a == NULL) {

        // Indica que nenhum aeroporto foi encontrada
        fprintf (file, "No airport found.\n");

        // Termina a função
        return;
    }

    // Obtém o código do aeroporto
    char *code = intToCode (getAirportCode (a));

    // Revela o aeroporto pretendido
    fprintf (file, "Code: %s, Number of visits: %d\n", code, number_visits);

    // Liberta a memória alocada para o código
    free (code);
}