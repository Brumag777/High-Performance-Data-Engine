#ifndef ENTITY_AIRCRAFT_H
#define ENTITY_AIRCRAFT_H

/**
 * @brief `Tamanho` do `identificador` de uma `aeronave`.
 */
#define SIZE_AIRCRAFT_IDENTIFIER 8

/**
 * @brief `Estrutura` para armazenar `aeronaves`.
 */
typedef struct aircraft Aircraft;

/**
 * @brief `Cria` uma `aeronave`.
 * @param manufacturer `Fabricante` da aeronave.
 * @param model `Modelo` da aeronave.
 * @param identifier `Identificador` da aeronave.
 * @return `Ponteiro` para a aeronave criada.
 */
Aircraft *createAircraft (const char *manufacturer, const char *model, const char *identifier);

/**
 * @brief `Elimina` uma `aeronave`.
 * @param a `Ponteiro` para a aeronave.
 */
void destroyAircraft (Aircraft *a);

/**
 * @brief Devolve o `fabricante` de uma `aeronave`.
 * @param a `Ponteiro` para a aeronave.
 * @return `Fabricante` da aeronave.
 */
const char *getAircraftManufacturer (const struct aircraft *a);

/**
 * @brief Devolve o `modelo` de uma `aeronave`.
 * @param a `Ponteiro` para a aeronave.
 * @return `Modelo` da aeronave.
 */
const char *getAircraftModel (const struct aircraft *a);

/**
 * @brief Devolve o `identificador` de uma `aeronave`.
 * @param a `Ponteiro` para a aeronave.
 * @return `Identificador` da aeronave.
 */
const char *getAircraftIdentifier (const struct aircraft *a);

/**
 * @brief Devolve o `número de voos` de uma `aeronave`.
 * @param a `Ponteiro` para a aeronave.
 * @return `Número de voos` da aeronave.
 */
unsigned short getAircraftFlightCount (const struct aircraft *a);

/**
 * @brief `Incrementa o número de voos` de uma `aeronave`.
 * @param a `Ponteiro` para a aeronave.
 */
void incAircraftFlightCount (Aircraft *a);

/**
 * @brief Compara duas `aeronaves`.
 * @param a1_ptr `Ponteiro` para a primeira aeronave.
 * @param a2_ptr `Ponteiro` para a segunda aeronave.
 * @return 1 se a primeira aeronave for maior, 0 se forem iguais e -1 se a segunda aeronave for maior.
 */
int compareAircrafs (const void *a1_ptr, const void *a2_ptr);

#endif