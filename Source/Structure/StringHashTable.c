// Headers utilizados
#include "Structure/StringHashTable.h"

// Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>

/**
 * @brief Calcula o `hash` de um registo.
 * @param key `Chave` do registo.
 * @return `Hash` do registo.
 */
static inline int hash (const char *key) {
    unsigned int h = 5381, c;
    while ((c = *key++)) h = ((h << 5) + h) + c;
    return h;
}

/**
 * @brief `Nodo` da `hash-table`.
 */
typedef struct string_node {
    char *key;
    int value;
} StringNode;

/**
 * @brief `Hash-table` para armazenamento indexado através de `linear probing` e `chave string`.
 */
typedef struct string_hash_table {
    StringNode *table;
    int mask;
    Boolean has_key_property;
} StringHashTable;

/**
 * @brief `Cria` uma `hash-table` com `chave string`.
 * @param capacity `Capacidade` da hash-table.
 * @param has_key_property `Booleano` que indica se as chaves são de propriedade da hash-table.
 * @return `Ponteiro` para a hash-table criada.
 */
StringHashTable *createStringHashTable (int capacity, Boolean has_key_property) {

    // Determina a capacidade ideal
    capacity = hashIdealCapacity (capacity);

    // Aloca memória para a estrutura
    StringHashTable *ht = malloc (sizeof (StringHashTable));

    // Define as componentes da estrutura
    ht -> table = malloc (capacity * sizeof (StringNode));
    ht -> mask = capacity - 1;
    ht -> has_key_property = has_key_property;

    // Inicializa a hash-table
    memset (ht -> table, 0, capacity * sizeof (StringNode));

    // Devolve o ponteiro
    return ht;
}

/**
 * @brief `Elimina` uma `hash-table` com `chave string`.
 * @param hp `Ponteiro` para a hash-table.
 */
void destroyStringHashTable (StringHashTable *ht) {

    // Liberta a memória alocada para as chaves
    if (ht -> has_key_property) for (int i = 0; i <= ht -> mask; i++) if (ht -> table [i].key) free (ht -> table [i].key);

    // Liberta a memória alocada para as componentes da estrutura
    free (ht -> table);

    // Liberta a memória alocada para a estrutura
    free (ht);
}

/**
 * @brief `Adiciona um registo` a uma `hash-table` com `chave string`.
 * @param ht `Ponteiro` para a hash-table.
 * @param key `Chave` do registo.
 * @param value `Valor` do registo.
 */
void registerStringHashTable (StringHashTable *ht, char *key, int value) {

    // Calcula o índice hash
    int i = hash (key) & ht -> mask;

    // Procura o índice para a inserção
    while (ht -> table [i].key) i = (i + 1) & ht -> mask;

    // Realiza o registo
    ht -> table [i].key = ht -> has_key_property ? strdup (key) : key;
    ht -> table [i].value = value;
}

/**
 * @brief `Procura um registo` de uma `hash-table` com `chave string`.
 * @param ht `Ponteiro` para a hash-table.
 * @param key `Chave` do registo.
 * @return `Valor` do registo.
 */
int getStringHashTable (StringHashTable *ht, const char *key) {

    // Calcula o índice hash
    int i = hash (key) & ht -> mask;

    // Procura o índice
    while (ht -> table [i].key) {

        // Verifica se as chaves coincidem
        if (strcmp (ht -> table [i].key, key) == 0) return ht -> table [i].value;

        // Avança o índice
        i = (i + 1) & ht -> mask;
    }

    // A aeronave não foi encontada
    return NO_VALUE;
}

/**
 * @brief `Incrementa o valor de um registo` de uma `hash-table` com `chave string`.
 * @param ht `Ponteiro` para a hash-table.
 * @param key `Chave` do registo.
 * @return `Valor` do registo.
 */
int incStringHashTable (StringHashTable *ht, char *key) {

    // Calcula o índice hash
    int i = hash (key) & ht -> mask;

    // Procura o índice
    while (ht -> table [i].key) {

        // Verifica se as chaves coincidem
        if (strcmp (ht -> table [i].key, key) == 0) return ++ht -> table [i].value;

        // Avança o índice
        i = (i + 1) & ht -> mask;
    }

    // A chave ainda não existia
    ht -> table [i].key = ht -> has_key_property ? strdup (key) : key;
    ht -> table [i].value = 1;

    // Retorna o número de ocorrências
    return 1;
}