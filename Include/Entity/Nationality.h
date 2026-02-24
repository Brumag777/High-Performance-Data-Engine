#ifndef ENTITY_NATIONALITY_H
#define ENTITY_NATIONALITY_H

/**
 * @brief `Estrutura` para armazenar `nacionalidades`.
 */
typedef struct nationality Nationality;

/**
 * @brief `Cria` uma `nacionalidade`.
 * @param name `Nome` da nacionalidade.
 * @return `Ponteiro` para a nacionalidade criada.
 */
Nationality *createNationality (const char *name);

/**
 * @brief `Elimina` uma `nacionalidade`.
 * @param n `Ponteiro` para a nacionalidade.
 */
void destroyNationality (Nationality *n);

/**
 * @brief Devolve o `nome` de uma `nacionalidade.
 * @param n `Ponteiro` para a nacionalidade.
 * @return `Nome` da nacionalidade.
 */
const char *getNationalityName (const struct nationality *n);

#endif