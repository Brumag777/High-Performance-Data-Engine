// Headers utilizados
#include "Entity/Passenger.h"
#include "Config.h"

// Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>

/**
 * @brief `Estrutura` para armazenar `passageiros`.
 */
typedef struct passenger {
    char name [POWER_OF_TWO_3 + POWER_OF_TWO_4];
    int document_number;
    unsigned short dob;
    short nationality;
} Passenger;

/**
 * @brief `Cria` o `nome` de um passageiro.
 * @param name `Nome do passageiro`.
 * @param first_name `Primeiro nome` do passageiro.
 * @param last_name `Último nome` do passageiro.
 * @return `Nome` do passageiro criado.
 */
void createPassengerName (char *name, const char *first_name, const char *last_name) {

    // Calcula o tamanho do primeiro nome
    int n1 = strlen (first_name);

    // Copia os nomes
    strcpy (name, first_name);
    strcpy (name + n1 + 1, last_name);
}

/**
 * @brief `Cria` um `passageiro`.
 * @param first_name `Primeiro nome` do passageiro.
 * @param last_name `Último nome` do passageiro.
 * @param document_number `Número de documento` do passageiro.
 * @param dob `Data de nascimento` do passageiro.
 * @param nationality `Identificador da nacionalidade` do passageiro.
 */
Passenger *createPassenger (const char *first_name, const char *last_name, int document_number, unsigned short dob, short nationality) {

    // Aloca memória para a estrutura
    Passenger *p = malloc (sizeof (Passenger));

    // Define as componentes da estrutura
    createPassengerName (p -> name, first_name, last_name);
    p -> document_number = document_number;
    p -> dob = dob;
    p -> nationality = nationality;

    // Devolve o ponteiro
    return p;
}

/**
 * @brief `Elimina` um `passageiro`.
 * @param p `Ponteiro` para o passageiro.
 */
void destroyPassenger (Passenger *p) {
    free (p);
}

/**
 * @brief Devolve o `primeiro nome` de um passageiro.
 * @param p `Ponteiro` para o passageiro.
 * @return `Primeiro nome` do passageiro.
 */
const char *getPassengerFirstName (const struct passenger *p) {
    return p -> name;
}

/**
 * @brief Devolve o `último nome` de um passageiro.
 * @param p `Ponteiro` para o passageiro.
 * @return `Último nome` do passageiro.
 */
const char *getPassengerLastName (const struct passenger *p) {
    return p -> name + strlen (p -> name) + 1;
}

/**
 * @brief Devolve o `número de documento` de um passageiro.
 * @param p `Ponteiro` para o passageiro.
 * @return `Número de documento` do passageiro.
 */
int getPassengerDocumentNumber (const struct passenger *p) {
    return p -> document_number;
}

/**
 * @brief Devolve a `data de nascimento` de um passageiro.
 * @param p `Ponteiro` para o passageiro.
 * @return `Data de nascimento` do passageiro.
 */
short getPassengerDob (const struct passenger *p) {
    return p -> dob;
}

/**
 * @brief Devolve a `nacionalidade` de um passageiro.
 * @param p `Ponteiro` para o passageiro.
 * @return `Nacionalidade` do passageiro.
 */
short getPassengerNationality (const struct passenger *p) {
    return p -> nationality;
}