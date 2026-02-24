// Headers utilizados
#include "Entity/Airport.h"

// Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>

/**
 * @brief `Estrutura` para armazenar `aeroportos`.
 */
typedef struct airport {
    char *name;
    char *city;
    char *type;
    unsigned short arrival_count;
    unsigned short departure_count;
    int code;
    char country [SIZE_AIRPORT_COUNTRY + 1];
} Airport;

/**
 * @brief Converte o `código` de um aeroporto para inteiro.
 * @param code `Código` do aeroporto em `string`.
 * @return `Código` do aeroporto em `inteiro`.
 */
int codeToInt (const char *code) {
    return 32 * 32 * (code [0] - 'A') + 32 * (code [1] - 'A') + (code [2] - 'A');
}

/**
 * @brief Converte um `inteiro` num `código` de aeroporto.
 * @param code `Código` do aeroporto em `string`.
 * @return Cópia do `código` do aeroporto em `string`.
 */
char *intToCode (int code) {

    // Declara o código
    char code_string [4];

    // Determina os caracteres
    code_string [0] = (code / (32 * 32) % 32) + 'A';
    code_string [1] = ((code / 32) % 32) + 'A';
    code_string [2] = (code % 32) + 'A';
    code_string [3] = 0;

    // Devolve uma cópia do código
    return strdup (code_string);
}

/**
 * @brief `Cria` um `aeroporto`.
 * @param name `Nome` do aeroporto.
 * @param city `Cidade` do aeroporto.
 * @param type `Tipo` do aeroporto.
 * @param country `País` do aeroporto.
 * @param code `Código` do aeroporto.
 * @return `Ponteiro` para o aeroporto criado.
 */
Airport *createAirport (const char *name, const char *city, const char *type, const char *country, const char *code) {

    // Aloca memória para a estrutura
    Airport *a = malloc (sizeof (Airport));

    // Define as componentes da estrutura
    a -> name = strdup (name);
    a -> city = strdup (city);
    a -> type = strdup (type);
    a -> arrival_count = 0;
    a -> departure_count = 0;
    a -> code = codeToInt (code);
    strcpy (a -> country, country);

    // Devolve o ponteiro
    return a;
}

/**
 * @brief `Elimina` um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 */
void destroyAirport (Airport *a) {

    // Liberta a memória alocada para as componentes da estrutura
    free (a -> name);
    free (a -> city);
    free (a -> type);

    // Liberta a memória alocada para a estrutura
    free (a);
}

/**
 * @brief Devolve o `nome` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 * @return `Nome` do aeroporto.
 */
const char *getAirportName (const struct airport *a) {
    return a -> name;
}

/**
 * @brief Devolve a `cidade` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 * @return `Cidade` do aeroporto.
 */
const char *getAirportCity (const struct airport *a) {
    return a -> city;
}

/**
 * @brief Devolve o `tipo` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 * @return `Tipo` do aeroporto.
 */
const char *getAirportType (const struct airport *a) {
    return a -> type;
}

/**
 * @brief Devolve o `número de chegadas` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 * @return `Número de chegadas` do aeroporto.
 */
unsigned short getAirportArrivalCount (const struct airport *a) {
    return a -> arrival_count;
}

/**
 * @brief Devolve o `número de partidas` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 * @return `Número de partidas` do aeroporto.
 */
unsigned short getAirportDepartureCount (const struct airport *a) {
    return a -> departure_count;
}

/**
 * @brief Devolve o `código` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 * @return `Código` do aeroporto.
 */
int getAirportCode (const struct airport *a) {
    return a -> code;
}

/**
 * @brief Devolve o `país` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 * @return `País` do aeroporto.
 */
const char *getAirportCountry (const struct airport *a) {
    return a -> country;
}

/**
 * @brief `Incrementa o número de chegadas` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 */
void incAirportArrivalCount (Airport *a) {
    a -> arrival_count++;
}

/**
 * @brief `Incrementa o número de partidas` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 */
void incAirportDepartureCount (Airport *a) {
    a -> departure_count++;
}