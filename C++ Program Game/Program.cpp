#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) 
{
    std::cout<< "\n You ar e a secret agent breaking into the level " << Difficulty;
    std::cout<< "secure servers room!!\n Enter the correct code to continue further in the mission \n\n";
}

bool PlayGame(int Difficulty) 
{
    PrintIntroduction(Difficulty); 

    // Print the welcome message on the terminal
    std::cout << "You are a secret Agent breaking into a big server room!!";
    std::cout << std::endl;
    std::cout << "You need to solve the questions to continue further!!";

    //Declared the 3 variables.
    int CodeA = rand() % Difficulty + Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty + Difficulty; 

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    //Print the sum and product on the terminal
    std::cout<<std::endl;
    std::cout << "You have to enter only three numbers: "<< std:: endl;
    std::cout<< "The add up of the 3 numbers are: "<<CodeSum<<std::endl;
    std::cout<< "The product of the 3 numbers are: "<< CodeProduct << std::endl;
    
    //Store players Guesses
    int GuessA, GuessB, GuessC;
    std::cin>> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC; 

    //std::cout << "The guess add up is: "<< GuessSum<< endl;
    //std::cout<< "The guess multiply product is: "<< GuessProduct << endl;

    //Checks the guesses are right or wrong!!
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout<< "Congratulations, you have completed the level. Now you will be directed to new level!!\n\n";
        return true;
    }
    else {
        std::cout<< "You have entered the wrong code!!";
        return false;
    }
}

int main ()
{
    srand(time(NULL)); 
    
    int LevelDifficulty = 1;
    int const MaxLevel = 10;
    
    while(LevelDifficulty <= MaxLevel) 
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears the error if we have!!
        std::cin.ignore(); //Discards the buffer!!

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    std::cout << "Congratulations You won !!";
    return 0;
} 