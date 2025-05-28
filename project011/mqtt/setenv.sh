#!/bin/bash
# Carrega variáveis do .env e roda o CMake

set -a             # Exporta todas as variáveis
source .env        # Lê o arquivo .env
set +a             # Para de exportar automaticamente

cmake -S . -B build
cmake --build build
