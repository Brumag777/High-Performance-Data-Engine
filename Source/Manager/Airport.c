// Headers utilizados
#include "Structure/CountMatrix.h"
#include "Structure/IntHashTable.h"
#include "Manager/Airport.h"
#include "Entity/Airport.h"
#include "Structure/Date.h"

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
 * @brief `Estrutura de gestão` dos `aeroportos`.
 */
typedef struct airport_manager {
    Airport *data;
    int data_len;
    IntHashTable *ht;
    CountMatrix *cm_by_day;
    CountMatrix *cm_by_nationality;
} AirportManager;

/**
 * @brief `Cria` um `gestor de aeroportos`.
 * @param dataset_type `Tipo de dataset`.
 * @return `Ponteiro` para o gestor de aeroportos criado.
 */
AirportManager *createAirportManager (DatasetType dataset_type) {

    // Aloca memória para a estrutura
    AirportManager *m = malloc (sizeof (AirportManager));

    // Define as componentes da estrutura
    m -> data = malloc ((dataset_type == DATASET_NORMAL ? 7355 : 7355) * sizeof (Airport));
    m -> ht = createIntHashTable (dataset_type == DATASET_NORMAL ? POWER_OF_TWO_14 : POWER_OF_TWO_14);
    m -> cm_by_day = createCountMatrix (dataset_type == DATASET_NORMAL ? 273 : 273, dataset_type == DATASET_NORMAL ? 7355 : 7355);
    m -> cm_by_nationality = createCountMatrix (dataset_type == DATASET_NORMAL ? 64 : 64, dataset_type == DATASET_NORMAL ? 7355 : 7355);
    m -> data_len = 0;

    // Devolve o ponteiro
    return m;
}

/**
 * @brief `Elimina` um `gestor de aeroportos`.
 * @param m `Ponteiro` para o `gestor de aeroportos`.
 */
void destroyAirportManager (AirportManager *m) {
    
    // Liberta a memória alocada para os aeroportos
    for (int i = 0; i < m -> data_len; i++) {
        free (m -> data [i].name);
        free (m -> data [i].city);
        free (m -> data [i].type);
    }

    // Liberta a memória alocada para as componentes da estrutura
    free (m -> data);
    if (m -> ht) destroyIntHashTable (m -> ht);
    destroyCountMatrix (m -> cm_by_day);
    destroyCountMatrix (m -> cm_by_nationality);

    // Liberta a memória alocada para a estrutura
    free (m);
}

/**
 * @brief `Regista um aeroporto` num `gestor de aeroportos`.
 * @param m `Ponteiro` para o `gestor de aeroportos`.
 * @param code `Código` do aeroporto.
 * @param name `Nome` do aeroporto.
 * @param city `Cidade` do aeroporto.
 * @param type `Tipo` do aeroporto.
 * @param country `País` do aeroporto.
 */
void registerAirport (AirportManager *m, const char *code, const char *name, const char *city, const char *type, const char *country) {

    // Converte o código em inteiro
    int code_int = codeToInt (code);

    // Regista o aeroporto na hash-table
    registerIntHashTable (m -> ht, code_int, m -> data_len);

    // Obtém o endereço do aeroporto
    Airport *a = &m -> data [m -> data_len++];

    // Regista o aeroporto
    a -> name = strdup (name);
    a -> city = strdup (city);
    a -> type = strdup (type);
    a -> arrival_count = 0;
    a -> departure_count = 0;
    a -> code = code_int;
    strcpy (a -> country, country);
}

/**
 * @brief `Obtém um registo` de um aeroporto de um `gestor de aeroportos`.
 * @param m `Ponteiro` para o `gestor de aeroportos`.
 * @param code `Código` do aeroporto.
 * @return `Ponteiro` para o aeroporto.
 */
Airport *getAirportById (AirportManager *m, int code) {

    // Procura o índice do aeroporto
    int index = getIntHashTable (m -> ht, code);

    // Devolve a aeronave
    return index == NO_VALUE ? NULL : &m -> data [index];
}

/**
 * @brief Incrementa o `contador de visitas` de um aeroporto de um `gestor de aeroportos`.
 * @param m `Ponteiro` para o `gestor de aeroportos`.
 * @param day `Dia normalizado` da visita.
 * @param code `Código` do aeroporto.
 */
void incAirportFlightCount (AirportManager *m, int day, int code) {
    incCountMatrix (m -> cm_by_day, day, getIntHashTable (m -> ht, code));
}

/**
 * @brief Incrementa o `contador de visitas` de um aeroporto de um `gestor de aeroportos`.
 * @param m `Ponteiro` para o `gestor de aeroportos`.
 * @param nationality `Índice da nacionalidade` da visita.
 * @param code `Código` do aeroporto.
 */
void incAirportNationalityCount (AirportManager *m, int nationality, int code) {
    incCountMatrix (m -> cm_by_nationality, nationality, getIntHashTable (m -> ht, code));
}

/**
 * @brief Prepara um `gestor de aeroportos` para as queries.
 * @param m `Ponteiro` para o gestor de aeroportos.
 */
void prepareAirports (AirportManager *m) {
    acumulateCountsMatrix (m -> cm_by_day);
}

/**
 * @brief Determina o `aeroporto mais visitado` num dado intervalo de tempo.
 * @param m `Ponteiro` para o gestor de aeroportos.
 * @param min_date `Início do intervalo` de tempo.
 * @param max_date `Fim do intervalo` de tempo.
 * @param number_visits O `número de visitas` do aeroporto será escrito neste ponteiro.
 * @return `Aeroproto mais visitado` no intervalo de tempo.
 */
Airport *getMostVisitedAirportBetweenDates (AirportManager *m, const int min_date [], const int max_date [], int *number_visits) {

    // Determina os índices dos dias
    int first_line = daysSinceJanFirst (min_date), second_line = daysSinceJanFirst (max_date);

    // Obtém o número de linhas e de colunas da matriz
    int nlines = getCountMatrixNLines (m -> cm_by_day);
    int ncolumns = getCountMatrixNColumns (m -> cm_by_day);

    // Verifica os limites das linhas
    if (first_line > second_line || first_line >= nlines || second_line < 0) return NULL;

    // Ajusta o limite da segunda data
    if (second_line >= nlines) second_line = nlines - 1;

    // Declara o máximo até ao momento
    int max_count = NO_VALUE, max_code = NO_VALUE;

    // Obtém as linhas
    unsigned short *fl = first_line > 0 ? getCountMatrixLine (m -> cm_by_day, first_line - 1) : NULL;
    unsigned short *sl = getCountMatrixLine (m -> cm_by_day, second_line);

    // Calcula as diferenças
    for (int i = 0; i < ncolumns; i++) {
        
        // Calcula a diferença
        unsigned short diff = fl ? (sl [i] - fl [i]) : sl [i];

        // Verifica se o novo elemento é maior que o máximo anterior
        if (diff > max_count || (diff == max_count && max_code > m -> data [i].code)) {
            max_count = diff;
            max_code = m -> data [i].code;
        }
    }

    // Atualiza o número de visitas do aeroporto
    *number_visits = max_count;

    // Retorna o aeroporto
    return max_count == NO_VALUE ? NULL : getAirportById (m, max_code);
}

/**
 * @brief Determina o `aeroporto mais visitado` num dado intervalo de tempo.
 * @param m `Ponteiro` para o gestor de aeroportos.
 * @param nationality `Índice da nacionalidade` pretendida.
 * @param number_visits O `número de visitas` do aeroporto será escrito neste ponteiro.
 * @return `Aeroproto mais visitado` no intervalo de tempo.
 */
Airport *getMostVisitedAirportByNationality (AirportManager *m, int nationality, int *number_visits) {

    // Verifica se a nacionalidade não existe
    if (nationality == NO_VALUE) return NULL;

    // Obtém o número de colunas da matriz
    int ncolumns = getCountMatrixNColumns (m -> cm_by_nationality);

    // Obtém a linha da matriz
    unsigned short *l = getCountMatrixLine (m -> cm_by_nationality, nationality);

    // Declara o máximo até ao momento
    int max_count = NO_VALUE, max_code = NO_VALUE;

    // Procura o máximo
    for (int i = 0; i < ncolumns; i++)
        if (l [i] > max_count || (l [i] == max_count && max_code > m -> data [i].code)) {
            max_count = l [i];
            max_code = m -> data [i].code;
        }

    // Atualiza o número de visitas do aeroporto
    *number_visits = max_count;

    // Retorna o aeroporto
    return max_count == NO_VALUE ? NULL : getAirportById (m, max_code);
}