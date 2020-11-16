/* 11/15/2020
* a code program similar to hangman.
Jacob Schatzer */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <Windows.h>

using namespace std;

// Create an int var to count the number of simulations being run starting at 1
int simNumber = 1;

// maximum number of incorrect guesses allowed
const int MAX_WRONG = 5;

int main()
{

	// Display Title of program to user
	printf("\nKeywords 2\n");
	

	// Ask the recruit to login using thier name
	char recruitName[100];
	printf("Hello Recruit. What is your name?\n");

	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	cin.getline(recruitName, sizeof(recruitName));

	// Display an overview of what Keywords II is to the recruit 
	system("cls");
	cout << "\n\nHello " << recruitName << "!\n" << endl;
	cout << "Congratulations gettting into the CIA!\n" << endl;
	cout << "The following is a new code breaking program>>";
	

	// Display directions to the recruit on how to use Keywords
	cout << "Instructions:\n" << endl;
	cout << "This Code Breaker Training Simulation Program will randomly select 3 words." << endl;
	cout << "Unlike the first earlier version of Keywords I, you will not see the scrambled letters!" << endl;
	cout << "You will NOT get scrambled letters to look at." << endl;
	cout << "You will NOT get hints." << endl;
	cout << "Are you ready to begin?\n" << endl;
	system("pause");
	system("cls");

	// Create a collection of 10 words you had wrote down manually
	vector<string> words;
	words.push_back("intelligence");
	words.push_back("bugged");
	words.push_back("secret");
	words.push_back("code");
	words.push_back("undercover");
	words.push_back("enemy");
	words.push_back("espionage");
	words.push_back("detection");
	words.push_back("tapped");
	words.push_back("encryption");

	// Display the simulation # is staring to the recruit. 
	cout << "Starting Simulation # " << simNumber << ".\n" << endl;

	// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
	int wrong = 0;                               // number of incorrect guesses
	for (int i = 0; i < 3; ++i) {
		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(words.begin(), words.end());
		const string THE_WORD = words[0];            // word to guess

		string soFar(THE_WORD.size(), '-');          // word guessed so far
		string used = "";                            // letters already guessed

	// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
		{
			//     Tell recruit how many incorrect guesses he or she has left	
			cout << "\n\nYou have " << (MAX_WRONG - wrong);
			cout << " incorrect guesses left.\n";

			//     Show recruit the letters he or she has guessed
			cout << "\nYou've used the following letters:\n" << used << endl;

			//     Show player how much of the secret word he or she has guessed
			cout << "\nSo far, the word is:\n" << soFar << endl;

			//     Get recruit's next guess
			char guess;
			cout << "\n\nEnter your guess: ";
			cin >> guess;
			guess = tolower(guess); //make lowercase since secret word is lowercase


			//     While recruit has entered a letter that he or she has already guessed
			while (used.find(guess) != string::npos)
			{
				cout << "\nYou've already guessed " << guess << endl;

				//          Get recruit ’s guess
				cout << "\nEnter your guess: ";
				cin >> guess;
				guess = tolower(guess);
			}

			//     Add the new guess to the group of used letters
			used += guess;

			//     If the guess is in the secret word
			if (THE_WORD.find(guess) != string::npos)
			{

				//          Tell the recruit the guess is correct
				cout << "That's right! " << guess << " is in the word.\n";

				//          Update the word guessed so far with the new letter
				for (unsigned int i = 0; i < THE_WORD.length(); ++i)
				{
					if (THE_WORD[i] == guess)
					{
						soFar[i] = guess;
					}
				}
			}

			//     Otherwise
			else
			{

				//          Tell the recruit the guess is incorrect
				cout << "Sorry, " << guess << " isn't in the word.\n";

				//          Increment the number of incorrect guesses the recruit has made
				++wrong;
			}
		}

		// If the recruit has made too many incorrect guesses
		if (wrong == MAX_WRONG)

			//     Tell the recruit that he or she has failed the Keywords II course.
			cout << "\nYou have failed the Keywords II course.";

		// Otherwise
		else

			//     Congratulate the recruit on guessing the secret words
			cout << "\nYou guessed it!";
		cout << "\nThe word was " << THE_WORD << endl;
	}
	// Ask the recruit if they would like to run the simulation again
	string playAgain;
	cout << "Would you like to play again? Y/N" << endl;
	cin >> playAgain;
	cout << playAgain << endl;

	// If the recruit wants to run the simulation again
	while (true) {
		if ((playAgain == "Y") or (playAgain == "y")) {

			//     Increment the number of simiulations ran counter
			cout << simNumber << endl;
			simNumber++;
			cout << simNumber << endl;
			//     Move program execution back up to // Display the simulation # is staring to the recruit. 
			system("cls");
			main();
		}

		// Otherwise 
		else if ((playAgain == "N") or (playAgain == "n")) {

			//     Display End of Simulations to the recruit
			cout << "End of Simulations" << endl;
			Sleep(2000);
			exit(0);
		}
		else {
			cout << "Please input Y or N..." << endl;
			cin >> playAgain;
		}
	}	//     Pause the Simulation with press any key to continue
	system("pause");
}