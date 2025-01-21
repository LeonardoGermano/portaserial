#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>

// Definições dos pinos
#define LED_R 11
#define LED_G 12
#define LED_B 13
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

void interpretar_comando(char *comando) {
    if (strcmp(comando, "LED_R ON") == 0) {
        gpio_put(LED_R, 1);
        printf("LED vermelho ligado.\n");
    } else if (strcmp(comando, "LED_R OFF") == 0) {
        gpio_put(LED_R, 0);
        printf("LED vermelho desligado.\n");
    } else if (strcmp(comando, "LED_G ON") == 0) {
        gpio_put(LED_G, 1);
        printf("LED verde ligado.\n");
    } else if (strcmp(comando, "LED_G OFF") == 0) {
        gpio_put(LED_G, 0);
        printf("LED verde desligado.\n");
    } else if (strcmp(comando, "LED_B ON") == 0) {
        gpio_put(LED_B, 1);
        printf("LED azul ligado.\n");
    } else if (strcmp(comando, "LED_B OFF") == 0) {
        gpio_put(LED_B, 0);
        printf("LED azul desligado.\n");
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
            char c = getchar_timeout_us(10000); // Aguarda caractere por 10ms
            if (c == '\n' || c == '\r' || c == EOF) {
                comando[i] = '\0'; // Finaliza a string
                break;
            } else if (c != 255 && i < sizeof(comando) - 1) {
                comando[i++] = c; // Preenche o buffer até o tamanho máximo
            }
        }

        if (strlen(comando) > 0) {
            interpretar_comando(comando);
        }
    }

    return 0;
}
