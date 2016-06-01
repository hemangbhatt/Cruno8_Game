/*********************************************************
** Project:     CMSC 202 Project4, Spring 2016                                                                                                                                                            
** Author:      Hemang Bhatt                                                                                                                                                                              
** Date:        03/10/15                                                                                                                                                                                  
** This file contains Cruno8 class' functions prototypes. 
 **********************************************************/

#ifndef CRUNO8_H
#define CRUNO8_H

#include "card.h"
#include "game.h"
#include "player.h"


// Cruno8 class is derived class of Card Class

class Cruno8: public Card {

 public:

  // Alternate constructor assignes suit
  Cruno8(unsigned int suit);


  // This virtual bool function decides whether
  // card is playble or not
  // This function takes Game pointer
  virtual bool playable(Game *gptr);


  // This virtual void function takes game pointer and player pointer
  // and plays card
  virtual void playCard(Game *gptr, Player *pptr);


  // This virtual string function prints 
  // taken action.
  virtual string toString() ;
};


#endif
