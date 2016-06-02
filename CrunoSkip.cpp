/*****************************************                                                                                                                                                       
 ** File:    CrunoSkip.cpp
 ** Project: CMSC 202 Project 4, Spring 2016                                                                                                                                                               
 ** Author:  Hemang Bhatt                                                                                                                                                                                  
 ** Date:    04/22/16                                                                                                                                                                                      
 **   This file contains the implemention of CrunoSkip Class.                                                                                                                                                 
*******************************************/

#include <iostream>
#include <sstream>
#include <string>

using namespace std ;

#include "CrunoSkip.h"
#include "card.h"
#include "CrunoGame.h"
#include "CrunoPlayer.h"
#include "player.h"


CrunoSkip::CrunoSkip(unsigned int suit) {

  m_suit = suit;
  m_points = 15;

}


// Plays Skip Card
void CrunoSkip::playCard(Game *gptr, Player *pptr) {

  CrunoGame* cgptr = dynamic_cast<CrunoGame*>(gptr);
  cgptr->nextPlayer();
  
  gptr->setSuit(m_suit);
  gptr->setPoints(m_points);
 
}

// Print Action of Wild Cards
string CrunoSkip::toString() {

  ostringstream oss ;

  oss << "SKIP";

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
