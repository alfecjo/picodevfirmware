# Projeto: Monitoramento MQTT com BitDogLab, Raspberry Pi e Wireshark

## Visão Geral

Este projeto demonstra a comunicação via protocolo MQTT utilizando uma placa **BitDogLab** como Publisher, uma **Raspberry Pi 3B+** como Broker MQTT e outra **Raspberry Pi 3B+** rodando **Xubuntu com Wireshark** para análise do tráfego de rede.

---

## Arquitetura do Sistema

- BitDogLab (Publisher) ---> MQTT Broker (Raspberry Pi 3B+) ---> Wireshark (Raspberry Pi com Xubuntu)

---

## Componentes Utilizados

| Componente              | Função                              |
|-------------------------|-------------------------------------|
| BitDogLab (PICO)        | Dispositivo IoT Publisher MQTT      |
| Raspberry Pi 3B+ (1)    | Broker MQTT (Mosquitto)             |
| Raspberry Pi 3B+ (2)    | Monitoramento com Xubuntu + Wireshark|

---

## Configuração dos Dispositivos

### 1. BitDogLab - Publisher MQTT

- Firmware: `picow_mqtt_client`
- Conectada via Wi-Fi à mesma rede local das Raspberries
- Envia mensagens MQTT para o Broker usando ADC + sensor interno de temperatura
- Configurações utilizadas no código:
  ```c
  #define MQTT_BROKER "192.168.X.X" // IP da Raspberry Pi Broker
  #define MQTT_PORT 1883
  #define MQTT_TOPIC "/temperatura"

### 2. Raspberry Pi 3B+ - MQTT Broker

- Sistema operacional: Raspberry Pi OS Lite (sem GUI)
- Broker instalado: Mosquitto MQTT Broker

- Instalação:

```bash
sudo apt update
sudo apt install mosquitto mosquitto-clients
sudo systemctl enable mosquitto
sudo systemctl start mosquitto
```

### Teste com cliente:
- Considerando variáveis corretamente definidas

```bash
mosquitto_pub -h $MQTT_SERVER --cafile $MQTT_SERVER/ca.crt --key $MQTT_SERVER/client.key --cert $MQTT_SERVER/client.crt -t "$1" -m "$2"

mosquitto_sub -h $MQTT_SERVER --cafile $MQTT_SERVER/ca.crt --key $MQTT_SERVER/client.key --cert $MQTT_SERVER/client.crt -t "$1"
```
### 3. Raspberry Pi 3B+ com Xubuntu + Wireshark

- Sistema operacional: Xubuntu Desktop (leve e responsivo)
- Objetivo: Captura e análise de pacotes MQTT e TCP/IP via Wireshark

- Etapas:

    - Instalação do Wireshark:

    ```bash
    sudo apt update
    sudo apt install wireshark
    sudo usermod -aG wireshark $USER
    ```
    - Reinicie o sistema após adicionar o usuário ao grupo wireshark.

- Interface de rede monitorada: wlan0 ou eth0, dependendo da conexão

- Filtro utilizado no Wireshark:
    - mqtt || tcp.port == 1883 (sem TLS)
    - mqtt || tcp.port == 8883 (com TLS)

### Possíveis Melhorias

- Adicionar autenticação TLS no Broker MQTT
- Publicar dados reais de sensores conectados à BitDogLab
- Armazenar os dados publicados usando um banco de dados leve como InfluxDB
- Visualizar dados em tempo real com Grafana

---

## 🍒 A Cereja do Bolo: Acesso Global e Interface Angular com AWS

Para completar a arquitetura, o objetivo é **transformar o laboratório local em um ambiente IoT acessível mundialmente**, por meio da exposição segura do broker MQTT à internet e da criação de uma interface web dinâmica desenvolvida em **Angular** e hospedada na **AWS S3**.

---

### 🌍 Expondo o Broker MQTT via IP Público

Através da **configuração do roteador**, é possível **tornar o broker MQTT da Raspberry Pi acessível globalmente**, usando o IP público fornecido pelo seu ISP:

#### 🛠️ Etapas para Habilitar Acesso Global

1. **Redirecionamento de Portas (Port Forwarding / NAT)**
   - Acesse o painel do seu roteador.
   - Crie uma regra que redirecione uma porta pública (ex: `1883` ou `9001` ou `8883` ) para o IP local da Raspberry Pi com o broker MQTT (exemplo):
     ```
     IP Público:1883 → IP Local da Pi (ex: 192.168.1.50):1883
     IP Público:9001 → IP Local da Pi:9001 (para WebSocket)
     ```

2. **IP Público Estático ou Dinâmico**
   - Caso seu IP seja dinâmico, use serviços de DNS dinâmico como:
     - [DuckDNS](https://www.duckdns.org/)
     - [No-IP](https://www.noip.com/)
   - Isso fornecerá um domínio estável (ex: `meubroker.duckdns.org`).

3. **Segurança**
   - Habilite autenticação no broker (usuário e senha).
   - Considere ativar TLS (SSL) para conexões criptografadas.
   - Configure o firewall do roteador para limitar acesso a IPs confiáveis ou regiões específicas.

---

### 🧠 Front-end Angular Hospedado na AWS S3

O controle e visualização dos dados será feito por uma aplicação **Angular** moderna, hospedada no **Amazon S3 com hospedagem estática ativada**, servindo como a **interface gráfica principal do sistema**.

#### 🔧 Características do Front-end:

- Desenvolvido em Angular 16+
- Comunicação com o broker MQTT via **WebSocket**
- Painel responsivo com gráficos, botões de controle e indicadores em tempo real
- Autenticação e controle de sessão
- Hospedado no S3 com possível integração ao **CloudFront + ACM** para HTTPS

#### 📦 Conexão Angular → MQTT

No Angular, a biblioteca **`mqtt.js`** será utilizada com WebSocket para conectar-se ao broker remoto:

```typescript
import * as mqtt from 'mqtt';

const client = mqtt.connect('ws://meubroker.duckdns.org:9001', {
  username: 'seu_usuario',
  password: 'sua_senha'
});

client.on('connect', () => {
  console.log('Conectado ao broker MQTT');
  client.subscribe('topico/sensores');
  client.publish('topico/atuadores', 'ligar');
});
```
### 🚦 Fluxo de Comunicação Esperado

```
[Navegador Angular]
        ↓ WebSocket
 [Broker MQTT Local na Pi]
        ↓ rede local
 [BitDogLab enviando dados]

```

- Tudo isso orquestrado por um roteador com portas corretamente expostas ao IP público, permitindo que qualquer pessoa autorizada acesse e controle o sistema via internet.

### 🛡️ Segurança Reforçada

- TLS no broker (porta 8883 ou WebSocket seguro wss)
- IP filtering no roteador (acesso restrito por IP ou geolocalização)
- Autenticação JWT na interface Angular
- Bucket S3 com acesso privado via CloudFront
- Logs, métricas e alertas de tráfego suspeito

> Com essa arquitetura, você transforma seu laboratório caseiro em uma plataforma IoT global, moderna, segura e escalável — pronta para demonstrações profissionais ou até aplicações comerciais.

