// Headers utilizados
#include "Structure/CountMatrix.h"
#include "Manager/Nationality.h"
#include "Structure/StringHashTable.h"

// Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>

/**
 * @brief `Estrutura` para armazenar `nacionalidades`.
 */
typedef struct nationality {
    char *name;
} Nationality;

/**
 * @brief `Estrutura de gestão` das `nacionalidades`.
 */
typedef struct nationality_manager {
    Nationality *data;
    int data_len;
    StringHashTable *ht;
} NationalityManager;

/**
 * @brief `Cria` um `gestor de nacionalidades`.
 * @param dataset_type `Tipo de dataset`.
 * @return `Ponteiro` para o gestor de nacionalidades criado.
 */
NationalityManager *createNationalityManager (DatasetType dataset_type) {
    
    // Aloca memória para a estrutura
    NationalityManager *m = malloc (sizeof (NationalityManager));

    // Determina o número de registos
    int nnationalities = dataset_type == DATASET_NORMAL ? NORMAL_NNATIONALITIES : LARGE_NNATIONALITIES;

    // Define as componentes da estrutura
    m -> data = malloc (nnationalities * sizeof (Nationality));
    m -> ht = createStringHashTable (nnationalities, FALSE);
    m -> data_len = 0;

    // Devolve o ponteiro
    return m;
}

/**
 * @brief `Elimina` um `gestor de nacionalidades`.
 * @param m `Ponteiro` para o `gestor de nacionalidades`.
 */
void destroyNationalityManager (NationalityManager *m) {

    // Liberta a memória alocada para as nacionalidades
    for (int i = 0; i < m -> data_len; i++) free (m -> data [i].name);

    // Liberta a memória alocada para as componentes da estrutura
    free (m -> data);
    if (m -> ht) destroyStringHashTable (m -> ht);

    // Liberta a memória alocada para a estrutura
    free (m);
}

/**
 * @brief `Regista uma nacionalidade` num `gestor de nacionalidades`.
 * @param m `Ponteiro` para o `gestor de nacionalidades`.
 * @param name `Nome` da nacionalidade.
 * @return `Índice` da nacionalidade.
 */
int registerNationality (NationalityManager *m, const char *name) {

    // Determina o índice da nacionalidade
    int index = getStringHashTable (m -> ht, name);

    // Verifica se a nacionalidade já existia
    if (index != NO_VALUE) return index;

    // Obtém o endereço da nacionalidade
    Nationality *n = &m -> data [m -> data_len];

    // Regista a nacionalidade
    n -> name = strdup (name);

    // Regista o nacionalidade na hash-hable
    registerStringHashTable (m -> ht, n -> name, m -> data_len);

    // Devolve o índice da nacionalidade
    return m -> data_len++;
}

/**
 * @brief `Obtém um registo` de uma nacionalidade de um `gestor de nacionalidades`.
 * @param m `Ponteiro` para o `gestor de nacionalidades`.
 * @param index `Índice` da nacionalidade.
 * @return `Ponteiro` para a nacionalidade.
 */
Nationality *getNationalityByIndex (NationalityManager *m, int index) {
    return &m -> data [index];
}

/**
 * @brief `Obtém o índice` de uma nacionalidade de um `gestor de nacionalidades`.
 * @param m `Ponteiro` para o `gestor de nacionalidades`.
 * @param name `Nome` da nacionalidade.
 * @return `Índice` da nacionalidade.
 */
int getNationalityIndex (NationalityManager *m, const char *name) {
    return getStringHashTable (m -> ht, name);
}

/**
 * @brief Prepara um `gestor de nacionalidades` para as queries.
 * @param m `Ponteiro` para o gestor de nacionalidades.
 */
void prepareNationalities (NationalityManager *m) {
    (void) m;
}