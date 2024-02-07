#include <studio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <base64.h>
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

   // Imprimir a mensagem invertida
    Serial.print("Mensagem decodificada e invertida: %s\n", reversed_message);
   
    // Liberar memória alocada
    free(encoded_message);
    free(decoded_message_base64);
    free(reversed_message);   
    return 0;
}

char* readFile() {
    FILE* file;
    char* buffer = NULL;
    long length;

    //abrindo arquivo
    file = fopen("D:\github\iot\ps00125\prova_bento\prova_bento_q2/message.txt", "rb");
    if (file == NULL) {
        return NULL;
    }

    //leitura
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = (char*)malloc(length + 1); //alocacao de memoria
    if (buffer == NULL) {
        fclose(file);
        return NULL;
    }

    //leitura e fechamento do arquivo
    fread(buffer, 1, length, file);
    fclose(file);
    buffer[length] = '\0';

    return buffer;
}
