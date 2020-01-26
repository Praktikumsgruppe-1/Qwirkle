/**********************************************************************/
// Datei: punkte.cpp
// Die Klasse Punkte enthält eine Funktion zum Berechnen der Punkte nach
// Beendigung der und eigenen Zugrunde und mehrere Variablen, die dafür
// nötig sind.
/**********************************************************************/
#include "punkte.h"
#include "game.h"

// Konstruktor
Punkte::Punkte()
{

}


// Funktion zum Berechnen der Punkte
int Punkte::calc(int xCoord,int yCoord)                                 //der Funktion werden die x und y Koordinaten gegeben
{
  rowcheck=xCoord+1;                                                    //es wird einen nach rechts gegangen
    qDebug() << "Punkteberechnen beginnt mit den Koordinaten:" << rowcheck << xCoord;
  if(feldarray[rowcheck][yCoord][3]==1)                                 //er guckt ob der Stein diese Runde gelegt wird
  {
    note=xCoord-1;                                                      //er geht von x aus einen nach links
    while(feldarray[note][yCoord][1]==feldarray[xCoord][yCoord][1])     //hier wird auf Farbe oder Form verglichen?
    {
      rowcounter=rowcounter+1;                                          //der zeilenzähler geht eins hoch
      note=note-1;                                                      //man geht einen nach links
    }
    note=xCoord+1;                                                      //er geht von x aus einen nach rechts
    while(feldarray[note][yCoord][1]==feldarray[xCoord][yCoord][1])     //solange wie die Farbe/Form gleich ist
    {
      rowcounter=rowcounter+1;                                          //geht der zähler eins hoch
      note=note+1;                                                      //und einen weiter nach rechts
    }

    //hier das ganze wie oben nur mit dem anderen Attribut was verglichen wird
    note=xCoord-1;
    while(feldarray[note][yCoord][2]==feldarray[xCoord][yCoord][2])
    {
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(feldarray[note][yCoord][2]==feldarray[xCoord][yCoord][2])
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
      while(feldarray[rowcheck][note][1]==feldarray[rowcheck][yCoord][1])
      {
        rowcounter=rowcounter+1;
        note=note-1;
      }
      note=yCoord+1;
      while(feldarray[rowcheck][note][1]==feldarray[rowcheck][yCoord][1])
      {
        rowcounter=rowcounter+1;
        note=note+1;
      }

      //es wird nach oben und unten auf Attribut 2 verglichen
      note=yCoord-1;
      while(feldarray[rowcheck][note][2]==feldarray[rowcheck][yCoord][2])
      {
        rowcounter=rowcounter+1;
        note=note-1;
      }
      note=yCoord+1;
      while(feldarray[rowcheck][note][2]==feldarray[rowcheck][yCoord][2])
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

      //es wird in der Zeile einen weiter nach rechts gegangen
      rowcheck=rowcheck+1;
    }

    while(feldarray[rowcheck][yCoord][3]==1);
  }


  rowcheck=xCoord-1;                                            //es wird einen nach links gegangen
  
  if(feldarray[rowcheck][yCoord][3]==1)
  {
    note=xCoord-1;
    while(feldarray[note][yCoord][1]==feldarray[xCoord][yCoord][1])
    {
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(feldarray[note][yCoord][1]==feldarray[xCoord][yCoord][1])
    {
      rowcounter=rowcounter+1;
      note=note+1;
    }
    note=xCoord-1;
    while(feldarray[note][yCoord][2]==feldarray[xCoord][yCoord][2]){
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(feldarray[note][yCoord][2]==feldarray[xCoord][yCoord][2])
    {
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
    do
    {
      note=yCoord-1;
      while(feldarray[rowcheck][note][1]==feldarray[rowcheck][yCoord][1])
      {
        rowcounter=rowcounter+1;
        note=note-1;
      }
      note=yCoord+1;
      while(feldarray[rowcheck][note][1]==feldarray[rowcheck][yCoord][1])
      {
        rowcounter=rowcounter+1;
        note=note+1;
      }
      note=yCoord-1;
      while(feldarray[rowcheck][note][2]==feldarray[rowcheck][yCoord][2])
      {
        rowcounter=rowcounter+1;
        note=note-1;
      }
      note=yCoord+1;
      while(feldarray[rowcheck][note][2]==feldarray[rowcheck][yCoord][2])
      {
        rowcounter=rowcounter+1;
        note=note+1;
      }
      if(rowcounter>0)
      {
        rowcounter=rowcounter+1;
        if(rowcounter==6){
          rowcounter=12;
        }
        finalcounter=finalcounter+rowcounter;
        rowcounter=0;
      }
      rowcheck=rowcheck-1;
    }
    while(feldarray[rowcheck][yCoord][3]==1);
  }

  rowcheck=yCoord+1;
  if(feldarray[xCoord][rowcheck][3]==1){
  note=yCoord-1;
  while(feldarray[xCoord][note][1]==feldarray[xCoord][yCoord][1])
  {
    rowcounter=rowcounter+1;
    note=note-1;
  }

  note=yCoord+1;
  while(feldarray[xCoord][note][1]==feldarray[xCoord][yCoord][1])
  {
    rowcounter=rowcounter+1;
    note=note+1;
  }
  note=yCoord-1;
  while(feldarray[xCoord][note][2]==feldarray[xCoord][yCoord][2])
  {
    rowcounter=rowcounter+1;
    note=note-1;
  }
  note=yCoord+1;
  while(feldarray[xCoord][note][2]==feldarray[xCoord][yCoord][2])
  {
    rowcounter=rowcounter+1;
    note=note+1;
  }

  if(rowcounter>0)
  {
    rowcounter=rowcounter+1;
    if(rowcounter==6){
      rowcounter=12;
    }
    finalcounter=finalcounter+rowcounter;
    rowcounter=0;
  }
  rowcheck=yCoord;
  do
  {
    note=xCoord-1;
    while(feldarray[note][rowcheck][1]==feldarray[xCoord][rowcheck][1])
    {
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(feldarray[note][rowcheck][1]==feldarray[xCoord][rowcheck][1])
    {
      rowcounter=rowcounter+1;
      note=note+1;
    }
    note=xCoord-1;
    while(feldarray[note][rowcheck][2]==feldarray[xCoord][rowcheck][2])
    {
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(feldarray[note][rowcheck][2]==feldarray[xCoord][rowcheck][2])
    {
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
  }while(feldarray[xCoord][rowcheck][3]==1);
}
  rowcheck=yCoord-1;
  if(feldarray[xCoord][rowcheck][3]==1){
  note=yCoord-1;
  while(feldarray[xCoord][note][1]==feldarray[xCoord][yCoord][1])
  {
    rowcounter=rowcounter+1;
    note=note-1;
  }
  note=yCoord+1;
  while(feldarray[xCoord][note][1]==feldarray[xCoord][yCoord][1])
  {
    rowcounter=rowcounter+1;
    note=note+1;
  }
  note=yCoord-1;
  while(feldarray[xCoord][note][2]==feldarray[xCoord][yCoord][2])
  {
    rowcounter=rowcounter+1;
    note=note-1;
  }
  note=yCoord+1;
  while(feldarray[xCoord][note][2]==feldarray[xCoord][yCoord][2]){
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
  do
  {
    note=xCoord-1;
    while(feldarray[note][rowcheck][1]==feldarray[xCoord][rowcheck][1])
    {
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(feldarray[note][rowcheck][1]==feldarray[xCoord][rowcheck][1])
    {
      rowcounter=rowcounter+1;
      note=note+1;
    }
    note=xCoord-1;
    while(feldarray[note][rowcheck][2]==feldarray[xCoord][rowcheck][2])
    {
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(feldarray[note][rowcheck][2]==feldarray[xCoord][rowcheck][2])
    {
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
  }while(feldarray[xCoord][rowcheck][3]==1);
}
  if(finalcounter==0){
    note=yCoord-1;
    while(feldarray[xCoord][note][1]==feldarray[xCoord][yCoord][1])
    {
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=yCoord+1;
    while(feldarray[xCoord][note][1]==feldarray[xCoord][yCoord][1])
    {
      rowcounter=rowcounter+1;
      note=note+1;
    }
    note=yCoord-1;
    while(feldarray[xCoord][note][2]==feldarray[xCoord][yCoord][2])
    {
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=yCoord+1;
    while(feldarray[xCoord][note][2]==feldarray[xCoord][yCoord][2])
    {
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
    while(feldarray[note][yCoord][1]==feldarray[xCoord][yCoord][1])
    {
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(feldarray[note][yCoord][1]==feldarray[xCoord][yCoord][1])
    {
      rowcounter=rowcounter+1;
      note=note+1;
    }
    note=xCoord-1;
    while(feldarray[note][yCoord][2]==feldarray[xCoord][yCoord][2])
    {
      rowcounter=rowcounter+1;
      note=note-1;
    }
    note=xCoord+1;
    while(feldarray[note][yCoord][2]==feldarray[xCoord][yCoord][2])
    {
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
  return finalcounter;
}

