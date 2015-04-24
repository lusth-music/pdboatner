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

void drumbeatVerseSoft(){
    drumkitHHClosed(1,0.4,"---x--x-", SX);
}

void drumbeatVerse(){
    int spot = getLocation();
    
    drumkitHHOpen  (1,0.25,"------x-", SX); setLocation(spot);
    drumkitHHClosed(1,0.3, "x-x--x--", SX); setLocation(spot);
    drumkitKick    (1,2,   "x--x--x-", SX); 
}

void drumbeatChorus(){
    int spot = getLocation();
    
    drumkitHHClosed(1,0.25,"xxx-xx-x", SX); setLocation(spot);
    drumkitHHOpen  (1,0.25,"---x--x-", SX); setLocation(spot);
    drumkitSnare   (1,1,   "--xx--x-", SX); setLocation(spot);
    drumkitKick    (1,2,   "x----x--", SX); 
}

void drumbeatBridgeSoft(){
    int spot = getLocation();
    
    drumkitHHClosed(1,0.4,"---x--x-", SX); setLocation(spot);
    drumkitKick    (1,2,  "x-------", SX); 
}

void bridge(){
    int i;
    for(i = 1; i <= 3; i++){
        drumbeatBridgeSoft();
    }

    int spot = getLocation();
    
    drumkitHHOpen  (1,0.25,"---x--x-", SX); setLocation(spot);
    drumkitHHClosed(1,0.4, "--x--x--", SX); setLocation(spot);
    drumkitSnare   (1,1,   "---x--x-", SX); setLocation(spot);
    drumkitKick    (1,2,   "x-----x-", SX); 

    for(i = 1; i <= 3; i++){
        drumbeatBridgeSoft();
    }

    spot = getLocation();
    drumkitHHOpen  (1,0.5,"---x--x-", SX); setLocation(spot);
    drumkitHHClosed(1,0.4, "--x--x-x", SX); setLocation(spot);
    drumkitSnare   (1,1,   "---x--x-", SX); setLocation(spot);
    drumkitKick    (1,2,   "x-x-x-x-", SX); 

    spot = getLocation();
    drumkitHHOpen  (1,0.5,"x-x-x-x-", SX); setLocation(spot);
    drumkitHHClosed(1,0.4, "--------", SX); setLocation(spot);
    drumkitSnare   (1,1,   "xxxxxxxx", SX); setLocation(spot);
    drumkitKick    (1,2,   "x-x-x-x-", SX); 
}
// final- 1 means final, 0 means normal
void chorus(int final){
    int i;

    if(final==1){
        for(i = 0; i < 22; i++){
            drumbeatChorus();
        }
        drumkitHHOpen  (1,0.5,"x-------", SX);
    } else {
        for(i = 0; i < 24; i++){
            drumbeatChorus();
        }
    }
}

// silent- 0 means play normally. 1 means play the first 8 measures silently
void verse(int silent){
    int i;

    if(silent==1){
        for(i = 0; i < 8; i++){
            drumbeatVerseSoft();
        }
        for(i = 0; i < 8; i++){
            drumbeatVerse();
        }
    } else {
        for(i = 0; i < 16; i++){
            drumbeatVerse();
        }
    }
}

void intro(){
    int i;
    for(i = 0; i < 4; i++){
        drumbeatVerse();
    }
}


int
main()
    {
//    int instrument;
//    int octave = 4;

    songInit();

//    instrument = readScale(dir,base);

    setTempo(130);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.3);

    openOutput("drums.rra",0,0);

 //   intro();
 //   verse(0);
 //   chorus(0);
 //   verse(0);
 //   chorus(0);
 //   bridge();
 //   verse(1);
    chorus(1);

    closeOutput();
    
    return 0;
    }
