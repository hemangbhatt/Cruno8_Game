/************************************************   
 ** File:    Cruno8.cpp                                                          
 ** Project: CMSC 202 Project 4, Spring 2016                                    
 ** Author:  Hemang Bhatt                                                       
 ** Date:    04/22/16                                                           
 **                                                                             
 **                                                                             
 ***********************************************/

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
using namespace std ;

#include "Cruno8.h"
#include "card.h"
#include "CrunoGame.h"
#include "CrunoPlayer.h"



// Alternate constructor to assign value and check for sanity
Cruno8:: Cruno8(unsigned int s) {

  if (s > Spades) { // sanity check
    s = Invalid;
}
  m_suit = s ;

  m_points = 8 ;
}




// This function is called when cruno8 card is used
bool Cruno8::playable(Game *gptr) {

  return true;
}


// This function plays Cruno8 card and chooses which suits to pick.
void Cruno8::playCard(Game *gptr, Player *pptr) {


  // Dynamic cast to cast pointer type
  CrunoPlayer* cpptr = dynamic_cast<CrunoPlayer*>(pptr);
  unsigned int suit = cpptr->pickSuit();
  CrunoGame* cgptr = dynamic_cast<CrunoGame*>(gptr);
  

  // prints picked card
  switch(m_suit) {
  case Clubs:
    cout << "Clubs picked" << endl;
    break;
  case Spades:
   cout << "Spades picked" << endl;
   break;
 case Hearts:
   cout << "Hearts picked" << endl;
   break;
  case Diamonds:
    cout << "Diamonds picked " << endl;
    break;
  default:
    cout << "No color picked" << endl;
  }
 
  cgptr->setSuit(suit);
  cgptr->setPoints(8);
  return ;
}



// Prints suits and card value
string Cruno8::toString() {

  ostringstream oss ;

  oss << "8";

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
