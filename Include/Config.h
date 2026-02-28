#ifndef CONFIG_H
#define CONFIG_H

/**
 * @brief `Potências de dois`.
 */
typedef enum powers_of_two {
    POWER_OF_TWO_0 = 1,
    POWER_OF_TWO_1 = 2,
    POWER_OF_TWO_2 = 4,
    POWER_OF_TWO_3 = 8,
    POWER_OF_TWO_4 = 16,
    POWER_OF_TWO_5 = 32,
    POWER_OF_TWO_6 = 64,
    POWER_OF_TWO_7 = 128,
    POWER_OF_TWO_8 = 256,
    POWER_OF_TWO_9 = 512,
    POWER_OF_TWO_10 = 1024,
    POWER_OF_TWO_11 = 2048,
    POWER_OF_TWO_12 = 4096,
    POWER_OF_TWO_13 = 8192,
    POWER_OF_TWO_14 = 16384,
    POWER_OF_TWO_15 = 32768,
    POWER_OF_TWO_16 = 65536,
    POWER_OF_TWO_17 = 131072,
    POWER_OF_TWO_18 = 262144,
    POWER_OF_TWO_19 = 524288,
    POWER_OF_TWO_20 = 1048576,
    POWER_OF_TWO_21 = 2097152,
    POWER_OF_TWO_22 = 4194304,
    POWER_OF_TWO_23 = 8388608,
    POWER_OF_TWO_24 = 16777216,
    POWER_OF_TWO_25 = 33554432
} PowersOfTwo;

/**
 * @brief `Enumeração` dos `números de registos` de cada entidade.
 */
typedef enum number_records {
    NORMAL_NAIRCRAFTS = 1000,
    NORMAL_NAIRLINES = 30,
    NORMAL_NAIRPORTS = 7354,
    NORMAL_NFLIGHTS = 1108699,
    NORMAL_NNATIONALITIES = 55,
    NORMAL_NPASSENGERS = 200000,
    NORMAL_NRESERVATIONS = 20000,
    LARGE_NAIRCRAFTS = 5000,
    LARGE_NAIRLINES = 30,
    LARGE_NAIRPORTS = 7354,
    LARGE_NFLIGHTS = 5616627,
    LARGE_NNATIONALITIES = 55,
    LARGE_NPASSENGERS = 2000000,
    LARGE_NRESERVATIONS = 4000000,
    NDAYS = 273,
    NWEEKS = 38
} NumberRecords;

/**
 * @brief `Booleano`.
 */
typedef enum {
    FALSE,
    TRUE
} Boolean;

/**
 * @brief `Versões de dataset`.
 */
typedef enum dataset_version {
    DATASET_WITH_ERRORS,
    DATASET_WITHOUT_ERRORS
} DatasetVersion;

/**
 * @brief `Tipos de dataset`.
 */
typedef enum dataset_type {
    DATASET_NORMAL,
    DATASET_LARGE
} DatasetType;

/**
 * @brief `Tamanho do buffer` utilizado.
 */
#define BUFFER_SIZE POWER_OF_TWO_10

/**
 * @brief Indica `nenhum valor encontrado` ou `valor inválido`.
 */
#define NO_VALUE -1

#endif