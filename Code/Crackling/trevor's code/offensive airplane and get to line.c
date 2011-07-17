/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/
/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
int main()
{
	//wait_for_light();
	//run_for(117);
	int l=0;
	while (l<2) {
		if (analog(0) < 100 /*line light value*/ )
		{	
			l=l+1;
		}
		forward(500);
	}
	//drop_airplanes(); //needs to be written
	reverseT(500,1);
	spinCW_degrees(500, 180);
	//while the line sensor that should detect the diagonal line first is over white
	while(){
		forward(600);
	}
	Turn_Left();
	toTape();
	//run the get to line function from before, wait for about 20 seconds, needs to be tested.
	
}

/*Function definitions go below.*/
