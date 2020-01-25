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
            qDebug("1. stein regeln");
  int note;
  if(feldarray[xCoord][yCoord][1]>0)
  {     //Feld belegt?
      qDebug("hier ist der fehler");
      return false;
  }
  note=xCoord+1;
  if(feldarray[note][yCoord][1]==0)
  {        // Feld im nichts?
    note=xCoord-1;
    if(feldarray[note][yCoord][1]==0)
    {
      note=yCoord+1;
      if(feldarray[xCoord][note][1]==0)
      {
        note=yCoord-1;
        if(feldarray[xCoord][note][1]==0)
        {
          qDebug("hier sollte er nicht sein");
            return false;
        }
      }
    }
  }
  note=xCoord+1;      // Feld neben verbotenen Steinen?
  if((feldarray[note][yCoord][1]>0)&&(feldarray[note][yCoord][1]!=colour)&&(feldarray[note][yCoord][2]!=symbol))
  {
    return false;
  }
  note=xCoord-1;
  if((feldarray[note][yCoord][1]>0)&&(feldarray[note][yCoord][1]!=colour)&&(feldarray[note][yCoord][2]!=symbol))
  {
    return false;
  }
  note=yCoord+1;
  if((feldarray[xCoord][note][1]>0)&&(feldarray[xCoord][note][1]!=colour)&&(feldarray[xCoord][note][2]!=symbol))
  {
    return false;
  }
  note=yCoord-1;
  if((feldarray[xCoord][note][1]>0)&&(feldarray[xCoord][note][1]!=colour)&&(feldarray[xCoord][note][2]!=symbol))
  {
    return false;
  }
  note=xCoord+1;
    if(feldarray[note][yCoord][1]==colour)
    {
      do{
        if((feldarray[note][yCoord][1]!=colour)||(feldarray[note][yCoord][2]==symbol))
        {
          return false;
        }
        note=note+1;
      }while(feldarray[note][yCoord][1]>0);
    }
    else if(feldarray[note][yCoord][2]==symbol)
    {
      do{
        if((feldarray[note][yCoord][2]!=symbol)||(feldarray[note][yCoord][1]==colour))
        {
          return false;
        }
        note=note+1;
      }while(feldarray[note][yCoord][1]>0);
    }
    note=xCoord-1;
    if(feldarray[note][yCoord][1]==colour)
    {
      do{
        if((feldarray[note][yCoord][1]!=colour)||(feldarray[note][yCoord][2]==symbol))
        {
          return false;
        }
        note=note-1;
      }while(feldarray[note][yCoord][1]>0);
    }
    else if(feldarray[note][yCoord][2]==symbol)
    {
      do{
        if((feldarray[note][yCoord][2]!=symbol)||(feldarray[note][yCoord][1]==colour))
        {
          return false;
        }
        note=note-1;
      }while(feldarray[note][yCoord][1]>0);
    }
    note=yCoord+1;
    if(feldarray[xCoord][note][1]==colour)
    {
      do{
        if((feldarray[xCoord][note][1]!=colour)||(feldarray[xCoord][note][2]==symbol))
        {
          return false;
        }
        note=note+1;
      }while(feldarray[xCoord][note][1]>0);
    }
    else if(feldarray[xCoord][note][2]==symbol)
    {
      do{
        if((feldarray[xCoord][note][2]!=symbol)||(feldarray[xCoord][note][1]==colour))
        {
          return false;
        }
        note=note+1;
      }while(feldarray[xCoord][note][1]>0);
    }
    note=yCoord-1;
    if(feldarray[xCoord][note][1]==colour)
    {
      do{
        if((feldarray[xCoord][note][1]!=colour)||(feldarray[xCoord][note][2]==symbol))
        {
          return false;
        }
        note=note-1;
      }while(feldarray[xCoord][note][1]>0);
    }
    else if(feldarray[xCoord][note][2]==symbol)
    {
      do{
        if((feldarray[xCoord][note][2]!=symbol)||(feldarray[xCoord][note][1]==colour))
        {
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
bool Regeln::check2(int xCoord, int yCoord, int colour, int symbol)
{
            qDebug("2. stein regeln");
            qDebug() << "Zeile: 162" << feldarray[xCoord][yCoord][0] << feldarray[xCoord][yCoord][1] << feldarray[xCoord][yCoord][2] << feldarray[xCoord][yCoord][3] << "Koordinanten:" << xCoord << yCoord;
  int note, notetwo;
  if(feldarray[xCoord][yCoord][1]==7)
  {
              qDebug("im feld liegt schon was");
    return false;
  }
  notetwo=0;
  note=xCoord+1;
  while (feldarray[note][yCoord][3]==1)
  {
      qDebug() << "Zeile: 174" << feldarray[note][yCoord][0] << feldarray[note][yCoord][1] << feldarray[note][yCoord][2] << feldarray[note][yCoord][3]<< "Koordinanten:" << xCoord << yCoord;
      qDebug("rechts daneben liegt ein schon gelegter stein");
    if (feldarray[note][yCoord][0]==1)
    {
        qDebug("der stein rechts daneben ist der 1. im zug");
      notetwo=1;
    }
    note=note+1;
  }
  note=xCoord-1;
  while (feldarray[note][yCoord][3]==1)
  {
      qDebug() << "Zeile: 186 "<< feldarray[note][yCoord][0] << feldarray[note][yCoord][1] << feldarray[note][yCoord][2] << feldarray[note][yCoord][3]<< "Koordinanten:" << xCoord << yCoord;
      qDebug("der stein links daneben ist ein schon gelegter stein");
    if (feldarray[note][yCoord][0]==1)
    {
        qDebug("der stein links daneben ist der 1. im zug");
      notetwo=1;
    }
    note=note-1;
  }
  note=yCoord+1;
  while (feldarray[xCoord][note][3]==1)
  {
       qDebug() << "Zeile: 198" << feldarray[xCoord][note][0] << feldarray[xCoord][note][1] << feldarray[xCoord][note][2] << feldarray[xCoord][note][3]<< "Koordinanten:" << xCoord << yCoord;
      qDebug("der stein darüber ist schon gelegt worden");
    if (feldarray[xCoord][note][0]==1)
    {
        qDebug("der stein darüber ist der 1. im zug");
      notetwo=1;
    }
    note=note+1;
  }
  note=yCoord-1;
  while (feldarray[xCoord][note][3]==1)
  {
      qDebug() << "Zeile: 210"  << feldarray[xCoord][note][0] << feldarray[xCoord][note][1] << feldarray[xCoord][note][2] << feldarray[xCoord][note][3]<< "Koordinanten:" << xCoord << yCoord;
      qDebug("der stein darunter ist schon gelegt worden");
    if (feldarray[xCoord][note][0]==1)
    {
      qDebug("der stein darunter ist der 1. stein im zug");
        notetwo=1;
    }
    note=note-1;
  }
  if (notetwo==0)
  {
      qDebug()<< "Zeile: 220" << feldarray[xCoord][yCoord][0] << feldarray[xCoord][yCoord][1] << feldarray[xCoord][yCoord][2] << feldarray[xCoord][yCoord][3];
    qDebug("kein stein drumherum war der 1. im zug");
      return false;
  }
  note=xCoord+1;
  if((feldarray[note][yCoord][1]>0)&&(feldarray[note][yCoord][1]!=colour)&&(feldarray[note][yCoord][2]!=symbol))
  {
    qDebug() << "Zeile: 227" << feldarray[note][yCoord][0] << feldarray[note][yCoord][1] << feldarray[note][yCoord][2] << feldarray[note][yCoord][3];
      qDebug("stein hat die falsche farbe und das falsche symbol, rechts");
      qDebug() << note << yCoord << colour << symbol << feldarray[note][yCoord][1] << feldarray[note][yCoord][2];
      return false;
  }
  note=xCoord-1;
  if((feldarray[note][yCoord][1]>0)&&(feldarray[note][yCoord][1]!=colour)&&(feldarray[note][yCoord][2]!=symbol)&&(feldarray[note][yCoord][1]!=9)&&(feldarray[note][yCoord][2]!=9))
  {
    qDebug() << "Zeile: 234" << feldarray[xCoord][note][0] << feldarray[xCoord][note][1] << feldarray[xCoord][note][2] << feldarray[xCoord][note][3];
      qDebug("stein hat die falsche farbe und das falsche symbol, links");
    qDebug() << note << yCoord << colour << symbol << feldarray[note][yCoord][1] << feldarray[note][yCoord][2];
      return false;
  }
  note=yCoord+1;
  if((feldarray[xCoord][note][1]>0)&&(feldarray[xCoord][note][1]!=colour)&&(feldarray[xCoord][note][2]!=symbol)&&(feldarray[note][yCoord][1]!=9)&&(feldarray[note][yCoord][2]!=9))
  {
      qDebug() << "Zeile: 243" << feldarray[xCoord][note][0] << feldarray[xCoord][note][1] << feldarray[xCoord][note][2] << feldarray[xCoord][note][3];
      qDebug("stein hat die falsche farbe und das falsche symbol, drüber");
      qDebug() << note << yCoord << colour << symbol << feldarray[note][yCoord][1] << feldarray[note][yCoord][2];
    return false;
  }
  note=yCoord-1;
  if((feldarray[xCoord][note][1]!=9)&&(feldarray[xCoord][note][1]!=colour)&&(feldarray[xCoord][note][2]!=symbol))
  {
     qDebug() << "Zeile: 251" << feldarray[xCoord][note][0] << feldarray[xCoord][note][1] << feldarray[xCoord][note][2] << feldarray[xCoord][note][3];
      qDebug("stein hat die falsche farbe und das falsche symbol, drunter");
      qDebug() << note << yCoord << colour << symbol << feldarray[note][yCoord][1] << feldarray[note][yCoord][2];
    return false;
  }


  note=xCoord+1;
    if(feldarray[note][yCoord][1]==colour)
    {
        qDebug("stein hat die richtige Farbe, rechts");
      do{
            if((feldarray[note][yCoord][1]!=colour)||(feldarray[note][yCoord][2]==symbol))
            {
                qDebug("stein hat die andere farbe oder das richtige symbol, rechts lang weiter");
                return false;
            }
        note=note+1;
        qDebug() << note;
      }
        while(feldarray[note][yCoord][1]>0);
        qDebug("solange nach rechts gehen wie steine liegen");
    }
    else if(feldarray[note][yCoord][2]==symbol)
    {
      qDebug("stein hat das richtige symbol, rechts");
        do{
            if((feldarray[note][yCoord][2]!=symbol)||(feldarray[note][yCoord][1]==colour))
            {
              qDebug("stein hat anderes Symbol oder die gleiche farbe, rechts lang weiter");
                return false;
            }
            note=note+1;
      }
      while((feldarray[note][yCoord][1]>0)&&(feldarray[note][yCoord][1]!=9));
    }


    note=xCoord-1;
    if(feldarray[note][yCoord][1]==colour)
    {
      qDebug("stein hat die richtige Farbe, links");
        do{
            if((feldarray[note][yCoord][1]!=colour)||(feldarray[note][yCoord][2]==symbol))
            {
              qDebug("stein hat die andere farbe oder das richtige symbol, links lang weiter");
                return false;
            }
            note=note-1;
      }
      while(feldarray[note][yCoord][1]>0);
      qDebug("solange nach links gehen wie steine liegen");
    }
    else if(feldarray[note][yCoord][2]==symbol)
    {
      qDebug("stein hat das richtige symbol, links");
        do{
            if((feldarray[note][yCoord][2]!=symbol)||(feldarray[note][yCoord][1]==colour))
            {
              qDebug("stein hat anderes Symbol oder die gleiche farbe, links lang weiter");
                return false;
            }
            note=note-1;
      }
        while(feldarray[note][yCoord][1]>0);
        qDebug("solange nach links gehen wie steine liegen");
    }

    note=yCoord+1;
    if(feldarray[xCoord][note][1]==colour)
    {
      qDebug("stein hat die richtige Farbe, drüber");
        do{
            if((feldarray[xCoord][note][1]!=colour)||(feldarray[xCoord][note][2]==symbol))
            {
              qDebug("stein hat die andere farbe oder das richtige symbol, hoch lang weiter");
                return false;
            }
            note=note+1;
      }
        while(feldarray[xCoord][note][1]>0);
        qDebug("solange nach oben gehen wie steine liegen");
    }
    else if(feldarray[xCoord][note][2]==symbol)
    {
      qDebug("stein hat das richtige symbol, oben");
        do{
            if((feldarray[xCoord][note][2]!=symbol)||(feldarray[xCoord][note][1]==colour))
            {
              qDebug("stein hat anderes Symbol oder die gleiche farbe, oben lang weiter");
              return false;
            }
            note=note+1;
      }
        while(feldarray[xCoord][note][1]>0);

        qDebug("solange nach oben gehen wie steine liegen");
    }
    note=yCoord-1;
    if(feldarray[xCoord][note][1]==colour)
    {
      qDebug("stein hat die richtige Farbe, drunter");
        do{
            if((feldarray[xCoord][note][1]!=colour)||(feldarray[xCoord][note][2]==symbol))
            {
              qDebug("stein hat die andere farbe oder das richtige symbol, unten lang weiter");
                return false;
            }
            note=note-1;
      }
        while(feldarray[xCoord][note][1]>0);

        qDebug("solange nach unten gehen wie steine liegen");
    }
    else if(feldarray[xCoord][note][2]==symbol)
    {
      qDebug("stein hat das richtige symbol, unten");
        do{
            if((feldarray[xCoord][note][2]!=symbol)||(feldarray[xCoord][note][1]==colour))
            {
              qDebug("stein hat anderes Symbol oder die gleiche farbe, unten lang weiter");
                return false;
            }
            note=note-1;
          }
        while(feldarray[xCoord][note][1]>0);
       qDebug("solange nach unten gehen wie steine liegen");
    }
    feldarray[xCoord][yCoord][1]=colour;
    feldarray[xCoord][yCoord][2]=symbol;
    feldarray[xCoord][yCoord][3]=1;
    qDebug() << "Werte nach den regeln in den regeln" << colour << symbol << feldarray[xCoord][yCoord][0] << feldarray[xCoord][yCoord][3];
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

