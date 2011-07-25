//Music library

#include "lib.Notes.h"
#include "lib.Beats.h"

/*
Make music by typing in n(note, duration);
Notes are in format [note][sharp/flat][octave]
For example, C#2 would be written as cs2, and Db2 would be written as db2

Duration can be written as the word of the duration of a specific note 
Ex. whole, half, quarter, etc.
It can also be written as 1 for whole, 2 for half, 4 for quarter, etc.

Make sure to make function and function prototypes for each new song

Songs should be in this format:

void song_name()
{
	tempo(60); //Change it to correct tempo
	n(C5, 4); //Will play a C5 quarter note
	//Add more notes as needed
}

*/

void mister_sandman();
void trololo();
void we_are_the_champions();

void mister_sandman()
{
	tempo(110);
	int i;
	for (i = 0; i < 2; i++)
	{
		n(c5, 8);
		n(e5, 8);
		n(g5, 8);
		n(b5, 8);
		n(a5, 8);
		n(g5, 8);
		n(e5, 8);
		n(c5, 8);
		n(d5, 8);
		n(f5, 8);
		n(a5, 8);
		n(c6, 8);
		n(b5, 4);
		r(4);
	}
	n(f5, 8);
	n(g5, 8);
	n(a5, 8);
	n(g5, 4);
	r(4);
	n(a5, 8);
	n(a5, 8);
	n(g5, 8);
	n(a5, 4);
}

void trololo()
{
	tempo(92);
	n(c5, 0.75);
	n(g4, 8);
	n(f4, 8);
	n(g4, 0.75);
	n(c4, 8);
	n(d4, 8);
	n(e4, 2.5);
	n(g4, 2.5);
	n(e4, 8);
	n(d4, 2);
	n(f4, 32);
	n(g4, 32);
	n(a4, 32);
	n(b4, 32);
	n(c5, 0.75);
	
}

void we_are_the_champions()
{
	tempo(104);
	n(f5, 2.5); //We---
	n(e5, 8); //are
	n(f5, 8); //the
	n(e5, 4); //cham-
	n(c5, 3.5); //pions
	n(a4, 8); //my
	n(d5, 4); //friend---
	n(a4, 2.5); //---
	r(4.5);
	n(c5, 8); //And
	n(f5, 2.5); //we'll---
	n(g5, 8); //keep
	n(a5, 8); //on
	n(c6, 4); //fight-
	n(a5, 3.5); //ing
	n(d5, 8); //till
	n(e5, 8); //the
	n(d5, 2.5); //end---
	r(3.75);
	n(d5, 3); //We
	n(c5, 4); //are
	n(d5, 8); //the
	n(c5, 3); //cham-
	n(bb4, 3); //pions
	//
	n(bb5, 3); //We
	n(a5, 4); //are
	n(bb5, 8); //the
	n(a5, 3); //cham-
	n(g5, 3); //pions
	//
	n(a5, 3); //No
	n(f5, 4); //time
	n(bb5, 8); //for
	n(a5, 3); //los-
	n(f5, 4); //ers
	n(bb5, 8); //'cause
	n(ab5, 3); //we
	n(f5, 4); //are
	n(bb5, 8); //the
	n(ab5, 3); //cham-
	n(f5, 3); //pions
}
