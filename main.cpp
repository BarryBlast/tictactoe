#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
#include <unistd.h>
#include <ctype.h>


using namespace std;

class PlayerNode {
public:
    string name;
};

///Winconditions function. Determines if an a line of X's or O's is present anywhere on the board.
bool WinConditions(string posit[][3])
{
    if(posit[0][0] == "X" && posit[0][1] == "X" && posit[0][2] == "X")
        {
            ///if X wins, returns true to main program.
        cout << "X Wins";
        return true;
        }
    else if(posit[1][0] == "X" && posit[1][1] == "X" && posit[1][2] == "X")
        {
        cout << "X Wins";
        return true;
        }
    else if(posit[2][0] == "X" && posit[2][1] == "X" && posit[2][2] == "X")
        {
        cout << "X Wins";
        return true;
        }
    else if(posit[0][0] == "X" && posit[1][0] == "X" && posit[2][0] == "X")
        {
        cout << "X Wins";
        return true;
        }
    else if(posit[0][1] == "X" && posit[1][1] == "X" && posit[2][1] == "X")
        {
        cout << "X Wins";
        return true;
        }
    else if(posit[0][2] == "X" && posit[1][2] == "X" && posit[2][2] == "X")
        {
        cout << "X Wins";
        return true;
        }
    else if(posit[0][0] == "X" && posit[1][1] == "X" && posit[2][2] == "X")
        {
        cout << "X Wins";
        return true;
        }
    else if(posit[2][0] == "X" && posit[1][1] == "X" && posit[0][2] == "X")
        {
        cout << "X Wins";
        return true;
        }

    else if(posit[0][0] == "O" && posit[0][1] == "O" && posit[0][2] == "O")
        {
        cout << "O Wins";
        return true;
        }
    else if(posit[1][0] == "O" && posit[1][1] == "O" && posit[1][2] == "O")
        {
        cout << "O Wins";
        return true;
        }
    else if(posit[2][0] == "O" && posit[2][1] == "O" && posit[2][2] == "O")
        {
        cout << "O Wins";
        return true;
        }
    else if(posit[0][0] == "O" && posit[1][0] == "O" && posit[2][0] == "O")
        {
        cout << "O Wins";
        return true;
        }
    else if(posit[0][1] == "O" && posit[1][1] == "O" && posit[2][1] == "O")
        {
        cout << "O Wins";
        return true;
        }
    else if(posit[0][2] == "O" && posit[1][2] == "O" && posit[2][2] == "O")
        {
        cout << "O Wins";
        return true;
        }
    else if(posit[0][0] == "O" && posit[1][1] == "O" && posit[2][2] == "O")
        {
        cout << "O Wins";
        return true;
        }
    else if(posit[2][0] == "O" && posit[1][1] == "O" && posit[0][2] == "O")
        {
        cout << "O Wins";
        return true;
        }
        ///if any of the above are not true, the function will return false to the main program
    else return false;
}
///in main function, operator will determine who goes first and that name will be stored in the first player variable
///X and O.
bool WhoGoesFirst(string& player, PlayerNode* FirstPlayer, PlayerNode* SecondPlayer)
{
    if (player == "X" || player == "x")
        {
        FirstPlayer->name = "X";
        SecondPlayer->name = "O";
        return true;
        }
    if (player == "O" || player == "o")
        {
        FirstPlayer->name = "O";
        SecondPlayer->name = "X";
        return true;
        }
    else if(player != "X" || player != "x" || player != "O" || player != "o")
            {
        cout << "Invalid Character. Try Again.";
        return false;
        }
}
///functionality to put pieces on board. 2 dimensional array and 3 for loops allow for 25 less lines of code
void PlacePieceOnBoard(int& temp, string posit[][3], PlayerNode* TempPlayer)
    {

        for(int i = 1, j = 0; i < 4; i++, j++)
            {
            if (temp == i && posit[0][j].size() == 0)
            posit[0][j] = TempPlayer->name;
            else if (temp == i && posit[0][j].size() > 0)
            {
            cout << "Space Full. Try Again: ";
            cin >> temp;
            }
            }

        for(int i = 4, j = 0; i < 7; i++, j++)
            {
            if (temp == i && posit[1][j].size() == 0)
            posit[1][j] = TempPlayer->name;
            else if (temp == i && posit[1][j].size() > 0)
            {
            cout << "Space Full. Try Again: ";
            cin >> temp;
            }
            }


        for(int i = 7, j = 0; i < 10; i++, j++)
            {
            if (temp == i && posit[2][j].size() == 0)
            posit[2][j] = TempPlayer->name;
            else if (temp == i && posit[2][j].size() > 0)
            {
            cout << "Space Full. Try Again: ";
            cin >> temp;
            }
            }

    }
///function to determine if there was a draw.
bool CatsGame(string posit[][3])
{
    if ((posit[0][0].size() > 0) && (posit[0][1].size() > 0) && (posit[0][2].size() > 0) && (posit[1][0].size() > 0) && (posit[1][1].size() > 0) && (posit[1][2].size() > 0) && (posit[2][0].size() > 0) && (posit[2][1].size() > 0) && (posit[2][2].size() > 0))
    {
        cout << "Cat's Game! No One Wins!";
        return true;
    }
    else return false;
}

///mapping the gameboard
void GameBoard(string posit[][3])
{
    cout << "        |        |         " << endl;
    cout << "        |        |         " << endl;
    cout << setw(1) << "" << setw(4) << posit[0][0] << "   |" <<setw(1) << "" << setw(4) <<  posit[0][1] << "   |    " << posit[0][2] << "     " << endl;
    cout << "        |        |         " << endl;
    cout << " -------|--------|-------- " << endl;
    cout << "        |        |         " << endl;
    cout << "        |        |         " << endl;
    cout << setw(1) << "" << setw(4) << posit[1][0] << "   |" <<setw(1) << "" << setw(4) <<  posit[1][1] << "   |    " << posit[1][2] << "     " << endl;
    cout << "        |        |         " << endl;
    cout << " -------|--------|-------- " << endl;
    cout << "        |        |         " << endl;
    cout << "        |        |         " << endl;
    cout << setw(1) << "" << setw(4) << posit[2][0] << "   |" <<setw(1) << "" << setw(4) <<  posit[2][1] << "   |    " << posit[2][2] << "     " << endl;
    cout << "        |        |         " << endl;
}

///main function that calls all of the other functions
int main()
{
    ///declare variables
    string posit[3][3];
    string player;
    int temp;
    PlayerNode* FirstPlayer;
    PlayerNode* SecondPlayer;

    FirstPlayer = new PlayerNode();
    SecondPlayer = new PlayerNode();

    ///user enters who starts. can be X or x or O or o. Will not continue until valid character selected.
    cout << "Choose who starts! Enter X or O: ";
    cin >> player;
    while (WhoGoesFirst(player, FirstPlayer, SecondPlayer) == false)
    {
        cin >> player;
    }

    ///while winConditions function returns false, game will continue to play until winner or draw (returns true)
    while (WinConditions(posit) == false)
    {
        ///clears screen with each iteration so doesn't get flooded with garbage
        system("CLS");
        ///call the gameboard
        GameBoard(posit);
       label: cout << FirstPlayer->name << ", choose a number correlating to the numbers on the board. 1-9: " << endl;
       cin >> temp;

    while ((temp > 9) || (temp < 1))
           {
            cout << "Number out of range!" << endl;
            goto label;
            }

        ///places piece on board
        PlacePieceOnBoard(temp, posit, FirstPlayer);
        ///clears everything and redraws board
        system("CLS");
        GameBoard(posit);
        ///checks to see if draw conditions met. if so, breaks loop
        if (CatsGame(posit) == true)
            {
                break;
            }
        ///checks to see if win conditions met. if so, breaks loop.
        if (WinConditions(posit) == true)
            {
                break;
            }
        ///second player goes next.
        label2: cout << SecondPlayer->name << ", choose a number correlating to the numbers on the board. 1-9: " << endl;
         cin >> temp;
        if ((temp > 9) || (temp < 1))
    {
        cout << "Number out of range!" << endl;
        goto label2;
    }
        PlacePieceOnBoard(temp, posit, SecondPlayer);
        system("CLS");
        GameBoard(posit);
    }
    ///once winner or draw is determined sleep for 5 seconds before closing
    sleep(5);
    return 0;
}
