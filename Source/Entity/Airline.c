// Headers utilizados
#include "Entity/Airline.h"

// Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * @brief `Estrutura` para armazenar `companhias`.
 */
typedef struct airline {
    char *name;
    int delay_count;
    int total_delay;
} Airline;

/**
 * @brief `Cria` uma `companhia`.
 * @param name `Nome` da companhia.
 * @param delay `Atraso` da companhia.
 * @return `Ponteiro` para a companhia criada.
 */
Airline *createAirline (const char *name, int delay) {

    // Aloca memória para a estrutura
    Airline *a = malloc (sizeof (Airline));

    // Define as componentes da estrutura
    a -> name = strdup (name);
    a -> delay_count = 1;
    a -> total_delay = delay;

    // Devolve o ponteiro
    return a;
}

/**
 * @brief `Elimina` uma `companhia`.
 * @param a `Ponteiro` para a companhia.
 */
void destroyAirline (Airline *a) {

    // Liberta a memória alocada para as componentes da estrutura
    free (a -> name);

    // Liberta a memória alocada para a estrutura
    free (a);
}

/**
 * @brief Devolve o `nome` de uma `companhia.
 * @param a `Ponteiro` para a companhia.
 * @return `Nome` da companhia.
 */
const char *getAirlineName (const struct airline *a) {
    return a -> name;
}

/**
 * @brief Devolve o `número de atrasos` de uma companhia.
 * @param a `Ponteiro` para a companhia.
 * @return `Número de atrasos` da companhia.
 */
int getAirlineDelayCount (const struct airline *a) {
    return a -> delay_count;
}

/**
 * @brief Devolve o `atraso total` de uma companhia.
 * @param a `Ponteiro` para a companhia.
 * @return `Atraso total` da companhia.
 */
int getAirlineTotalDelay (const struct airline *a) {
    return a -> total_delay;
}

/**
 * @brief Adiciona um `atraso` a uma companhia.
 * @param a `Ponteiro` para a companhia.
 * @param delay `Atraso` da companhia.
 */
void addAirlineDelay (Airline *a, int delay) {
    a -> delay_count++;
    a -> total_delay += delay;
}

/**
 * @brief Compara duas `companhias`.
 * @param a1_ptr `Ponteiro` para a primeira companhia.
 * @param a2_ptr `Ponteiro` para a segunda companhia.
 * @return 1 se a primeira companhia for maior, 0 se forem iguais e -1 se a segunda companhia for maior.
 */
int compareAirlines (const void *a1_ptr, const void *a2_ptr) {

    // Faz cast dos ponteiros
    const struct airline *a1 = a1_ptr;
    const struct airline *a2 = a2_ptr;

    // Calcula o tempo de atraso médio das companhias
    long long avg1 = round (1000.0L * (long double) a1 -> total_delay / a1 -> delay_count);
    long long avg2 = round (1000.0L * (long double) a2 -> total_delay / a2 -> delay_count);

    // Compara o número de voos
    if (avg1 < avg2) return 1;
    if (avg1 > avg2) return -1;

    // Compara os identificadores
    return strcmp (a1 -> name, a2 -> name);
}