#ifndef STRING_HASH_TABLE_H
#define STRING_HASH_TABLE_H

// Headers utilizados
#include "Config.h"

/**
 * @brief Calcula a `capacidade ideal` de uma estrutura `hash`.
 * @param real_capacity `Capacidade real` da estrutura.
 * @return `Capacidade ideal` da estrutura.
 */
int hashIdealCapacity (int real_capacity);

/**
 * @brief `Hash-table` para armazenamento indexado através de `linear probing` e `chave string`.
 */
typedef struct string_hash_table StringHashTable;

/**
 * @brief `Cria` uma `hash-table` com `chave string`.
 * @param capacity `Capacidade` da hash-table.
 * @param has_key_property `Booleano` que indica se as chaves são de propriedade da hash-table.
 * @return `Ponteiro` para a hash-table criada.
 */
StringHashTable *createStringHashTable (int capacity, Boolean has_key_property);

/**
 * @brief `Elimina` uma `hash-table` com `chave string`.
 * @param hp `Ponteiro` para a hash-table.
 */
void destroyStringHashTable (StringHashTable *ht);

/**
 * @brief `Adiciona um registo` a uma `hash-table` com `chave string`.
 * @param ht `Ponteiro` para a hash-table.
 * @param key `Chave` do registo.
 * @param value `Valor` do registo.
 */
void registerStringHashTable (StringHashTable *ht, char *key, int value);

/**
 * @brief `Procura um registo` de uma `hash-table` com `chave string`.
 * @param ht `Ponteiro` para a hash-table.
 * @param key `Chave` do registo.
 * @return `Valor` do registo.
 */
int getStringHashTable (StringHashTable *ht, const char *key);

/**
 * @brief `Incrementa o valor de um registo` de uma `hash-table` com `chave string`.
 * @param ht `Ponteiro` para a hash-table.
 * @param key `Chave` do registo.
 * @return `Valor` do registo.
 */
int incStringHashTable (StringHashTable *ht, char *key);

#endif