#define NF (1 << PD1)
#define NA (1 << PD2)
#define MOTOR (1 << PD3)
#define ALARME (1 << PD4)
#define SENSOR (1 << PD0)
int main(){
  
  DDRD = DDRD | MOTOR;
  DDRD = DDRD | ALARME;
  PORTD = PORTD | NF;
  PORTD = PORTD & ~(MOTOR);
  PORTD = PORTD & ~(ALARME);

  for(;;){
    
    if((PIND & NA) == NA){ //0b00000100
      PORTD = PORTD | MOTOR;
    }
    if((PIND & NF) == 0){
      PORTD = PORTD & ~(MOTOR);
    }
    if((PIND & SENSOR) == 0){
      PORTD = PORTD | ALARME;
    }
    if(((PIND & SENSOR) == 1) & ((PIND & NA) == NA)){
      PORTD = PORTD & ~(ALARME);
    }
  }

}