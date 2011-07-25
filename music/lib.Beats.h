//Beats library
//No need for a time signature?
#define whole 1
#define half 2
#define quarter 4
#define eighth 8
#define sixteenth 16
#define thirtysecond 32
#define sixtyfourth 64

float tepo;

void tempo(float temp); //Tempo
void n(float note, float duration); //Single note
void r(float duration); //Rest

void tempo(float temp)
{
	tepo = temp;
}

void n(float note, float duration)
{
	float val = (((60 / tepo) / duration) * 4000);
	Beep(note, val);
}

void r(float duration)
{
	float val = (((60 / tepo) / duration) * 4000);
	Beep(0, val);
}
