#include "regeln.h"
#include "game.h"
#include "spielfeld.h"
//#include <studio.h>

Regeln::Regeln()
{
    checkcounter = 0;
    /*feldarray[23][55][1]=2;
    feldarray[23][55][2]=6;
    check(24,55,2,7);
    check(25,55,2,4);
    check(26,55,2,3);
    check(26,54,2,1);
    */
}

//Regelprüfung für 1. Stein
// gibt true zurück, wenn man den Stein dort ablegen darf
bool Regeln::check1(int xCoord, int yCoord, int colour, int symbol){
  int note;
  if(feldarray[xCoord][yCoord][1]>0){     //Feld belegt?
    return false;
  }
  note=xCoord+1;
  if(feldarray[note][yCoord][1]==0){        // Feld im nichts?
    note=xCoord-1;
    if(feldarray[note][yCoord][1]==0){
      note=yCoord+1;
      if(feldarray[xCoord][note][1]==0){
        note=yCoord-1;
        if(feldarray[xCoord][note][1]==0){
          return false;
        }
      }
    }
  }
  note=xCoord+1;      // Feld neben verbotenen Steinen?
  if((feldarray[note][yCoord][1]>0)&&(feldarray[note][yCoord][1]!=colour)&&(feldarray[note][yCoord][2]!=symbol)){
    return false;
  }
  note=xCoord-1;
  if((feldarray[note][yCoord][1]>0)&&(feldarray[note][yCoord][1]!=colour)&&(feldarray[note][yCoord][2]!=symbol)){
    return false;
  }
  note=yCoord+1;
  if((feldarray[xCoord][note][1]>0)&&(feldarray[xCoord][note][1]!=colour)&&(feldarray[xCoord][note][2]!=symbol)){
    return false;
  }
  note=yCoord-1;
  if((feldarray[xCoord][note][1]>0)&&(feldarray[xCoord][note][1]!=colour)&&(feldarray[xCoord][note][2]!=symbol)){
    return false;
  }
  note=xCoord+1;
    if(feldarray[note][yCoord][1]==colour){
      do{
        if((feldarray[note][yCoord][1]!=colour)||(feldarray[note][yCoord][2]==symbol)){
          return false;
        }
        note=note+1;
      }while(feldarray[note][yCoord][1]>0);
    }
    else if(feldarray[note][yCoord][2]==symbol){
      do{
        if((feldarray[note][yCoord][2]!=symbol)||(feldarray[note][yCoord][1]==colour)){
          return false;
        }
        note=note+1;
      }while(feldarray[note][yCoord][1]>0);
    }
    note=xCoord-1;
    if(feldarray[note][yCoord][1]==colour){
      do{
        if((feldarray[note][yCoord][1]!=colour)||(feldarray[note][yCoord][2]==symbol)){
          return false;
        }
        note=note-1;
      }while(feldarray[note][yCoord][1]>0);
    }
    else if(feldarray[note][yCoord][2]==symbol){
      do{
        if((feldarray[note][yCoord][2]!=symbol)||(feldarray[note][yCoord][1]==colour)){
          return false;
        }
        note=note-1;
      }while(feldarray[note][yCoord][1]>0);
    }
    note=yCoord+1;
    if(feldarray[xCoord][note][1]==colour){
      do{
        if((feldarray[xCoord][note][1]!=colour)||(feldarray[xCoord][note][2]==symbol)){
          return false;
        }
        note=note+1;
      }while(feldarray[xCoord][note][1]>0);
    }
    else if(feldarray[xCoord][note][2]==symbol){
      do{
        if((feldarray[xCoord][note][2]!=symbol)||(feldarray[xCoord][note][1]==colour)){
          return false;
        }
        note=note+1;
      }while(feldarray[xCoord][note][1]>0);
    }
    note=yCoord-1;
    if(feldarray[xCoord][note][1]==colour){
      do{
        if((feldarray[xCoord][note][1]!=colour)||(feldarray[xCoord][note][2]==symbol)){
          return false;
        }
        note=note-1;
      }while(feldarray[xCoord][note][1]>0);
    }
    else if(feldarray[xCoord][note][2]==symbol){
      do{
        if((feldarray[xCoord][note][2]!=symbol)||(feldarray[xCoord][note][1]==colour)){
          return false;
        }
        note=note-1;
      }while(feldarray[xCoord][note][1]>0);
    }
    feldarray[xCoord][yCoord][0]=1;
    feldarray[xCoord][yCoord][1]=colour;
    feldarray[xCoord][yCoord][2]=symbol;
    feldarray[xCoord][yCoord][3]=1;
    checkcounter=1;
    return true;
}

// Regeln ab dem 2. Stein
bool Regeln::check2(int xCoord, int yCoord, int colour, int symbol){
  int note, notetwo;
  if(feldarray[xCoord][yCoord][1]>0){
    return false;
  }
  notetwo=0;
  note=xCoord+1;
  while (feldarray[note][yCoord][3]==1) {
    if (feldarray[note][yCoord][0]==1) {
      notetwo=1;
    }
    note=note+1;
  }
  note=xCoord-1;
  while (feldarray[note][yCoord][3]==1) {
    if (feldarray[note][yCoord][0]==1) {
      notetwo=1;
    }
    note=note-1;
  }
  note=yCoord+1;
  while (feldarray[xCoord][note][3]==1) {
    if (feldarray[xCoord][note][0]==1) {
      notetwo=1;
    }
    note=note+1;
  }
  note=yCoord-1;
  while (feldarray[xCoord][note][3]==1) {
    if (feldarray[xCoord][note][0]==1) {
      notetwo=1;
    }
    note=note-1;
  }
  if (notetwo==0){
    return false;
  }
  note=xCoord+1;
  if((feldarray[note][yCoord][1]>0)&&(feldarray[note][yCoord][1]!=colour)&&(feldarray[note][yCoord][2]!=symbol)){
    return false;
  }
  note=xCoord-1;
  if((feldarray[note][yCoord][1]>0)&&(feldarray[note][yCoord][1]!=colour)&&(feldarray[note][yCoord][2]!=symbol)){
    return false;
  }
  note=yCoord+1;
  if((feldarray[xCoord][note][1]>0)&&(feldarray[xCoord][note][1]!=colour)&&(feldarray[xCoord][note][2]!=symbol)){
    return false;
  }
  note=yCoord-1;
  if((feldarray[xCoord][note][1]>0)&&(feldarray[xCoord][note][1]!=colour)&&(feldarray[xCoord][note][2]!=symbol)){
    return false;
  }
    note=xCoord+1;
    if(feldarray[note][yCoord][1]==colour){
      do{
        if((feldarray[note][yCoord][1]!=colour)||(feldarray[note][yCoord][2]==symbol)){
          return false;
        }
        note=note+1;
      }while(feldarray[note][yCoord][1]>0);
    }
    else if(feldarray[note][yCoord][2]==symbol){
      do{
        if((feldarray[note][yCoord][2]!=symbol)||(feldarray[note][yCoord][1]==colour)){
          return false;
        }
        note=note+1;
      }while(feldarray[note][yCoord][1]>0);
    }
    note=xCoord-1;
    if(feldarray[note][yCoord][1]==colour){
      do{
        if((feldarray[note][yCoord][1]!=colour)||(feldarray[note][yCoord][2]==symbol)){
          return false;
        }
        note=note-1;
      }while(feldarray[note][yCoord][1]>0);
    }
    else if(feldarray[note][yCoord][2]==symbol){
      do{
        if((feldarray[note][yCoord][2]!=symbol)||(feldarray[note][yCoord][1]==colour)){
          return false;
        }
        note=note-1;
      }while(feldarray[note][yCoord][1]>0);
    }
    note=yCoord+1;
    if(feldarray[xCoord][note][1]==colour){
      do{
        if((feldarray[xCoord][note][1]!=colour)||(feldarray[xCoord][note][2]==symbol)){
          return false;
        }
        note=note+1;
      }while(feldarray[xCoord][note][1]>0);
    }
    else if(feldarray[xCoord][note][2]==symbol){
      do{
        if((feldarray[xCoord][note][2]!=symbol)||(feldarray[xCoord][note][1]==colour)){
          return false;
        }
        note=note+1;
      }while(feldarray[xCoord][note][1]>0);
    }
    note=yCoord-1;
    if(feldarray[xCoord][note][1]==colour){
      do{
        if((feldarray[xCoord][note][1]!=colour)||(feldarray[xCoord][note][2]==symbol)){
          return false;
        }
        note=note-1;
      }while(feldarray[xCoord][note][1]>0);
    }
    else if(feldarray[xCoord][note][2]==symbol){
      do{
        if((feldarray[xCoord][note][2]!=symbol)||(feldarray[xCoord][note][1]==colour)){
          return false;
        }
        note=note-1;
      }while(feldarray[xCoord][note][1]>0);
    }
    feldarray[xCoord][yCoord][1]=colour;
    feldarray[xCoord][yCoord][2]=symbol;
    feldarray[xCoord][yCoord][3]=1;
    return true;
}

bool Regeln::check(int xCoord, int yCoord, int colour, int symbol)
{
  if (checkcounter==0)
  {
    return check1(xCoord, yCoord, colour, symbol);
  }
  else if(checkcounter==1)
  {
    return check2(xCoord, yCoord, colour, symbol);
  }
}
