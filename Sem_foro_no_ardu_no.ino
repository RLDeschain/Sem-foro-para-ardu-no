int ledVermelho = 8; //atribui o valor 8 para a variável ledVermelho
int ledAmarelo = 9; //atribui o valor 9 para a variável ledAmarelo
int ledVerde = 10; //atribui o valor 10 para a variável ledVerde
int pedVerde = 11; //atribui o valor 11 para a variável pedVerde.
int pedVermelho = 12; //atribui o valor 12 para a variável pedVermelho.
int botao = 2; //atitui o valor 2 para a variável botão.
int esperar = 5000; //atibui o valor 5000 que é o equivalente a 5 segundos para a variável esperar.
unsigned long conferirTempo;//conta o tempo desde que o botão foi pressinado.


void setup() {
  pinMode(ledVermelho, OUTPUT); //usa o valor armazenado na variável ledVermelho para definir o pino a ser usado no arduíno e define ele como saída.
  pinMode(ledAmarelo, OUTPUT);//usa o valor armazenado na variável ledAmarelo para definir o pino a ser usado no arduíno e define ele como saída.
  pinMode(ledVerde, OUTPUT);//usa o valor armazenado na variável ledVerde para definir o pino a ser usado no arduíno e define ele como saída.
  pinMode(pedVermelho, OUTPUT);//usa o valor armazenado na variável pedVermelho para definir o pino a ser usado no arduíno e define ele como saída.
  pinMode(pedVerde, OUTPUT);//usa o valor armazenado na variável pedVerde para definir o pino a ser usado no arduíno e define ele como saída.
  pinMode(botao, INPUT);//usa o valor armazenado na variável botao para definir o pino a ser usado no arduíno e define ele como entrada.
  digitalWrite(ledVerde, HIGH); //acende o sinal verde para os carros no início do programa.
  digitalWrite(pedVermelho, HIGH); //acende o sinal vermelhor para os pedestres no início do programa.
}

void loop() {
  int estado = digitalRead(botao); //armazena na variável botão o valor lido no switch.
  if (estado == HIGH && (millis() - conferirTempo) > 5000) {
    mudarLuzes();
    /*caso o botão seja pressionado e o intervalo entre a chamada do botão seja menor que 5 segundos o programa chama a função "changeLights" que altera o sinal verde para o amarelo e depois para o vermelho*/
  }
}
void mudarLuzes() {
  //definição da função "mudarLuzes"
  digitalWrite(ledVerde, LOW); //apaga a luz verde do semáforo.
  digitalWrite(ledAmarelo, HIGH); // acende a luz amarela do semáforo.
  delay(2000); //espera 2 segundos.
  digitalWrite(ledAmarelo, LOW); // apaga a luz amarela do semáforo.
  digitalWrite(ledVermelho, HIGH); //acende a luz vermelha do semáforo
  delay(1000);// espera 1 segundo de segurança para mudar as luzes do semáforo para pedestres
  digitalWrite(pedVermelho, LOW); //apaga o sinal vermelho para os pedestres;
  digitalWrite(pedVerde, HIGH); //acende o sinal verde para os pedestres
  delay(esperar); // espera por um intervalo de tempo definido na declaração do programa.
  /*após 5 segundos o laço for é executado 10 vezes fazendo o sinal de pedestres piscar indicando assim que que o semáforo está prestes a mudar de estado*/
  for (int x = 0; x < 10; x++) {
    digitalWrite(pedVerde, LOW);
    delay(250);
    digitalWrite(pedVerde, HIGH);
    delay(250);
  }
  digitalWrite(pedVermelho, HIGH);
  delay(500);
  digitalWrite(ledAmarelo, HIGH);
  delay(500);
  digitalWrite(ledAmarelo, LOW);
  delay(500);
  digitalWrite(ledVerde, HIGH);
  conferirTempo = millis();
}
