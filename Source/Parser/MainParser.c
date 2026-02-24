// Headers utilizados
#include "Parser/MainParser.h"
#include "Manager/Database.h"
#include "Parser/Aircraft.h"
#include "Parser/Airport.h"
#include "Parser/Flight.h"
#include "Parser/Passenger.h"
#include "Parser/Reservation.h"
#include "Config.h"

// Bibliotecas utilizadas
#include <stdio.h>
#include <string.h>

/**
 * @brief `Enumeração dos datasets`.
 */
typedef enum dataset_enum {
    N_AIRCRAFT,
    N_AIRPORT,
    N_PASSENGER,
    N_FLIGHT,
    N_RESERVATION,
    N_DATASETS
} DatasetEnum;

/**
 * @brief `Tamanho do buffer` dos parsers.
 */
#define PARSER_BUFFER_SIZE POWER_OF_TWO_20

/**
 * @brief `Buffer de erros` dos parsers.
 */
static char error_buffer [PARSER_BUFFER_SIZE];

/**
 * @brief `Funções de parsing` de cada um dos datasets.
 */
static Boolean (*parseLineFuncs [N_DATASETS]) (char *, DatabaseManager *) = {parseLineAircraft, parseLineAirport, parseLinePassenger, parseLineFlight, parseLineReservation};

/**
 * @brief Abre os `ficheiros dos datasets`.
 * @param read_files `Ficheiros de leitura` a abrir.
 * @param write_files `Ficheiros de escrita` a abrir.
 * @param directory `Diretoria` dos `ficheiros de leitura`.
 */
static void openDatasetFiles (FILE *read_files [], FILE *write_files [], const char *directory) {

    // Declara os nomes dos ficheiros de leitura
    char read_file_names [N_DATASETS][BUFFER_SIZE];

    // Define os nomes dos ficheiros de leitura
    sprintf (read_file_names [N_AIRCRAFT], "%s/Aircrafts.csv", directory);
    sprintf (read_file_names [N_AIRPORT], "%s/Airports.csv", directory);
    sprintf (read_file_names [N_PASSENGER], "%s/Passengers.csv", directory);
    sprintf (read_file_names [N_FLIGHT], "%s/Flights.csv", directory);
    sprintf (read_file_names [N_RESERVATION], "%s/Reservations.csv", directory);

    // Abre os ficheiros de leitura
    for (int i = 0; i < N_DATASETS; i++) read_files [i] = fopen (read_file_names [i], "r");

    // Abre os ficheiros de escrita
    write_files [N_AIRCRAFT] = fopen ("DatasetErrors/Aircrafts_errors.csv", "w");
    write_files [N_AIRPORT] = fopen ("DatasetErrors/Airports_errors.csv", "w");
    write_files [N_PASSENGER] = fopen ("DatasetErrors/Passengers_errors.csv", "w");
    write_files [N_FLIGHT] = fopen ("DatasetErrors/Flights_errors.csv", "w");
    write_files [N_RESERVATION] = fopen ("DatasetErrors/Reservations_errors.csv", "w");
}

/**
 * @brief Realiza o parsing de um `dataset`.
 * @param read_file `Ficheiro de leitura`.
 * @param write_file `Ficheiro de escrita`.
 * @param buffer `Buffer` a utilizar.
 * @param dm `Ponteiro` para o gestor da base de dados.
 * @param parseLine `Função de parsing` a utilizar.
 */
static void genericParse (FILE *read_file, FILE *write_file, char *buffer, DatabaseManager *dm, Boolean (*parseLine) (char *, DatabaseManager *)) {

    // Offset no buffer de erros
    int offset = 0;

    // Linha original
    char original_line [BUFFER_SIZE];

    // Lê a primeira linha
    if (fgets (buffer, BUFFER_SIZE, read_file)) fprintf (write_file, "%s", buffer);

    // Lê o ficheiro linha a linha
    while (fgets (buffer, BUFFER_SIZE, read_file)) {

        // Copia a linha original
        strcpy (original_line, buffer);
        int len = strlen (original_line);

        // Carrega a linha
        if (parseLine (buffer, dm) == FALSE) {

            // Verifica se o buffer encheu
            if (offset + len > PARSER_BUFFER_SIZE) {

                // Regista o buffer
                fwrite (error_buffer, 1, offset, write_file);

                // Reseta o offset
                offset = 0;
            }

            // Copia a linha de erro
            memcpy (error_buffer + offset, original_line, len);

            // Atualiza o offset
            offset += len;
        }
    }

    // Regista o restante do buffer
    if (offset > 0) fwrite (error_buffer, 1, offset, write_file);
}

/**
 * @brief Realiza o `parsing dos datasets`.
 * @param dm `Ponteiro` para o gestor da base de dados.
 * @param directory `Diretoria` para os ficheiros de leitura.
 */
void parseDatasets (DatabaseManager *dm, const char *directory) {

    // Declara os ficheiros
    FILE *read_files [N_DATASETS], *write_files [N_DATASETS];

    // Abre os ficheiros
    openDatasetFiles (read_files, write_files, directory);

    // Declara o buffer
    char buffer [BUFFER_SIZE];

    // Processa cada dataset
    for (int i = 0; i < N_DATASETS; i++) {

        // Processa o dataset
        genericParse (read_files [i], write_files [i], buffer, dm, parseLineFuncs [i]);

        // Fecha os ficheiros
        fclose (read_files [i]); fclose (write_files [i]);
    }
}