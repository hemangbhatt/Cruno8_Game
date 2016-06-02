/*****************************************                                                                                                                                                                 
 ** File:    CrunoReverse.cpp                                                                                                                                                                                    
 ** Project: CMSC 202 Project 4, Spring 2016                                                                                                                                                               
 ** Author:  Hemang Bhatt                                                                                                                                                                                  
 ** Date:    04/22/16                                                                                                                                                                                      
 **   This file contains the implemention of CrunoReverse Class.                                                                                                                                                   
 ******************************************/

#include "CrunoReverse.h"
#include "card.h"
#include "CrunoGame.h"
#include "CrunoPlayer.h"
#include <sstream>
#include <string>

using namespace std;

#include <iostream>
#include <string>


// assignes value
CrunoReverse::CrunoReverse(unsigned int s) {
  m_suit = s;
  m_points = 16;
}

// Plays Skip card
void CrunoReverse::playCard(Game *gptr, Player *pptr) {

  CrunoGame* cgptr = dynamic_cast<CrunoGame*>(gptr);
  
  cgptr->isReversed = !cgptr->isReversed;

  cgptr->setSuit(m_suit);
  cgptr->setPoints(m_points);

}


//Print Wild cards
string CrunoReverse::toString() {

  ostringstream oss ;

  oss << "REVERSE";

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
