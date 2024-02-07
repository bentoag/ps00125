#include <Arduino_FreeRTOS.h>
#define LED_PIN 13
#define tf1_delay pdMS_TO_TICKS(1000) //1Hz
#define tf2_delay pdMS_TO_TICKS(2000) //2Hz

float temperaturaCelsius = 10.0;
int i, j;

//declaracao da tarefa
void tf1(void *pvParameters);
void tf2(void *pvParameters);

void setup() {
  //inicializacao da serial
  Serial.begin(9600);
  //criacao das tarefas
  xTaskCreate(tf1, "Tarefa 1", 128, NULL, 1, NULL);
  xTaskCreate(tf2, "Tarefa 2", 128, NULL, 2, NULL);
}

void loop() {
  vTaskDelete(NULL);
}

void tf1(void *pvParameters){
  (void) pvParameters;

  for(i=0; i<100; i++){
     temperaturaCelsius +=1.5; //incremento de 1.5 na temp em celsius
    //imprimindo o resultado
    Serial.print("Temperatura em ºC Celsius: ");
    Serial.print(temperaturaCelsius);
    vTaskDelay(tf1_delay);
    }
  
 
}

void tf2(void *pvParameters){
  (void) pvParameters;
  for(j=0; j<100; j++){
    float temperaturaFahrenheit = ((temperaturaCelsius*(9.0/5.0))+ 32.0); //conversao ºC para ºF
    //imprimindo o resultado
    Serial.print("Temperatura em ºC Fahrenheit: ");
    Serial.print(temperaturaFahrenheit);
    vTaskDelay(tf2_delay);
    
  }
  
}
