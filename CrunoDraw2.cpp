/*****************************************                                                                                                                                                                 
 ** File:    CrunoDraw2.cpp                                                                                                             
 ** Project: CMSC 202 Project 4, Spring 2016                                                                                                                                                               
 ** Author:  Hemang Bhatt                                                                                                                                                                                  
 ** Date:    04/22/16                                                                                                                                                                                      
 **   This file contains the implemention of CrunoDraw2 Class.                                                                                                                                                 
********************************************/

#include <iostream>
#include <sstream>
#include <string>

using namespace std ;

#include "CrunoDraw2.h"
#include "card.h"
#include "CrunoGame.h"
#include "CrunoPlayer.h"


// Assignes CrunoDraw2 value and suit
CrunoDraw2::CrunoDraw2(unsigned int suit) {
  m_suit = suit;
  m_points = 17;
}

// Plays CrunoDraw2 Cards
void CrunoDraw2::playCard(Game *gptr, Player *pptr) {

  CrunoGame* cgptr = dynamic_cast<CrunoGame*>(gptr);
  
  CrunoPlayer* cpptr = dynamic_cast<CrunoPlayer*>(pptr);

  Card* card1 = cgptr->dealOneCard();
  Card* card2 = cgptr->dealOneCard();
  

  Player* nextPlayer; 
  nextPlayer = cgptr->getPlayerById(cgptr->playerAfter(cgptr->currentPlayer()));
  
  nextPlayer->takeCard(card1);
  nextPlayer->takeCard(card2);
  
  
  gptr->setSuit(m_suit);
  gptr->setPoints(m_points);


}


//Prints Wild Card
string CrunoDraw2::toString() {

  ostringstream oss ;

  oss << "DRAW 2";

  switch ( m_suit ) {
  case Clubs :
    oss << " of Clubs" ;
    break ;
  case Diamonds :
    oss << " of Diamonds" ;
    break ;
  case Hearts :
    oss << " of Hearts" ;
    break ;
  case Spades :
    oss << " of Spades" ;
    break ;
  default :
    oss << "of INVALID SUIT\n" ;
  }
  return oss.str() ;
}
