// Headers utilizados
#include "Entity/Aircraft.h"

// Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>

/**
 * @brief `Estrutura` para armazenar `aeronaves`.
 */
typedef struct aircraft {
    char *manufacturer;
    char *model;
    char identifier [SIZE_AIRCRAFT_IDENTIFIER + 1];
    unsigned short flight_count;
} Aircraft;

/**
 * @brief `Cria` uma `aeronave`.
 * @param manufacturer `Fabricante` da aeronave.
 * @param model `Modelo` da aeronave.
 * @param identifier `Identificador` da aeronave.
 * @return `Ponteiro` para a aeronave criada.
 */
Aircraft *createAircraft (const char *manufacturer, const char *model, const char *identifier) {

    // Aloca memória para a estrutura
    Aircraft *a = malloc (sizeof (Aircraft));

    // Define as componentes da estrutura
    a -> manufacturer = strdup (manufacturer);
    a -> model = strdup (model);
    strcpy (a -> identifier, identifier);
    a -> flight_count = 0;

    // Devolve o ponteiro
    return a;
}

/**
 * @brief `Elimina` uma `aeronave`.
 * @param a `Ponteiro` para a aeronave.
 */
void destroyAircraft (Aircraft *a) {

    // Liberta a memória alocada para as componentes da estrutura
    free (a -> manufacturer);
    free (a -> model);

    // Liberta a memória alocada para a estrutura
    free (a);
}

/**
 * @brief Devolve o `fabricante` de uma `aeronave`.
 * @param a `Ponteiro` para a aeronave.
 * @return `Fabricante` da aeronave.
 */
const char *getAircraftManufacturer (const struct aircraft *a) {
    return a -> manufacturer;
}

/**
 * @brief Devolve o `modelo` de uma `aeronave`.
 * @param a `Ponteiro` para a aeronave.
 * @return `Modelo` da aeronave.
 */
const char *getAircraftModel (const struct aircraft *a) {
    return a -> model;
}

/**
 * @brief Devolve o `identificador` de uma `aeronave`.
 * @param a `Ponteiro` para a aeronave.
 * @return `Identificador` da aeronave.
 */
const char *getAircraftIdentifier (const struct aircraft *a) {
    return a -> identifier;
}

/**
 * @brief Devolve o `número de voos` de uma `aeronave`.
 * @param a `Ponteiro` para a aeronave.
 * @return `Número de voos` da aeronave.
 */
unsigned short getAircraftFlightCount (const struct aircraft *a) {
    return a -> flight_count;
}

/**
 * @brief `Incrementa o número de voos` de uma `aeronave`.
 * @param a `Ponteiro` para a aeronave.
 */
void incAircraftFlightCount (Aircraft *a) {
    a -> flight_count++;
}

/**
 * @brief Compara duas `aeronaves`.
 * @param a1_ptr `Ponteiro` para a primeira aeronave.
 * @param a2_ptr `Ponteiro` para a segunda aeronave.
 * @return 1 se a primeira aeronave for maior, 0 se forem iguais e -1 se a segunda aeronave for maior.
 */
int compareAircrafs (const void *a1_ptr, const void *a2_ptr) {

    // Faz cast dos ponteiros
    const struct aircraft *a1 = a1_ptr;
    const struct aircraft *a2 = a2_ptr;

    // Compara o número de voos
    if (a1 -> flight_count < a2 -> flight_count) return 1;
    if (a1 -> flight_count > a2 -> flight_count) return -1;

    // Compara os identificadores
    return strcmp (a1 -> identifier, a2 -> identifier);
}