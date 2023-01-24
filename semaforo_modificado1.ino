// C++ code
//
// semaforo
int pinRed = 10;
int pinYellow = 9;
int pinGreen = 8;

int pinbotao = 7;

int faseSemaforo;

int pedestreRed = 3;
int pedestreGreen = 2;

int estadobtn;
int pressionado;

// pra fazer o semaforo do caso 4 ficar piscando
int piscagem;

void setup(){
  
pinMode(pinRed, OUTPUT);
pinMode(pinYellow, OUTPUT);
pinMode(pinGreen, OUTPUT);

pinMode(pinbotao, INPUT);

pinMode(pedestreRed, OUTPUT);
pinMode(pedestreGreen, OUTPUT);
  
faseSemaforo = 1;
  // vai ser usado para ler se o botao foi pressionado e vai impedir de o botao ler muito rapido
pressionado = digitalRead(pinbotao);
  
  piscagem = 0;
  
}


void loop(){
  
  estadobtn = digitalRead(pinbotao);
  
	// botão e sua ação
  if((estadobtn == HIGH) && (pressionado == LOW)){ // o botao vai considerar um toque
    if (faseSemaforo < 4){
    ++faseSemaforo;
    }else {
    	faseSemaforo = 1;
    }
  }
  pressionado = estadobtn;
  
  
  // semaforo
  switch (faseSemaforo) {
  	case 1:
    digitalWrite(pinRed, HIGH);
    digitalWrite(pinYellow, LOW);
    digitalWrite(pinGreen, LOW);
    
    
    digitalWrite(pedestreRed, HIGH);// parte dos pedestres
    digitalWrite(pedestreGreen, LOW);
    break;
    
    case 2:
    digitalWrite(pinRed, LOW);
    digitalWrite(pinYellow, HIGH);
    digitalWrite(pinGreen, LOW);
    
    digitalWrite(pedestreRed, HIGH);
    digitalWrite(pedestreGreen, LOW);
    break;
    
    case 3:
    digitalWrite(pinRed, LOW);
    digitalWrite(pinYellow, LOW);
    digitalWrite(pinGreen, HIGH);
  
   digitalWrite(pedestreGreen, HIGH);
   digitalWrite(pedestreRed, LOW);
   break;
    
   case 4:
    digitalWrite(pinRed, LOW);
    digitalWrite(pinYellow, LOW);
    digitalWrite(pinGreen, HIGH);

    while (piscagem < 20) {
      digitalWrite(pedestreGreen, HIGH);
      delay(500);
      digitalWrite(pedestreGreen, LOW);
      ++piscagem;
      delay(200);
    }
    
    faseSemaforo = 1;
 
   digitalWrite(pedestreRed, LOW);
   break;
    
  }
}