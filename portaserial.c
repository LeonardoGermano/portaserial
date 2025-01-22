#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>

// Definições dos pinos
#define LED_R 13  // O LED vermelho está no pino 13
#define LED_G 11  // O LED verde está no pino 11
#define LED_B 12  // O LED azul está no pino 12
#define BUZZER 21

void configurar_gpio() {
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);

    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);

    gpio_init(LED_B);
    gpio_set_dir(LED_B, GPIO_OUT);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

void apagar_tudo() {
    gpio_put(LED_R, 0);
    gpio_put(LED_G, 0);
    gpio_put(LED_B, 0);
    gpio_put(BUZZER, 0);
}

// Função para limpar caracteres de controle
void limpar_comando(char *comando) {
    int i = 0, j = 0;
    while (comando[i] != '\0') {
        if (comando[i] != '\r' && comando[i] != '\n') {
            comando[j++] = comando[i];
        }
        i++;
    }
    comando[j] = '\0'; // Termina a string corretamente
}

void interpretar_comando(char *comando) {
    if (strcmp(comando, "LED_G ON") == 0) {
        gpio_put(LED_G, 1);  // LED verde ligado
        printf("LED verde ligado.\n");
    } else if (strcmp(comando, "LED_G OFF") == 0) {
        gpio_put(LED_G, 0);  // LED verde desligado
        printf("LED verde desligado.\n");
    } else if (strcmp(comando, "LED_B ON") == 0) {
        gpio_put(LED_B, 1);  // LED azul ligado
        printf("LED azul ligado.\n");
    } else if (strcmp(comando, "LED_B OFF") == 0) {
        gpio_put(LED_B, 0);  // LED azul desligado
        printf("LED azul desligado.\n");
    } else if (strcmp(comando, "LED_R ON") == 0) {
        gpio_put(LED_R, 1);  // LED vermelho ligado
        printf("LED vermelho ligado.\n");
    } else if (strcmp(comando, "LED_R OFF") == 0) {
        gpio_put(LED_R, 0);  // LED vermelho desligado
        printf("LED vermelho desligado.\n");
    } else if (strcmp(comando, "BUZZER ON") == 0) {
        gpio_put(BUZZER, 1);
        printf("Buzzer ligado.\n");
    } else if (strcmp(comando, "BUZZER OFF") == 0) {
        gpio_put(BUZZER, 0);
        printf("Buzzer desligado.\n");
    } else {
        printf("Comando invalido: %s\n", comando);
    }
}

int main() {
    stdio_init_all();
    configurar_gpio();

    printf("Sistema inicializado. Pronto para receber comandos.\n");

    char comando[50];
    while (true) {
        int i = 0;
        memset(comando, 0, sizeof(comando)); // Limpar o buffer de comando

        while (true) {
            char c = getchar(); // Leitura direta sem timeout
            if (c == '\n' || c == '\r' || c == EOF) {
                if (i > 0) { // Se a string não está vazia
                    comando[i] = '\0'; // Finaliza a string
                    break;
                }
            } else if (i < sizeof(comando) - 1) {
                comando[i++] = c; // Preenche o buffer até o tamanho máximo
            }
        }

        if (strlen(comando) > 0) {
            // Limpar caracteres extras de controle
            limpar_comando(comando);
            interpretar_comando(comando);
        }

        // Adicionando pequeno delay para não sobrecarregar o loop
        sleep_ms(50);
    }

    return 0;
}
