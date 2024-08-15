#include <iostream>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentMarker;
int currentPlayer;

void drawBoard() {
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int winner() {
    for (int i = 0; i < 3; i++) {
        // Rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
        // Columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return currentPlayer;

    return 0;
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
    } else {
        currentMarker = 'X';
    }

    if (currentPlayer == 1) {
        currentPlayer = 2;
    } else {
        currentPlayer = 1;
    }
}

void game() {
    std::cout << "Player 1, choose your marker (X/O): ";
    char markerP1;
    std::cin >> markerP1;
    while(markerP1 != 'x' && markerP1 != 'X' && markerP1 !='o' && markerP1!='O'){
	    std::cout<<"Invalid enter again (X/O)";
	    std::cin>>markerP1;
    }
    if(markerP1 == 'x'){markerP1 = 'X';}else if (markerP1 == 'o'){markerP1 = 'O';}
    currentPlayer = 1;
    currentMarker = markerP1;

    drawBoard();

    int playerWon;

    for (int i = 0; i < 9; i++) {
        std::cout << "It's player " << currentPlayer << "'s turn. Enter your slot: ";
        int slot;
        std::cin >> slot;

        if (slot < 1 || slot > 9) {
            std::cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            std::cout << "Slot already taken! Try again.\n";
            i--;
            continue;
        }

        drawBoard();

        playerWon = winner();

        if (playerWon == 1) {
            std::cout << "Player 1 wins!\n";
            break;
        }
        if (playerWon == 2) {
            std::cout << "Player 2 wins!\n";
            break;
        }

        swapPlayerAndMarker();
    }

    if (playerWon == 0) {
        std::cout << "It's a tie!\n";
    }
}

int main() {
    game();
    return 0;
}

