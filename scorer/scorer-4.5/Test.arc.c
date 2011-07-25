#define CREATE

#include "config.Definitions.h"

void main()
{

	//initialize();
	create_connect();
	enable_servos();
	armPosBlockStack1();
	clawStack1();
	create_drive(-75,-580);
	while(!black_button());
	//richardNav();
}
