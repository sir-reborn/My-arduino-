

#include "pitches.h"

const int SPEAKER=9;  //Speaker Pin

int notes[] = {
SO,MI,0,  RE,MI,SO,0,
LA,SO,MI,0,  RE,DO,0,
SO,MI,0,  RE,MI,SO,0,
LA,SO,MI,0,  RE,DO,0,
RE,MI,0,   DO,RE,0,
RE,MI,0, DO,LA
};


int times[] = {
 500,750,500, 500,500,750,500,
 500,500,750,500,   500,750,500,
 500,750,500, 500,500,750,500,
 500,500,750,500,   500,750,500,
  500,750,500,   500,750,500,
   500,750,500,   500,750
};


void setup()
{
 //Play each note for the right duration
 for (int i = 0; i < 39; i++)
 {
  tone(SPEAKER, notes[i], times[i]);
  delay(times[i]);
 }
}

void loop()
{
 //Press the reset button to play again.
}
