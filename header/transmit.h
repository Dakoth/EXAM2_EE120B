//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i



/*complete the state machine*/

void Transmit()
{
    switch(transmit_state)
    {
        case TInit:
		transmit_state = Output; 
            break;

	case Output: 
	    transmit_state = Output;
        default:
            transmit_state = TInit;
            break;
    }
    switch(transmit_state)
    {
        case TInit:
            break;
	case Output: 
	    tmpB = (PingO) | (Eq << 1) | (ZC << 2) | (maxAmp << 3);  
        default:
            break;
    }

}
