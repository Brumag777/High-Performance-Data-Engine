// Headers utilizados
#include "Parser/Aircraft.h"
#include "Parser/Utility.h"
#include "Validation/Aircraft.h"
#include "Manager/Database.h"
#include "Manager/Aircraft.h"

/**
 * @brief Realiza o `parsing` de uma `linha das aeronaves`.
 * @param line `Linha` do dataset.
 * @param dm `Ponteiro` para o `gestor da base de dados`.
 * @return `Booleano` que indica se a linha era válida.
 */
Boolean parseLineAircraft (char *line, DatabaseManager *dm) {

    // Carrega o identificador
    char *identifier = separateBlock (&line, '"');

    // Carrega o fabricante
    char *manufacturer = separateBlock (&line, '"');

    // Carrega o modelo
    char *model = separateBlock (&line, '"');

    // Carrega o ano
    if (validateYear (separateBlock (&line, '"')) == FALSE) return FALSE;

    // Regista a aeronave
    registerAircraft (getDatabaseAircrafts (dm), manufacturer, model, identifier);

    // A aeronave é válida
    return TRUE;
}