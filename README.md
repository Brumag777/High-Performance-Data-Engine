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
Para testar a performance total na sua máquina, aceda ao link a seguir e siga as instruções.
📥 Mirror Pessoal (Google Drive)

#### **Instruções**
1. Descarregue o ficheiro .zip no link acima.
2. Extraia o ficheiro .zip na raiz do repositório. O arquivo já contém a pasta Datasets/ formatada corretamente para o programa.
3. Execute o comando make para compilar o motor.
4. Execute ./Program para iniciar o processamento e análise.
- **Nota**: Pode usar make clean para remover os ficheiros binários gerados.

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
To test the full performance on your machine, access the link below and follow the instructions.
📥 Personal Mirror (Google Drive)

#### **Instructions**
1. Download the .zip file from the link above.
2. Extract the .zip file into the repository's root directory. The archive already contains the Datasets/ folder correctly formatted for the program.
3. Run the make command to compile the engine.
4. Run ./Program to start the processing and analysis.
- **Note**: You can use make clean to remove the generated binary files.
