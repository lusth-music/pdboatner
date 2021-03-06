#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
#define base "mandolin/sample_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "quickstart";
char *PROGRAM_VERSION = "0.01";

static int last = 0;


int drumbeatVerse(){
    int spot = getLocation();
    
    drumkitHHClosed(1,0.4,"---x-----x--", SX); setLocation(spot);
    drumkitKick    (1,2,"x-------x---", SX); 
}

int drumbeatChorus(){
    int spot = getLocation();
    
    drumkitHHClosed(1,0.25,"xxx-", SX); setLocation(spot);
    drumkitHHOpen  (1,0.25,"---x", SX); setLocation(spot);
    drumkitSnare   (1,1,"---x-x---x-x", SX); setLocation(spot);
    drumkitKick    (1,2,"x-------x---", SX); 
}

int chorusChords(int instrument, int octave){
    setAmplitude(0.30);
    c(1, Q + Qt + Qt, instrument, octave);
    setAmplitude(0.25);
    c(1, Q + Qt, instrument, octave);
    c(1, Q, instrument, octave);

    setAmplitude(0.30);
    ci6(3, Q + Qt + Qt, instrument, octave); 
    setAmplitude(0.25);
    ci6(3, Q + Qt, instrument, octave); 
    ci6(3, Q, instrument, octave); 
    
    
    setAmplitude(0.30);
    ci1(4, Q + Qt + Qt, instrument, octave-1);
    setAmplitude(0.25);
    ci1(4, Q + Qt, instrument, octave-1);
    ci1(4, Q, instrument, octave-1);
    
    setAmplitude(0.30);
    cchord(5, Q + Qt + Qt, instrument, octave-1, "Osx"); 
    setAmplitude(0.25);
    ci1(5, Q + Qt, instrument, octave-1); 
    ci1(5, Q, instrument, octave-1); 

    setAmplitude(0.30);
}

int verseChords(int instrument, int octave){
    setAmplitude(0.30);
    c(1, Q + Qt + Qt, instrument, octave);
    setAmplitude(0.25);
    c(1, Q + Qt, instrument, octave);
    c(1, Q, instrument, octave);

    setAmplitude(0.30);
    ci1(5, Q + Qt + Qt, instrument, octave-1); 
    setAmplitude(0.25);
    ci1(5, Q + Qt, instrument, octave-1); 
    ci1(5, Q, instrument, octave-1); 
    
    
    setAmplitude(0.30);
    ci1(4, Q + Qt + Qt, instrument, octave-1);
    setAmplitude(0.25);
    ci1(4, Q + Qt, instrument, octave-1);
    ci1(4, Q, instrument, octave-1);
    
    setAmplitude(0.30);
    ci1(5, Q + Qt + Qt, instrument, octave-1); 
    setAmplitude(0.25);
    ci1(5, Q + Qt, instrument, octave-1); 
    ci1(5, Q, instrument, octave-1); 

    setAmplitude(0.30);
}

int
main()
    {
    int instrument;
    int octave = 2;

    songInit();

    instrument = readScale(dir,base);

    setTempo(180);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.3);

    openOutput("quickstart.rra",0,0);


    int location = getLocation();

    int i;
    for(i = 0; i < 4; i++){
        drumbeatVerse();
    }

    for(i = 0; i < 4; i++){
        drumbeatChorus();
    }

    setLocation(location);

    verseChords(instrument, octave);
    chorusChords(instrument, octave);


    closeOutput();
    
    return 0;
    }
