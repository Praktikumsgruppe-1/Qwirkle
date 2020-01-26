/*
int hand;                                                                          // Anzahl der Handsteine des letzten spielers
int pass;                                                                          // anzahl der gepassten Runden in folge Pascal hat gesagt er würde den counter dafür machen
int endcheck(int pass, int hand)
{
  int *p;
  int playercount=2;                                                               // Anzahl der Spieler wird überprüft
  if (player3points>0)
  {
    playercount=3;
  }
  if (player4points>0)
  {
    playercount=4;
  }
  if(Game.beutelStackFarbe.empty() && pass==playernumber)                         // alle haben gepasst,
    {
        p=winner(player1points,player2points,player3points,player4points);
        cout << *(p+3) << endl << *(p+2) << endl;
        if(*(p+1)>0){
          cout << *(p+1) << endl;
        }
        if(*(p+0)>0){
          cout << *(p+0) << endl;
    }
  }else if(Game.beutelStackFarbe.empty() && hand==0){  // Beutel und Hand leer
    //hier müssne dem zuletzt aktiven Spieler noch 6 Punkte gegeben werden
    p=winner(player1points,player2points,player3points,player4points);
    cout << *(p+3) << endl << *(p+2) << endl;
    if(*(p+1)>0){
      cout << *(p+1) << endl;
    }
    if(*(p+0)>0){
      cout << *(p+0) << endl;
    }
  }else(){
    return 0;
  }
}

int * winner(int player1, int player2, int player3, int player4)
{
  static int ergebnis[]={player1,player2,player3,player4};
  sort(ergebnis, ergebnis+4);
  return ergebnis;
}
*/
