#ifndef HASH_SET_H
#define HASH_SET_H

// Headers utilizados
#include "Config.h"

/**
 * @brief `Hash-set` indexado através de `linear probing`.
 */
typedef struct hash_set HashSet;

/**
 * @brief `Cria` um `hash-set`.
 * @param capacity `Capacidade` do hash-set.
 * @return `Ponteiro` para o hash-set criado.
 */
HashSet *createHashSet (int capacity);

/**
 * @brief `Elimina` um `hash-set`.
 * @param hp `Ponteiro` para o hash-set.
 */
void destroyHashSet (HashSet *hs);

/**
 * @brief `Adiciona um registo` a um `hash-set` com `chave inteira`.
 * @param ht `Ponteiro` para a hash-table.
 * @param key `Chave` do registo.
 * @return `Booleano` que indica se o registo `já existia`.
 */
Boolean registerHashSet (HashSet *hs, int key);

#endif