#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
#define base "bass-acoustic/adrian-drawn_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "bass";
char *PROGRAM_VERSION = "0.01";

static float soft = 0.2;
static float full = 0.30;

void intro(int instrument, int octave){
    setAmplitude(soft);
    n(1, W, instrument, octave, 0);
    n(5, W, instrument, octave, 0);
    n(6, W, instrument, octave, 0);
    n(4, W, instrument, octave, 0);
    setAmplitude(full);
}

void verse(int instrument, int octave){
    int i;
    for(i = 0; i < 3; i++){
        n(1, W, instrument, octave, 0);

        n(5, W, instrument, octave, 0);

        n(6, Hd, instrument, octave, 0);
        n(5, Q, instrument, octave, 0);

        n(4, Hd, instrument, octave, 0);
        n(2, Q, instrument, octave, 0);
    }

    n(1, W, instrument, octave, 0);

    n(4, W, instrument, octave, 0);

    n(5, Hd, instrument, octave, 0);
    n(1, Q, instrument, octave+1, 0);

    n(7, W, instrument, octave, 0);
}

// final- 1 means final, 0 means normal
void chorus(int instrument, int octave, int final){
    int i;

    for(i = 0; i < 2; i++){
        n(1, W, instrument, octave, 0);

        n(1, Hd, instrument, octave, 0);
        n(2, Q, instrument, octave, 0);
    
        setAmplitude(soft); 
        n(3, W, instrument, octave, 0); setAmplitude(full);
        n(7, W, instrument, octave-1, 0);

        n(6, W, instrument, octave-1, 0);

        n(1, H, instrument, octave, 0);
        n(6, H, instrument, octave-1, 0);

        n(5, Hd, instrument, octave-1, 0);
        n(1, Q, instrument, octave, 0);
        
        switch(i){
        case 0:
            n(7, W, instrument, octave-1, 0);
            break;
        case 1:
            n(7, Hd, instrument, octave-1, 0);
            n(5, Q, instrument, octave-1, 0);
            break;
        }
    }


    n(4, W, instrument, octave-1, 0);

    n(5, W, instrument, octave-1, 0);

    n(6, Qd, instrument, octave-1, 0);
    n(5, H + I, instrument, octave-1, 0);

    n(4, W, instrument, octave-1, 0);

    n(4, W, instrument, octave-1, 0);

    n(5, W, instrument, octave-1, 0);

    
    if(final==1){
        setAmplitude(soft);
        n(1, Hd, instrument, octave, 0);
    } else {
        n(1, W, instrument, octave, 0);

        n(7, W, instrument, octave-1, 0);
    }
}


void bridge(int instrument, int octave){
    
    int progression[6] = {4,5,6,7,6,7};
    int i;
    for(i = 0; i < 6; i++){
        n(progression[i], I, instrument, octave, 0);
        forwards(Q);
        n(progression[i], I, instrument, octave, 0);
        forwards(Q);
        n(progression[i], I, instrument, octave, 0);
        forwards(I);
    }

    n(1, I, instrument, octave+1, 0);
    forwards(Q);
    n(1, I, instrument, octave+1, 0);
    forwards(Q);
    n(1, Q, instrument, octave+1, 0);

    setAmplitude(soft);
    n(5, W, instrument, octave, 0);
    
    n(5, W, instrument, octave, 0);
    setAmplitude(full);
}

int
main()
    {
    int instrument;
    int octave = 2;

    songInit();

    instrument = readScale(dir,base);

    setTempo(130);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.9999);
    setAmplitude(full);

    openOutput("bass.rra",0,0);


    intro(instrument, octave);
    verse(instrument, octave);
    chorus(instrument, octave, 0);
    verse(instrument, octave);
    chorus(instrument, octave, 0);
    bridge(instrument, octave);
    verse(instrument, octave);
    chorus(instrument, octave, 1);


    closeOutput();
    
    return 0;
    }
