#ifndef MANAGER_NATIONALITY_H
#define MANAGER_NATIONALITY_H

typedef struct nationality Nationality;

// Headers utilizados
#include "Config.h"

/**
 * @brief `Estrutura de gestão` das `nacionalidades`.
 */
typedef struct nationality_manager NationalityManager;

/**
 * @brief `Cria` um `gestor de nacionalidades`.
 * @param dataset_type `Tipo de dataset`.
 * @return `Ponteiro` para o gestor de nacionalidades criado.
 */
NationalityManager *createNationalityManager (DatasetType dataset_type);

/**
 * @brief `Elimina` um `gestor de nacionalidades`.
 * @param m `Ponteiro` para o `gestor de nacionalidades`.
 */
void destroyNationalityManager (NationalityManager *m);

/**
 * @brief `Regista uma nacionalidade` num `gestor de nacionalidades`.
 * @param m `Ponteiro` para o `gestor de nacionalidades`.
 * @param name `Nome` da nacionalidade.
 * @return `Índice` da nacionalidade.
 */
int registerNationality (NationalityManager *m, const char *name);

/**
 * @brief `Obtém um registo` de uma nacionalidade de um `gestor de nacionalidades`.
 * @param m `Ponteiro` para o `gestor de nacionalidades`.
 * @param index `Índice` da nacionalidade.
 * @return `Ponteiro` para a nacionalidade.
 */
Nationality *getNationalityByIndex (NationalityManager *m, int index);

/**
 * @brief `Obtém o índice` de uma nacionalidade de um `gestor de nacionalidades`.
 * @param m `Ponteiro` para o `gestor de nacionalidades`.
 * @param name `Nome` da nacionalidade.
 * @return `Índice` da nacionalidade.
 */
int getNationalityIndex (NationalityManager *m, const char *name);

/**
 * @brief Prepara um `gestor de nacionalidades` para as queries.
 * @param m `Ponteiro` para o gestor de nacionalidades.
 */
void prepareNationalities (NationalityManager *m);

#endif