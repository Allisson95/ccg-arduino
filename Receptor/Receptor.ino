// Projeto: Carrinho controlado por gestos.
// Participantes:
// Allisson Alves, Hugo Hiago, Juliandson Barros, Luan Henrique, Lucas Simas, Rafael Marques, Tiago Nunes.
// Programa: Código receptor.

// Inclui a biblioteca VirtualWire.
#include <VirtualWire.h>
// Inclui a biblioteca AFMotor.
#include <AFMotor.h>

// Define o pino 2 como pino do receptor de dados do RF.
const int PINO_RECEPTOR = 2;

// Constantes para auxiliar na recepção das informações do carrinho.
const byte PARADO = 0;
const byte FRENTE = 1;
const byte RE = 2;
const byte ESQUERDA = 3;
const byte DIREITA = 4;

// Define os motores no Motor Shield.
AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);

void setup() {
  Serial.begin(9600);

  vw_set_rx_pin(PINO_RECEPTOR);
  vw_setup(2000);
  vw_rx_start();
}

void loop() {
  // Armazena as mensagens recebidas.
  byte mensagem[VW_MAX_MESSAGE_LEN] = { PARADO };
  // Armazena o tamanho das mensagens.
  byte tamanhoMensagem = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(mensagem, &tamanhoMensagem)) {
    Serial.print("Recebido: ");
    for (int i = 0; i < tamanhoMensagem; i++)
    {
      Serial.print(mensagem[i], HEX);
    }
    Serial.println();

    switch (mensagem[0]) {
      case PARADO:
        Serial.println("Parado!");
        desligarTodosOsMotores();
        break;
      case FRENTE:
        Serial.println("Andando para Frente!");
        andarParaFrente();
        break;
      case DIREITA:
        Serial.println("Virando a Direita!");
        virarParaDireita();
        break;
      case ESQUERDA:
        Serial.println("Virando a Esquerda!");
        virarParaEsquerda();
        break;
      case RE:
        Serial.println("Andando para Trás!");
        andarParaTras();
        break;
    }
  }
}

void desligarTodosOsMotores() {
  desligarMotor(&M1);
  desligarMotor(&M2);
  desligarMotor(&M3);
  desligarMotor(&M4);
}

void andarParaFrente() {
  ligarMotorParaFrente(&M1, 200);
  ligarMotorParaFrente(&M2, 200);
  ligarMotorParaFrente(&M3, 200);
  ligarMotorParaFrente(&M4, 200);
}

void andarParaTras() {
  ligarMotorParaTras(&M1, 150);
  ligarMotorParaTras(&M2, 150);
  ligarMotorParaTras(&M3, 150);
  ligarMotorParaTras(&M4, 150);
}

void virarParaDireita() {
  ligarMotorParaFrente(&M1, 200);
  ligarMotorParaFrente(&M2, 200);
  desligarMotor(&M3);
  desligarMotor(&M4);
}

void virarParaEsquerda() {
  desligarMotor(&M1);
  desligarMotor(&M2);
  ligarMotorParaFrente(&M3, 200);
  ligarMotorParaFrente(&M4, 200);
}

void desligarMotor(AF_DCMotor *motor) {
  motor->setSpeed(0);
  motor->run(RELEASE);
}

void ligarMotorParaFrente(AF_DCMotor *motor, int velocidade) {
  motor->setSpeed(velocidade);
  motor->run(FORWARD);
}

void ligarMotorParaTras(AF_DCMotor *motor, int velocidade) {
  motor->setSpeed(velocidade);
  motor->run(BACKWARD);
}

