// Headers utilizados
#include "Structure/HashSet.h"

// Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>

/**
 * @brief Calcula o `hash` de um registo.
 * @param key `Chave` do registo.
 * @return `Hash` do registo.
 */
static inline int hash (int key) {
    key ^= key >> 16;
    key *= 0x7feb352dU;
    key ^= key >> 15;
    key *= 0x846ca68bU;
    key ^= key >> 16;
    return key;
}

/**
 * @brief `Hash-set` indexado através de `linear probing`.
 */
typedef struct hash_set {
    int *table;
    int mask;
} HashSet;

/**
 * @brief `Cria` um `hash-set`.
 * @param capacity `Capacidade` do hash-set.
 * @return `Ponteiro` para o hash-set criado.
 */
HashSet *createHashSet (int capacity) {

    // Determina a capacidade ideal
    capacity = hashIdealCapacity (capacity);

    // Aloca memória para a estrutura
    HashSet *hs = malloc (sizeof (HashSet));

    // Define as componentes da estrutura
    hs -> table = malloc (capacity * sizeof (int));
    hs -> mask = capacity - 1;

    // Inicializa o hash-set
    memset (hs -> table, NO_VALUE, capacity * sizeof (int));

    // Devolve o ponteiro
    return hs;
}

/**
 * @brief `Elimina` um `hash-set`.
 * @param hp `Ponteiro` para o hash-set.
 */
void destroyHashSet (HashSet *hs) {

    // Liberta a memória alocada para as componentes da estrutura
    free (hs -> table);

    // Liberta a memória alocada para a estrutura
    free (hs);
}

/**
 * @brief `Adiciona um registo` a um `hash-set` com `chave inteira`.
 * @param ht `Ponteiro` para a hash-table.
 * @param key `Chave` do registo.
 * @return `Booleano` que indica se o registo `já existia`.
 */
Boolean registerHashSet (HashSet *hs, int key) {

    // Calcula o índice hash
    int i = hash (key) & hs -> mask;

    // Procura o índice para a inserção
    while (hs -> table [i] != NO_VALUE) {

        // Verifica se o registo já existia
        if (hs -> table [i] == key) return TRUE;

        // Avança o índice
        i = (i + 1) & hs -> mask;
    }

    // Realiza o registo
    hs -> table [i] = key;

    // O registo ainda não existia
    return FALSE;
}