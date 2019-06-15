/* this game was re-created to display better ways of implementation 
than just a standard do-while loop.     
                            
    * a class was created with public data types and initialized in the constructor 
    * functions were used for the computers choice, users choice, winner, and results 
    * pointers were used to pass refrence for the counter in determining how many times 
    there was a winner or the number of ties
*/

#include <iostream>
#include <ctime>

class rps
{
    public:
    int rnum;
    int userWins;
    int compWins;
    int numTies;
    char compChoice;
    char userChoice;

    rps()
    {
        rnum = 0;
        userWins = 0;
        compWins = 0;
        numTies = 0;

    }

    void player()
    {
        std::cout << "Please enter Rock, Paper, or Scissors -"
        << " 'R' for Rock, 'P' for Paper, 'S' for Scissors: ";
        std::cin >> userChoice;
        std::cout << "\n";

    }

    void computer()
    {
        srand ((unsigned int) time(0));

        rnum = rand() % 3;

        switch(rnum)
        {
            case 0:compChoice ='R';
                break;
            case 1:compChoice = 'P';
                break;
            case 2:compChoice = 'S';
                break;
        }

        if(compChoice == 'R')
            std::cout << "The computer chose rock.\n";
        else if(compChoice == 'P')
            std::cout << "The computer chose paper.\n";
        else if(compChoice == 'S')
            std::cout << "The computer chose scissors.\n";
        std::cout << "\n";
        
    }

    void winner(int* U, int* C, int* T)
    {
        *U = userWins;
        *C = compWins;
        *T = numTies;

        if(compChoice == userChoice){
        std::cout << "It's a tie!\n";
        numTies++;
        }
        else if(userChoice == 'P' && compChoice == 'R'){
            std::cout << "You win! Paper covers rock.\n";
            userWins++;
        }
        else if(userChoice == 'S' && compChoice == 'R'){
            std::cout << "Computer wins! Rock beats scissors.\n";
            compWins++;
        }
        else if(userChoice == 'S' && compChoice == 'P'){
            std::cout << "You win! Scissors beats paper.\n";
            userWins++;
        }
        else if(userChoice == 'R' && compChoice == 'P'){
            std::cout << "Computer wins! Paper covers rock.\n";
            compWins++;
        }
        else if(userChoice == 'R' && compChoice == 'S'){
            std::cout << "You win! Rock beats scissors.\n";
            userWins++;
        }
        else if(userChoice == 'P' && compChoice == 'S'){
            std::cout << "Computer wins! Scissors beats paper.\n";
            compWins++;
        }
        else std::cout << "Invalid input.\n";
        std::cout << "\n";

        
    }

    void results()
    {
        std::cout << "Here are the results...\n\n";
        std::cout << "YOU: " << userWins << "  " << "COMPUTER: " << compWins;
        std::cout << "  TIES: " << numTies << "\n";
    }


};


int main(){

  rps obj;
  char char1('y');
  int userWins = 0;
  int compWins = 0;
  int numTies = 0;

  std::cout << "=======THIS IS A GAME OF ROCK, PAPER, SCISSORS!=======\n\n";
  
  while(char1 == 'y' || char1 == 'Y' ){

    obj.player();
    obj.computer();
    obj.winner(&userWins, &compWins, &numTies);
    
    std::cout << "Enter y to play again or anything else to win: ";
    std::cin >> char1;
    std::cout << "\n";

  }

  obj.results();



  return 0;  
}