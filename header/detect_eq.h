//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i
static unsigned char j = 0;


/*complete the state machine*/

void Detect_EQ()
{
    switch(detect_eq_state)
    {
        case DEQInit:
            //init variable(s) here.
	    Amp = 0;
	    Eq = 0;
	    Dir = 0;
	    detect_eq_state = noEQ; 
            break;


	case noEQ:
	    if (Amp == 0) {
		detect_eq_state = noEq;
	    }
	    else if (Amp > 0) {
		detect_eq_state = EQdetected; 
		j = 0;
	    }
	    break;


	case EQdetected: 
	    if (j >= 10 && (Amp == 0))
	    {
		detect_eq_state = noEQ;
	    }
	    else { //else not 10 sec of 1 input 
		if (Amp == 0) {
			j++;
		}
		else {
		     j = 0;
		}
	    }
	    break; 

        default:
            detect_eq_state = DEQInit;
            break;
    }
    switch(detect_eq_state)
    {
        case DEQInit:
            break;

	case noEQ: 
		Eq = 0;
		Dir = tmpA & 0x07;
		Amp = tmpA >> 3; 		
	    	break;

	case EQdetected:
		Eq = 1;
		Dir = tmpA & 0x07;
		Amp = tmpA >> 3; 		
	    break; 
        default:
            break;
    }
}
