#include<iostream>
#include<map>
using namespace std;
#define loop(i,x,n) for(int i = x; i < n; i++)

//map containes character related to grid index
map<int,char> cellValue;
void setMap(){
    int ch = 49;
    loop(i,1,10){
        //Filled with grid indexes later will be filled with 'X' or 'O'
        cellValue[i] = (char)ch;
        ch++;
    } 
}


//Check if game ties
bool tie = false;

//token used in game (if 'X' means 'X' will be marked this time if 'O' means 'O' will be marked)
char token = 'X';
char tokenX = 'X';
char tokenO = 'O';

//Count number of total turns, if they reach 9 game will be over
int turns = 0;

//Will be true if there is any winner
bool win = false;

//function to print structure of game
void structure(){
    cout << "   |   |   " << endl;
    cout << " " << cellValue[1] << " | " << cellValue[2] << " | " << cellValue[3] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " <<cellValue[4] << " | " << cellValue[5] << " | " << cellValue[6] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " <<cellValue[7] << " | " << cellValue[8] << " | " << cellValue[9] << endl;
    cout << "   |   |   " << endl;
}

//function to fill 'X' or 'O' at relative indexes input by user
void algo(){
    int pos;
    cout << "Enter postion you want to mark as " << token << " : ";
    cin >> pos;
    
    if(pos < 1 || pos > 9) cout << "No valid postion! You lost your turn" << endl;
    else if(cellValue[pos] != 'X' && cellValue[pos] != 'O'){
        cellValue[pos] = token;
        turns++;
    }
    else cout << "Already filled! You lost your turn" << endl;


}

bool rules(){
    //Check win for 'X'
    if(cellValue[5] == 'X'){
        //diagonals
        if(cellValue[1] == 'X' && cellValue[9] == 'X') return true;
        if(cellValue[3] == 'X' && cellValue[7] == 'X') return true;

        //2nd column
        if(cellValue[2] == 'X' && cellValue[8] == 'X') return true;
        //2nd row 
        if(cellValue[4] == 'X' && cellValue[6] == 'X') return true;
    }

    if(cellValue[1] == 'X'){
        //1st row
        if(cellValue[2] == 'X' && cellValue[3] == 'X') return true;
        //1st columns
        if(cellValue[4] == 'X' && cellValue[7] == 'X') return true;
    }

    if(cellValue[9] == 'X'){
        //3rd row
        if(cellValue[3] == 'X' && cellValue[5] == 'X') return true;
        //3rd columns
        if(cellValue[7] == 'X' && cellValue[8] == 'X') return true;
    }

    //Check win for 'O'
    if(cellValue[5] == 'O'){
        //diagonals
        if(cellValue[1] == 'O' && cellValue[9] == 'O') return true;
        if(cellValue[3] == 'O' && cellValue[7] == 'O') return true;

        //2nd column
        if(cellValue[2] == 'O' && cellValue[8] == 'O') return true;
        //2nd row 
        if(cellValue[4] == 'O' && cellValue[6] == 'O') return true;
    }

    if(cellValue[1] == 'O'){
        //1st row
        if(cellValue[2] == 'O' && cellValue[3] == 'O') return true;
        //1st columns
        if(cellValue[4] == 'O' && cellValue[7] == 'O') return true;
    }

    if(cellValue[9] == 'O'){
        //3rd row
        if(cellValue[3] == 'O' && cellValue[5] == 'O') return true;
        //3rd columns
        if(cellValue[7] == 'O' && cellValue[8] == 'O') return true;
    }

    if(token == tokenX) token = tokenO;
    else token = tokenX;

    return false;
}

//Driver code
int main()
{
  int playAgain = 0;

  do{
    turns = 0;
    win = false;

    setMap();
    while(turns < 9 && !win){
        structure();
        algo();
        win = rules();
        system("cls");
    }
    structure();
    if(win) cout << token << " won the game" << endl;
    else cout << "It's a tie!" << endl;

    cout << "To exit press 0. To play again press 1 : ";
    cin >> playAgain;
  }while(playAgain);
  return 0;
}
