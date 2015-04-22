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

    int progression[16] = {1,1,3,3,4,4,5,5,1,1,3,3,4,4,5,5};

    int i;
    for(i = 0; i < 16; i++){

        switch(progression[i]){
        case 1:
            n(1, Qd, instrument, octave - 1, 0); 
            c(1, Q, instrument, octave);      
            b(1, Qd, instrument, octave, "x--", "-x-", "--x", SX);

            break;
        case 3:
            n(3, Qd, instrument, octave - 1, 0); 
            cchord(3, Q,  instrument, octave, "xxY");
            b     (3, Qd, instrument, octave, "--Y", "x--", "-x-", SX);

            break;
        case 4:
            n(4, Qd, instrument, octave - 1, 0);
            cchord(4, Q, instrument, octave-1, "Xxx");
            b     (4, Qd, instrument, octave-1, "-x-", "--x", "X--", SX);

            break;
        case 5:
            n(5, Qd, instrument, octave - 1, 0);
            cchord(5, Q, instrument, octave-1, "Xxx");
            b     (5, Qd, instrument, octave-1, "-x-", "--x", "X--", SX);

            break;
        }
    }

    float volumeFull = 0.3;
    float volumeSoft = 0.15;
    

    setAmplitude(volumeSoft);
    n(4, Qd, instrument, octave - 2, 0); setAmplitude(volumeFull);
    backwards(Qd); 
    cchord(4, Qd, instrument, octave-1, "Xxx");
    cchord(4, Q, instrument, octave-1, "Xxx");
    b     (4, Qd, instrument, octave-1, "-x-", "--x", "X--", SX);

    setAmplitude(volumeSoft);
    n(5, Qd, instrument, octave - 2, 0); setAmplitude(volumeFull);
    backwards(Qd); 
    cchord(5, Qd, instrument, octave-1, "Xxx");
    cchord(5, Q, instrument, octave-1, "Xxx");
    b     (5, Qd, instrument, octave-1, "-x-", "--x", "X--", SX);

//    c(6, Qd, instrument, octave-1); // Alternative to the broken chord
    b     (6, Qd, instrument, octave-1, "--x", "-x-", "x--", SX);
    backwards(Qd); 
//    setAmplitude(volumeSoft); // Since this is a broken chord, give the bass full volume to compensate and match full chords
    n(6, Qd, instrument, octave-2, 0); 
//    setAmplitude(volumeFull);
    ci1(5, Q, instrument, octave-1);
    backwards(Q);
    setAmplitude(volumeSoft);
    n(5, Q, instrument, octave-2, 0); setAmplitude(volumeFull);
    b     (5, Qd, instrument, octave-1, "-x-", "--x", "X--", SX);
    
    for(i = 0; i < 2; i++){
        setAmplitude(volumeSoft);
        n(4, Qd, instrument, octave - 2, 0); setAmplitude(volumeFull);
        backwards(Qd); 
        cchord(4, Qd, instrument, octave-1, "Xxx");
        cchord(4, Q, instrument, octave-1, "Xxx");
        b     (4, Qd, instrument, octave-1, "-x-", "--x", "X--", SX);
    }

    setAmplitude(volumeSoft);
    n(5, Qd, instrument, octave - 2, 0); setAmplitude(volumeFull);
    backwards(Qd); 
    cchord(5, Qd, instrument, octave-1, "Xsx");
    cchord(5, Q, instrument, octave-1, "Xxx");
    b     (5, Qd, instrument, octave-1, "-x-", "--x", "X--", SX);

    c(1, Qd, instrument, octave);
    backwards(Qd);
    setAmplitude(volumeSoft);
    n(1, Qd, instrument, octave - 1, 0); setAmplitude(volumeFull);
    c(1, Q, instrument, octave);
    b(1, Qd, instrument, octave, "x--", "-x-", "--x", SX);

    setAmplitude(volumeSoft);
    n(5, Qd, instrument, octave - 2, 0); setAmplitude(volumeFull);
    backwards(Qd); 
    cchord(5, Qd, instrument, octave-1, "Xxx");
    cchord(5, Q, instrument, octave-1, "Xxx");
    b     (5, Qd, instrument, octave-1, "-x-", "--x", "X--", SX);

    return 1;
}

int verseChords(int instrument, int octave){

    //TODO Change this. Similar to chorus. Follow suspensions and such like when playing the piano.

    int i;
    
    for(i = 0; i < 3; i++){
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
        c(6, Qd, instrument, octave-1);
        setAmplitude(0.25);
        c(6, Qd, instrument, octave-1);
        c(6, Q, instrument, octave-1);
    
        setAmplitude(0.30);
        ci1(4, Qd, instrument, octave-1); 
        setAmplitude(0.25);
        ci1(4, Qd, instrument, octave-1); 
        ci1(4, Q, instrument, octave-1); 

        setAmplitude(0.30);
    }

    setAmplitude(0.30);
    c(1, Qd, instrument, octave);
    setAmplitude(0.25);
    c(1, Qd, instrument, octave);
    c(1, Q, instrument, octave);

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
    ci1(5, Qd, instrument, octave-1); 
    setAmplitude(0.25);
    ci1(5, Qd, instrument, octave-1); 
    ci1(5, Q, instrument, octave-1); 

    return 1;
}

int bridgeChords(int instrument, int octave){
    float volumeFull = 0.3;
    float volumeSoft = 0.15;

    int i;
    for(i = 0; i < 2; i++){
        b(4, Qd, instrument, octave, "x--", "--Y", "-Y-", SX);
        b(4, Qd, instrument, octave, "x--", "--Y", "-Y-", SX);
        b(4, Q, instrument, octave, "x--", "--Y", SX);

        b(5, Qd, instrument, octave, "x--", "--Y", "-Y-", SX);
        b(5, Qd, instrument, octave, "x--", "--Y", "-Y-", SX);
        b(5, Q, instrument, octave, "x--", "--Y", SX);
    }

    for(i = 0; i < 2; i++){
        setAmplitude(volumeSoft);
        n(4, W, instrument, octave - 2, 0); setAmplitude(volumeFull);
        backwards(W); 
        b(4, Qd, instrument, octave, "x--", "--Y", "-Y-", SX);
        b(4, Qd, instrument, octave, "x--", "--Y", "-Y-", SX);
        b(4, Q, instrument, octave, "x--", "--Y", SX);
    
        setAmplitude(volumeSoft);
        n(5, W, instrument, octave - 2, 0); setAmplitude(volumeFull);
        backwards(W); 
        b(5, Qd, instrument, octave, "x--", "--Y", "-Y-", SX);
        b(5, Qd, instrument, octave, "x--", "--Y", "-Y-", SX);
        b(5, Q, instrument, octave, "x--", "--Y", SX);
    }

    setAmplitude(volumeSoft);
    n(5, Qd, instrument, octave - 2, 0); setAmplitude(0.2);
    n(5, Qd, instrument, octave - 2, 0); setAmplitude(0.25);
    n(5, Q, instrument, octave - 2, 0); 
    backwards(W); 
    b(5, Qd, instrument, octave, "x--", "--Y", "-Y-", SX);
    b(5, Qd, instrument, octave, "x--", "--Y", "-Y-", SX);
    b(5, Q, instrument, octave, "x--", "--Y", SX);
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


    verseChords(instrument, octave);
    chorusChords(instrument, octave);
    verseChords(instrument, octave);
    chorusChords(instrument, octave);
    bridgeChords(instrument, octave);
    verseChords(instrument, octave);
    chorusChords(instrument, octave);


    closeOutput();
    
    return 0;
    }
