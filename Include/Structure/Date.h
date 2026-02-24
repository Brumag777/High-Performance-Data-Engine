#ifndef DATE_H
#define DATE_H

/**
 * @brief `Enumeração` para `datas`.
 */
typedef enum date_enum {
    YEAR,
    MONTH,
    DAY,
    HOUR,
    MINUTE
} DateEnum;

/**
 * @brief Calcula o número de dias decorridos desde `01-01-2025` até uma data.
 * @param date `Data` em vetor.
 * @return `Número de dias decorriados desde 01-01-2025` até à data.
 */
int daysSinceJanFirst (const int date []);

/**
 * @brief Calcula, em minutos, `a diferença entre duas datas`.
 * @param first_date `Primeira data` em vetor.
 * @param second_date `Segunda data` em vetor.
 * @return `Diferença entre as datas` em minutos.
 */
int dateDiff (const int first_date [], const int second_date []);

/**
 * @brief Calcula o `índice de semana` de uma data.
 * @param date `Data` em vetor.
 * @return `Índice da semana`.
 */
short dateWeekIndex (const int date []);

/**
 * @brief Converte uma `data em vetor` numa `data em inteiro`, com tempo.
 * @param date `Data` em vetor.
 * @return `Data em inteiro`.
 */
int datetimeToInt (const int date []);

/**
 * @brief Converte uma `data em vetor` numa `data em inteiro`, sem tempo.
 * @param date `Data` em vetor.
 * @return `Data em inteiro`.
 */
unsigned short dateToInt (const int date []);

/**
 * @brief Compara duas `datas em vetor`, com tempo.
 * @param first_date `Primeira data` em vetor.
 * @param second_date `Segunda data` em vetor.
 * @return 1 se a primeira data for maior, 0 se forem iguais e -1 se a segunda data for maior.
 */
int compareDatetimes (const int first_date [], const int second_date []);

/**
 * @brief Compara duas `datas em vetor`, sem tempo.
 * @param first_date `Primeira data` em vetor.
 * @param second_date `Segunda data` em vetor.
 * @return 1 se a primeira data for maior, 0 se forem iguais e -1 se a segunda data for maior.
 */
int compareDates (const int first_date [], const int second_date []);

#endif