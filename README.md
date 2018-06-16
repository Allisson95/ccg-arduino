# Projeto Carrinho de Mão
O projeto consiste em um carrinho controlado por gestos da mão.
## Itens utilizados
**Transmissor**
 - Arduino Lilypad
 - Acelerômetro e Giroscópio 3 Eixos 6 DOF MPU-6050
 - Módulo RF Transmissor
 - Bateria 5v

**Receptor**
 - Arduino UNO R3
 - Arduino Motor Shield L293D
 - Módulo RF Receptor
 - Kit Chassi 4WD Robô para Arduino
 - Bateria 12v

## Bibliotecas utilizadas
**Transmissor**
 - [MPU6050_tockn](https://github.com/Tockn/MPU6050_tockn)
 - Wire
 - [VirtualWire](http://www.airspayce.com/mikem/arduino/VirtualWire/)

**Receptor**
 - [VirtualWire](http://www.airspayce.com/mikem/arduino/VirtualWire/)
 - [AFMotor](https://github.com/adafruit/Adafruit-Motor-Shield-library/)

## Material de apoio
[**Tutorial: Acelerômetro MPU6050 com Arduino**](https://www.filipeflop.com/blog/tutorial-acelerometro-mpu6050-arduino/)
[**Comunicação Wireless com Módulo RF 433MHz**](https://www.filipeflop.com/blog/modulo-rf-transmissor-receptor-433mhz-arduino/)
[**Controle Motor DC 12v com Arduino Motor Shield L293D**](https://www.filipeflop.com/blog/controle-motor-dc-arduino-motor-shield/)
