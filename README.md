### README.md  

# Atividade 2: Controle de pinos GPIO da Ferramenta Educacional BitDogLab  

## Descrição  
Esta atividade tem como objetivo explorar o controle de pinos GPIO utilizando a ferramenta educacional **BitDogLab** em conjunto com o microcontrolador **RP2040**. Por meio da comunicação via porta serial **UART**, foram implementados comandos que permitem o controle de um LED RGB e de um buzzer.  

### Funcionalidades  
- Controle individual dos LEDs RGB conectados aos GPIOs 11, 12 e 13.  
- Controle do sinal sonoro do buzzer conectado ao GPIO 21.  
- Interpretação de comandos via porta serial para ativar/desativar os periféricos.  

## Requisitos  
- **Microcontrolador**: RP2040 (Raspberry Pi Pico ou similar).  
- **Ferramenta Educacional**: BitDogLab.  
- **Periféricos**:  
  - LED RGB conectado aos pinos GPIO 11, 12 e 13.  
  - Buzzer conectado ao GPIO 21.  
- **Ambiente de Desenvolvimento**:  
  - VS Code com extensões necessárias para Raspberry Pi Pico.  
  - SDK da Raspberry Pi Pico.  
  - Conexão UART para comunicação via porta serial.  

## Instruções para Uso  

### 1. Configuração do Hardware  
Conecte os periféricos conforme o seguinte mapeamento:  
- **LED Vermelho**: GPIO 13.  
- **LED Verde**: GPIO 11.  
- **LED Azul**: GPIO 12.  
- **Buzzer**: GPIO 21.  

### 2. Comandos Disponíveis  
Use os comandos abaixo para interagir com o sistema via porta serial:  

| Comando       | Ação                          |  
|---------------|-------------------------------|  
| `LED_R ON`    | Liga o LED vermelho           |  
| `LED_R OFF`   | Desliga o LED vermelho        |  
| `LED_G ON`    | Liga o LED verde              |  
| `LED_G OFF`   | Desliga o LED verde           |  
| `LED_B ON`    | Liga o LED azul               |  
| `LED_B OFF`   | Desliga o LED azul            |  
| `BUZZER ON`   | Liga o buzzer                 |  
| `BUZZER OFF`  | Desliga o buzzer              |  

### 3. Configuração do Software  
1. Clone este repositório:  
   ```bash  
   git clone https://github.com/seu_usuario/atividade2-bitdoglab.git  
   ```  
2. Compile o código utilizando o SDK da Raspberry Pi Pico.  
3. Faça o upload para a placa RP2040.  

### 4. Comunicação Serial  
Utilize um terminal serial (como o **Putty**, **Tera Term** ou o monitor serial do **VS Code**) para enviar comandos e visualizar os retornos do sistema. Configure a porta serial com os seguintes parâmetros:  
- Baud rate: **115200**  
- Data bits: **8**  
- Paridade: **Nenhuma**  
- Stop bits: **1**  

### 5. Execução  
Ao iniciar o sistema, o microcontrolador estará pronto para receber comandos via UART. Digite os comandos listados na seção anterior para controlar os periféricos conectados.  

## Vídeo Demonstrativo  
Confira o funcionamento do projeto no vídeo abaixo:  
[**Link para o vídeo demonstrativo**](https://drive.google.com/file/d/1H2f_kH3bOCKV9nR5KODAVbIyvlRaBR3L/view?usp=sharing)  



## Estrutura do Código  
O programa está estruturado da seguinte maneira:  
- **Configuração GPIO**: Inicializa os pinos de entrada e saída.  
- **Função `interpretar_comando`**: Lê e interpreta os comandos enviados via UART.  
- **Loop principal**: Aguarda e processa os comandos enviados pelo usuário.  

## Resultados Esperados  
- Controle preciso dos LEDs RGB e do buzzer através de comandos UART.  
- Feedback textual no terminal indicando o estado atual dos periféricos (ligado/desligado).  

## Contribuição  
Sinta-se à vontade para contribuir com melhorias ou adaptações no código. Para isso:  
1. Faça um fork do repositório.  
2. Crie uma branch para suas modificações:  
   ```bash  
   git checkout -b minha-contribuicao  
   ```  
3. Envie um pull request detalhando as alterações realizadas.  

---

