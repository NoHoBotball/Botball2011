#include "lib.Assignments.h"
#include "lib.Which Side.h"
#include "lib.Strategy selection.h"
#include "lib.Movement.h"
#include "lib.Rotation.h"
#include "lib.Advanced movement.h"
#include "lib.Strategies.h"

int main() //Remember to write everything for left side of botguy!
{
	
	/*whichSide(); //Pick what side the Speedling is on. Code should be written for left side of board, will mirror movement if on right
	forwardT(500,1);
	reverseT(500,1);
	forward(200);
	sleep(1);
	stop();
	spinCW_time(200,5);
	spinCCW_time(200,5);
	spinCW_time(800,5);
	spinCCW_time(800,5);
	spinCW_degrees(300, 360); 
	sleep(1);
	spinCCW_degrees(300, 360); //doesnt work?
	sleep(1);
	spinCW_degrees(300, 180);
	sleep(1); 
	spinCCW_degrees(300, 180);
	sleep(1);
	spinCW_degrees(300, 90);
	sleep(1);
	spinCCW_degrees(300, 90);
	sleep(5);
	spinCW_degrees(700, 90);
	sleep(1);
	spinCCW_degrees(700, 90);
	sleep(1);
	strategySelect(); //Choose what our Speedling will do for the game
	//wait_for_light(light); //Waits for light to start
	//runStrategy(); //Runs the strategy that the user selects
	*/
	
	
	
	
	enable_servos();
	claw_up();
	whichSide(); //Pick what side the Speedling is on. Code should be written for left side of board, will mirror movement if on right
	
	
	//THE WAIT FOR LIGHT IS IN THE BORDERCROSS STRATEGY
	
	strategySelect(); //Choose what our Speedling will do for the game
	
	
	/*while(1) {
	spinCCW_90();
	sleep(1);
	*/
	
	run_strategy(strategy);
	} 
