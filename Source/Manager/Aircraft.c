// Headers utilizados
#include "Manager/Aircraft.h"
#include "Entity/Aircraft.h"
#include "Structure/StringHashTable.h"

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
 * @brief `Estrutura de gestão` das `aeronaves`.
 */
typedef struct aircraft_manager {
    Aircraft *data;
    int data_len;
    StringHashTable *ht;
} AircraftManager;

/**
 * @brief `Cria` um `gestor de aeronaves`.
 * @param dataset_type `Tipo de dataset`.
 * @return `Ponteiro` para o gestor de aeronaves criado.
 */
AircraftManager *createAircraftManager (DatasetType dataset_type) {

    // Aloca memória para a estrutura
    AircraftManager *m = malloc (sizeof (AircraftManager));

    // Define as componentes da estrutura
    m -> data = malloc ((dataset_type == DATASET_NORMAL ? 1000 : 5000) * sizeof (Aircraft));
    m -> ht = createStringHashTable (dataset_type == DATASET_NORMAL ? POWER_OF_TWO_12 : POWER_OF_TWO_14, FALSE);
    m -> data_len = 0;

    // Devolve a estrutura
    return m;
}

/**
 * @brief `Elimina` um `gestor de aeronaves`.
 * @param m `Ponteiro` para o `gestor de aeronaves`.
 */
void destroyAircraftManager (AircraftManager *m) {

    // Liberta a memória alocada para as aeronaves
    for (int i = 0; i < m -> data_len; i++) {
        free (m -> data [i].manufacturer);
        free (m -> data [i].model);
    }

    // Liberta a memória alocada para as componentes da estrutura
    free (m -> data);
    if (m -> ht) destroyStringHashTable (m -> ht);

    // Liberta a memória alocada para a estrutura
    free (m);
}

/**
 * @brief `Regista uma aeronave` num `gestor de aeronaves`.
 * @param m `Ponteiro` para o `gestor de aeronaves`.
 * @param manufacturer `Fabricante` da aeronave.
 * @param model `Modelo` da aeronave.
 * @param identifier `Identificador` da aeronave.
 */
void registerAircraft (AircraftManager *m, const char *manufacturer, const char *model, const char *identifier) {

    // Obtém o endereço da aeronave
    Aircraft *a = &m -> data [m -> data_len];

    // Regista a aeronave
    a -> manufacturer = strdup (manufacturer);
    a -> model = strdup (model);
    strcpy (a -> identifier, identifier);
    a -> flight_count = 0;

    // Regista a aeronave na hash-table
    registerStringHashTable (m -> ht, a -> identifier, m -> data_len++);
}

/**
 * @brief `Obtém um registo` de uma aeronave de um `gestor de aeronaves`.
 * @param m `Ponteiro` para o `gestor de aeronaves`.
 * @param identifier `Identificador` da aeronave.
 * @return `Ponteiro` para a aeronave.
 */
Aircraft *getAircraftById (AircraftManager *m, const char *identifier) {

    // Procura o índice da aeronave
    int index = getStringHashTable (m -> ht, identifier);

    // Devolve a aeronave
    return index == NO_VALUE ? NULL : &m -> data [index];
}

/**
 * @brief Prepara um `gestor de aeronaves` para as queries.
 * @param m `Ponteiro` para o gestor de aeronaves.
 */
void prepareAircrafts (AircraftManager *m) {

    // Elimina a hash-table
    destroyStringHashTable (m -> ht); m -> ht = NULL;

    // Ordena o array das aeronaves
    qsort (m -> data, m -> data_len, sizeof (Aircraft), compareAircrafs);
}

/**
 * @brief Determinas as `N aeronaves com mais voos`. Opcionalmente, pode ser dado um `filtro por fabricante`.
 * @param m `Ponteiro` para o gestor de aeronaves.
 * @param manufacturer `Fabricante` pretendido. Pode ser `NULL` caso não seja pretendido um filtro.
 * @param N `Número de aeronaves` pretendido.
 * @param aircrafts `Aeronaves` encontradas serão escritas neste ponteiro.
 * @return `Número de aeronaves encontradas`.
 */
int getTopNMostFlownAircrafts (AircraftManager *m, const char *manufacturer, int N, Aircraft *aircrafts []) {

    // Obtém a data
    Aircraft *data = m -> data;

    // Inicializa o número de aeronaves encontradas
    int number_found = 0;

    // Percorre o array até encontrar todas as aeronaves pretendidas
    for (int i = 0; number_found < N && i < m -> data_len; i++) {

        // Obtém o elemento do array
        Aircraft *a = &data [i];

        // Obtém o fabricante da aeronave
        const char *amanufacturer = getAircraftManufacturer (a);

        // Verifica se a aeronave possui o fabricante desejado
        if (manufacturer == NULL || strcmp (manufacturer, amanufacturer) == 0) aircrafts [number_found++] = a;
    }

    // Retorna o array
    return number_found;
}