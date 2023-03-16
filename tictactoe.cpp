#include <iostream>
#include <string>

using namespace std;

string grid[3][3] = {"0", "1", "2", "3", "4", "5", "6", "7", "8"};

void display()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// there are 8 winning positions for each player (trivial to enumerate manually, but what about 100x100 tictactoe?)

bool check_win()
{
    if (
        // rows
        grid[0][0] == grid[0][1] && grid[0][0] == grid[0][2] ||
        grid[1][0] == grid[1][1] && grid[1][0] == grid[1][2] ||
        grid[2][0] == grid[2][1] && grid[2][0] == grid[2][2] ||
        // columns
        grid[0][0] == grid[1][0] && grid[0][0] == grid[2][0] ||
        grid[0][1] == grid[1][1] && grid[0][1] == grid[2][1] ||
        grid[0][2] == grid[1][2] && grid[0][2] == grid[2][2] ||
        // diagonals
        grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2] ||
        grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0])
    {
        return true;
    }
    return false;
}

int main()
{
    cout << "\033[1;1H\033[2J"; // clear the screen and return to line zero
    display();                  // with love - buggo

    // an invalid input/move should not terminate the program

    int player = 1;
    string mark = "X";
    bool winner = false;

    while (!winner)
    {
        cout << "Player " << player << ", "
             << "select an integer (0-8): ";
        int num;
        cin >> num;

        if (cin.fail())
        {
            cerr << "Invalid input" << endl;
            continue;
        }

        if (num < 0 || num > 8)
        {
            cerr << "Integer out of bounds" << endl;
            continue;
        }

        // find a more elegant way to write this
        if (num >= 0 && num < 3)
        {
            if (grid[0][num] != "X" && grid[0][num] != "O")
            {
                grid[0][num] = mark;
            }
            else
            {
                cout << "Invalid move" << endl;
                continue;
            }
        }

        else if (num >= 3 && num < 6)
        {
            if (grid[1][num - 3] != "X" && grid[1][num - 3] != "O")
            {
                grid[1][num - 3] = mark;
            }
            else
            {
                cout << "Invalid move" << endl;
                continue;
            }
        }

        else
        {
            if (grid[2][num - 6] != "X" && grid[2][num - 6] != "O")
            {
                grid[2][num - 6] = mark;
            }
            else
            {
                cout << "Invalid move" << endl;
                continue;
            }
        }

        cout << "\033[1;1H\033[2J"; // clear the screen and return to line zero
        display();

        winner = check_win();
        if (!winner)
        {
            if (player == 1)
            {
                player = 2;
                mark = "O";
            }
            else
            {
                player = 1;
                mark = "X";
            }
        }
    }
    cout << "Player " << player << " wins!" << endl;
    return 0;
}
