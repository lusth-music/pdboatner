#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
#define base "piano/bright_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "piano";
char *PROGRAM_VERSION = "0.01";

static int last = 0;

int chorusChords(int instrument, int octave){

    int progression[18] = {1,1,3,3,4,4,5,5,1,1,3,3,4,4,5,5,4,5};

    int i;
    for(i = 0; i < 18; i++){

        switch(progression[i]){
        case 1:
            setAmplitude(0.30);
            c(1, Qd, instrument, octave);
            setAmplitude(0.25);
            c(1, Qd, instrument, octave);
            c(1, Q, instrument, octave);

            break;
        case 3:
            setAmplitude(0.30);
            ci6(3, Qd, instrument, octave); 
            setAmplitude(0.25);
            ci6(3, Qd, instrument, octave); 
            ci6(3, Q, instrument, octave); 

            break;
        case 4:
            setAmplitude(0.30);
            ci1(4, Qd, instrument, octave-1);
            setAmplitude(0.25);
            ci1(4, Qd, instrument, octave-1);
            ci1(4, Q, instrument, octave-1);

            break;
        case 5:
            setAmplitude(0.30);
            ci1(5, Qd, instrument, octave-1);
            setAmplitude(0.25);
            ci1(5, Qd, instrument, octave-1);
            ci1(5, Q, instrument, octave-1);

            break;
        }
    }
    
    setAmplitude(0.30);
    c(6, Qd, instrument, octave-1);
    setAmplitude(0.25);
    ci1(5, Qd, instrument, octave-1);
    ci1(5, Q, instrument, octave-1);

    setAmplitude(0.30);
    ci1(4, Qd, instrument, octave-1);
    setAmplitude(0.25);
    ci1(4, Qd, instrument, octave-1);
    ci1(4, Q, instrument, octave-1);
  
    setAmplitude(0.30);
    ci1(4, Qd, instrument, octave-1);
    setAmplitude(0.25);
    ci1(4, Qd, instrument, octave-1);
    ci1(4, Q, instrument, octave-1);
  

    setAmplitude(0.30);
    cchord(5, Qd, instrument, octave-1, "Osx"); 
    setAmplitude(0.25);
    ci1(5, Qd, instrument, octave-1); 
    ci1(5, Q, instrument, octave-1); 

    setAmplitude(0.30);
    c(1, Qd, instrument, octave);
    setAmplitude(0.25);
    c(1, Qd, instrument, octave);
    c(1, Q, instrument, octave);

    setAmplitude(0.30);

    return 1;
}

int verseChords(int instrument, int octave){
    setAmplitude(0.30);
    c(1, Qd, instrument, octave);
    setAmplitude(0.25);
    c(1, Qd, instrument, octave);
    c(1, Q, instrument, octave);

    setAmplitude(0.30);
    ci1(5, Qd, instrument, octave-1); 
    setAmplitude(0.25);
    ci1(5, Qd, instrument, octave-1); 
    ci1(5, Q, instrument, octave-1); 
    
    
    setAmplitude(0.30);
    ci1(4, Qd, instrument, octave-1);
    setAmplitude(0.25);
    ci1(4, Qd, instrument, octave-1);
    ci1(4, Q, instrument, octave-1);
    
    setAmplitude(0.30);
    ci1(5, Qd, instrument, octave-1); 
    setAmplitude(0.25);
    ci1(5, Qd, instrument, octave-1); 
    ci1(5, Q, instrument, octave-1); 

    setAmplitude(0.30);

    return 1;
}

int
main()
    {
    int instrument;
    int octave = 4;

    songInit();

    instrument = readScale(dir,base);

    setTempo(130);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.3);

    openOutput("piano.rra",0,0);


//    verseChords(instrument, octave);
    chorusChords(instrument, octave);


    closeOutput();
    
    return 0;
    }
