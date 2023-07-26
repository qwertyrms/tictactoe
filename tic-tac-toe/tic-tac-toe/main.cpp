//
//  main.cpp
//  tic-tac-toe
//
//  Created by Remon Sabuz on 7/26/23.
//

#include <iostream>
using namespace std;

const int SIZE = 3;

void printGrid(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << grid[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "---------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(char grid[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
            return true;
        if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player)
            return true;
    }
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
        return true;
    if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)
        return true;
    return false;
}

// Function to check if the grid is full
bool checkFull(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char grid[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = ' ';
        }
    }

    cout << "Welcome to Remon's Tic-Tac-Toe game!" << endl;

    char currentPlayer = 'X';
    int row, col;

    while (true) {
        cout << "Current Grid:" << endl;
        printGrid(grid);

        cout << "Player " << currentPlayer << ", enter row (0-2): ";
        cin >> row;
        cout << "Player " << currentPlayer << ", enter column (0-2): ";
        cin >> col;

        // Check if the input is valid
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || grid[row][col] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        grid[row][col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(grid, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (checkFull(grid)) {
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Final Grid:" << endl;
    printGrid(grid);
    return 0;
}
