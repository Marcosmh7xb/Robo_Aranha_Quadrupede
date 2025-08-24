# Robo_Aranha_Quadrupede

Este relatório apresenta a escolha e as especificações do nosso projeto: um robô aranha quadrúpede, que utiliza nove servomotores para sua movimentação. Optamos por este modelo considerando os recursos disponíveis, garantindo viabilidade tanto na fabricação quanto no controle do robô.

O robô possui quatro patas, cada uma equipada com dois servomotores para movimentação, enquanto um servo adicional foi designado para a cabeça, permitindo que ela se mova de forma independente.

Ele foi projetado para ser um robô quadrúpede ambulante, utilizando peças impressas em 3D, servomotores e um Arduino para controle central. Para gerenciar de forma eficiente todos os servos, foi utilizada a placa PCA9685, que permite expandir as conexões e controlar múltiplos motores com maior estabilidade.

Além da locomoção, uma função extra foi adicionada ao projeto: a interação com o ambiente. Quando o sensor ultrassônico detectar um obstáculo à frente, o robô moverá uma das patas dianteiras como se estivesse tentando afastá-lo, proporcionando maior expressividade e tornando sua movimentação mais natural e interativa.
