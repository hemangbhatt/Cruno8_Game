/***********************************************
 ** File:    CrunoPlayer.cpp                                                                                                                                                                
 ** Project: CMSC 202 Project 4, Spring 2016                                                                                                                                                               
 ** Author:  Hemang Bhatt                                                                                                                                                                                  
 ** Date:    04/22/16                                                                                                                                                                                      
 **                                                                                                                                                                                                        
 **   This file contains the implemention of CrunoPlayer Class.                                                                                                                                                 
 ***********************************************/

#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std ;

#include "card.h"
#include "CrunoPlayer.h"
#include "CrunoGame.h"


CrunoPlayer::CrunoPlayer(Game* gptr, unsigned int numCards) : Player(gptr, numCards)
{}


// A smarter player will pick a suit 
// based on his/her hand (e.g., pick the most common suit).
// 
//
unsigned int CrunoPlayer::pickSuit() {
  int countClubs = 0;
  int countDiamonds = 0;
  int countHearts = 0;
  int countSpades = 0;

  for(int i = 0; i < m_numCards; i++) {

      if ( m_cards[i]->getSuit() == 1 )
	countClubs++;
      
      else if ( m_cards[i]->getSuit() == 2 )
	countDiamonds++;

      else if ( m_cards[i]->getSuit() == 3 )
	countHearts++;

      else if ( m_cards[i]->getSuit() == 4 )
	countSpades++;
    }

  int suit[4] = {countClubs, countDiamonds, countHearts, countSpades};
  unsigned int max = 0;
  for (int i = 0; i < 4; i++) {
    if (suit[i] > max)
      max = i;
}

  max += 1; // to return the value of high number of cards for suit
  return max;
  
}
