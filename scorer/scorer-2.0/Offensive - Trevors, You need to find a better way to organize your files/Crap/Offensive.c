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
	int threshold = 512; 
	int high = 600;
	int low = 400;
	while (analog10(1) < threshold) {
		mav(0,low); mav(3,low);
	}
	while (analog10(2) < threshold) {
		mav(0,-low); mav(3,low); 
	}
	while (analog10(1) < threshold, analog10(2) < threshold) { 
		mav(0,low); mav(3,low);
		}
	//get over both pvc pipes possibly make loner or do two sequences to make more accuarte?
		
		if (bumpsensor(1) == 1) { 
		Move(3 sec)
		if (black_button()!=0) break; }
	
		while (analog10(1) <= threshold) {
			mav(0, high); mav(3, low);
			if (black_button()!=0) break; }

			ao();
	//sticky your code is shit and doesnt work
			
			
// Train the camera so that it recognizes a red colored
// object for color channel 0
{ 
  int x, y, color=0;  
// set up for color channel 0 (red)
  while (black_button() == 0) 
//run till button is pressed
    { 
      track_update();
// process the most recent image
      if (track_count(color) > 0)
        { 
// get  x, y for the biggest blob the channel sees
           x = track_x(color,0); y = track_y(color,0);    
           printf("Biggest blob at (%d,%d)\n",x,y);
		while (track_x(color,0) != 0) {
			//try to get x,y to center of the camera
		
			while( track_x(color, 0) > 84) (
				mav(0, 750) // if its to the right go left more
				mav(1, 850) // it slows down one wheel and speeds up the other to veer left
			)
			while (track_x(color,0) < 75) { 
				mav(0,850)
				mav(1,750)// does the opposite, runs towards the right to adjust
				}
			}
        {
   else
        { printf("No color match in Frame\n"); }
      
sleep(0.2);  // give print time to register
    }
  printf("Program is done.\n");
}


			//CAMERA CODE---	
			//digital(8) will be the port 
			while (digital(8) == 1 && 
		
			}

/*Function definitions go below.*/
