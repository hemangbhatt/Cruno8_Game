/*****************************************
** File:    CrunoSkip.h
** Project: CMSC 202 Project 4, Spring 2016
** Author:  Hemang Bhatt
** Date:    04/22/16
**   This file contains the CrunoSkip class.
*******************************************/

#ifndef CRUNOSKIP_H
#define CRUNOSKIP_H

#include "CrunoGame.h"
#include "CrunoPlayer.h"
#include "game.h"
#include "player.h"
#include "card.h"

class CrunoSkip: public Card {
 
 public:

  CrunoSkip(unsigned int s);

  virtual void playCard(Game *gptr, Player *pptr);

  virtual string toString() ;
};



#endif
