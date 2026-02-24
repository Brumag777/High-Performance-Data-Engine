#ifndef ENTITY_PASSENGER_H
#define ENTITY_PASSENGER_H

/**
 * @brief `Estrutura` para armazenar `passageiros`.
 */
typedef struct passenger Passenger;

/**
 * @brief `Cria` o `nome` de um passageiro.
 * @param name `Nome do passageiro`.
 * @param first_name `Primeiro nome` do passageiro.
 * @param last_name `Último nome` do passageiro.
 * @return `Nome` do passageiro criado.
 */
void createPassengerName (char *name, const char *first_name, const char *last_name);

/**
 * @brief `Cria` um `passageiro`.
 * @param first_name `Primeiro nome` do passageiro.
 * @param last_name `Último nome` do passageiro.
 * @param document_number `Número de documento` do passageiro.
 * @param dob `Data de nascimento` do passageiro.
 * @param nationality `Identificador da nacionalidade` do passageiro.
 */
Passenger *createPassenger (const char *first_name, const char *last_name, int document_number, unsigned short dob, short nationality);

/**
 * @brief `Elimina` um `passageiro`.
 * @param p `Ponteiro` para o passageiro.
 */
void destroyPassenger (Passenger *p);

/**
 * @brief Devolve o `primeiro nome` de um passageiro.
 * @param p `Ponteiro` para o passageiro.
 * @return `Primeiro nome` do passageiro.
 */
const char *getPassengerFirstName (const struct passenger *p);

/**
 * @brief Devolve o `último nome` de um passageiro.
 * @param p `Ponteiro` para o passageiro.
 * @return `Último nome` do passageiro.
 */
const char *getPassengerLastName (const struct passenger *p);

/**
 * @brief Devolve o `número de documento` de um passageiro.
 * @param p `Ponteiro` para o passageiro.
 * @return `Número de documento` do passageiro.
 */
int getPassengerDocumentNumber (const struct passenger *p);

/**
 * @brief Devolve a `data de nascimento` de um passageiro.
 * @param p `Ponteiro` para o passageiro.
 * @return `Data de nascimento` do passageiro.
 */
short getPassengerDob (const struct passenger *p);

/**
 * @brief Devolve a `nacionalidade` de um passageiro.
 * @param p `Ponteiro` para o passageiro.
 * @return `Nacionalidade` do passageiro.
 */
short getPassengerNationality (const struct passenger *p);

#endif