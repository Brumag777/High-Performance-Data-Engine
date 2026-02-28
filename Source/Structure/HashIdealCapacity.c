// Headers utilizados
#include "Structure/HashSet.h"
#include "Structure/IntHashTable.h"
#include "Structure/StringHashTable.h"
#include "Config.h"

/**
 * @brief Calcula a `capacidade ideal` de uma estrutura `hash`.
 * @param real_capacity `Capacidade real` da estrutura.
 * @return `Capacidade ideal` da estrutura.
 */
int hashIdealCapacity (int real_capacity) {

    // Verifica se a capacidade real é insignificanente
    if (real_capacity < POWER_OF_TWO_7) return POWER_OF_TWO_10;

    // Organiza as capacidades ideias
    int ideal_capacities [] = {POWER_OF_TWO_0, POWER_OF_TWO_1, POWER_OF_TWO_2, POWER_OF_TWO_3, POWER_OF_TWO_4, POWER_OF_TWO_5, POWER_OF_TWO_6, POWER_OF_TWO_7, POWER_OF_TWO_8, POWER_OF_TWO_9, POWER_OF_TWO_10, POWER_OF_TWO_11, POWER_OF_TWO_12, POWER_OF_TWO_13, POWER_OF_TWO_14, POWER_OF_TWO_15, POWER_OF_TWO_16, POWER_OF_TWO_17, POWER_OF_TWO_18, POWER_OF_TWO_19, POWER_OF_TWO_20, POWER_OF_TWO_21, POWER_OF_TWO_22, POWER_OF_TWO_23, POWER_OF_TWO_24, POWER_OF_TWO_25};

    // Procura a capacidade ideal entre as pequenas
    for (int i = 8; i < 12; i++) if (real_capacity < ideal_capacities [i]) return ideal_capacities [i + 2];

    // Procura a capacidade ideal entre as medianas
    for (int i = 12; i < 20; i++) if (real_capacity < ideal_capacities [i]) return ideal_capacities [i + 1];

    // Procura a capacidade ideal entre as grandes
    for (int i = 20; i < 26; i++) if (real_capacity < ideal_capacities [i] + ideal_capacities [i - 1]) return ideal_capacities [i + 1];

    // Retorna um valor inválido
    return NO_VALUE;
}