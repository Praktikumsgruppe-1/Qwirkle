#include "punkte.h"

Punkte::Punkte()
{

// Spielfeld mit 4 Einträgen pro Feld für Farbe und Form des Steins
  int field[181][181][4]={};
  int checkcounter;
  int lastx;
  int lasty;

//Punkteberechnung
int calc(int xCoord,int yCoord)                                 //der Funktion werden die x und y Koordinaten gegeben
{
  int note;                                                     //Zwischenspeicherplatz
  int rowcheck;
  int rowcounter=0;
  int finalcounter=0;

  rowcheck=xCoord+1;                                            //es wird einen nach rechts gegangen

  if(field[rowcheck][yCoord][3]==1)                             //Was zur Hölle ist der dritte Eintrag???
  {
    note=xCoord-1;                                              //er geht von x aus einen nach links
    while(field[note][yCoord][1]==field[xCoord][yCoord][1])     //hier wird auf Farbe oder Form verglichen?
    {
      rowcounter=rowcounter+1;                                  //der zeilenzähler geht eins hoch
      note=note-1;                                              //man geht einen nach links
    }
    note=xCoord+1;                                              //er geht von x aus einen nach rechts
    while(field[note][yCoord][1]==field[xCoord][yCoord][1])     //solange wie die Farbe/Form gleich ist
    {
      rowcounter=rowcounter+1;                                  //geht der zähler eins hoch
      note=note+1;                                              //und einen weiter nach rechts
    }

    //hier das ganze wie oben nur mit dem anderen Attribut was verglichen wird
    note=xCoord-1;
    while(field[note][yCoord][2]==field[xCoord][yCoord][2])
    {
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(field[note][yCoord][2]==field[xCoord][yCoord][2])
    {
      rowcounter=rowcounter+1;
      note=note+1;
    }

    //die Punkte für die Zeilen die gelegt wurden werden auf die Gesamtpunktzahl draufgerechnet
    if(rowcounter>0)
    {
      rowcounter=rowcounter+1;                              //logikfehler??, bei einer reihe von 6 bekommt er 7 Punkte und kommt nicht mehr in die if-schleife
      if(rowcounter==6)
      {
        rowcounter=12;
      }
      finalcounter=finalcounter+rowcounter;
      rowcounter=0;
    }

    // es wird für jeden stein in der Zeile nach oben und unten auf Reihen getestet
    rowcheck=xCoord;
    do
    {
      //es wird nach oben unten auf Attribut 1 verglichen
      note=yCoord-1;
      while(field[rowcheck][note][1]==field[rowcheck][yCoord][1])
      {
        rowcounter=rowcounter+1;
        note=note-1;
      }
      note=yCoord+1;
      while(field[rowcheck][note][1]==field[rowcheck][yCoord][1])
      {
        rowcounter=rowcounter+1;
        note=note+1;
      }

      //es wird nach oben und unten auf Attribut 2 verglichen
      note=yCoord-1;
      while(field[rowcheck][note][2]==field[rowcheck][yCoord][2])
      {
        rowcounter=rowcounter+1;
        note=note-1;
      }
      note=yCoord+1;
      while(field[rowcheck][note][2]==field[rowcheck][yCoord][2])
      {
        rowcounter=rowcounter+1;
        note=note+1;
      }

      //punktezusammenzählung mit der Qwirkel(alle 6) berücksichtigung
      if(rowcounter>0)
      {
        rowcounter=rowcounter+1;
        if(rowcounter==6)
        {
          rowcounter=12;
        }
        finalcounter=finalcounter+rowcounter;
        rowcounter=0;
      }

      //es wird in der Zeile einen weiter nach rechts gegangen, aber was ist mit links???
      rowcheck=rowcheck+1;
    }

    while(field[rowcheck][yCoord][3]==1);
  }


  rowcheck=xCoord-1;                                            //es wird einen nach links gegangen
  
  if(field[rowcheck][yCoord][3]==1)
  {
    note=xCoord-1;
    while(field[note][yCoord][1]==field[xCoord][yCoord][1]){
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(field[note][yCoord][1]==field[xCoord][yCoord][1]){
      rowcounter=rowcounter+1;
      note=note+1;
    }
    note=xCoord-1;
    while(field[note][yCoord][2]==field[xCoord][yCoord][2]){
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(field[note][yCoord][2]==field[xCoord][yCoord][2]){
      rowcounter=rowcounter+1;
      note=note+1;
    }
    if(rowcounter>0){
      rowcounter=rowcounter+1;
      if(rowcounter==6){
        rowcounter=12;
      }
      finalcounter=finalcounter+rowcounter;
      rowcounter=0;
    }
    rowcheck=xCoord;
    do{
      note=yCoord-1;
      while(field[rowcheck][note][1]==field[rowcheck][yCoord][1]){
        rowcounter=rowcounter+1;
        note=note-1;
      }
      note=yCoord+1;
      while(field[rowcheck][note][1]==field[rowcheck][yCoord][1]){
        rowcounter=rowcounter+1;
        note=note+1;
      }
      note=yCoord-1;
      while(field[rowcheck][note][2]==field[rowcheck][yCoord][2]){
        rowcounter=rowcounter+1;
        note=note-1;
      }
      note=yCoord+1;
      while(field[rowcheck][note][2]==field[rowcheck][yCoord][2]){
        rowcounter=rowcounter+1;
        note=note+1;
      }
      if(rowcounter>0){
        rowcounter=rowcounter+1;
        if(rowcounter==6){
          rowcounter=12;
        }
        finalcounter=finalcounter+rowcounter;
        rowcounter=0;
      }
      rowcheck=rowcheck-1;
    }while(field[rowcheck][yCoord][3]==1);
  }
  rowcheck=yCoord+1;
  if(field[xCoord][rowcheck][3]==1){
  note=yCoord-1;
  while(field[xCoord][note][1]==field[xCoord][yCoord][1]){
    rowcounter=rowcounter+1;
    note=note-1;
  }
  note=yCoord+1;
  while(field[xCoord][note][1]==field[xCoord][yCoord][1]){
    rowcounter=rowcounter+1;
    note=note+1;
  }
  note=yCoord-1;
  while(field[xCoord][note][2]==field[xCoord][yCoord][2]){
    rowcounter=rowcounter+1;
    note=note-1;
  }
  note=yCoord+1;
  while(field[xCoord][note][2]==field[xCoord][yCoord][2]){
    rowcounter=rowcounter+1;
    note=note+1;
  }
  if(rowcounter>0){
    rowcounter=rowcounter+1;
    if(rowcounter==6){
      rowcounter=12;
    }
    finalcounter=finalcounter+rowcounter;
    rowcounter=0;
  }
  rowcheck=yCoord;
  do{
    note=xCoord-1;
    while(field[note][rowcheck][1]==field[xCoord][rowcheck][1]){
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(field[note][rowcheck][1]==field[xCoord][rowcheck][1]){
      rowcounter=rowcounter+1;
      note=note+1;
    }
    note=xCoord-1;
    while(field[note][rowcheck][2]==field[xCoord][rowcheck][2]){
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(field[note][rowcheck][2]==field[xCoord][rowcheck][2]){
      rowcounter=rowcounter+1;
      note=note+1;
    }
    if(rowcounter>0){
      rowcounter=rowcounter+1;
      if(rowcounter==6){
        rowcounter=12;
      }
      finalcounter=finalcounter+rowcounter;
      rowcounter=0;
    }
    rowcheck=rowcheck+1;
  }while(field[xCoord][rowcheck][3]==1);
}
  rowcheck=yCoord-1;
  if(field[xCoord][rowcheck][3]==1){
  note=yCoord-1;
  while(field[xCoord][note][1]==field[xCoord][yCoord][1]){
    rowcounter=rowcounter+1;
    note=note-1;
  }
  note=yCoord+1;
  while(field[xCoord][note][1]==field[xCoord][yCoord][1]){
    rowcounter=rowcounter+1;
    note=note+1;
  }
  note=yCoord-1;
  while(field[xCoord][note][2]==field[xCoord][yCoord][2]){
    rowcounter=rowcounter+1;
    note=note-1;
  }
  note=yCoord+1;
  while(field[xCoord][note][2]==field[xCoord][yCoord][2]){
    rowcounter=rowcounter+1;
    note=note+1;
  }
  if(rowcounter>0){
    rowcounter=rowcounter+1;
    if(rowcounter==6){
      rowcounter=12;
    }
    finalcounter=finalcounter+rowcounter;
    rowcounter=0;
  }
  rowcheck=yCoord;
  do{
    note=xCoord-1;
    while(field[note][rowcheck][1]==field[xCoord][rowcheck][1]){
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(field[note][rowcheck][1]==field[xCoord][rowcheck][1]){
      rowcounter=rowcounter+1;
      note=note+1;
    }
    note=xCoord-1;
    while(field[note][rowcheck][2]==field[xCoord][rowcheck][2]){
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(field[note][rowcheck][2]==field[xCoord][rowcheck][2]){
      rowcounter=rowcounter+1;
      note=note+1;
    }
    if(rowcounter>0){
      rowcounter=rowcounter+1;
      if(rowcounter==6){
        rowcounter=12;
      }
      finalcounter=finalcounter+rowcounter;
      rowcounter=0;
    }
    rowcheck=rowcheck-1;
  }while(field[xCoord][rowcheck][3]==1);
}
  if(finalcounter==0){
    note=yCoord-1;
    while(field[xCoord][note][1]==field[xCoord][yCoord][1]){
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=yCoord+1;
    while(field[xCoord][note][1]==field[xCoord][yCoord][1]){
      rowcounter=rowcounter+1;
      note=note+1;
    }
    note=yCoord-1;
    while(field[xCoord][note][2]==field[xCoord][yCoord][2]){
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=yCoord+1;
    while(field[xCoord][note][2]==field[xCoord][yCoord][2]){
      rowcounter=rowcounter+1;
      note=note+1;
    }
    if(rowcounter>0){
      rowcounter=rowcounter+1;
      if(rowcounter==6){
        rowcounter=12;
      }
      finalcounter=finalcounter+rowcounter;
      rowcounter=0;
    }
    note=xCoord-1;
    while(field[note][yCoord][1]==field[xCoord][yCoord][1]){
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(field[note][yCoord][1]==field[xCoord][yCoord][1]){
      rowcounter=rowcounter+1;
      note=note+1;
    }
    note=xCoord-1;
    while(field[note][yCoord][2]==field[xCoord][yCoord][2]){
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(field[note][yCoord][2]==field[xCoord][yCoord][2]){
      rowcounter=rowcounter+1;
      note=note+1;
    }
    if(rowcounter>0){
      rowcounter=rowcounter+1;
      if(rowcounter==6){
        rowcounter=12;
      }
      finalcounter=finalcounter+rowcounter;
      rowcounter=0;
    }
  }
  checkcounter=0;
  lastx=0;
  lasty=0;
  return finalcounter;
}
}
