// Headers utilizados
#include "Query/MainQuery.h"
#include "Query/Query1.h"
#include "Query/Query2.h"
#include "Query/Query3.h"
#include "Query/Query4.h"
#include "Query/Query5.h"
#include "Query/Query6.h"
#include "Config.h"

// Bibliotecas utilizadas
#include <string.h>

/**
 * @brief `Executa as queries` pré-definidas.
 * @param dm `Ponteiro` para o gestor da base de dados.
 * @param read_file_name `Nome` do ficheiro de leitura.
 */
void executeQueries (DatabaseManager *dm, const char *read_file_name) {

    // Abre o ficheiro
    FILE *read_file = fopen (read_file_name, "r");

    // Declara o buffer
    char buffer [BUFFER_SIZE];

    // Declara o nome do ficheiro de escrita
    char write_file_name [BUFFER_SIZE] = "DefinedOutputs/";

    // Lê o ficheiro linha a linha
    for (int i = 1; fgets (buffer, BUFFER_SIZE, read_file); i++) {

        // Remove o '\n' no final do buffer
        buffer [strcspn (buffer, "\n")] = 0;

        // Define o nome do ficheiro
        sprintf (write_file_name + 15, "Output%d.txt", i);

        // Abre o ficheiro de escrita
        FILE *write_file = fopen (write_file_name, "w");

        // Realiza a query
        switch (*buffer) {
            case '1': executeQuery1 (dm, buffer + 2 + (buffer [1] == 'S'), write_file); break;
            case '2': executeQuery2 (dm, buffer + 2 + (buffer [1] == 'S'), write_file); break;
            case '3': executeQuery3 (dm, buffer + 2 + (buffer [1] == 'S'), write_file); break;
            case '4': executeQuery4 (dm, buffer + 2 + (buffer [1] == 'S'), write_file); break;
            case '5': executeQuery5 (dm, buffer + 2 + (buffer [1] == 'S'), write_file); break;
            case '6': executeQuery6 (dm, buffer + 2 + (buffer [1] == 'S'), write_file); break;
        }

        // Fecha o ficheiro de escrita
        fclose (write_file);
    }

    // Fecha o ficheiro
    fclose (read_file);
}