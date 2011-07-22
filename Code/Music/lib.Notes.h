//Notes library

/*
Middle C is C4
A4 = 440 Hz
Speed of sound = 345m/s = 1130 ft/s == 770 miles/hr
*/

/*
Would it have been easier to use arrays in combonation with the equation above?
Someone please do that for me!
*/

#define c0 16.35
#define cs0 17.32
#define db0 17.32
#define d0 18.35
#define ds0 19.45
#define eb0 19.45
#define e0 20.60
#define f0 21.83
#define fs0 23.12
#define gb0 23.12
#define g0 24.50
#define gs0 25.96
#define ab0 25.96
#define a0 27.50 //Lowest a piano goes
#define as0 29.14
#define bb0 29.14
#define b0 30.87

int init_notes();//returns number of octaves initialized

float cb[];
float c [];
float cs[];

float db[];
float d [];
float ds[];

float eb[];
float e [];
float es[];

float fb[];
float f [];
float fs[];

float gb[];
float g [];
float gs[];

float ab[];
float a [];
float as[];

float bb[];
float b [];
float bs[];
//test it you might have trouble compiling with windows but it should work with linux
//just ignore the "...assumed to have one element" warnings
int init_notes(){
	int octaves = 10;
	int i = 2;
	
	for(cb[1] = b0 ; i < octaves; i++) cb[i] = cb[i-1]*2;	i = 1;
	for(c [0] = c0 ; i < octaves; i++) c [i] = c [i-1]*2;	i = 1;
	for(cs[0] = cs0; i < octaves; i++) cs[i] = cs[i-1]*2;	i = 1;
	
	for(db[0] = cs0; i < octaves; i++) db[i] = db[i-1]*2;	i = 1;
	for(d [0] = d0 ; i < octaves; i++) d [i] = d [i-1]*2;	i = 1;
	for(ds[0] = ds0; i < octaves; i++) ds[i] = ds[i-1]*2;	i = 1;
	
	for(eb[0] = ds0; i < octaves; i++) eb[i] = eb[i-1]*2;	i = 1;
	for(e [0] = e0 ; i < octaves; i++) e [i] = e [i-1]*2;	i = 1;
	for(es[0] = f0 ; i < octaves; i++) es[i] = es[i-1]*2;	i = 1;
	
	for(fb[0] = e0 ; i < octaves; i++) fb[i] = fb[i-1]*2;	i = 1;
	for(f [0] = f0 ; i < octaves; i++) f [i] = f [i-1]*2;	i = 1;
	for(fs[0] = fs0; i < octaves; i++) fs[i] = fs[i-1]*2;	i = 1;
	
	for(gb[0] = fs0; i < octaves; i++) gb[i] = gb[i-1]*2;	i = 1;
	for(g [0] = g0 ; i < octaves; i++) g [i] = g [i-1]*2;	i = 1;
	for(gs[0] = gs0; i < octaves; i++) gs[i] = gs[i-1]*2;	i = 1;
	
	for(ab[0] = gs0; i < octaves; i++) ab[i] = ab[i-1]*2;	i = 1;
	for(a [0] = a0 ; i < octaves; i++) a [i] = a [i-1]*2;	i = 1;
	for(as[0] = as0; i < octaves; i++) as[i] = as[i-1]*2;	i = 1;
	
	for(bb[0] = as0; i < octaves; i++) bb[i] = bb[i-1]*2;	i = 1;
	for(b [0] = b0 ; i < octaves; i++) b [i] = b [i-1]*2;	i = 1;
	for(bs[0] = c[1];i < octaves; i++) bs[i] = bs[i-1]*2;	i = 1;
	
	return i;
}
//
#define c1 32.70
#define cs1 34.65
#define db1 34.65
#define d1 36.71
#define ds1 38.89
#define eb1 38.89
#define e1 41.20
#define f1 43.65
#define fs1 46.25
#define gb1 46.25
#define g1 49.00
#define gs1 51.91
#define ab1 51.91
#define a1 55.00
#define as1 58.27
#define bb1 58.27
#define b1 61.74
//
#define c2 65.41
#define cs2 69.30
#define db2 69.30
#define d2 73.42
#define ds2 77.78
#define eb2 77.78
#define e2 82.41
#define f2 87.31
#define fs2 92.50
#define gb2 92.50
#define g2 98.00
#define gs2 103.83
#define ab2 103.83
#define a2 110.00
#define as2 116.54
#define bb2 116.54
#define b2 123.47
//
#define c3 130.81
#define cs3 138.59
#define db3 138.59
#define d3 146.83
#define ds3 155.56
#define eb3 155.56
#define e3 164.81
#define f3 174.61
#define fs3 185.00
#define gb3 185.00
#define g3 196.00
#define gs3 207.65
#define ab3 207.65
#define a3 220.00
#define as3 233.08
#define bb3 233.08
#define b3 246.94
//
#define c4 261.63
#define cs4 277.18
#define db4 277.18
#define d4 293.66
#define ds4 311.13
#define eb4 311.13
#define e4 329.63
#define f4 349.23
#define fs4 369.99
#define gb4 369.99
#define g4 392.00
#define gs4 415.30
#define ab4 415.30
#define a4 440.00
#define as4 466.16
#define bb4 466.16
#define b4 493.88
//
#define c5 523.25
#define cs5 554.37
#define db5 554.37
#define d5 587.33
#define ds5 622.25
#define eb5 622.25
#define e5 659.26
#define f5 698.46
#define fs5 739.99
#define gb5 739.99
#define g5 783.99
#define gs5 830.61
#define ab5 830.61
#define a5 880.00
#define as5 932.33
#define bb5 932.33
#define b5 987.77
//
#define c6 1046.50
#define cs6 1108.73
#define db6 1108.73
#define d6 1174.66
#define ds6 1244.51
#define eb6 1244.51
#define e6 1318.51
#define f6 1396.91
#define fs6 1479.98
#define gb6 1479.98
#define g6 1567.98
#define gs6 1661.22
#define ab6 1661.22
#define a6 1760.00
#define as6 1864.66
#define bb6 1864.44
#define b6 1975.53
//
#define c7 2093.00
#define cs7 2217.46
#define db7 2217.46
#define d7 2349.32
#define ds7 2489.02
#define eb7 2489.02
#define e7 2637.02
#define f7 2793.83
#define fs7 2959.96
#define gb7 2959.96
#define g7 3135.96
#define gs7 3322.44
#define ab7 3322.44
#define a7 3520.00
#define as7 3729.31
#define bb7 3729.31
#define b7 3951.07
//
#define c8 4186.01 //Highest a piano goes
#define cs8 4434.92
#define db8 4434.92
#define d8 4698.64
#define ds8 4978.03
#define eb8 4978.03
