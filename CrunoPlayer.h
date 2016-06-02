/*****************************************
** File:    CrunoPlayer.h
** Project: CMSC 202 Project 4, Spring 2016
** Author:  Hemang Bhatt
** Date:    04/22/16

** This file has the class declarations for the CrunoPlayer class.
*******************************************/

#ifndef CRUNOPLAYER_H
#define CRUNOPLAYER_H

#include "player.h"
#include "card.h"
#include "game.h"



// This CrunoPlayer is derived class from player class

class CrunoPlayer : public Player {

public:

   // Make a player. Worst case scenario, the player has all
   // of the cards. So, need to know numCards to allocate 
   // enough space.
  CrunoPlayer(Game* gptr, unsigned int numCards);
  
   // Player may be asked to pick a suit (e.g., after playing an 8 in Crazy Eights).
   // Based on maximum cards individual has of same suits.
   virtual unsigned int pickSuit() ;

 
};
#endif
