/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
#define CREATE
#include "config.Definitions.h"

int main()
{
	create_connect();
	create_drive(300,9280);
	sleep(1);
	create_drive(-300,9280);
	sleep(1);
}

/*Function definitions go below.*/
