#ifndef ENTITY_FLIGHT_H
#define ENTITY_FLIGHT_H

/**
 * @brief `Estrutura` para armazenar `voos`.
 */
typedef struct flight Flight;

/**
 * @brief `Cria` um `voo`.
 * @param origin `Identificador do aeroporto de origem` do voo.
 * @param destination `Identificador do aeroporto de destino` do voo.
 * @param week `Semana de partida prevista` do voo.
 * @param status `Estado` do voo.
 * @return `Ponteiro` para o voo criado.
 */
Flight *createFlight (short origin, short destination, char week, char status);

/**
 * @brief `Elimina` um voo.
 * @param f `Ponteiro` para o voo.
 */
void destroyFlight (Flight *f);

/**
 * @brief Devolve o `identificador do aeroporto de origem` de um voo.
 * @param f `Ponteiro` para o voo.
 * @return `Identificador do aeroporto de origem` do voo.
 */
short getFlightOrigin (const struct flight *f);

/**
 * @brief Devolve o `identificador do aeroporto de destino` de um voo.
 * @param f `Ponteiro` para o voo.
 * @return `Identificador do aeroporto de destino` do voo.
 */
short getFlightDestination (const struct flight *f);

/**
 * @brief Devolve a `semana de partida prevista` de um voo.
 * @param `Ponteiro` para o voo.
 * @return `Semana de partida prevista` do voo.
 */
char getFlightWeek (const struct flight *f);

/**
 * @brief Devolve o `estado` de um voo.
 * @param `Ponteiro` para o voo.
 * @return `Estado` do voo.
 */
char getFlightStatus (const struct flight *f);

#endif