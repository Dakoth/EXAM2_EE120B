
//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i
static unsigned char i, H, L; 

//Shared variable PingO
/*complete the state machine*/

void Ping()
{
    switch(ping_state)
    {
        case PInit:
		i = 0;
		H = 1;
		L = 9;
		ping_state = High;
            break;


	case High: 
	    if (i <= H) { 
		ping_state = High; 
	    }
	    else {
		i = 0;
		ping_state = Low;
	    }
	    break;

	case Low: 
	    if (i <= L) { 
		ping_state = Low; 
	    }
	    else {
		i = 0;
		ping_state = High;
	    }
	    break;

        default:
            ping_state = PInit;
            break;
    }
    switch(ping_state)
    {
        case PInit:
            break;

	case High: 
	    i++;
            PingO = 1;
	    break;

	case Low: 
	    i++; 
	    PingO = 0;
	    break;

        default:
            break;
    }
}
