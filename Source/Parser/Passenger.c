// Headers utilizados
#include "Parser/Passenger.h"
#include "Parser/Utility.h"
#include "Validation/Passenger.h"
#include "Validation/Date.h"
#include "Structure/Date.h"
#include "Manager/Database.h"
#include "Manager/Nationality.h"
#include "Manager/Passenger.h"

// Bibliotecas utilizadas
#include <stdlib.h>

/**
 * @brief `Regista um passageiro` num `gestor de passageiros`.
 * @param m `Ponteiro` para o `gestor de passageiros`.
 * @param document_number `Número de documento` do passageiro.
 * @param first_name `Primeiro nome` do passageiro.
 * @param last_name `Último nome` do passageiro.
 * @param dob `Data de nascimento` do passageiro.
 * @param nationality `Identificador da nacionalidade` do passageiro.
 */
void registerPassenger (PassengerManager *m, int document_number, const char *first_name, const char *last_name, unsigned short dob, short nationality);

/**
 * @brief Realiza o `parsing` de uma `linha dos passageiros`.
 * @param line `Linha` do dataset.
 * @param dm `Ponteiro` para o `gestor da base de dados`.
 * @return `Booleano` que indica se a linha era válida.
 */
Boolean parseLinePassenger (char *line, DatabaseManager *dm) {

    // Carrega o número de documento
    char *block = separateBlock (&line, '"');
    if (validadeDocumentNumber (block) == FALSE) return FALSE;
    int document_number = atoi (block);

    // Carrega o primeiro nome
    char *first_name = separateBlock (&line, '"');

    // Carrega o último nome
    char *last_Name = separateBlock (&line, '"');

    // Carrega a data de nascimento
    int dob [3] = {0};
    if (validateDate (separateBlock (&line, '"'), FALSE, dob) == FALSE) return FALSE;

    // Carrega a nacionalidade
    char *nationality = separateBlock (&line, '"');

    // Carrega o género
    if (validateGender (separateBlock (&line, '"')) == FALSE) return FALSE;

    // Carrega o email
    if (validateEmail (separateBlock (&line, '"')) == FALSE) return FALSE;

    // Regista a nacionalidade
    int nationality_index = registerNationality (getDatabaseNationalities (dm), nationality);

    // Regista o passageiro
    registerPassenger (getDatabasePassengers (dm), document_number, first_name, last_Name, dateToInt (dob), nationality_index);

    // O aeroporto é válido
    return TRUE;
}