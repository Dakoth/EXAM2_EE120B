/*	Author: agonz250
 *	Lab Section:
 *  Exam #2
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
#include "timer.h"

/* SM state declarations --- fill in as needed */
typedef enum ping_states { PInit, High, Low                                         } ping_states;
typedef enum detect_eq_states { DEQInit, noEQ, EQdetected                                   } detect_eq_states;

typedef enum detect_max_amp_states { DMAInit, DMA_noEQ, DMA_EQ
} detect_max_amp_states; 
typedef enum detect_zc_states { DZCInit,                                    } detect_zc_states;
typedef enum transmit_states {TInit, Output } transmit_states;

/* shared variables --- fill in as needed */
unsigned char tmpA = 0x00; 
unsigned char PingO;

unsigned char Amp, Dir, Eq; 

unsigned ZC, dir1, dir2; 


unsigned char maxAmp; 

unsigned char tmpB = 0x00;

/* state variables --- do not alter */
ping_states ping_state;
detect_eq_states detect_eq_state;
detect_max_amp_states detect_max_amp_state;
detect_zc_states detect_zc_state;
transmit_states transmit_state;

/* SM definitions --- complete each task as a SM in the appropriate file.
 * Alternatively, you can remove the #include statement and insert your
 *   SM implementation directly. 
 */
#include "ping.h"
#include "detect_eq.h"
#include "detect_max_amp.h"
#include "detect_zc.h"
#include "transmit.h"


/* main function --- do not alter */
int main(void) {
    /* DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;

    // Common period for all tasks set to 100ms
    TimerSet(100);
    TimerOn();

    // init state vars
    ping_state = PInit;
    detect_eq_state = DEQInit;
    detect_max_amp_state = DMAInit;
    detect_zc_state = DZCInit;
    transmit_state = TInit;

    while (1) {
	tmpA = ~PINA; 
        Ping();
        Detect_EQ();
        Detect_Max_Amp();
        Detect_ZC();
        Transmit();


	PORTB = tmpB; 
        while (!TimerFlag) { }
        TimerFlag = 0;
    }
    return 1;
}
