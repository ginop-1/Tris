#include <iostream>
#include <random>
#include <experimental/random>

using std::cout;
using std::cin;
using std::string;
using std::endl;

bool isGridFull(string*, int);
void PrintGrid(string*);
string CPUmove(string*, string, string, int);
bool CheckWin(string*, string);
bool isMoveCorrect(string*, string, int);
string moveAndCheck(string*, string, int);

int main()
{
    string playerXO, CPUXO, printNumbers; 
    bool startplayer; int playermove, cpumove, i, gameMode;
    string grid[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    PrintGrid(grid);
    for (auto i=0; i<=8; i++) grid[i] = " "; // for cleaning the array
    cout << "Welcome to the tris game!" << endl
         << "the initial player will be random" << endl
         << "Choose a game mode: 1 vs PC (1) or 1 vs 1 (2):" << endl;
    while (true)
    {
        cin >> gameMode;
        if (gameMode == 1 || gameMode == 2) break;
        cout << "wrong value, please reinsert: ";
    }
    cout << "Now choose between X or O: ";
    while (true) 
    {
        cin >> playerXO;
        if (playerXO == "X" || playerXO == "x" || playerXO == "O" || playerXO == "o") break;
        else cout << "wrong value, please reinsert: ";
    }
    if (playerXO == "x") playerXO = "X";
    else playerXO = "O"; 
    if (playerXO == "X") CPUXO = "O";
    else CPUXO = "X";
    startplayer = std::experimental::randint(0, 1);

    while (true)
    {
        if (startplayer) 
        {
            if (isGridFull(grid, i=0)) break;
            if (gameMode == 1) cout << "it's your turn, choose a box\n";
            else cout << "It's player 1 turn, choose a box\n";
            moveAndCheck(grid, playerXO, playermove);
            PrintGrid(grid);
            if (CheckWin(grid, playerXO)) 
            {
                if (gameMode == 1) 
                {
                    cout << "Congrats, you have won! \n\n";
                    break;
                }
                else 
                {
                    cout << "player 1 win!";
                    break;
                }
            } 
            startplayer = false;
        }
        if (startplayer == false && gameMode == 2)
        {
            if (isGridFull(grid, i=0)) break;
            cout << "it's P2 turn, choose a box\n";
            moveAndCheck(grid, CPUXO, playermove);
            PrintGrid(grid);
            if (CheckWin(grid, CPUXO))
            {
                cout << "player2 wins! \n\n";
                break;
            }
            startplayer = true;
        } 
        else
        {
            if (isGridFull(grid, i=0)) break;
            cout << "CPU turn\n";
            CPUmove(grid, CPUXO, playerXO, i=0);
            PrintGrid(grid);
            if (CheckWin(grid, CPUXO))
            {
                cout << "the CPU wins! \n\n";
                break;
            }
            startplayer = true;
        }
    }       
    return 0;
}

void PrintGrid(string grid[8])
{
    cout << "\n"
         << grid[0] << "|" << grid[1] << "|" << grid[2] << endl
         << "-----" << endl
         << grid[3]<< "|" << grid[4] << "|" << grid[5] << endl
         << "-----" << endl 
         << grid[6] << "|" << grid[7] << "|" << grid[8] << endl
         << "\n" ;
}

bool isGridFull(string grid[8], int i)
{
    for (i=0; i<=8; i++)
    {
        if (grid[i] == " ") 
        {
            return false;
        }
    }
    cout << "Thid is a draw! ";
    return true;
}

string moveAndCheck(string grid[8], string PlayerXO, int playermove)
{
    while (true) 
    {
        cin >> playermove;
        playermove--;
        if (grid[playermove] != " ") cout << "this box is already filled, please insert a valid value: ";
        else 
        {
            grid[playermove] = PlayerXO; 
            return PlayerXO;

        }
    }
}

bool isMoveCorrect(string grid[8], string XorO, int a, int b, int c)
{
    if (grid[a]==XorO && grid[b]==XorO && grid[c]==" ") return true;
}

bool CheckWin(string grid[8], string XorO)
{
    if (grid[0] == XorO && grid[1] == XorO && grid[2] == XorO) return true; // first row
    if (grid[3] == XorO && grid[4] == XorO && grid[5] == XorO) return true; // second row
    if (grid[6] == XorO && grid[7] == XorO && grid[8] == XorO) return true; // third row
    if (grid[0] == XorO && grid[3] == XorO && grid[6] == XorO) return true; // first column
    if (grid[1] == XorO && grid[4] == XorO && grid[7] == XorO) return true; // second column
    if (grid[2] == XorO && grid[5] == XorO && grid[8] == XorO) return true; // third column
    if (grid[0] == XorO && grid[4] == XorO && grid[8] == XorO) return true; // first oblique
    if (grid[2] == XorO && grid[4] == XorO && grid[6] == XorO) return true; // second oblique
    return false;
}

string CPUmove(string grid[8], string XorO, string enemyXO, int i)
{
        // TRY TO WIN IF POSSIBLE 
    
    // ROWS
    if (isMoveCorrect(grid, XorO, 0, 1 ,2)) { grid[2] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 1, 2 ,0)) { grid[0] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 0, 2 ,1)) { grid[1] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 3, 4 ,5)) { grid[5] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 4, 5 ,3)) { grid[3] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 3, 5 ,4)) { grid[4] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 6, 7 ,8)) { grid[8] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 7, 8 ,6)) { grid[6] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 6, 8 ,7)) { grid[7] = XorO; return XorO; }
    // COLUMNS
    if (isMoveCorrect(grid, XorO, 0, 3 ,6)) { grid[6] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 1, 4 ,7)) { grid[7] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 2, 5 ,8)) { grid[8] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 0, 6 ,3)) { grid[3] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 1, 7 ,4)) { grid[4] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 2, 8 ,5)) { grid[5] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 3, 6 ,0)) { grid[0] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 4, 7 ,1)) { grid[1] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 5, 8 ,2)) { grid[2] = XorO; return XorO; }
    //OBLIQUE
    if (isMoveCorrect(grid, XorO, 0, 4 ,4)) { grid[8] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 2, 4 ,6)) { grid[6] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 0, 8 ,4)) { grid[4] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 2, 6 ,4)) { grid[4] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 4, 6 ,2)) { grid[2] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 4, 8 ,0)) { grid[0] = XorO; return XorO; }
    
        // TRY TO NOT LOSE IF POSSIBLE
    // ROWS
    if (isMoveCorrect(grid, enemyXO, 0, 1 ,2)) { grid[2] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 1, 2 ,0)) { grid[0] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 0, 2 ,1)) { grid[1] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 3, 4 ,5)) { grid[5] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 4, 5 ,3)) { grid[3] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 3, 5 ,4)) { grid[4] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 6, 7 ,8)) { grid[8] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 7, 8 ,6)) { grid[6] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 6, 8 ,7)) { grid[7] = XorO; return XorO; }
    // COLUMNS
    if (isMoveCorrect(grid, enemyXO, 0, 3 ,6)) { grid[6] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 1, 4 ,7)) { grid[7] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 2, 5 ,8)) { grid[8] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 0, 6 ,3)) { grid[3] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 1, 7 ,4)) { grid[4] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 2, 8 ,5)) { grid[5] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 3, 6 ,0)) { grid[0] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 4, 7 ,1)) { grid[1] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 5, 8 ,2)) { grid[2] = XorO; return XorO; }
    //OBLIQUE
    if (isMoveCorrect(grid, enemyXO, 0, 4 ,4)) { grid[8] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 2, 4 ,6)) { grid[6] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 0, 8 ,4)) { grid[4] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 2, 6 ,4)) { grid[4] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 4, 6 ,2)) { grid[2] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 4, 8 ,0)) { grid[0] = XorO; return XorO; }
    
        // OTHER MOVES
    
    for (auto i=0; i<=8; i+=2)
    {
        if (grid[i] == " ") 
        {
            grid[i] = XorO;
            return XorO;
        }
        if (i == 8) i=1;
    } 
}