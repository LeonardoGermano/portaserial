#include "pico/stdlib.h"

#define LED1_PIN 12  // Definindo o pino do LED1
#define LED2_PIN 11  // Definindo o pino do LED2
#define LED3_PIN 13  // Definindo o pino do LED3
#define BUZZER_PIN 21 // Definindo o pino do Buzzer

// Função para ativar/desativar um pino GPIO
void toggle_gpio(uint pin, bool state) {
    gpio_put(pin, state);
}

int main() {
    // Inicializa o sistema de GPIO
    stdio_init_all();

    // Configura os pinos dos LEDs como saída
    gpio_init(LED1_PIN);
    gpio_set_dir(LED1_PIN, GPIO_OUT);

    gpio_init(LED2_PIN);
    gpio_set_dir(LED2_PIN, GPIO_OUT);

    gpio_init(LED3_PIN);
    gpio_set_dir(LED3_PIN, GPIO_OUT);

    // Configura o pino do buzzer como saída
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    while (true) {
        // Liga o LED1
        toggle_gpio(LED1_PIN, true);
        sleep_ms(500);
        toggle_gpio(LED1_PIN, false);

        // Liga o LED2
        toggle_gpio(LED2_PIN, true);
        sleep_ms(500);
        toggle_gpio(LED2_PIN, false);

        // Liga o LED3
        toggle_gpio(LED3_PIN, true);
        sleep_ms(500);
        toggle_gpio(LED3_PIN, false);

        // Ativa o buzzer
        toggle_gpio(BUZZER_PIN, true);
        sleep_ms(500);
        toggle_gpio(BUZZER_PIN, false);

        // Pausa entre ciclos
        sleep_ms(500);
    }

    return 0;
}
