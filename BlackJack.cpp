// BlackJack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Cards.h"
#include "Players.h"
#include <cstdlib>
#include <ctime>


using namespace std;

void populateDeck(Cards[]);

int generateRandom();
//Write a function that replaces
// 1. Producing a random number (done)
// 2. Turning the corresponding position in repeat array to true (encapsulates 1)
// 3. Adding Card to Hand
// 4. returns value





int main()


{	
	int highPlayer = 0;
	Cards deck[53];
	int highScore = 0;
	 repeat[53];

	populateDeck(deck);

	int numPlayers;
	int cardPos = -1;

	cout << "How many players? Between 2 - 4" << endl;
	cin >> numPlayers;
	cout << "Players: " << numPlayers << endl;

	Players Player[4];
	int value = 0;
	for (int num = 0; num < numPlayers; num++) {
		cout << "Player: " << num << endl;

		for (int cardNo = 1; cardNo < 3; cardNo++) {

			cout << "Card No " << cardNo << endl;

			do
			{

				cardPos = generateRandom();
				cout << "Number generated: " << cardPos << endl;
				
			} while (repeat[cardPos] == true);


			repeat[cardPos] = true;
			Player[num].AddCard(deck[cardPos]);
			cout << endl;
		}

		cout << " Player " << num << " has: ";

		value = Player[num].ShowHand();
		cout << endl;

		string newCard;

		do
		{
			cout << "Would you like a new card? Y/N" << endl;
			cin >> newCard;
			if(newCard == "Y") {
				do
				{
					cardPos = generateRandom();
					cout << "Number generated: " << cardPos << endl;
					cin.get();
				} while (repeat[cardPos] == true);

				repeat[cardPos] = true;
				Player[num].AddCard(deck[cardPos]);
				cout << endl;
				value = Player[num].ShowHand();

			}
			
			
		} while (newCard == "Y" && value < 21);

		if (value <= 21 && value > highScore) {
			highScore = value;
			highPlayer = num;
		}
	}

	cout << "Winner is Player: " << highPlayer << endl;
	cout << "Score is " << highScore << "\n";
	
	cin.get();
	system("pause");
    return 0;
}

//Write a function that populates a deck fo 52 cards producing an array of objects
//pass array by reference
//populate variables

int generateRandom() {

	srand(time(0));

	return ((rand() % 52) + 1);
}

void populateDeck(Cards deck[]) {

	for (int i = 1; i < 53; i++) {

		if (i <= 13) {
			deck[i].SetType("Spades");
			deck[i].SetNumber(i);
		}
		else if (i <= 26) {
			deck[i].SetType("Clubs");
			deck[i].SetNumber(i - 13);

		}
		else if (i <= 39) {
			deck[i].SetType("Diamonds");
			deck[i].SetNumber(i - 26);
		}
		else if (i <= 52) {
			deck[i].SetType("Hearts");
			deck[i].SetNumber(i - 39);
		}

		cout << "Type: " << deck[i].GetType() << " || " << "Number: " << deck[i].GetNumber() << endl;

	}
}



