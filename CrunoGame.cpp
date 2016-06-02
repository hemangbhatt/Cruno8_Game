/*****************************************
 ** File:    CrunoGame.cpp                                                                                                                                                             
 ** Project: CMSC 202 Project 4, Spring 2016                                                                                                                                                               
 ** Author:  Hemang Bhatt                                                                                                                                                                                  
 ** Date:    04/22/16                                                                                                                                                                                      
 **   This file contains the implemention of CrunoGame Class.                                                                                                                                                 
 ***********************************************/

#include <stdlib.h>
#include <iostream>
using namespace std ;

#include "CrunoSkip.h"
#include "CrunoReverse.h"
#include "CrunoDraw2.h"

#include "Cruno8.h"
#include "card.h"
#include "player.h"
#include "CrunoGame.h"

// Check the validity for crashing programs

static void ifNullCrash(void *ptr) {
  if (ptr == NULL) {
    cerr << "Could not allocate memory\n" ;
    exit(1) ;
  }
  return ;
}


// Initialize the game based on the number of players.
void CrunoGame::initialize(int numPlayers) {
   m_suit = 0 ;
   m_points = 0 ;
   m_currentPlayer = 0 ;

   // can't play by yourself
   //
   if (numPlayers < 2) {
      cerr << "Insufficient players\n" ;
      exit(1) ;
   }

   // not enough cards to make it fun for >10.
   //
   if (numPlayers > 10) {
      cerr << "Too many players\n" ;
      exit(1) ;
   }

   m_numPlayers = 0 ;  // no players added yet.

   // allocate space for max requested
   //
   m_maxPlayers = numPlayers ;
   m_players = new Player*[numPlayers] ;
   ifNullCrash(m_players) ;

   m_winner = m_maxPlayers + 1 ;  // not a real player

   // usually use just one deck
   int decks = 1 ;
   m_maxCards = 52+24 ;   // 52 cards in one deck

   if (numPlayers > 5) {
      // use two decks
      decks = 2 ;
      m_maxCards = 104+24+24 ;   // 104 cards in two decks
   }


   // allocate space for the discard pile
   m_discard = new Card*[m_maxCards] ;
   ifNullCrash(m_discard) ;
   m_numDiscard = 0 ;  // nothing discarded yet

   // allocate space for the stock pile
   m_stock = new Card*[m_maxCards] ;
   ifNullCrash(m_stock) ;


   int i = 0 ;  // next available slot in m_stock[]

   for (int d = 0 ; d < decks ; d++) {  // # of decks
      
      // iterate over suits
      for (unsigned int s = Card::Clubs ; s <= Card::Spades ; s++) {

         // iterate over point values 
         for (unsigned int p = 2 ; p <= 17 ; p++) {

	   if(p == 8) {
	       m_stock[i] = new Cruno8(s);
	       i++;
	       continue;
	   }
	   if(p == 15) {
	       m_stock[i] = new CrunoSkip(s);
	       i++;
	       m_stock[i] = new CrunoSkip(s);
	       i++;
	       continue;
	   }
	   
	   if(p == 16) {
             
	       m_stock[i] = new CrunoReverse(s);
	       i++;
               m_stock[i] = new CrunoReverse(s);
	       i++;
	       continue;
      }

	   if(p == 17) {
             
	       m_stock[i] = new CrunoDraw2(s);
	       i++;
               m_stock[i] = new CrunoDraw2(s);
	       i++;
	       continue;
	   }

            m_stock[i] = new Card(s,p) ;  // insert new card
            ifNullCrash(m_stock[i]) ;
            i++ ;

         }
      }
   }

   // remember how many cards we added
   m_numStock = m_maxCards ;

   // Still haven't started (need to have players added)
   m_started = false ;
   m_over = false ;
}



// Deals one Cards

Card *CrunoGame::dealOneCard() {
   Card *cptr ;

   // Sanity check
   //
   if (m_numStock < 1) {
     Card** temp = m_stock;
     m_stock = m_discard;
     m_discard = temp;
     
     m_numStock = m_numDiscard;
     m_numDiscard = 0;
     
     m_discard[0] = m_stock[m_numStock - 1];
     m_numDiscard++;
     m_numStock--;
     // Random seed to shuffle
     srand(12131243243423) ;                                                                                                                                
     for(unsigned int i = 0 ; i < m_numStock ; i++) {                                                                                             
       Card *temp ;                                                                                                                              
                                                                                                                                                
       unsigned int j = rand() % m_numStock ;                                                                                                                 
       temp = m_stock[i] ;                                                                                                                       
       m_stock[i] = m_stock[j] ;                                                                                                                 
       m_stock[j] = temp ;                                                                                                                       
     }   
     
     
   }

   // Gimme!
   //
   m_numStock-- ;
   cptr = m_stock[m_numStock] ;
   m_stock[m_numStock] = NULL ;

   return cptr ;
}


// use % m_numPlayers to wrap around.
//

Player* CrunoGame::getPlayerById(unsigned int i) {
  return m_players[i];
}

unsigned int CrunoGame::nextPlayer() {
  if(isReversed == false) {

    m_currentPlayer = (m_currentPlayer + 1) % m_numPlayers ;
     return m_currentPlayer ;
  }
  else {
      m_currentPlayer -= 1;
      if(m_currentPlayer == -1)
	m_currentPlayer = m_numPlayers - 1;
      return m_currentPlayer;
    }
}


// use % m_numPlayers to wrap around.
//
unsigned int CrunoGame::playerAfter(unsigned int thisPlayer) {
  if(isReversed == false) 
    return (thisPlayer + 1) % m_numPlayers ;

  else {
      int i = thisPlayer - 1;
      if(i == -1)
	i = m_numPlayers - 1;
      return i;
    }
}
