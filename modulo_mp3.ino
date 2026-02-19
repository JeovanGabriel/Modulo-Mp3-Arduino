/*Modulo MP3 que funciona tanto por Controle IR (Infra Vermelho)
e por push button em caso de problemas com o receptor, 
uso principal para cosplay*/


//bibliotecas
  #include <DFPlayerMini_Fast.h>
  #include <IRremote.h>
  #if !defined(UBRR1H)
  #include <SoftwareSerial.h>
  SoftwareSerial mySerial(10, 11); 
  #endif

//variaveis
  //Pinos Bt = Botão
  int bt01 = 2;
  int bt02 = 3;
  int bt03 = 4;
  int bt04 = 5;
  int btMais = 6;
  int btMenos = 7;
  int btParar = 8;
  int receptor = 9;

  //Leitura
  int estadoBt;
  float valorIR;

  //valores hexadecimais do controle IR
  unsigned long tecla01 = 0xBA45FF00;
  unsigned long tecla02 = 0xB946FF00;
  unsigned long tecla03 = 0xB847FF00;
  unsigned long tecla04 = 0xBB44FF00;
  unsigned long tecla05 = 0xBF40FF00;
  unsigned long tecla06 = 0xBC43FF00;
  unsigned long tecla07 = 0xF807FF00;
  unsigned long tecla08 = 0xEA15FF00;
  unsigned long tecla09 = 0xF609FF00;
  unsigned long teclaMais = 0xE718FF00;
  unsigned long teclaMenos = 0xAD52FF00;
  unsigned long teclaParar = 0xE31CFF00;

  //parametro
  DFPlayerMini_Fast myMP3;


void setup() {
  //Botões
  pinMode(bt01,INPUT_PULLUP);
  pinMode(bt02,INPUT_PULLUP);
  pinMode(bt03,INPUT_PULLUP);
  pinMode(bt04,INPUT_PULLUP);
  pinMode(btMais,INPUT_PULLUP);
  pinMode(btMenos,INPUT_PULLUP);
  pinMode(btParar,INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  //Receptor
  IrReceiver.begin(receptor);


  #if !defined(UBRR1H)
    mySerial.begin(9600);
    myMP3.begin(mySerial);
  #else
    Serial.begin(9600);
    myMP3.begin(Serial1);
  #endif

  myMP3.volume(30);
  delay(100);

}

void loop() {
  //Receptor IR 
  if (IrReceiver.decode())
{
   valorIR = IrReceiver.decodedIRData.decodedRawData;
   
   if (valorIR == tecla01){
      myMP3.play(1);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
   }

   if (valorIR == tecla02){
      myMP3.play(2);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
   }

   if (valorIR == tecla03){
      myMP3.play(3);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
   }

   if (valorIR == tecla04){
      myMP3.play(4);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
   }

   if (valorIR == tecla05){
      myMP3.play(5);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
   }

   if (valorIR == tecla06){
      myMP3.play(6);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
   }

   if (valorIR == tecla07){
      myMP3.play(7);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
   }

   if (valorIR == tecla08){
      myMP3.play(8);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
   }

   if (valorIR == tecla09){
      myMP3.play(9);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
   }

   if (valorIR == teclaMais){
      myMP3.incVolume();
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);
   }

   if (valorIR == teclaMenos){
      myMP3.decVolume();
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);
   }

   if (valorIR == teclaParar){
      myMP3.stop();
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);
   }

   IrReceiver.resume();
   digitalWrite(LED_BUILTIN, LOW);
}

//Push button
  estadoBt = digitalRead(bt01);
  if(estadoBt == LOW) {
    myMP3.play(1);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);    
  }

  estadoBt = digitalRead(bt02);
  if(estadoBt == LOW) {
    myMP3.play(2);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
  }

    estadoBt = digitalRead(bt03);
  if(estadoBt == LOW) {
    myMP3.play(3);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
  }
  
    estadoBt = digitalRead(bt04);
  if(estadoBt == LOW) {
    myMP3.play(4);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
  }

    estadoBt = digitalRead(btMais);
  if(estadoBt == LOW) {
    myMP3.incVolume();
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
  }

    estadoBt = digitalRead(btMenos);
  if(estadoBt == LOW) {
    myMP3.decVolume();
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
  }

    estadoBt = digitalRead(btParar);
  if(estadoBt == LOW) {
    myMP3.stop();
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
  }
  digitalWrite(LED_BUILTIN, LOW);
}
