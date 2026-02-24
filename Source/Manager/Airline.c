// Headers utilizados
#include "Manager/Airline.h"
#include "Entity/Airline.h"
#include "Structure/StringHashTable.h"

// Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>

/**
 * @brief `Estrutura` para armazenar `companhias`.
 */
typedef struct airline {
    char *name;
    int delay_count;
    int total_delay;
} Airline;

/**
 * @brief `Estrutura de gestão` das `companhias`.
 */
typedef struct airline_manager {
    Airline *data;
    int data_len;
    StringHashTable *ht;
} AirlineManager;

/**
 * @brief `Cria` um `gestor de companhias`.
 * @param dataset_type `Tipo de dataset`.
 * @return `Ponteiro` para o gestor de companhias criado.
 */
AirlineManager *createAirlineManager (DatasetType dataset_type) {

    // Aloca memória para a estrutura
    AirlineManager *m = malloc (sizeof (AirlineManager));

    // Define as componentes da estrutura
    m -> data = malloc ((dataset_type == DATASET_NORMAL ? POWER_OF_TWO_5 : POWER_OF_TWO_5) * sizeof (Airline));
    m -> ht = createStringHashTable (dataset_type == DATASET_NORMAL ? POWER_OF_TWO_9 : POWER_OF_TWO_9, FALSE);
    m -> data_len = 0;

    // Devolve o ponteiro
    return m;
}

/**
 * @brief `Elimina` um `gestor de companhias`.
 * @param m `Ponteiro` para o `gestor de companhias`.
 */
void destroyAirlineManager (AirlineManager *m) {

    // Liberta a memória alocada para as companhias
    for (int i = 0; i < m -> data_len; i++) free (m -> data [i].name);

    // Liberta a memória alocada para as componentes da estrutura
    free (m -> data);
    if (m -> ht) destroyStringHashTable (m -> ht);

    // Liberta a memória alocada para a estrutura
    free (m);
}

/**
 * @brief `Regista uma companhia` num `gestor de companhias`.
 * @param m `Ponteiro` para o `gestor de companhias`.
 * @param name `Nome` da companhia.
 * @param delay `Atraso` da companhia.
 */
void registerAirline (AirlineManager *m, const char *name, int delay) {

    // Procura a aeronave
    Airline *a = getAirlineById (m, name);

    // Verifica se a aeronave já existia
    if (a) {

        // Regista o delay da companhia
        addAirlineDelay (a, delay);

        // Termina a função
        return;
    }

    // Obtém o endereço da companhia
    a = &m -> data [m -> data_len];

    // Regista a companhia
    a -> name = strdup (name);
    a -> delay_count = 1;
    a -> total_delay = delay;

    // Regista o companhia na hash-table
    registerStringHashTable (m -> ht, a -> name, m -> data_len++);
}

/**
 * @brief `Obtém um registo` de uma companhia de um `gestor de companhias`.
 * @param m `Ponteiro` para o `gestor de companhias`.
 * @param name `Nome` da companhia
 * @return `Ponteiro` para a companhia.
 */
Airline *getAirlineById (AirlineManager *m, const char *name) {

    // Procura o índice da companhia
    int index = getStringHashTable (m -> ht, name);

    // Devolve a companhia
    return index == NO_VALUE ? NULL : &m -> data [index];
}

/**
 * @brief Prepara um `gestor de companhias` para as queries.
 * @param m `Ponteiro` para o gestor de companhias.
 */
void prepareAirlines (AirlineManager *m) {

    // Elimina a hash-table
    destroyStringHashTable (m -> ht); m -> ht = NULL;

    // Ordena o array das aeronaves
    qsort (m -> data, m -> data_len, sizeof (Airline), compareAirlines);
}

/**
 * @brief Determinas as `N companhias com maior tempo de atraso médio por voo`.
 * @param m `Ponteiro` para o gestor de companhias.
 * @param N `Número de companhias` pretendido.
 * @param airlines `Companhias` encontradas serão escritas neste ponteiro.
 * @return `Número de companhias encontradas`.
 */
int getTopNMostDelayedAirlines (AirlineManager *m, int N, Airline *airlines []) {

    // Obtém a data
    Airline *data = m -> data;

    // Declara o número de companhias encontradas
    int number_found;

    // Percorre o array até encontrar todas as companhias pretendidas
    for (number_found = 0; number_found < N && number_found < m -> data_len; number_found++) airlines [number_found] = &data [number_found];

    // Retorna o array
    return number_found;
}