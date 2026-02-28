// Headers utilizados
#include "Manager/Flight.h"
#include "Entity/Flight.h"
#include "Structure/IntHashTable.h"

// Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>

/**
 * @brief Converte um `id de voo` num inteiro.
 * @param id `Id` do voo.
 * @return `Inteiro` correspondente ao id.
 */
static inline int flightIdToInt (const char *id) {
    int letters = (id [0] - 'A') * 26 + (id [1] - 'A'), number;
    const char *p = id + 2;
    for (number = 0; *p; p++) number = number * 10 + (*p - '0');
    int len = p - (id + 2), base = letters * 1000000u + number;
    return (base << 1) | (len == 6 ? 1u : 0u);
}

/**
 * @brief `Estrutura` para armazenar `voos`.
 */
typedef struct flight {
    short origin;
    short destination;
    char week;
    char status;
} Flight;

/**
 * @brief `Estrutura de gestão` dos `voos`.
 */
typedef struct flight_manager {
    Flight *data;
    int data_len;
    IntHashTable *ht;
} FlightManager;

/**
 * @brief `Cria` um `gestor de voos`.
 * @param dataset_type `Tipo de dataset`.
 * @return `Ponteiro` para o gestor de voos criado.
 */
FlightManager *createFlightManager (DatasetType dataset_type) {

    // Aloca memória para a estrutura
    FlightManager *m = malloc (sizeof (FlightManager));

    // Determina o número de registos
    int nflights = dataset_type == DATASET_NORMAL ? NORMAL_NFLIGHTS : LARGE_NFLIGHTS;
    
    // Define as componentes da estrutura
    m -> data = malloc (nflights * sizeof (Flight));
    m -> ht = createIntHashTable (nflights);
    m -> data_len = 0;

    // Devolve o ponteiro
    return m;
}

/**
 * @brief `Elimina` um `gestor de voos`.
 * @param m `Ponteiro` para o `gestor de voos`.
 */
void destroyFlightManager (FlightManager *m) {

    // Liberta a memória alocada para as componentes da estrutura
    free (m -> data);
    if (m -> ht) destroyIntHashTable (m -> ht);

    // Liberta a memória alocada para a estrutura
    free (m);
}

/**
 * @brief `Regista um voo` num `gestor de voos`.
 * @param m `Ponteiro` para o `gestor de voos`.
 * @param id `Id` do voo.
 * @param origin `Identificador do aeroporto de origem` do voo.
 * @param destination `Identificador do aeroporto de destino` do voo.
 * @param week `Semana de partida prevista` do voo.
 * @param status `Estado` do voo.
 */
void registerFlight (FlightManager *m, const char *id, short origin, short destination, char week, char status) {

    // Regista o voo na hash-table
    registerIntHashTable (m -> ht, flightIdToInt (id), m -> data_len);

    // Obtém o endereço do voo
    Flight *f = &m -> data [m -> data_len++];

    // Regista o voo
    f -> origin = origin;
    f -> destination = destination;
    f -> week = week;
    f -> status = status;
}

/**
 * @brief `Obtém um registo` de um voo de um `gestor de voos`.
 * @param m `Ponteiro` para o `gestor de voos`.
 * @param id `Id` do voo.
 * @return `Ponteiro` para o voo.
 */
Flight *getFlightById (FlightManager *m, const char *id) {

    // Procura o índice do voo
    int index = getIntHashTable (m -> ht, flightIdToInt (id));

    // Devolve o voo
    return index == NO_VALUE ? NULL : &m -> data [index];
}

/**
 * @brief Prepara um `gestor de voos` para as queries.
 * @param m `Ponteiro` para o gestor de voos.
 */
void prepareFlights (FlightManager *m) {
    destroyIntHashTable (m -> ht); m -> ht = NULL;
}