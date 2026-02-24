#ifndef MANAGER_RESERVATION_H
#define MANAGER_RESERVATION_H

// Headers utilizados
#include "Config.h"

/**
 * @brief `Estrutura de gestão` das `reservas`.
 */
typedef struct reservation_manager ReservationManager;

/**
 * @brief `Cria` um `gestor de reservas`.
 * @param dataset_type `Tipo de dataset`.
 * @return `Ponteiro` para o gestor de reservas criado.
 */
ReservationManager *createReservationManager (DatasetType dataset_type);

/**
 * @brief `Elimina` um `gestor de reservas`.
 * @param m `Ponteiro` para o `gestor de reservas`.
 */
void destroyReservationManager (ReservationManager *m);

/**
 * @brief `Regista uma reserva` num `gestor de reservas`.
 * @param m `Ponteiro` para o `gestor de reservas`.
 * @param id `Id` da reserva.
 * @return `Booleano` que indica se o registo `foi bem-sucedido`.
 */
Boolean registerReservation (ReservationManager *m, int id);

/**
 * @brief Prepara um `gestor de reservas` para as queries.
 * @param m `Ponteiro` para o gestor de reservas.
 */
void prepareReservations (ReservationManager *m);

#endif