/*
       Authors: Matt Vavro, Nate Henry, Zach Matthews, Braden Ritts
       Course: COMP 220, Computer Programming II
       Date: 
       Description: Simulates a two player card game of War 
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>


using namespace std;


class WAR
{
       friend class PLAYER;
public:
       void shuffleCards(PLAYER& p1, PLAYER& p2);
          void reShuffleCards(PLAYER& p);
       int compareCards(int oneTop, int twoTop);
       void draw(PLAYER& p1, PLAYER& p2);
       vector<int> drawn;
       int victor;


private:
       int oneTop;
       int twoTop;
       int winner;
       string oneSuit;
       string twoSuit;
       string oneCard;
       string twoCard;

} ;

class PLAYER
{
public:
       void giveCards(WAR& w);
       void addCards();
       vector<int> cards;
} ;



int main()
{

       WAR deck;

       PLAYER playerOne;
       PLAYER playerTwo;
          
       deck.shuffleCards(playerOne,playerTwo);                                   

       do
       {
              do
              {
                    deck.victor = deck.compareCards(playerOne.cards[0], playerTwo.cards[0]);


                    if (deck.victor == 1)                    
                    {
                           playerOne.giveCards(deck);                      // gives won cards to player one
                           playerOne.cards.erase(playerOne.cards.begin());
                           playerTwo.cards.erase(playerTwo.cards.begin());
                    }
              
                    else if (deck.victor == 2)                    
                    {
                            playerTwo.giveCards(deck);                      // gives won cards to player two
                            playerOne.cards.erase(playerOne.cards.begin());
                            playerTwo.cards.erase(playerTwo.cards.begin());
                    }
       
                    else
                    {
                            playerOne.cards.erase(playerOne.cards.begin());
                            playerTwo.cards.erase(playerTwo.cards.begin());
                            deck.draw(playerOne, playerTwo);                                      
                    }

              } while (deck.victor == 3);

                       cout << "At the end of this round, player 1 has " << playerOne.cards.size() << " cards." << endl;
                       cout << "At the end of this round, player 2 has " << playerTwo.cards.size() << " cards.\n" << endl;

                       deck.reShuffleCards(playerOne);
                       deck.reShuffleCards(playerTwo);

          } while (playerOne.cards.size() > 0 && playerTwo.cards.size() > 0);        // runs while neither player is out of cards


       if (playerOne.cards.size() == 0)
       {
              cout << "Player Two has won!" << endl;
       }

       if (playerTwo.cards.size() == 0)
       {
              cout << "Player One has won!" << endl;
       }

       return 0;
}


int WAR::compareCards(int oneTop, int twoTop)		// compares the cards that have been drawn and prints to the screen which player won the hand and how many cards each have remaining
{

       drawn.push_back(oneTop);
       drawn.push_back(twoTop);

       if (oneTop > 0 && oneTop <= 13)
       {
              oneSuit = " of spades";
       } 
       else if (oneTop > 13 && oneTop <= 26)
       {
              oneTop -= 13;
              oneSuit = " of clubs";
       }
       else if (oneTop > 26 && oneTop <= 39)
       {
              oneTop -= 26;
              oneSuit = " of diamonds";
       }
       else if (oneTop > 39 && oneTop <= 52)
       {
              oneTop -= 39;
              oneSuit = " of hearts";
       }
       
       else 
       {
              oneSuit = "ERROR";
       }

       
       switch (oneTop)
       {
              case 1: 
                     oneCard = "Two";
                     break;
              case 2:
                     oneCard = "Three";
                     break;
              case 3: 
                     oneCard = "Four";
                     break;
              case 4: 
                     oneCard = "Five";
                     break;
              case 5: 
                     oneCard = "Six";
                     break;
              case 6: 
                     oneCard = "Seven";
                     break;
              case 7: 
                     oneCard = "Eight";
                     break;
              case 8: 
                     oneCard = "Nine";
                     break;
              case 9: 
                     oneCard = "Ten";
                     break;
              case 10: 
                     oneCard = "Jack";
                     break;
              case 11: 
                     oneCard = "Queen";
                     break;
              case 12: 
                     oneCard = "King";
                     break;
              case 13: 
                     oneCard = "Ace";
                     break;
              default:
                     oneCard = "ERROR";
                     break;
       
       }


       if (twoTop > 13 && twoTop <= 26)
       {
              twoTop -= 13;
              twoSuit = " of clubs";
       }
       else if (twoTop > 26 && twoTop <= 39)
       {
              twoTop -= 26;
              twoSuit = " of diamonds";
       }
       else if (twoTop > 39 && twoTop <= 52)
       {
              twoTop -= 39;
              twoSuit = " of hearts";
       }
       else if (twoTop > 0 && twoTop <= 13)
       {
              twoSuit = " of spades";
       } 


       switch (twoTop)
       {
              case 1: 
                     twoCard = "Two";
                     break;
              case 2:
                     twoCard = "Three";
                     break;
              case 3: 
                     twoCard = "Four";
                     break;
             case 4: 
                     twoCard = "Five";
                     break;
              case 5: 
                     twoCard = "Six";
                     break;
              case 6: 
                     twoCard = "Seven";
                     break;
              case 7: 
                     twoCard = "Eight";
                     break;
              case 8: 
                     twoCard = "Nine";
                     break;
              case 9: 
                     twoCard = "Ten";
                     break;
              case 10: 
                     twoCard = "Jack";
                     break;
              case 11: 
                     twoCard = "Queen";
                     break;
              case 12: 
                     twoCard = "King";
                     break;
              case 13: 
                     twoCard = "Ace";
                     break;
              default:
                     twoCard = "ERROR";
                     break;
       
       }


       cout << "Player One drew the " << oneCard << oneSuit << "." << endl;
       cout << "Player Two drew the " << twoCard << twoSuit << "." << endl;

       if (oneTop > twoTop)
       {
              cout << "Player One wins this hand" << endl;
              winner = 1;
       }

       else if (twoTop > oneTop)
       {
              cout << "Player Two wins this hand" << endl;
              winner = 2;
       }

       else
       {
              cout << "This hand is a draw, three cards will be placed aside by each player and then redraw." << endl;
              winner = 3;
       }

       return winner;
}

void WAR::draw(PLAYER& p1, PLAYER& p2)			// places 3 cards aside from each player to be won in the next round 
{
    for (int i = 0; i < 3; i++)
    {
              if(p1.cards.size() == 0)
              {
                     cout << "Player one doesn't have enough cards to finish the duel. They will give the rest of their cards to Player two." << endl;
                     while (drawn.size() > 0)
                     {
                           p2.cards.push_back(drawn[0]);
                           drawn.erase(drawn.begin());
                     }
                     victor = 0;
                     return;
                           
              }

              if(p2.cards.size() == 0)
              {
                     cout << "Player two doesn't have enough cards to finish the duel. They will give the rest of their cards to Player one." << endl;
                     while(drawn.size() > 0)
                     {
                           p1.cards.push_back(drawn[0]);
                           drawn.erase(drawn.begin());
                     }
                     victor = 0;
                     return;
                           
              }

              drawn.push_back(p1.cards[0]);
              drawn.push_back(p2.cards[0]);
              p1.cards.erase(p1.cards.begin());
              p2.cards.erase(p2.cards.begin());
    }

       if(p1.cards.size() == 0)
              {
                  cout << "Player one doesn't have enough cards to finish the duel. They will give the rest of their cards to Player two." << endl;
                  while (drawn.size() > 0)
                  {
                        p2.cards.push_back(drawn[0]);
                        drawn.erase(drawn.begin());
                  }
                  victor = 0;
                  return;
                           
              }

              if(p2.cards.size() == 0)
              {
                     cout << "Player two doesn't have enough cards to finish the duel. They will give the rest of their cards to Player one." << endl;
                     while(drawn.size() > 0)
                     {
                           p1.cards.push_back(drawn[0]);
                           drawn.erase(drawn.begin());
                     }
                     victor = 0;
                     return;
                           
              }
       
}

void PLAYER::giveCards(WAR& w)				// places the cards from this hand into the winner's pile of won cards.
{
       for(int i = 0; i < w.drawn.size(); i++)
       {
              cards.push_back(w.drawn[i]);
       }
          w.drawn.erase(w.drawn.begin(),w.drawn.end());
       return;
}

void WAR::shuffleCards(PLAYER& p1, PLAYER& p2)       // creates vector for the cards and randomizes their order and deals them into 2 stacks, one for each player
{
       srand(time(0));
       int count = 0;
       while(count<26)
       {
			int x = (rand () % 52)+1;
            int check = 0;

            for(int z=0;z<p1.cards.size();z++)
            {
                  if(x == p1.cards[z])
                  {
					  check = 1;
                  }
            }
            if(check == 0)
            {
                 p1.cards.push_back(x);
                 count++;
            }
       }
       for(int i=0;i<500;i++)
       {
              int check = 0;
              int x = (rand () % 52)+1;

              for(int z=0;z<p1.cards.size();z++)
              {
                     if(x == p1.cards[z])
                     {
                           check = 1;
                     }
              }
              for(int y=0;y<p2.cards.size();y++)
              {
                     if(x == p2.cards[y])
                     {
                           check = 1;
                     }
              }
              if(check == 0)
              {
                     p2.cards.push_back(x);
              }
       }
}

void WAR::reShuffleCards(PLAYER& p)				// reshuffles the cards after a player's stack has been played to avoid an infinite loop 
{
       vector<int> temp;

       while (p.cards.size() > 0)
       {
              int x = rand() % p.cards.size();
              temp.push_back(p.cards[x]);
              p.cards.erase(p.cards.begin() + x);
       }

       while (temp.size() > 0)
       {
              p.cards.push_back(temp[0]);
              temp.erase(temp.begin());
       }
}


