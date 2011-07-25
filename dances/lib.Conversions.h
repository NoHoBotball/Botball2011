//Library -- Conversion
//Conversion

#define LIB_CONVERSIONS
#define PI (3.14)
/*	
/	Description	:
/		-This File contains all Conversion funcions
/
/	Written and Maintained By:
/		-Jae Kim		02/2011-
/		
/	
*/

float mmtoinches(float mm);
float inchestomm(float inches);
float mm_to_inches(float mm);
float inches_to_mm(float inches);

float degs_to_rads(float degs);
float rads_to_degs(float rads);

float vel_to_angvel(float radius, float vel);
float angvel_to_vel(float radius, float angvel);

//Funcion Defintions
float inchestomm(float inches)
{
	float mm;
	mm = (inches*25.4);
	return mm;
}

float mmtoinches(float mm)
{
	float inches;
	inches = (mm/25.4);
	return inches;
}
float inches_to_mm(float inches)
{
	float mm;
	mm = (inches*25.4);
	return mm;
}

float mm_to_inches(float mm)
{
	float inches;
	inches = (mm/25.4);
	return inches;
}

float degs_to_rads(float degs)
{
	float rads;
	rads = (degs*360/(2*PI));
	return rads;
}

float rads_to_degs(float rads)
{
	float degs;
	degs = (rads*(2*PI)/360);
	return degs;
}

float vel_to_angvel(float radius, float vel)
{
	float angvel;
	angvel = (vel/radius);
	return angvel;
}

float angvel_to_vel(float radius, float angvel)
{
	float vel;
	vel  = (angvel*radius);
	return angvel;
}
