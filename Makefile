# ----------------------------------
# Evita recompilações desnecessárias
.PHONY: all clean asan

# ----------
# Compilador
CC = gcc

# ----------
# Flags base
BASE_CFLAGS = -IInclude -Wall -Wextra -pedantic -O2 -g
BASE_LIBS   = -lm

# ----------------
# AddressSanitizer
ASAN_FLAGS = -fsanitize=address -fno-omit-frame-pointer
ASAN_LIBS  = -fsanitize=address

# ----------------
# Ficheiros comuns
COMMON_SRC := $(shell find Source -type f -name "*.c" -not -name "Main.c")
COMMON_OBJ := $(COMMON_SRC:.c=.o)

# ------------------
# Programa principal
MAIN_SRC := Source/Main.c
MAIN_OBJ := $(MAIN_SRC:.c=.o)

# -----
# Alvos
TARGET_PROGRAM := Program
TARGET_TEST  := Test

# ----------------
# Alvo por defeito
all: $(TARGET_PROGRAM)

# -------------------
# Alvo básico simples
$(TARGET_PROGRAM): CFLAGS = $(BASE_CFLAGS)
$(TARGET_PROGRAM): LIBS   = $(BASE_LIBS)
$(TARGET_PROGRAM): $(COMMON_OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# --------------------
# Alvo básico de teste
test: $(TARGET_TEST)
$(TARGET_TEST): CFLAGS = $(BASE_CFLAGS) $(ASAN_FLAGS)
$(TARGET_TEST): LIBS   = $(BASE_LIBS) $(ASAN_LIBS)
$(TARGET_TEST): $(COMMON_OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# -------------------------
# Regra genérica (.c -> .o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# -------
# Limpeza
clean:
	@echo "🧹"
	@find . -type f \( -name "*.o" -o -name "*.gcda" -o -name "*.gcno" -o -name "*.gcov" \) -delete
	@rm -f $(TARGET_PROGRAM) $(TARGET_TEST)
	@rm -f DatasetErrors/* 2>/dev/null || true
	@rm -f DefinedOutputs/* 2>/dev/null || true