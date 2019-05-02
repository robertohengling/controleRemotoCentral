## Controle Remoto Central
A ideia do projeto é utilizar um aplicativo e um arduino com transmissor IR (de qualquer controle remoto velho) para controlar todos os equipamentos de um ou mais ambientes.
O aplicativo está sendo feito em IONIC.
# Existem 2 .ino no diretório arduino:
O receptor é necessário para ler o código referente ao comando que deve ser copiado (para isso é necessário um receptor IR, pode ser utilizado um de algum equipamento velho, como TV, DVD, ETC).
O emissor é o sketch que deve ser utilizado para enviar os comandos aos equipamentos.
Ou seja:
Primeiro é necessário copiar os códigos enviados por cada tecla que deseja copiar, depois é necessário preencher corretamente o arquivo "ionic\controleRemoto\src\app\home\ambientes.json".
Projeto em fase inicial.
Requisitos de hardware: Arduino, ethernet ou wifi shield, emissor IR, receptor IR, resistor de 200 Ohms.
