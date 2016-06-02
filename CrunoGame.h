/*****************************************
** File:    CrunoGame.h
** Project: CMSC 202 Project 4, Spring 2016
** Author:  Hemang Bhatt
** Date:    04/22/16
** This file has the class declarations for the CrunoGame class. 
********************************************/

#ifndef CrunoGame_H
#define CrunoGame_H

#include "game.h"

class Cruno8;
class CrunoSkip;
class CrunoDraw2;
class CrunoPlayer;
class Card ;
class Player ;

class CrunoGame : public Game {

public:

  // Flag to check that is the game play
  bool isReversed;


   // This function return the player id to
   // use pointers on.
  Player* getPlayerById(unsigned int i);
  
  // This Function initialize number of players in the game.
  virtual void initialize(int numPlayers) ;


  // This functions deals card when necessary
  virtual Card * dealOneCard() ;


   // This functions returns the next player value;
   virtual unsigned int nextPlayer() ;


   // Given the current direction of play, the player that would
   // have the turn after thisPlayer's turn. The playGame() function
   // uses playerAfter() to step through the players.
   //
   virtual unsigned int playerAfter(unsigned int thisPlayer) ;

};

#endif
