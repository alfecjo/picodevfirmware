# 🚀 EmbarcaTech 2025 - Fase II

## 📚 Objetivo
Este repositório apresenta os projetos de **Sistemas Embarcados** desenvolvidos na **EmbarcaTech 2025 - Fase II**. Aqui você encontrará o código-fonte, documentação e recursos utilizados no desenvolvimento dos sistemas.

## 📂 Estrutura do Repositório

```
/meu_projeto
│── /build                  # Diretório de compilação (gerado pelo CMake)
│── /src                    # Código-fonte principal (.c, .cpp)
│── /include                # Cabeçalhos (.h, .hpp)
│── /lib                    # Bibliotecas externas (se necessário)
│── /examples               # Exemplos de uso do código (opcional)
│── CMakeLists.txt          # Configuração do projeto CMake
│── pico_sdk_import.cmake   # Importação do SDK da Raspberry Pi
│── assets                  # Imagens, Vídeos e Diagramas
│── docs                    # Documentação Técnica
│── README.md               # Projeto em Foco
├── LICENSE
```

## 🔗 Projetos
Abaixo está a lista de projetos desenvolvidos. Cada um possui um diretório específico dentro do repositório:

- [Projeto 1 - Nome do Projeto](./projetos/projeto1/)
- [Projeto 2 - Nome do Projeto](./projetos/projeto2/)
- [Projeto 3 - Nome do Projeto](./projetos/projeto3/)

## 🖼️ Setup do Hardware
Sugestão: incluir aqui uma **foto geral do kit** ou do **setup utilizado** nos projetos. Isso pode ajudar na reprodução dos experimentos.

## 🛠️ Requisitos e Configuração
Para compilar e rodar os projetos no **Raspberry Pi Pico W**, siga os passos abaixo:

1. **Instale o SDK do Pico** seguindo as instruções oficiais da Raspberry Pi.
2. Clone este repositório:
   ```bash
   git clone https://github.com/seu_usuario/seu_repositorio.git
   cd meu_projeto
   ```
3. **Crie o diretório de build e compile:**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
4. **Carregue o firmware no Raspberry Pi Pico W.**

## 👤 Autor
**Antonio Almeida - Hbr Campinas**

Se tiver dúvidas ou sugestões, fique à vontade para contribuir ou abrir uma _issue_. 🚀
