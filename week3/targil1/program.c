
#include <unistd.h>
#include <stdio.h>
#include <w32api/synchapi.h>

void playGameOfLife(char board[5][5], int size, int turns);

void printBoard(char board[5][5], int size);

void doNextTurn(char board[5][5], int size);

void doSleep(int milis);

int countNeighbours(char board[5][5], int size, int i, int j);

int main() {

    char board[5][5] = {
            {'0', '0', '0', '0', '0'},
            {'0', '0', '1', '1', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '0', '0'}
    };

    playGameOfLife(board, 5, 15);
}

void playGameOfLife(char board[5][5], int size, int turns) {

    printBoard(board, size);


    for (int k = 0; k < turns; ++k) {

        printf("\n");

        doNextTurn(board, size);
        printBoard(board, size);
        doSleep(100);
    }
}

void doSleep(int milis) {

#ifdef WIN32
    Sleep(milis);
#else
    usleep(milis * 1000);
#endif
}

void doNextTurn(char board[5][5], int size) {

    char tempBoard[size][size];

    // copy the board to temp
    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {
            tempBoard[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {

            int count = countNeighbours(tempBoard, size, i, j);
            int self = (tempBoard[i][j] == '1' ? 1 : 0);

            if (self == 0) {

                if (count == 3) {
                    board[i][j] = '1';
                } else {
                    board[i][j] = '0';
                }
            }

            else {

                if (count == 3 || count == 2) {
                    board[i][j] = '1';
                } else {
                    board[i][j] = '0';
                }
            }

        }
    }
}

int countNeighbours(char board[5][5], int size, int i, int j) {

    int count = 0;

    // up

    if (i > 0 && j > 0){
        char temp1 = board[i-1][j-1];
        if (temp1 == '1') count++;
    }

    if (i > 0) {
        char temp2 = board[i - 1][j];
        if (temp2 == '1') count++;
    }

    if (i > 0 && j < (size - 1)) {
        char temp3 = board[i - 1][j + 1];
        if (temp3 == '1') count++;
    }

    // center

    if (j > 0) {
        char temp4 = board[i][j - 1];
        if (temp4 == '1') count++;
    }

    if (j < (size - 1)) {
        char temp5 = board[i][j + 1];
        if (temp5 == '1') count++;
    }

    // bottom

    if (i < (size - 1) && j > 0) {
        char temp6 = board[i + 1][j - 1];
        if (temp6 == '1') count++;
    }

    if (i < (size - 1)) {
        char temp7 = board[i + 1][j];
        if (temp7 == '1') count++;
    }

    if (i < (size - 1) && j < (size - 1)) {
        char temp8 = board[i + 1][j + 1];
        if (temp8 == '1') count++;
    }

    return count;
}

void printBoard(char board[5][5], int size) {

    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {
            printf("%c ", board[i][j]);
        }

        printf("\n");
    }
}