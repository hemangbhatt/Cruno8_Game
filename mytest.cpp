/*****************************************
 * ** File:    mytest.cpp
 * ** Project: CMSC 202 Project 4, Spring 2016
 * ** Author:  Hemang Bhatt
 * ** Date:    4/22/16
 * **   This file contains the main driver program for Project 4.
 * ***********************************************/
 
 // This is a test file


#include <iostream>
using namespace std ;


#include "Cruno8.h"
#include "CrunoSkip.h"
#include "CrunoReverse.h"
#include "CrunoDraw2.h"
#include "card.h"
#include "CrunoGame.h"
#include "CrunoPlayer.h"

int main() {

   CrunoGame G ;

   G.initialize(10) ;  // say we'll have ten players

   // Make the 10 players and add them
   // We could add any object derived from Player.
   // So, we can have a mix of smart, dumb or cheating
   // players in the same game.
   //

   int n = G.getNumCards() ;
   CrunoPlayer *pptr1 = new CrunoPlayer(&G,n) ;
   CrunoPlayer *pptr2 = new CrunoPlayer(&G,n) ;
   CrunoPlayer *pptr3 = new CrunoPlayer(&G,n) ;
   CrunoPlayer *pptr4 = new CrunoPlayer(&G,n) ;

   CrunoPlayer *pptr5 = new CrunoPlayer(&G,n) ;
   CrunoPlayer *pptr6 = new CrunoPlayer(&G,n) ;
   CrunoPlayer *pptr7 = new CrunoPlayer(&G,n) ;
   CrunoPlayer *pptr8 = new CrunoPlayer(&G,n) ;

   CrunoPlayer *pptr9 = new CrunoPlayer(&G,n) ;
   CrunoPlayer *pptr10 = new CrunoPlayer(&G,n) ;
   


   G.addPlayer(pptr1) ;
   G.addPlayer(pptr2) ;
   G.addPlayer(pptr3) ;
   G.addPlayer(pptr4) ;
   G.addPlayer(pptr5) ;
   G.addPlayer(pptr6) ;
   G.addPlayer(pptr7) ;
   G.addPlayer(pptr8) ;

   //G.addPlayer(pptr9) ;
   //G.addPlayer(pptr10) ;
   

   // Play game with different random seeds.
   // The random seeds control the initial shuffle.

   //   G.startGame(3810743) ;
   G.startGame(8132987) ;
   //   G.startGame(7831035) ;
//   G.startGame(2310831) ;

   return 0 ;
}
