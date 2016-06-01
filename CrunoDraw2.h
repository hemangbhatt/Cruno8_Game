/*****************************************
** File:    CrunoDraw2.h
** Project: CMSC 202 Project 4, Spring 2016
** Author:  Hemang Bhatt
** Date:    04/22/16
**   This file contains the function prototypes for CrunoDraw2 class.
******************************************/

#ifndef CRUNODRAW2_H
#define CRUNODRAW2_H

#include "player.h"
#include "game.h"
#include "card.h"

// The CrunoDraw2 Class is Derived class from
// Card class.
class CrunoDraw2: public Card {

 public:


  //This constructor assignes the suit value
  CrunoDraw2(unsigned int s);

  // This virtual function takes action about playing card.
  virtual void playCard(Game *gptr, Player *pptr);

  // This virtual function print the taken action about card.
  virtual string toString() ;

};

#endif
