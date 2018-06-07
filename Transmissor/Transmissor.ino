// Projeto: Carrinho controlado por gestos.
// Participantes:
// Allisson Alves, Hugo Hiago, Juliandson Barros, Luan Henrique, Lucas Simas, Rafael Marques, Tiago Nunes.
// Programa: Código transmissor.

// Biblioteca MPU6050 para facilitar o uso do Acelerômetro.
#include <MPU6050_tockn.h>
// Inclui a biblioteca Wire.
#include <Wire.h>
// Inclui a biblioteca VirtualWire.
#include <VirtualWire.h>

// Define o pino 8 como pino do transmissor de dados do RF.
const int PINO_TRANSMISSOR = 8;

// Constantes para auxiliar na trasmissão das informações do carrinho.
const byte PARADO = 0;
const byte FRENTE = 1;
const byte RE = 2;
const byte ESQUERDA = 3;
const byte DIREITA = 4;

// Variáveis para armazenar os valores do acelerômetro.
float x, y, z;

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);

  Wire.begin();
  mpu6050.begin();
  // mpu6050.calcGyroOffsets(true);

  vw_set_tx_pin(PINO_TRANSMISSOR);
  vw_setup(2000);
}

void loop() {
  // Atualiza os dados do acelerômetro.
  mpu6050.update();

  // Captura os angulos X, Y
  x = mpu6050.getAccAngleX();
  y = mpu6050.getAccAngleY();

  Serial.print("X: ");
  Serial.print(x);
  Serial.print(" - Y: ");
  Serial.print(y);
  Serial.println();

  byte mensagem;

  if (x > -20 and x < 20) {
    if (y > -20 and y < 20) {
      mensagem = PARADO;
      Serial.println("Parado!");
    } else if (y > 20 and y < 60) {
      mensagem = RE;
      Serial.println("Ré!");
    } else if (y < 0 and y > -60) {
      mensagem = FRENTE;
      Serial.println("Frente!");
    }
  } else if ((x > -60 and x < -20) and (y > -20 and y < 20)) {
    mensagem = DIREITA;
    Serial.println("Direita!");
  } else if ((x > 5 and x < 60) and (y > -30 and y < 30)) {
    mensagem = ESQUERDA;
    Serial.println("Esquerda!");
  }

  enviarMensagem(mensagem);
  delay(500);
}

void enviarMensagem(char *mensagem) {
  vw_send((uint8_t *)&mensagem, 1);
  vw_wait_tx(); // Aguarda o envio da mensagem.
}
