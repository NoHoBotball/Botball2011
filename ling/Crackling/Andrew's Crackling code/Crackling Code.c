#include "lib.Strategy selection.h"
#include "lib.Which Side.h"

int main() //Remember to write everything for left side of botguy!
{
	whichSide(); //Pick what side the Crackling is on. Code should be written for left side of board.
	initialize(); //Initialization program
	strategySelect(); //Choose what our Crackling will do for the game
	wait_for_light(light); //Waits for light to start
	runStrategy(); //Runs the strategy that the user selects
}
