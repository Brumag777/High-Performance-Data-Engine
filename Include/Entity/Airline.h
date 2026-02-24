#ifndef ENTITY_AIRLINE_H
#define ENTITY_AIRLINE_H

/**
 * @brief `Estrutura` para armazenar `companhias`.
 */
typedef struct airline Airline;

/**
 * @brief `Cria` uma `companhia`.
 * @param name `Nome` da companhia.
 * @param delay `Atraso` da companhia.
 * @return `Ponteiro` para a companhia criada.
 */
Airline *createAirline (const char *name, int delay);

/**
 * @brief `Elimina` uma `companhia`.
 * @param a `Ponteiro` para a companhia.
 */
void destroyAirline (Airline *a);

/**
 * @brief Devolve o `nome` de uma `companhia.
 * @param a `Ponteiro` para a companhia.
 * @return `Nome` da companhia.
 */
const char *getAirlineName (const struct airline *a);

/**
 * @brief Devolve o `número de atrasos` de uma companhia.
 * @param a `Ponteiro` para a companhia.
 * @return `Número de atrasos` da companhia.
 */
int getAirlineDelayCount (const struct airline *a);

/**
 * @brief Devolve o `atraso total` de uma companhia.
 * @param a `Ponteiro` para a companhia.
 * @return `Atraso total` da companhia.
 */
int getAirlineTotalDelay (const struct airline *a);

/**
 * @brief Adiciona um `atraso` a uma companhia.
 * @param a `Ponteiro` para a companhia.
 * @param delay `Atraso` da companhia.
 */
void addAirlineDelay (Airline *a, int delay);

/**
 * @brief Compara duas `companhias`.
 * @param a1_ptr `Ponteiro` para a primeira companhia.
 * @param a2_ptr `Ponteiro` para a segunda companhia.
 * @return 1 se a primeira companhia for maior, 0 se forem iguais e -1 se a segunda companhia for maior.
 */
int compareAirlines (const void *a1_ptr, const void *a2_ptr);

#endif