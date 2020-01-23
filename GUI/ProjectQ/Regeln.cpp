/*
//#include <studio.h>
#include <iostream>
using namespace std;

// Spielfeld mit 4 Einträgen pro Feld für Farbe und Form des Steins
  int field[181][181][4]={};
  int checkcounter=0;
  int lastx=0;
  int lasty=0;

//Regelprüfung für 1. Stein
int check1(int xCoord, int yCoord, int colour, int symbol){
  int note;
  if(field[xCoord][yCoord][1]>0){     //Feld belegt?
    return false;
  }
  note=xCoord+1;
  if(field[note][yCoord][1]==0){        // Feld im nichts?
    note=xCoord-1;
    if(field[note][yCoord][1]==0){
      note=yCoord+1;
      if(field[xCoord][note][1]==0){
        note=yCoord-1;
        if(field[xCoord][note][1]==0){
          return false;
        }
      }
    }
  }
  note=xCoord+1;      // Feld neben verbotenen Steinen?
  if((field[note][yCoord][1]>0)&&(field[note][yCoord][1]!=colour)&&(field[note][yCoord][2]!=symbol)){
    return false;
  }
  note=xCoord-1;
  if((field[note][yCoord][1]>0)&&(field[note][yCoord][1]!=colour)&&(field[note][yCoord][2]!=symbol)){
    return false;
  }
  note=yCoord+1;
  if((field[xCoord][note][1]>0)&&(field[xCoord][note][1]!=colour)&&(field[xCoord][note][2]!=symbol)){
    return false;
  }
  note=yCoord-1;
  if((field[xCoord][note][1]>0)&&(field[xCoord][note][1]!=colour)&&(field[xCoord][note][2]!=symbol)){
    return false;
  }
  note=xCoord+1;
    if(field[note][yCoord][1]==colour){
      do{
        if((field[note][yCoord][1]!=colour)||(field[note][yCoord][2]==symbol)){
          return false;
        }
        note=note+1;
      }while(field[note][yCoord][1]>0);
    }
    else if(field[note][yCoord][2]==symbol){
      do{
        if((field[note][yCoord][2]!=symbol)||(field[note][yCoord][1]==colour)){
          return false;
        }
        note=note+1;
      }while(field[note][yCoord][1]>0);
    }
    note=xCoord-1;
    if(field[note][yCoord][1]==colour){
      do{
        if((field[note][yCoord][1]!=colour)||(field[note][yCoord][2]==symbol)){
          return false;
        }
        note=note-1;
      }while(field[note][yCoord][1]>0);
    }
    else if(field[note][yCoord][2]==symbol){
      do{
        if((field[note][yCoord][2]!=symbol)||(field[note][yCoord][1]==colour)){
          return false;
        }
        note=note-1;
      }while(field[note][yCoord][1]>0);
    }
    note=yCoord+1;
    if(field[xCoord][note][1]==colour){
      do{
        if((field[xCoord][note][1]!=colour)||(field[xCoord][note][2]==symbol)){
          return false;
        }
        note=note+1;
      }while(field[xCoord][note][1]>0);
    }
    else if(field[xCoord][note][2]==symbol){
      do{
        if((field[xCoord][note][2]!=symbol)||(field[xCoord][note][1]==colour)){
          return false;
        }
        note=note+1;
      }while(field[xCoord][note][1]>0);
    }
    note=yCoord-1;
    if(field[xCoord][note][1]==colour){
      do{
        if((field[xCoord][note][1]!=colour)||(field[xCoord][note][2]==symbol)){
          return false;
        }
        note=note-1;
      }while(field[xCoord][note][1]>0);
    }
    else if(field[xCoord][note][2]==symbol){
      do{
        if((field[xCoord][note][2]!=symbol)||(field[xCoord][note][1]==colour)){
          return false;
        }
        note=note-1;
      }while(field[xCoord][note][1]>0);
    }
    field[xCoord][yCoord][0]=1;
    field[xCoord][yCoord][1]=colour;
    field[xCoord][yCoord][2]=symbol;
    field[xCoord][yCoord][3]=1;
    checkcounter=1;
    lastx=xCoord;
    lasty=yCoord;
    return true;
}

// Regeln ab dem 2. Stein
int check2(int xCoord, int yCoord, int colour, int symbol){
  int note, notetwo;
  if(field[xCoord][yCoord][1]>0){
    return false;
  }
  notetwo=0;
  note=xCoord+1;
  while (field[note][yCoord][3]==1) {
    if (field[note][yCoord][0]==1) {
      notetwo=1;
    }
    note=note+1;
  }
  note=xCoord-1;
  while (field[note][yCoord][3]==1) {
    if (field[note][yCoord][0]==1) {
      notetwo=1;
    }
    note=note-1;
  }
  note=yCoord+1;
  while (field[xCoord][note][3]==1) {
    if (field[xCoord][note][0]==1) {
      notetwo=1;
    }
    note=note+1;
  }
  note=yCoord-1;
  while (field[xCoord][note][3]==1) {
    if (field[xCoord][note][0]==1) {
      notetwo=1;
    }
    note=note-1;
  }
  if (notetwo==0){
    return false;
  }
  note=xCoord+1;
  if((field[note][yCoord][1]>0)&&(field[note][yCoord][1]!=colour)&&(field[note][yCoord][2]!=symbol)){
    return false;
  }
  note=xCoord-1;
  if((field[note][yCoord][1]>0)&&(field[note][yCoord][1]!=colour)&&(field[note][yCoord][2]!=symbol)){
    return false;
  }
  note=yCoord+1;
  if((field[xCoord][note][1]>0)&&(field[xCoord][note][1]!=colour)&&(field[xCoord][note][2]!=symbol)){
    return false;
  }
  note=yCoord-1;
  if((field[xCoord][note][1]>0)&&(field[xCoord][note][1]!=colour)&&(field[xCoord][note][2]!=symbol)){
    return false;
  }
    note=xCoord+1;
    if(field[note][yCoord][1]==colour){
      do{
        if((field[note][yCoord][1]!=colour)||(field[note][yCoord][2]==symbol)){
          return false;
        }
        note=note+1;
      }while(field[note][yCoord][1]>0);
    }
    else if(field[note][yCoord][2]==symbol){
      do{
        if((field[note][yCoord][2]!=symbol)||(field[note][yCoord][1]==colour)){
          return false;
        }
        note=note+1;
      }while(field[note][yCoord][1]>0);
    }
    note=xCoord-1;
    if(field[note][yCoord][1]==colour){
      do{
        if((field[note][yCoord][1]!=colour)||(field[note][yCoord][2]==symbol)){
          return false;
        }
        note=note-1;
      }while(field[note][yCoord][1]>0);
    }
    else if(field[note][yCoord][2]==symbol){
      do{
        if((field[note][yCoord][2]!=symbol)||(field[note][yCoord][1]==colour)){
          return false;
        }
        note=note-1;
      }while(field[note][yCoord][1]>0);
    }
    note=yCoord+1;
    if(field[xCoord][note][1]==colour){
      do{
        if((field[xCoord][note][1]!=colour)||(field[xCoord][note][2]==symbol)){
          return false;
        }
        note=note+1;
      }while(field[xCoord][note][1]>0);
    }
    else if(field[xCoord][note][2]==symbol){
      do{
        if((field[xCoord][note][2]!=symbol)||(field[xCoord][note][1]==colour)){
          return false;
        }
        note=note+1;
      }while(field[xCoord][note][1]>0);
    }
    note=yCoord-1;
    if(field[xCoord][note][1]==colour){
      do{
        if((field[xCoord][note][1]!=colour)||(field[xCoord][note][2]==symbol)){
          return false;
        }
        note=note-1;
      }while(field[xCoord][note][1]>0);
    }
    else if(field[xCoord][note][2]==symbol){
      do{
        if((field[xCoord][note][2]!=symbol)||(field[xCoord][note][1]==colour)){
          return false;
        }
        note=note-1;
      }while(field[xCoord][note][1]>0);
    }
    field[xCoord][yCoord][1]=colour;
    field[xCoord][yCoord][2]=symbol;
    field[xCoord][yCoord][3]=1;
    lastx=xCoord;
    lasty=yCoord;
    return true;
}

void check(int xCoord, int yCoord, int colour, int symbol){
  if (checkcounter==0){
    check1(xCoord, yCoord, colour, symbol);
  }
  else if(checkcounter==1){
    check2(xCoord, yCoord, colour, symbol);
  }
}

int main() {
  field[23][55][1]=2;
  field[23][55][2]=6;
  check(24,55,2,7);
  check(25,55,2,4);
  check(26,55,2,3);
  check(26,54,2,1);

  cout << field[23][55][1] << field[23][55][2] << endl;
  cout << field[24][55][1] << field[24][55][2] << endl;
  cout << field[25][55][1] << field[25][55][2] << endl;
  cout << field[26][55][1] << field[26][55][2] << endl;
  cout << field[26][54][1] << field[26][54][2] << endl;
  cout << field[all][all][1] << endl;
  return 0;
}
*/
