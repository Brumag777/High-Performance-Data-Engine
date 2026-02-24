// Headers utilizados
#include "Manager/Reservation.h"
#include "Structure/HashSet.h"

// Bibliotecas utilizadas
#include <stdlib.h>

/**
 * @brief `Estrutura de gestão` das `reservas`.
 */
typedef struct reservation_manager {
    HashSet *hs;
} ReservationManager;

/**
 * @brief `Cria` um `gestor de reservas`.
 * @param dataset_type `Tipo de dataset`.
 * @return `Ponteiro` para o gestor de reservas criado.
 */
ReservationManager *createReservationManager (DatasetType dataset_type) {

    // Aloca memória para a estrutura
    ReservationManager *m = malloc (sizeof (ReservationManager));
    
    // Define as componentes da estrutura
    m -> hs = createHashSet (dataset_type == DATASET_NORMAL ? POWER_OF_TWO_16 : POWER_OF_TWO_23);

    // Devolve o ponteiro
    return m;
}

/**
 * @brief `Elimina` um `gestor de reservas`.
 * @param m `Ponteiro` para o `gestor de reservas`.
 */
void destroyReservationManager (ReservationManager *m) {

    // Liberta a memória alocada para as componentes da estrutura
    if (m -> hs) destroyHashSet (m -> hs);

    // Liberta a memória alocada para a estrutura
    free (m);
}

/**
 * @brief `Regista uma reserva` num `gestor de reservas`.
 * @param m `Ponteiro` para o `gestor de reservas`.
 * @param id `Id` da reserva.
 * @return `Booleano` que indica se o registo `foi bem-sucedido`.
 */
Boolean registerReservation (ReservationManager *m, int id) {
    return registerHashSet (m -> hs, id) == TRUE ? FALSE : TRUE;
}

/**
 * @brief Prepara um `gestor de reservas` para as queries.
 * @param m `Ponteiro` para o gestor de reservas.
 */
void prepareReservations (ReservationManager *m) {
    destroyHashSet (m -> hs); m -> hs = NULL;
}