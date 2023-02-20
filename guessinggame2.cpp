#include <iostream>
#include <random>
using namespace std;

int main()
{
    //initializing random engine, and variables
    random_device myEngine;
    uniform_int_distribution<int> randomInt(1, 100);

    int randNum;
    int playerNum;
    char playAgain;
    int g = 1; //guesses

    randNum = randomInt(myEngine);

    cout << "Guess a number between 1 and 100, or 0 to quit: ";
    cin >> playerNum;


    do
    {
        if (playerNum > randNum && playerNum < 100) //too big
        {
            cout << "Your guess is TOO BIG." << endl;
            cout << "Guess a number between 1 and 100 or 0 to quit: ";
            cin >> playerNum;
            g++;
        }
        else if (playerNum < randNum && playerNum > 0) //too small
        {
            cout << "Your guess is TOO SMALL." << endl;
            cout << "Guess a number between 1 and 100 or 0 to quit: ";
            cin >> playerNum;
            g++;
        }
        else if (playerNum == 0) //if player quits
        {
            cout << "Would you like to play again? (Y/N): ";
            cin >> playAgain;
            if (playAgain == 'Y' || playAgain == 'y')
            {
                randNum = randomInt(myEngine);
                cout << "Guess a number between 1 and 100, or 0 to quit: ";
                cin >> playerNum;
            }
            else if (playAgain == 'N' || playAgain == 'n') //quit
            {
                return 0;
            }
        }
        else if (playerNum == randNum) //guesses correct
        {
            cout << "GOOD JOB! That's correct! You used " << g << " guesses!" << endl;
            g = 1;
            cout << "Would you like to play again (Y/N): ";
            cin >> playAgain;
            if (playAgain == 'Y' || playAgain == 'y')
            {
                randNum = randomInt(myEngine);
                cout << "Guess a number between 1 and 100, or 0 to quit: ";
                cin >> playerNum;
            }
            else if (playAgain == 'N' || playAgain == 'n')
            {
                return 0;
            }
        }
        else if (playerNum < 0 || playerNum > 100) //if user chooses a number thats not 0-100
        {
            cout << "Invalid. Please guess a number between 1 and 100, or 0 to quit: ";
            cin >> playerNum;
        }
    } while (playerNum != randNum || playerNum == randNum); //loops if the number is or isn't the random number
}