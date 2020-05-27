//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i

/* complete the state machine. */

void Detect_Max_Amp()
{
    switch(detect_max_amp_state)
    {
        case DMAInit:
		maxAmp = 0; 
            break;
       
	case DMA_noEQ: 
	   if (Eq == 0) {
		detect_max_amp_state = DMA_noEQ; 
	   }
	   else if (Eq > 0){
		detect_max_amp_state = DMA_EQ; 
		maxAmp = Amp; 
	   }
	   break;


	case DMA_EQ: 
		if (Eq > 0) {
			detect_max_amp_state = DMA_EQ;

			if (Amp > maxAmp) {
				maxAmp = Amp; 
			}
		}
		else if (Eq == 0) {
			detect_max_amp_state = DMA_noEQ; 
		}
	 	break;   


        default:
            break;
    }
    switch(detect_max_amp_state)
    {
        case DMAInit:
            break;

	case DMA_noEQ:
	    maxAmp = 0;
	    break; 


        default:
            break;
    }
}
