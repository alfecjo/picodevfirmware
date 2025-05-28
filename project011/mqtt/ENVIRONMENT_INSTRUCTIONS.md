# 📄 Instruções para Compilar o Projeto com Variáveis de Ambiente (.env)

## ✅ Pré-requisitos

- Terminal Linux (ou Git Bash se for no Windows)
- CMake instalado
- Arquivo `.env` com as variáveis de ambiente configuradas
- Arquivo `setenv.sh` criado...

---

## 📁 Estrutura Esperada

```bash
projeto/
├── .env
├── CMakeLists.txt
├── setenv.sh  # script de compilação
└── (outros arquivos do projeto)
```

---

## 🚀 Passo para tornar o script `setenv.sh` executável

No terminal, dentro da pasta do projeto, execute:

```bash
chmod +x setenv.sh
```

- Este comando permite que o script seja executado como um programa.