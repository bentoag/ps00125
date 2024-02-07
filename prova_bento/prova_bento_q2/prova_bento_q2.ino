#include <studio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "decoder.h"

#define FILE_PATH "D:\github\iot\ps00125\prova_bento\prova_bento_q2/message.txt"
#define BUFFER_SIZE 1024

//prototipo das funcoes definidas no arquivo decoder
char* readFile();
char* base64(char* encoded_message);
char* reverse(char* decoded_message);

void setup() {
   //inicializacao da serial
    Serial.begin(9600);

}

void loop() {
  //ler o arquivo message
  char* encoded_message = readFile();
    if(encoded_message==NULL){
      Serial.print("Erro ao ler o arquivo de texto. \n");
      return 1;
    }
  // chamar funcao para decodificar a mensagem
  char* decoded_message_base64 = base64(encoded_message);  
    if (decoded_message_base64 == NULL) {
          Serial.print("Erro ao decodificar a mensagem.\n");
          return 1;
      }
    //chamar funcao para inverter mensagem
  char* reversed_message = reverse(decoded_message_base64);   
    if (reversed_message == NULL) {
        Serial.print("Erro ao inverter a mensagem.\n");
        return 1;
    }

  
}
