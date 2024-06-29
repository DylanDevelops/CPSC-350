#include <limits>
#include "ttt_functions.hpp"

void displayBoard(const std::vector<std::vector<std::string>>& board) {
    std::cout << "   1   2   3\n";

    char rowLabel = 'A';
    for (const auto& row : board) {
        std::cout << rowLabel << " ";

        for (const auto& cell : row) {
            std::cout << cell << " ";
        }

        std::cout << rowLabel;
        std::cout << "\n";
        rowLabel++;
    }

    std::cout << "   1   2   3\n";
}

void playGame(std::vector<std::vector<std::string>>& board) {
    std::string currentPlayer = "X";
    bool gameWon = false;

    while (!gameWon) {
        displayBoard(board);
        std::cout << "Player " << currentPlayer << "'s turn. Enter row (A-C) and column (1-3): ";
        char row;
        int col;
        std::cin >> row >> col;

        // Convert input to board indices
        int rowIndex = row - 'A';
        int colIndex = col - 1;

        // Validate input
        if (row < 'A' || row > 'C' || col < 1 || col > 3) {
            std::cout << "Invalid input. Please enter a valid row (A-C) and column (1-3).\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Update the board
        if (board[rowIndex][colIndex] == "[ ]") {
            board[rowIndex][colIndex] = "[" + currentPlayer + "]";
        } else {
            std::cout << "That spot is taken. Try again.\n";
            continue;
        }

        // Check for a win
        if (checkWin(board)) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << " wins!\n";
            gameWon = true;
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == "X") ? "O" : "X";

        std::cout << std::endl;
    }
}

bool checkWin(const std::vector<std::vector<std::string>>& board) {
    // Checks rows
    for (const auto& row : board) {
        if (row[0] == row[1] && row[1] == row[2] && row[0] != "[ ]") {
            return true;
        }
    }

    // Checks columns
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != "[ ]") {
            return true;
        }
    }

    // Checks diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != "[ ]" ||
        board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != "[ ]") {
        return true;
    }
    return false;
}