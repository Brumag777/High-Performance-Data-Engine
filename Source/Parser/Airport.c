// Headers utilizados
#include "Parser/Airport.h"
#include "Parser/Utility.h"
#include "Validation/Airport.h"
#include "Manager/Database.h"
#include "Manager/Airport.h"

/**
 * @brief Realiza o `parsing` de uma `linha dos aeroportos`.
 * @param line `Linha` do dataset.
 * @param dm `Ponteiro` para o `gestor da base de dados`.
 * @return `Booleano` que indica se a linha era válida.
 */
Boolean parseLineAirport (char *line, DatabaseManager *dm) {

    // Carrega o código
    char *code = separateBlock (&line, '"');
    if (validateCode (code) == FALSE) return FALSE;

    // Carrega o nome
    char *name = separateBlock (&line, '"');

    // Carrega a cidade
    char *city = separateBlock (&line, '"');

    // Carrega o país
    char *country = separateBlock (&line, '"');

    // Carrega a latitude
    if (validateLatitude (separateBlock (&line, '"')) == FALSE) return FALSE;

    // Carrega a longitude
    if (validateLongitude (separateBlock (&line, '"')) == FALSE) return FALSE;

    // Carrega o icao
    separateBlock (&line, '"');

    // Carrega o tipo
    char *type = separateBlock (&line, '"');
    if (validateType (type) == FALSE) return FALSE;

    // Regista o aeroporto
    registerAirport (getDatabaseAirports (dm), code, name, city, type, country);

    // O aeroporto é válido
    return TRUE;
}