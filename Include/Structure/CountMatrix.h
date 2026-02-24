#ifndef COUNT_MATRIX_H
#define COUNT_MATRIX_H

/**
 * @brief `Estrutura` para guardar `contadores` numa matriz.
 */
typedef struct count_matrix CountMatrix;

/**
 * @brief `Cria` uma `matriz de contadores`.
 * @param nlines `Número de linhas` da matriz.
 * @param ncolumns `Número de colunas` da matriz.
 * @return `Ponteiro` para a matriz de contadores criada.
 */
CountMatrix *createCountMatrix (int nlines, int ncolumns);

/**
 * @brief `Elimina` uma `matriz de contadores`.
 * @param cm `Ponteiro` para a matriz de contadores.
 */
void destroyCountMatrix (CountMatrix *cm);

/**
 * @brief `Incrementa um contador` de uma `matriz de contadores`.
 * @param cm `Ponteiro` para a matriz de contadores.
 * @param line `Linha` do contador.
 * @param column `Coluna` do contador.
 */
void incCountMatrix (CountMatrix *cm, int line, int column);

/**
 * @brief Torna uma `matriz de contadores` numa `matriz acumulada`.
 * @param cm `Ponteiro` para a matriz de contadores.
 */
void acumulateCountsMatrix (CountMatrix *cm);

/**
 * @brief Devolve o `número de linhas` de uma `matriz de contadores`.
 * @param cm `Ponteiro` para a matriz de contadores.
 * @return `Número de linhas` da matriz de contadores.
 */
int getCountMatrixNLines (CountMatrix *cm);

/**
 * @brief Devolve o `número de coluneas` de uma `matriz de contadores`.
 * @param cm `Ponteiro` para a matriz de contadores.
 * @return `Número de colunas` da matriz de contadores.
 */
int getCountMatrixNColumns (CountMatrix *cm);

/**
 * @brief Devolve uma `linha` de uma `matriz de contadores`.
 * @param cm `Ponteiro` para a matriz de contadores.
 * @return `Ponteiro` para a linha da matriz de contadores.
 */
unsigned short *getCountMatrixLine (CountMatrix *cm, int line);

#endif