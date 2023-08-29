#include <iostream>
#include <stdlib.h>
using namespace std;

// Array to store the Tic Tac Toe board
char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

// Current player's turn (initially 'X')
char input = 'X';

// Variables to store user's choice and board position
int choice, row, column;

// Variable to keep track of the game's state (draw or not)
bool draw = false;

// Function to display the current status of the game board
void board_display() {
    cout << "\n\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[0][0] << "  | " << board[0][1] << "   | " << board[0][2] << "\n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[1][0] << "  | " << board[1][1] << "   | " << board[1][2] << "\n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[2][0] << "  | " << board[2][1] << "   | " << board[2][2] << "\n";
    cout << "\t\t     |     |     \n";
}

// Function to take user input and validate it
void player_input() {
    int chosenPosition;
    bool validChoice = false;

    while (!validChoice) {
        if (input == 'X') {
            cout << "\n\tPLAYER - 1 [X] Turn: ";
        } else if (input == 'O') {
            cout << "\n\tPLAYER - 2 [O] Turn: ";
        }
        cin >> chosenPosition;

        if (chosenPosition >= 1 && chosenPosition <= 9) {
            // Convert position to row and column
            row = (chosenPosition - 1) / 3;
            column = (chosenPosition - 1) % 3;

            if (board[row][column] != 'X' && board[row][column] != 'O') {
                board[row][column] = (input == 'X') ? 'X' : 'O';
                validChoice = true;  // Valid choice, exit the loop
                input = (input == 'X') ? 'O' : 'X';
            } else {
                cout << "\nBox was already filled!\nPlease choose another!\n\n";
            }
        } else {
            cout << "\nInvalid Move. Please choose a number between 1 and 9.\n\n";
        }
    }
}

// Function to check if the game is over (win, draw, or continue)
bool gameover() {
    // Checking for wins in rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] ||
            board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return false; // There's a win
        }
    }

    // Checking for wins in diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
        board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return false; // There's a win
    }

    // Checking if the game is still in progress
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return true; // The game is still ongoing
            }
        }
    }

    // If no wins and no empty cells, it's a draw
    draw = true;
    return false;
}

// Main gameplay loop
void gameplay() {
    while (gameover()) {
        board_display();
        player_input();
    }
    board_display();

    if (input == 'X' && draw == false) {
        cout << "\n\nCongratulations! Player with 'O' has won the game!\n\n";
    } else if (input == 'O' && draw == false) {
        cout << "\n\nCongratulations! Player with 'X' has won the game!\n\n";
    } else {
        cout << "\n\nGAME DRAW!!!\n\n";
    }
}

int main() {

    system("Color FD");
    cout << "\t\t\tT I C K -- T A C -- T O E -- G A M E\t\t\t";
    cout << endl << "\t\t\t(--> F O R  2   P L A Y E R S <--)" << endl << endl;
    cout << "PLAYER - 1 [X]\nPLAYER - 2 [O]\n\n";

    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        gameplay();
        cout << "Want to play again (y/n)? ";
        cin >> playAgain;
        if (playAgain == 'y' || playAgain == 'Y') {
            // Reset the board and other game variables for a new game
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    board[i][j] = (char)(i * 3 + j + '1'); // Reset the board with numbers
                }
            }
            input = 'X';
            draw = false;
        }
    }

    cout << "\n\t\t\tThank you for playing!!\n\n";
    system("pause");
    return 0;
}
