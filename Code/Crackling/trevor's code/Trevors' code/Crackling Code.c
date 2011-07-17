//#include "lib.Assignments.h"
#include "lib.Strategy selection.h"
#include "lib.Which Side.h"
//#include "lib.Movement.h"
//#include "lib.Rotation.h"
//#include "lib.Advanced movement.h"
//#include "lib.Strategies.h"
int main() //Remember to write everything for left side of botguy!
{
	hold_airplanes();
	whichSide(); //Pick what side the Crackling is on. Code should be written for left side of board.
	strategySelect(); //Choose what our Crackling will do for the game
	//wait_for_light(light); //Waits for light to start
	runStrategy(); //Runs the strategy that the user selects
}
