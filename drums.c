#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
#define base "piano/bright_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "drums";
char *PROGRAM_VERSION = "0.01";

static int last = 0;


int drumbeatVerse(){
    int spot = getLocation();
    
    drumkitHHClosed(1,0.4,"x-x-x-x-", SX); setLocation(spot);
    drumkitKick    (1,2,  "x--x--x-", SX); 
}

int drumbeatChorus(){
    int spot = getLocation();
    
    drumkitHHClosed(1,0.25,"xxx-xx-x", SX); setLocation(spot);
    drumkitHHOpen  (1,0.25,"---x--x-", SX); setLocation(spot);
    drumkitSnare   (1,1,   "--xx--x-", SX); setLocation(spot);
    drumkitKick    (1,2,   "x----x--", SX); 
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

    openOutput("drums.rra",0,0);


    int location = getLocation();

    int i;

    for(i = 0; i < 24; i++){
        drumbeatChorus();
    }

    closeOutput();
    
    return 0;
    }
