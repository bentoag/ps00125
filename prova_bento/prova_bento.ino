#include <Arduino_FreeRTOS.h>
#define LED_PIN 13
#define tf1_delay pdMS_TO_TICKS(1000) //1Hz
#define tf2_delay pdMS_TO_TICKS(2000) //2Hz

float temperaturaCelsius = 10.0;

//declaracao da tarefa
void tf1(void *pvParameters)
void tf2(void *pvParameters)

void setup() {
  //inicializacao da serial
  Serial.begin(9600);
  //criacao das tarefas
  xTaskCreate(tf1, "Tarefa 1", 128, NULL, 1, NULL);
  xTaskCreate(tf2, "Tarefa 2", 128, NULL, 2, NULL);
}

void loop() {

}
