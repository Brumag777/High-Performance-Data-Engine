// Headers utilizados
#include "Manager/Passenger.h"
#include "Entity/Passenger.h"
#include "Structure/IntHashTable.h"
#include "Structure/Date.h"

// Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * @brief `Estrutura` para armazenar o `gasto de um passageiro numa reserva`.
 */
typedef struct spending {
    int document_number;
    int price;
} Spending;

/**
 * @brief `Estrutura` para armazenar os `gastos dos passageiros` numa semana.
 */
typedef struct week_spendings {
    Spending *data;
    int len;
} WeekSpendings;

/**
 * @brief `Estrutura` para armazenar o `top 10 de passageiros` de uma semana.
 */
typedef struct top10 {
    int passengers [10];
    int npassengers;
} Top10;

/**
 * @brief `Estrutura` para armazenar a `informação dos passageiros` sobre uma semana.
 */
typedef struct week_info {
    WeekSpendings sps;
    Top10 top10;
} WeekInfo;

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
 * @brief `Estrutura de gestão` dos `passageiros`.
 */
typedef struct passenger_manager {
    Passenger *data;
    int data_len;
    IntHashTable *ht;
    WeekInfo *info;
    int info_capacity;
} PassengerManager;

/**
 * @brief `Cria` um `gestor de passageiros`.
 * @param dataset_type `Tipo de dataset`.
 * @return `Ponteiro` para o gestor de passageiros criado.
 */
PassengerManager *createPassengerManager (DatasetType dataset_type) {

    // Aloca memória para a estrutura
    PassengerManager *m = malloc (sizeof (PassengerManager));
    
    // Define as componentes da estrutura
    m -> data = malloc ((dataset_type == DATASET_NORMAL ? 200000 : 2000000) * sizeof (Passenger));
    m -> ht = createIntHashTable (dataset_type == DATASET_NORMAL ? POWER_OF_TWO_19 : POWER_OF_TWO_22);
    m -> info_capacity = dataset_type == DATASET_NORMAL ? 40 : 40;
    m -> info = malloc (m -> info_capacity * sizeof (WeekInfo));
    m -> data_len = 0;

    // Inicializa a informação das semanas
    memset (m -> info, 0, m -> info_capacity * sizeof (WeekInfo));

    // Aloca memória para os arrays de gastos dos passageiros
    for (int i = 0; i < m -> info_capacity; i++) m -> info [i].sps.data = malloc ((dataset_type == DATASET_NORMAL ? 600 : 120000) * sizeof (Spending));

    // Devolve o ponteiro
    return m;
}

/**
 * @brief `Elimina` um `gestor de passageiros`.
 * @param m `Ponteiro` para o `gestor de passageiros`.
 */
void destroyPassengerManager (PassengerManager *m) {

    // Liberta a memória alocada para os arrays de gastos dos passageiros
    for (int i = 0; i < m -> info_capacity; i++) if (m -> info [i].sps.data) free (m -> info [i].sps.data);

    // Liberta a memória alocada para as componentes da estrutura
    free (m -> data);
    destroyIntHashTable (m -> ht);
    free (m -> info);

    // Liberta a memória alocada para a estrutura
    free (m);
}

/**
 * @brief `Regista um passageiro` num `gestor de passageiros`.
 * @param m `Ponteiro` para o `gestor de passageiros`.
 * @param document_number `Número de documento` do passageiro.
 * @param first_name `Primeiro nome` do passageiro.
 * @param last_name `Último nome` do passageiro.
 * @param dob `Data de nascimento` do passageiro.
 * @param nationality `Identificador da nacionalidade` do passageiro.
 */
void registerPassenger (PassengerManager *m, int document_number, const char *first_name, const char *last_name, unsigned short dob, short nationality) {

    // Regista o passageiro na hash-table
    registerIntHashTable (m -> ht, document_number, m -> data_len);

    // Obtém o endereço do passageiro
    Passenger *p = &m -> data [m -> data_len++];

    // Regista o passageiro
    createPassengerName (p -> name, first_name, last_name);
    p -> document_number = document_number;
    p -> dob = dob;
    p -> nationality = nationality;
}

/**
 * @brief `Obtém um registo` de um passageiro de um `gestor de passageiros`.
 * @param m `Ponteiro` para o `gestor de passageiros`.
 * @param document_number `Número de documento` do passageiro.
 * @return `Ponteiro` para o passageiro.
 */
Passenger *getPassengerById (PassengerManager *m, int document_number) {

    // Procura o índice do voo
    int index = getIntHashTable (m -> ht, document_number);

    // Devolve a aeronave
    return index == NO_VALUE ? NULL : &m -> data [index];
}

/**
 * @brief `Regista o gasto de um passageiro` num `gestor de passageiros`.
 * @param m `Ponteiro` para o `gestor de passageiros`.
 * @param document_number `Número de documento` do passageiro.
 * @param price `Preço do gasto` do passageiro.
 * @param week `Semana do gasto` do passageiro.
 */
void registerPassengerSpending (PassengerManager *m, int document_number, float price, int week) {

    // Obtém o endereço dos gastos da semana
    WeekSpendings *ws = &m -> info [week].sps;

    // Registo o gasto do passageiro
    ws -> data [ws -> len++] = (Spending) {getIntHashTable (m -> ht, document_number), round (price * 100.0f)};
}

/**
 * @brief Devolve o `índice de um passageiro`.
 * @param m `Ponteiro` para o `gestor de passageiros`.
 * @param document_number `Número de documento` do passageiro.
 * @return `Ponteiro` para o passageiro.
 */
int getPassengerIndex (PassengerManager *m, int document_number) {
    return getIntHashTable (m -> ht, document_number);
}

/**
 * @brief Realiza `bubble-up` numa `min-heap`.
 * @param h `Min-heap`.
 * @param index `Índice` do `bubble-up`.
 */
static void bubbleUp (Spending h [], int index) {
    while (index) {
        int parent = (index - 1) / 2;
        if (h [index].price < h [parent].price || (h [index].price == h [parent].price && h [index].document_number > h [parent].document_number)) {
            Spending temp = h [index];
            h [index] = h [parent];
            h [parent] = temp;
            index = parent;
        } else break;
    }
}

/**
 * @brief Realiza `bubble-down` numa `min-heap`.
 * @param h `Min-heap`.
 * @param size `Tamanho` da min-heap.
 * @param index `Índice` do `bubble-down`.
 */
static void bubbleDown (Spending h [], int size, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
        if (left < size) {
            if (h [left].price < h [smallest].price || (h [left].price == h [smallest].price && h [left].document_number > h [smallest].document_number)) {
                smallest = left;
            }
        } if (right < size) {
            if (h [right].price < h [smallest].price || (h [right].price == h [smallest].price && h [right].document_number > h [smallest].document_number)) {
                smallest = right;
            }
        } if (smallest != index) {
            Spending temp = h [index];
            h [index] = h [smallest];
            h [smallest] = temp;
            index = smallest;
        } else break;
    }
}

/**
 * @brief Encontra o `top 10 de uma semana`.
 * @param top10 `Ponteiro` para o top 10 da semana.
 * @param ps `Passageiros` armazenados.
 * @param counts `Gastos dos passageiros` na semana.
 * @param n `Número de passageiros` armazenados.
 */
static void getWeekTop10 (Top10 *top10, Passenger *ps, const int counts [], int n) {

    // Inicializa a min-heap
    Spending h [10]; int heap_len = 0;

    // Percorre o array de contadores para formar a min-heap
    for (int i = 0; i < n; i++) {

        // Verifica se o passageiro não realizou nenhuma reserva na semana
        if (counts [i] == 0) continue;

        // Verifica se a min-heap ainda não está cheia
        if (heap_len < 10) {
            h [heap_len].document_number = ps [i].document_number;
            h [heap_len].price = counts [i];
            bubbleUp (h, heap_len++);
        }

        // Verifica se o novo elemento deve ser adicionado à min-heap
        else if (counts [i] > h [0].price || (counts [i] == h [0].price && h [0].document_number > ps [i].document_number)) {
            h [0].document_number = ps [i].document_number;
            h [0].price = counts [i];
            bubbleDown (h, heap_len, 0);
        }
    }

    // Copia o top 10 da semana
    for (int i = 0; i < heap_len; i++) top10 -> passengers [i] = h [i].document_number;

    // Define o número de passageiros no top 10 da semana
    top10 -> npassengers = heap_len;
}

/**
 * @brief Prepara um `gestor de passageiros` para as queries.
 * @param m `Ponteiro` para o gestor de passageiros.
 */
void preparePassengers (PassengerManager *m) {

    // Declara o array de contadores
    int counts [m -> data_len];

    // Percorre o array das informações semanais
    for (int i = 0; i < m -> info_capacity; i++) {

        // Zera o array de contadores
        memset (counts, 0, m -> data_len * sizeof (int));

        // Obtém os gastos dos passageiros na semana
        WeekSpendings sps = m -> info [i].sps;

        // Forma o array dos gastos por passageiro
        for (int i = 0; i < sps.len; i++) counts [sps.data [i].document_number] += sps.data [i].price;

        // Encontra o top 10 da semana
        getWeekTop10 (&m -> info [i].top10, m -> data, counts, m -> data_len);

        // Liberta os gastos dos passageiros da semana
        free (m -> info [i].sps.data); m -> info [i].sps.data = NULL;
    }
}

/**
 * @brief Determina o passageiro que `ficou no top 10 semanal mais vezes` num dado intervalo de tempo.
 * @param m `Ponteiro` para o gestor de passageiros.
 * @param min_date `Início do intervalo` de tempo.
 * @param max_date `Fim do intervalo` de tempo.
 * @param number_appearences O `número de aparições` no top 10 será escrito neste ponteiro.
 * @return Ponteiro para o passageiro que `ficou no top 10 semanal mais vezes`.
 */
Passenger *getMostExpensivePassenger (PassengerManager *m, const int min_date [], const int max_date [], int *number_appearences) {

    // Determina os índices das semanas
    int first_line = dateWeekIndex (min_date), last_line = dateWeekIndex (max_date);

    // Verifica os limites das linhas
    if (first_line > last_line || first_line >= m -> info_capacity || last_line < 0) return NULL;

    // Ajusta o limite da segunda data
    if (last_line >= m -> info_capacity) last_line = m -> info_capacity - 1;

    // Cria uma hash-table para contabilizar as ocorrências dos passageiros
    IntHashTable *ht = createIntHashTable (POWER_OF_TWO_10);

    // Máximo até ao momento
    int max_dc = NO_VALUE, max_count = NO_VALUE;

    // Contabiliza as ocorrências dos passageiros
    for (int i = first_line; i <= last_line; i++) {

        // Obtém o top 10 da semana
        Top10 top10 = m -> info [i].top10;

        // Percorre o top 10 da semana
        for (int j = 0, value; j < top10.npassengers; j++) {

            // Obtém a chave e o valor
            value = incIntHashTable (ht, top10.passengers [j]);

            // Verifica se o novo elemento é maior que o máximo atual
            if (value > max_count || (value == max_count && top10.passengers [j] < max_dc)) {
                max_dc = top10.passengers [j]; max_count = value;
            }
        }
    }

    // Elimina a hash-table
    destroyIntHashTable (ht);

    // Atualiza o número de ocorrências do passageiro
    *number_appearences = max_count;

    // Retorna o passageiro
    return max_dc == NO_VALUE ? NULL : getPassengerById (m, max_dc);
}