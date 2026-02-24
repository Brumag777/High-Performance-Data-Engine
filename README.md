# ✈️ **High-Performance Flight Data Engine**

## PT **Português**

### 🚀 **Descrição**
Este projeto consiste num **motor de processamento e análise de dados em larga escala** desenvolvido em Linguagem C.
Foi desenhado para lidar com **milhões de registos** de voos, reservas e passageiros, garantindo respostas a consultas complexas em tempo quase instantâneo.
O projeto foi desenvolvido no âmbito da unidade curricular de **Laboratórios de Informática III** (2025/2026).

### ⚡ **Performance**
- **Parsing & Validação**: ~6.6s (processamento de erros e escrita em disco incluídos).
- **Preparação de Dados**: ~70ms (construção de matrizes e prefix sums).
- **Execução de Queries**: ~4ms para 300 consultas (média de 0.013ms por query).
- **Utilização de RAM**: ~260MB de uso de RAM máximo.

### 🛠️ **Destaques Técnicos**
- **Complexidade O(1)**: Uso de matrizes de acumulação e outras estruturas especializadas para estatísticas de aeroportos e nacionalidades.
- **Gestão de Memória**: Implementação de Hash Tables customizadas e limpeza agressiva de buffers temporários para reduzir o footprint de RAM após o parsing.
- **Prefix Sums**: Algoritmos de soma acumulada para resolver queries de intervalos temporais sem iterações desnecessárias.

### 🖥️ **Condições de Teste**
Os benchmarks foram realizados num ambiente Linux de alto desempenho:
- **CPU**: Intel® Core™ i7-13620H
- **RAM**: 16 GB DDR5
- **Perfil do Sistema**: Modo de Desempenho
- **Conjunto de Dados**: Grande

### 📂 **Datasets**
Devido às limitações de tamanho de ficheiro do GitHub, os conjuntos de dados completos (Normal e Large) não estão incluídos neste repositório. 
Para testar o motor de dados, podes:
1. **Descarregar os dados oficiais** (fornecidos no âmbito da UC de LI3).
2. Colocar os ficheiros `.csv` dentro de uma pasta local chamada `Datasets/`.
3. Garantir que a estrutura segue o formato esperado pelo programa: `Aircrafts.csv`, `Airports.csv`, `Flights.csv`, `Passengers.csv` e `Reservations.csv`.

## US **English**

### 🚀 **Description**
A large-scale **data processing and analysis engine** developed in C.
It was engineered to manage **millions** of flight, reservation, and passenger records, ensuring near-instantaneous responses to complex statistical queries.
Developed for the **Laboratórios de Informática III** (2025/2026) course.

### ⚡ **Performance**
- **Parsing & Validation**: ~6.4s (including error handling and disk I/O).
- **Data Preparation**: ~70ms (matrix building and prefix sum calculation).
- **Query Execution**: ~4ms for 300 queries (avg. 0.013ms per query).
- **RAM usage**: ~260MB of max RAM usage.

### 🛠️ **Technical Highlights**
- **O(1) Complexity**: Direct access matrices and other specialized structures for airport and nationality statistics.
- **Memory Management**: Custom-built Hash Tables and aggressive buffer cleanup to minimize RAM usage post-parsing.
- **Prefix Sums**: Optimized algorithms for time-interval queries, avoiding redundant iterations over large datasets.

### 🖥️ **Test conditions**
The benchmarks were performed on a high-performance Linux environment:
- **CPU**: Intel® Core™ i7-13620H
- **RAM**: 16GB DDR5
- **System Profile**: Performance Mode
- **Dataset**: Large

### 📂 **Datasets**
Due to GitHub's file size restrictions, the full datasets (Normal and Large) are not included in this repository.
To test the engine, you can:
1. **Download the official data** (provided by the LI3 course).
2. Place the `.csv` files inside a local folder named `Datasets/`.
3. Ensure the file structure follows the expected format: `Aircrafts.csv`, `Airports.csv`, `Flights.csv`, `Passengers.csv`, and `Reservations.csv`.
