// C++ code
//

int pinLed[9] = {13,12,11,10,9,8,7,6,5};

// variavel para controlar qual led está aceso
int led;

void setup(){

  	int x;
  
    for (x = 0; x <= 8; x++) { // x = 0 é a primeira posição do array, ele vai repetir até que x seja menor ou igual a 6, de quanto em quanto o x aumenta
    pinMode(pinLed[x], OUTPUT);
  } 
}

void loop(){
  
  for (led = 0; led <= 6; led++){ // led = 0, se led for <= a 6, adiciona 1, 1 no valor da variavel led, acende um led de cada vez   
    delay(200);
  	digitalWrite(pinLed[led], HIGH);
    
    // vai piscar o led pra avisar que ta carregando
    digitalWrite(pinLed[7], HIGH);
    delay(190);
    digitalWrite(pinLed[7], LOW);
  }
  
  // 6 não é maior que zero(true), por isso -1
  for (led = 6; led >= 0; --led){ // led = 6, se led for >= que 0, tira 1, 1 a menos no valor da variavel led, desliga um led de cada vez   
    delay(200);
  	digitalWrite(pinLed[led], LOW);
    
    // vai piscar o led pra avisar que ta descarregando
    digitalWrite(pinLed[8], HIGH);
    delay(190);
    digitalWrite(pinLed[8], LOW);
  }

}