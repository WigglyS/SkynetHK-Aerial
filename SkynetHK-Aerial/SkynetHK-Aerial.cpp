// SkynetHK-Aerial.cpp : Defines the entry point for the console application.

#include "stdafx.h"
//lets me use rand()
#include <cstdlib>
#include "iostream"
//lets me check the time
#include <ctime>

using namespace std;
int highNumber = 64;
int lowNumber = 1;
int guess = 0;
int numGuess = 1;
char again;

int main()
{
	
	do
	{ 
		//have to reset the numbers for the play again
		highNumber = 64;
		lowNumber = 1;
		numGuess = 1;
		

		// seeds the random number based of the time
		srand(static_cast<unsigned int>(time(0)));
		// picks a random number 1-64
		int EnemyLocation = (rand() % 64) + 1;

		cout << "Enemy Location = " << EnemyLocation<< "\n";
		system("pause");

		//make the guess the bianary search function
		int guess = (highNumber - ((highNumber - lowNumber) / 2)+ lowNumber);
		cout << "\nSkynet drone guesses grid square: " << guess;

		while (guess != EnemyLocation)
		{
			
			
			//sets the new high or low number based on if it was high or low
			if (guess > EnemyLocation)
			{
				highNumber = guess;
				guess = (((highNumber - lowNumber) / 2) + lowNumber);
				cout << "\nSkynet drone guesses grid square: " << guess;
				//incriment so it counts how many guesses it takes
				++numGuess;

			}
			if (guess < EnemyLocation)
			{
				lowNumber = guess;
				guess = (((highNumber - lowNumber) / 2) + lowNumber);
				cout << "\nSkynet drone guesses grid square: " << guess;
				//incriment so it counts how many guesses it takes
				++numGuess;
			}

			//the while loop didnt end when the guess hit the number so i added this
			if (guess == EnemyLocation)
			{
				break;
			}


		}
		cout << "\nIt took " << numGuess << " guesses to find to location of the enemy\n";

		cout << "\n run again? (y/n): ";
		cin >> again;
		//lets you run the program again if the used put y
	} while (again == 'y');
	

    return 0;
}

