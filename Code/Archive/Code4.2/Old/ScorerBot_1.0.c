/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/
int light_port;
float dist1;//dist1 == the distance (in mm) the create must go to be clear of towers
int trn_spd1;//turn speed 1 (in mm/s) 
int drv_spd1;//drive speed 1 (in mm/s)
float std_lag;//standard lag time for updates
int sensor_claw_touch_front;//digital touch sensor 0 is on front of claw

/*Function prototypes below*/
int calibration();//calibration function
int side();//function to determine what side create is on.  Requires user input.

int position_scorer(int side);//side is 0 for right, 1 for left


int main()
{
	
	//variable declarations go here.
	int side = side();
	
	
	// uncomment the line below anf put 1s in the appropriate places if using floating sensors (ET and sonar)
	//set_each_analog_state(0,0,0,0,0,0,0,0);// This line sets analog ports to be pullup (0) or floating (1)
	
	// uncomment the line below to have the rest of the program wait for the starting light to turn on
	//wait_for_light(port_number);//replace "port_number" with the analog port number into which the light sensor is connected
	wait_for_light(light_port);
	shut_down_in(200);
	position_scorer(side);
	// uncomment the line below to have a function run for a specified amount of seconds
	//run_for(num_secs, function_name);//replace num_secs with the amount of time to run and function_name with your function's name
}

/*Function definitions go below.*/
int calibration(){
	
int side(){
	printf("Is create on right or left?\n");
	printf("If on right input A\n");
	printf("If on left input B\n");
	while (a_button == 0 && b_button == 0){
		if (a_button == 1){//if on right press 'a_button' and function returns 0
			return(0);
		}
		else if (b_button == 1){//if on left press 'b_button' and function returns 1
			return(1);
		}
		
int position_scorer(int side){
	create_safe();
	if (side == 0){
		turn_create(trn_spd1,-90);//turn CW towards luggage
		move_create(drv_spd1,dist1);//drive forward dist1 at drvspd1 over luggage
		turn_create(trn_spd1,90);//turn CCW towards opposite side
		move_create(drv_spd2,0);//drive forward at drvspd2 until towards opposite hit pvc
		while (get_create_rbump(std_lag) == 0 || get_create_lbump(std_lag) == 0){
			sleep(0.1);
		}
		create_stop();//stop create
		turn_create(trn_spd1,90);//turn towards center
		move_create(drv_spd2,0);//drive forward at drvspd2 towards center until hit pvc
		while (get_create_rbump(std_lag) == 0 || get_create_lbump(std_lag) == 0){
			sleep(0.1);
		}
		create_stop();//stop create
		turn_create(trn_spd1,90);//turn towards towers
		move_create(drv_spd1,0);//drive forward at drv_spd1 until touch sensor on front of claw is 'on'
		while (sensor_claw_touch_front == 0){
			sleep(0.1);
		}
		create_stop();//stop create
	}
	else if (side == 1){
		
	}
