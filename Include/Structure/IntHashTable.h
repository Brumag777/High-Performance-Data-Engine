#ifndef INT_HASH_TABLE_H
#define INT_HASH_TABLE_H

/**
 * @brief `Hash-table` para armazenamento indexado através de `linear probing` e `chave inteira`.
 */
typedef struct int_hash_table IntHashTable;

/**
 * @brief `Cria` uma `hash-table` com `chave inteira`.
 * @param capacity `Capacidade` da hash-table.
 * @return `Ponteiro` para a hash-table criada.
 */
IntHashTable *createIntHashTable (int capacity);

/**
 * @brief `Elimina` uma `hash-table` com `chave inteira`.
 * @param hp `Ponteiro` para a hash-table.
 */
void destroyIntHashTable (IntHashTable *ht);

/**
 * @brief `Adiciona um registo` a uma `hash-table` com `chave inteira`.
 * @param ht `Ponteiro` para a hash-table.
 * @param key `Chave` do registo.
 * @param value `Valor` do registo.
 */
void registerIntHashTable (IntHashTable *ht, int key, int value);

/**
 * @brief `Procura um registo` de uma `hash-table` com `chave inteira`.
 * @param ht `Ponteiro` para a hash-table.
 * @param key `Chave` do registo.
 * @return `Valor` do registo.
 */
int getIntHashTable (IntHashTable *ht, int key);

/**
 * @brief `Incrementa o valor de um registo` de uma `hash-table` com `chave inteira`.
 * @param ht `Ponteiro` para a hash-table.
 * @param key `Chave` do registo.
 * @return `Valor` do registo.
 */
int incIntHashTable (IntHashTable *ht, int key);

#endif