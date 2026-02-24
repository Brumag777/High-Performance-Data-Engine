// Headers utilizados
#include "Structure/Date.h"
#include "Config.h"

/**
 * @brief `Número de minutos` num dia.
 */
#define NUMBER_MINUTES_IN_ONE_DAY 1440

/**
 * @brief `Número de dias` de cada mês.
 */
static const int days_in_month [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/**
 * @brief Calcula o número de dias decorridos desde `01-01-2025` até uma data.
 * @param date `Data` em vetor.
 * @return `Número de dias decorriados desde 01-01-2025` até à data.
 */
int daysSinceJanFirst (const int date []) {

    // Verifica se a data é anterior a 2025
    if (date [YEAR] < 2025) return NO_VALUE;

    // Número de dias desde 1 de janeiro
    int days = 0;

    // Calcula o número de dias desde 1 de janeiro
    for (int m = 1; m < date [MONTH]; m++) days += days_in_month [m - 1];
    days += date [DAY] - 1;

    // Retorna o número de dias deste 1 de janeiro
    return days;
}

/**
 * @brief Calcula, em minutos, `a diferença entre duas datas`.
 * @param first_date `Primeira data` em vetor.
 * @param second_date `Segunda data` em vetor.
 * @return `Diferença entre as datas` em minutos.
 */
int dateDiff (const int first_date [], const int second_date []) {
    return daysSinceJanFirst (second_date) * NUMBER_MINUTES_IN_ONE_DAY + second_date [HOUR] * 60 + second_date [MINUTE] - (daysSinceJanFirst (first_date) * NUMBER_MINUTES_IN_ONE_DAY + first_date [HOUR] * 60 + first_date [MINUTE]);
}

/**
 * @brief Calcula o `índice de semana` de uma data.
 * @param date `Data` em vetor.
 * @return `Índice da semana`.
 */
short dateWeekIndex (const int date []) {
    return (daysSinceJanFirst (date) + 3) / 7;
}

/**
 * @brief Converte uma `data em vetor` numa `data em inteiro`, com tempo.
 * @param date `Data` em vetor.
 * @return `Data em inteiro`.
 */
int datetimeToInt (const int date []) {
    return (date [YEAR] << 20) | (date [MONTH] << 16) | (date [DAY] << 11) | (date [HOUR] << 6) | date [MINUTE];
}

/**
 * @brief Converte uma `data em vetor` numa `data em inteiro`, sem tempo.
 * @param date `Data` em vetor.
 * @return `Data em inteiro`.
 */
unsigned short dateToInt (const int date []) {
    return ((date [YEAR] - 1900) << 9) | (date [MONTH] << 5) | date [DAY];
}

/**
 * @brief Compara duas `datas em vetor`, com tempo.
 * @param first_date `Primeira data` em vetor.
 * @param second_date `Segunda data` em vetor.
 * @return 1 se a primeira data for maior, 0 se forem iguais e -1 se a segunda data for maior.
 */
int compareDatetimes (const int first_date [], const int second_date []) {

    // Compara as componentes das datas
    for (int i = YEAR; i <= MINUTE; i++) {
        if (first_date [i] > second_date [i]) return 1;
        if (first_date [i] < second_date [i]) return -1;
    }

    // As datas são iguais
    return 0;
}

/**
 * @brief Compara duas `datas em vetor`, sem tempo.
 * @param first_date `Primeira data` em vetor.
 * @param second_date `Segunda data` em vetor.
 * @return 1 se a primeira data for maior, 0 se forem iguais e -1 se a segunda data for maior.
 */
int compareDates (const int first_date [], const int second_date []) {

    // Compara as componentes das datas
    for (int i = YEAR; i <= DAY; i++) {
        if (first_date [i] > second_date [i]) return 1;
        if (first_date [i] < second_date [i]) return -1;
    }

    // As datas são iguais
    return 0;
}