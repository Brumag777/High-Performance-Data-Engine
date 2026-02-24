// Headers utilizados
#include "Entity/Airline.h"

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
 * @brief `Cria` uma `nacionalidade`.
 * @param name `Nome` da nacionalidade.
 * @return `Ponteiro` para a nacionalidade criada.
 */
Nationality *createNationality (const char *name) {

    // Aloca memória para a estrutura
    Nationality *n = malloc (sizeof (Nationality));

    // Define as componentes da estrutura
    n -> name = strdup (name);

    // Devolve o ponteiro
    return n;
}

/**
 * @brief `Elimina` uma `nacionalidade`.
 * @param n `Ponteiro` para a nacionalidade.
 */
void destroyNationality (Nationality *n) {

    // Liberta a memória alocada para as componentes da estrutura
    free (n -> name);

    // Liberta a memória alocada para a estrutura
    free (n);
}

/**
 * @brief Devolve o `nome` de uma `nacionalidade.
 * @param n `Ponteiro` para a nacionalidade.
 * @return `Nome` da nacionalidade.
 */
const char *getNationalityName (const struct nationality *n) {
    return n -> name;
}