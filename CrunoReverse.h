/*****************************************
 ** File:    CrunoReverse.h
 ** Project: CMSC 202 Project 4, Spring 2016
 ** Author:  Hemang Bhatt
 ** Date:    04/22/16
 **   This file contains the CrunoReverse Class.
*******************************************/

#ifndef CRUNOREVERSE_H
#define CRUNOREVERSE_H

#include "player.h"
#include "game.h"
#include "card.h"

//This CrunoReverse class is derived class
//from Card class
 
class CrunoReverse: public Card {

 public:

  // This alternate constructor takes suits value
  // and assignes to appropriate member values 
  CrunoReverse(unsigned int s);

  // This virtual void playCard function takes Game and Player class
  // Pointers, and decided play card
  virtual void playCard(Game *gptr, Player *pptr);

  //This function prints appropriate taken action on card
  virtual string toString() ;

};

#endif
