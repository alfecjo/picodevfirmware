### Observação importante:
Pode ser necessário algumas alterações no arquivo CMakeLists.txt, haja visto que cada instalação
do ambiente segue características individuais de cada projetista. Sem essas alterações o
código pode não apresentar o comportamento desejado!
___
### 🚀 **Tarefa..**

## 📌 Contador decrescente com registro de eventos por interrupçãoTarefa

## 🛠️ Explicação da Lógica da Tarefa

## 🎯 Faça um programa, em linguagem C, que implemente um contador decrescente controlado por interrupção, com o seguinte comportamento:

1. **Toda vez que o Botão A (GPIO5) for pressionado:**

2. O contador decrescente reinicia em 9 e o valor da contagem é mostrado no display OLED.

3. O sistema entra em modo de contagem regressiva ativa, decrementando o contador de 1 em 1 a cada segundo até chegar em zero.

4. Durante essa contagem (ou seja, de 9 até 0), o programa deve registrar quantas vezes o Botão B (GPIO6) foi pressionado. O valor deste registro de eventos de botão pressionado também deve ser mostrado no display OLED.

5. Quando o contador atingir zero, o sistema congela e ignora temporariamente os cliques no Botão B (eles não devem ser acumulados fora do intervalo ativo).

6. **O sistema permanece parado após a contagem, exibindo:**

7. O valor 0 no contador

8. A quantidade final de cliques no Botão B registrados durante o período de 9 segundo (contagem regressiva)

9. **Somente ao pressionar novamente o Botão A, o processo todo se reinicia:**

10. O contador volta para 9

11. O número de cliques do Botão B é zerado

12. A contagem recomeça do início
___

### 📝 **O código foi desenvolvido em C/C++ e testado no ambiente Bitdoglab.**

### 🔧 **Status**

 🚧 Testado 🟢
___

### 📋 **Lista de Testes que contribuiram para a criação do projeto:**

🟢 Teste 0001 - Ok! Debounce por tempo...
___
![Projeto final testado](\assets\20250412_174721.jpg)