#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty){
    std::cout << "You are the fist secret agent breaking into this server....." << std::endl;
    std::cout << "A level " << Difficulty << " ";
    std::cout << "firewall block the way, you want to get the password for the server......" << std::endl;
}

bool PlayGame(int Difficulty){
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "There are 3 numbers in the code" << std::endl;
    std::cout << "The summation of 3 numbers are: " << CodeSum << std::endl;
    std::cout << "The product of 3 numbers are: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cout<< " Please enter three number with space between: ";
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << std::endl;
    std::cout << "You entered: " << GuessA <<" "<< GuessB <<" "<< GuessC << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct){
        std::cout << "\n***You Win! You get this layer password.....***\n" << std::endl; 
        return true;
    } else {
        std::cout << "\n***You failed! You did not get this layer password..... Please Try again\n" << std::endl;
        return false;
    }

}

int main()
{   
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    while(LevelDifficulty <= MaxDifficulty){
        bool LevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any error massage
        std::cin.ignore(); // Clear input buffer
        if (LevelComplete){
            std::cout << "***Increasing the level of difficulty***\n\n";
            // increase level of difficulty
            ++LevelDifficulty;
        }
    }
    std::cout << "\n**** Great work agent! You finally break into this server!!!***\n";
    return 0;
}
