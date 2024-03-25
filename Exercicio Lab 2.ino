#define ledVermelho (1<<PD0) //0b00000001
#define ledAmarelo (1<<PD1)  //0b00000010 necessário fazer pull down
#define ledAzul (1 << PD2)   // necessário fazer pull down
#define BOTAO (1<<PD3)

int main() {
    // declaração de pinos do Portal B - Pino 0 (saída), as entradas não precisam
    DDRD = ledVermelho | ledAzul | ledAmarelo; // 0b00000001 = 1<<0
    DDRC = 0;
    DDRB = 0;
 
    // declaração dos circuitos de pull up (joga o NL do pino para VCC) - PULL DOWN SE FAZ EM CIRCUITOS (joga o NL do pino para zero)
    PORTB = 0;
    PORTD |= (BOTAO); // Habilitar PULL-UP no PD5

    PORTD |= (ledVermelho);
 
    // definindo variáveis para leitura
    unsigned short int lerBotao,estado;

    for (;;) // Super Loop
    {  
        
        if ((PIND & BOTAO) == 0) { // Botão está pressionado ?
            PORTD &= ~( ledVermelho); // PD7 -> LOW 

            PORTD |= ( ledAmarelo);   // PD7 -> HIGH       
            _delay_ms(500); 
            PORTD &= ~(ledAmarelo); // PD7 -> LOW    
            _delay_ms(500);

            PORTD |= (ledAmarelo); // PD7 -> LOW 

            
            _delay_ms(500);
            PORTD &= ~(ledAmarelo); // PD7 -> LOW 
            _delay_ms(500);
            PORTD |= (ledAmarelo);  // PD7 -> HIGH
            _delay_ms(500);
            PORTD &= ~(ledAmarelo); // PD7 -> LOW 
            
            _delay_ms(500);
            
            PORTD |= (ledAmarelo);  // PD7 -> HIGH
            _delay_ms(500);
            PORTD &= ~(ledAmarelo); // PD7 -> LOW 
            estado = HIGH;
            PORTD |= (ledAzul);
            while ((PIND & BOTAO)==BOTAO){
              PORTD |= (ledAzul);
              //Serial.println("D")
            }
            PORTD &= ~(ledAzul);
            PORTD |= (ledVermelho); 
            _delay_ms(500);
        }
    }

    return 0;
}
