#include <stdlib.h>
#include "Simon.h"
void sequenceGenerate(Game *x);
void gameInit () {
  sequenceGenerate(&Simon);
  //keeping track of sequence
  Serial.println ("Generating Sequence");
  for (int i = 0; i < 50; i++) {
    Serial.print (Simon.sequence[i]);
    Serial.print (" ");
    if ((i + 1) % 10 == 0) Serial.println();
  }
}

void sequenceGenerate(Game *x) {
  for (int i = 0; i < 50; i++) {
    x->sequence[i] = (enum ACTION)(rand() % 7);
  }
}
