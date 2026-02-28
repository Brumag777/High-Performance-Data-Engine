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
 * @brief `Nodo` da `hash-table`.
 */
typedef struct int_node {
    int key;
    int value;
} IntNode;

/**
 * @brief `Hash-table` para armazenamento indexado através de `linear probing` e `chave inteira`.
 */
typedef struct int_hash_table {
    IntNode *table;
    int mask;
} IntHashTable;

/**
 * @brief `Cria` uma `hash-table` com `chave inteira`.
 * @param capacity `Capacidade` da hash-table.
 * @return `Ponteiro` para a hash-table criada.
 */
IntHashTable *createIntHashTable (int capacity) {

    // Determina a capacidade ideal
    capacity = hashIdealCapacity (capacity);

    // Aloca memória para a estrutura
    IntHashTable *ht = malloc (sizeof (IntHashTable));

    // Define as componentes da estrutura
    ht -> table = malloc (capacity * sizeof (IntNode));
    ht -> mask = capacity - 1;

    // Inicializa a hash-table
    memset (ht -> table, NO_VALUE, capacity * sizeof (IntNode));

    // Devolve o ponteiro
    return ht;
}

/**
 * @brief `Elimina` uma `hash-table` com `chave inteira`.
 * @param hp `Ponteiro` para a hash-table.
 */
void destroyIntHashTable (IntHashTable *ht) {

    // Liberta a memória alocada para as componentes da estrutura
    free (ht -> table);

    // Liberta a memória alocada para a estrutura
    free (ht);
}

/**
 * @brief `Adiciona um registo` a uma `hash-table` com `chave inteira`.
 * @param ht `Ponteiro` para a hash-table.
 * @param key `Chave` do registo.
 * @param value `Valor` do registo.
 */
void registerIntHashTable (IntHashTable *ht, int key, int value) {

    // Calcula o índice hash
    int i = hash (key) & ht -> mask;

    // Procura o índice para a inserção
    while (ht -> table [i].key != NO_VALUE) i = (i + 1) & ht -> mask;

    // Realiza o registo
    ht -> table [i].key = key;
    ht -> table [i].value = value;
}

/**
 * @brief `Procura um registo` de uma `hash-table` com `chave inteira`.
 * @param ht `Ponteiro` para a hash-table.
 * @param key `Chave` do registo.
 * @return `Valor` do registo.
 */
int getIntHashTable (IntHashTable *ht, int key) {

    // Calcula o índice hash
    int i = hash (key) & ht -> mask;

    // Procura o índice
    while (ht -> table [i].key != NO_VALUE) {

        // Verifica se as chaves coincidem
        if (ht -> table [i].key == key) return ht -> table [i].value;

        // Avança o índice
        i = (i + 1) & ht -> mask;
    }

    // A aeronave não foi encontada
    return NO_VALUE;
}

/**
 * @brief `Incrementa o valor de um registo` de uma `hash-table` com `chave inteira`.
 * @param ht `Ponteiro` para a hash-table.
 * @param key `Chave` do registo.
 * @return `Valor` do registo.
 */
int incIntHashTable (IntHashTable *ht, int key) {

    // Calcula o índice hash
    int i = hash (key) & ht -> mask;

    // Procura o índice
    while (ht -> table [i].key != NO_VALUE) {

        // Verifica se as chaves coincidem
        if (ht -> table [i].key == key) return ++ht -> table [i].value;

        // Avança o índice
        i = (i + 1) & ht -> mask;
    }

    // A chave ainda não existia
    ht -> table [i].key = key;
    ht -> table [i].value = 1;

    // Retorna o número de ocorrências
    return 1;
}