// Headers utilizados
#include "Structure/CountMatrix.h"
#include "Config.h"

// Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>

/**
 * @brief `Estrutura` para guardar `contadores` numa matriz.
 */
typedef struct count_matrix {
    unsigned short *counts;
    int nlines;
    int ncolumns;
} CountMatrix;

/**
 * @brief `Cria` uma `matriz de contadores`.
 * @param nlines `Número de linhas` da matriz.
 * @param ncolumns `Número de colunas` da matriz.
 * @return `Ponteiro` para a matriz de contadores criada.
 */
CountMatrix *createCountMatrix (int nlines, int ncolumns) {

    // Aloca memória para a estrutura
    CountMatrix *cm = malloc (sizeof (CountMatrix));

    // Define as componentes da estrutura
    cm -> counts = malloc (nlines * ncolumns * sizeof (unsigned short));
    cm -> nlines = nlines;
    cm -> ncolumns = ncolumns;

    // Inicializa os contadores
    memset (cm -> counts, 0, nlines * ncolumns * sizeof (unsigned short));

    // Devolve o ponteiro
    return cm;
}

/**
 * @brief `Elimina` uma `matriz de contadores`.
 * @param cm `Ponteiro` para a matriz de contadores.
 */
void destroyCountMatrix (CountMatrix *cm) {

    // Liberta a memória alocada para as componentes da estrutura
    free (cm -> counts);

    // Liberta a memória alocada para a estrutura
    free (cm);
}

/**
 * @brief `Incrementa um contador` de uma `matriz de contadores`.
 * @param cm `Ponteiro` para a matriz de contadores.
 * @param line `Linha` do contador.
 * @param column `Coluna` do contador.
 */
void incCountMatrix (CountMatrix *cm, int line, int column) {
    cm -> counts [line * cm -> ncolumns + column]++;
}

/**
 * @brief Determina o `máximo de uma linha` de uma `matriz de contadores`.
 * @param cm `Ponteiro` para a matriz de contadores.
 * @param line `Linha` de interesse.
 * @param max_index Os `índices dos máximos` serão escritos neste ponteiro.
 * @param nmaxs O `número de máximos encontrado` será escrito neste ponteiro.
 * @return `Máximo da linha` de interesse.
 */
unsigned short maxLineCountMatrix (CountMatrix *cm, int line, int *max_indexes, int *nmaxs) {

    // Máximo até ao momento
    unsigned short max = *nmaxs = 0;

    // Obtém a linha
    unsigned short *l = cm -> counts + line * cm -> ncolumns;

    // Procura o máximo
    for (int i = 0; i < cm -> ncolumns; i++)

        // Verifica se o contador é maior que o máximo anterior
        if (l [i] > max) {
            max = l [i];
            *nmaxs = 1;
            max_indexes [0] = i;
        }

        // Verifica se o contador é igual ao anterior
        else if (l [i] == max) max_indexes [(*nmaxs)++] = i;

    // Devolve o máximo
    return max;
}

/**
 * @brief Determina o `máximo da diferença entre duas linhas` de uma `matriz de contadores`.
 * @param cm `Ponteiro` para a matriz de contadores.
 * @param fisrtline `Primeira linha` de interesse.
 * @param max_index Os `índices dos máximos` serão escrito neste ponteiro.
 * @param nmax O `número de máximos encontrado` será escrito neste ponteiro.
 * @return `Máximo` da linha diferença.
 */
unsigned short maxLineDiffCountMatrix (CountMatrix *cm, int first_line, int second_line, int *max_indexes, int *nmaxs) {

    // Máximo até ao momento
    unsigned short max = *nmaxs = 0;

    // Verifica os limites das linhas
    if (first_line > second_line || first_line >= cm -> nlines || second_line < 0) return 0;

    // Verifica se a primeira linha é a primeira
    if (first_line <= 0) return maxLineCountMatrix (cm, second_line, max_indexes, nmaxs);

    // Ajusta o limite da segunda data
    if (second_line >= cm -> nlines) second_line = cm -> nlines - 1;

    // Obtém as linhas
    unsigned short *fl = cm -> counts + (first_line - 1) * cm -> ncolumns;
    unsigned short *sl = cm -> counts + second_line * cm -> ncolumns;

    // Calcula a linha diferença
    for (int i = 0; i < cm -> ncolumns; i++) {
        
        // Calcula a diferença
        unsigned short diff = sl [i] - fl [i];

        // Verifica se o contador é maior que o máximo anterior
        if (diff > max) {
            max = diff;
            *nmaxs = 1;
            max_indexes [0] = i;
        }

        // Verifica se o contador é igual ao anterior
        else if (diff == max) max_indexes [(*nmaxs)++] = i;
    }

    // Devolve o máximo
    return max;
}

/**
 * @brief Torna uma `matriz de contadores` numa `matriz acumulada`.
 * @param cm `Ponteiro` para a matriz de contadores.
 */
void acumulateCountsMatrix (CountMatrix *cm) {

    // Percorre cada linha da matriz
    for (int i = 1; i < cm -> nlines; i++) {

        // Obtém as linhas
        unsigned short *prevl = cm -> counts + (i - 1) * cm -> ncolumns;
        unsigned short *newl = cm -> counts  + i * cm -> ncolumns;

        // Acumula a linha
        for (int j = 0; j < cm -> ncolumns; j++) newl [j] += prevl [j];
    }
}

/**
 * @brief Devolve o `número de linhas` de uma `matriz de contadores`.
 * @param cm `Ponteiro` para a matriz de contadores.
 * @return `Número de linhas` da matriz de contadores.
 */
int getCountMatrixNLines (CountMatrix *cm) {
    return cm -> nlines;
}

/**
 * @brief Devolve o `número de coluneas` de uma `matriz de contadores`.
 * @param cm `Ponteiro` para a matriz de contadores.
 * @return `Número de colunas` da matriz de contadores.
 */
int getCountMatrixNColumns (CountMatrix *cm) {
    return cm -> ncolumns;
}

/**
 * @brief Devolve uma `linha` de uma `matriz de contadores`.
 * @param cm `Ponteiro` para a matriz de contadores.
 * @return `Ponteiro` para a linha da matriz de contadores.
 */
unsigned short *getCountMatrixLine (CountMatrix *cm, int line) {
    return cm -> counts + line * cm -> ncolumns;
}