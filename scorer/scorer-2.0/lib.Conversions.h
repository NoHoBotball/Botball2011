//Library -- Conversion
//Conversion

#define LIB_CONVERSIONS
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
