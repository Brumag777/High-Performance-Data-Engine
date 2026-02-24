#ifndef ENTITY_AIRPORT_H
#define ENTITY_AIRPORT_H

/**
 * @brief `Tamanho` do `país` de um `aeroporto`.
 */
#define SIZE_AIRPORT_COUNTRY 2

/**
 * @brief `Estrutura` para armazenar `aeroportos`.
 */
typedef struct airport Airport;

/**
 * @brief Converte o `código` de um aeroporto para inteiro.
 * @param code `Código` do aeroporto em `string`.
 * @return `Código` do aeroporto em `inteiro`.
 */
int codeToInt (const char *code);

/**
 * @brief Converte um `inteiro` num `código` de aeroporto.
 * @param code `Código` do aeroporto em `string`.
 * @return Cópia do `código` do aeroporto em `string`.
 */
char *intToCode (int code);

/**
 * @brief `Cria` um `aeroporto`.
 * @param name `Nome` do aeroporto.
 * @param city `Cidade` do aeroporto.
 * @param country `País` do aeroporto.
 * @param type `Tipo` do aeroporto.
 * @param code `Código` do aeroporto.
 * @return `Ponteiro` para o aeroporto criado.
 */
Airport *createAirport (const char *name, const char *city, const char *country, const char *type, const char *code);

/**
 * @brief `Elimina` um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 */
void destroyAirport (Airport *a);

/**
 * @brief Devolve o `nome` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 * @return `Nome` do aeroporto.
 */
const char *getAirportName (const struct airport *a);

/**
 * @brief Devolve a `cidade` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 * @return `Cidade` do aeroporto.
 */
const char *getAirportCity (const struct airport *a);

/**
 * @brief Devolve o `tipo` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 * @return `Tipo` do aeroporto.
 */
const char *getAirportType (const struct airport *a);

/**
 * @brief Devolve o `número de chegadas` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 * @return `Número de chegadas` do aeroporto.
 */
unsigned short getAirportArrivalCount (const struct airport *a);

/**
 * @brief Devolve o `número de partidas` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 * @return `Número de partidas` do aeroporto.
 */
unsigned short getAirportDepartureCount (const struct airport *a);

/**
 * @brief Devolve o `código` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 * @return `Código` do aeroporto.
 */
int getAirportCode (const struct airport *a);

/**
 * @brief Devolve o `país` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 * @return `País` do aeroporto.
 */
const char *getAirportCountry (const struct airport *a);

/**
 * @brief `Incrementa o número de chegadas` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 */
void incAirportArrivalCount (Airport *a);

/**
 * @brief `Incrementa o número de partidas` de um `aeroporto`.
 * @param a `Ponteiro` para o aeroporto.
 */
void incAirportDepartureCount (Airport *a);

#endif