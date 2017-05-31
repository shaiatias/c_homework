#include <stdio.h>

#define MAXROW 10
#define MAXCOL 10
#define MAXGEN 10

typedef enum {
    DEAD, ALIVE
} State;

typedef enum {
    TRUE, FALSE
} Boolean;


typedef State Grid[MAXROW + 2][MAXCOL + 2][MAXGEN];

void playGameOfLife(Grid board, int rows, int columns, int turns);

void printBoard(Grid board, int rows, int columns, int atTurn);

void doNextTurn(Grid board, int previousTurn, int rows, int columns);

int countNeighbours(Grid board, int turn, int rows, int columns, int i, int j);

void printResults(Grid board, int boardsCount, int rows, int columns);

int getInt(char message[]);

Boolean fillTheBoard(Grid board, int rows, int cols);

Boolean checkCellValue(int value);

Boolean checkBoardValues(int rows, int cols, int generations);

int main() {

    Grid board = {0};

    int rows = getInt("Enter Rows: ");
    int cols = getInt("Enter Columns: ");
    int turns = getInt("Enter Turns: ");

    if (checkBoardValues(rows, cols, turns) == FALSE)
        return 1;

    if (fillTheBoard(board, rows, cols) == FALSE)
        return 2;

    playGameOfLife(board, rows, cols, turns);

    return 0;
}

void playGameOfLife(Grid board, int rows, int columns, int turns) {

    for (int k = 0; k < turns; ++k) {
        doNextTurn(board, k, rows, columns);
    }

    printResults(board, turns, rows, columns);
}

void doNextTurn(Grid board, int previousTurn, int rows, int columns) {

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < columns; ++j) {

            int count = countNeighbours(board, previousTurn, rows, columns, i, j);
            int self = (board[i][j][previousTurn] == ALIVE ? 1 : 0);

            if (self == 0) {

                if (count == 3) {
                    board[i][j][previousTurn+1] = ALIVE;
                } else {
                    board[i][j][previousTurn+1] = DEAD;
                }
            }

            else {

                if (count == 3 || count == 2) {
                    board[i][j][previousTurn+1] = ALIVE;
                } else {
                    board[i][j][previousTurn+1] = DEAD;
                }
            }

        }
    }
}

int countNeighbours(Grid board, int turn, int rows, int columns, int i, int j) {

    int count = 0;

    // up

    if (i > 0 && j > 0){
        State temp1 = board[i-1][j-1][turn];
        if (temp1 == ALIVE) count++;
    }

    if (i > 0) {
        State temp2 = board[i - 1][j][turn];
        if (temp2 == ALIVE) count++;
    }

    if (i > 0 && j < (columns - 1)) {
        State temp3 = board[i - 1][j + 1][turn];
        if (temp3 == ALIVE) count++;
    }

    // center

    if (j > 0) {
        State temp4 = board[i][j - 1][turn];
        if (temp4 == ALIVE) count++;
    }

    if (j < (columns - 1)) {
        State temp5 = board[i][j + 1][turn];
        if (temp5 == ALIVE) count++;
    }

    // bottom

    if (i < (rows - 1) && j > 0) {
        State temp6 = board[i + 1][j - 1][turn];
        if (temp6 == ALIVE) count++;
    }

    if (i < (rows - 1)) {
        State temp7 = board[i + 1][j][turn];
        if (temp7 == ALIVE) count++;
    }

    if (i < (rows - 1) && j < (columns - 1)) {
        State temp8 = board[i + 1][j + 1][turn];
        if (temp8 == ALIVE) count++;
    }

    return count;
}

void printBoard(Grid board, int rows, int columns, int atTurn) {

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < columns; ++j) {
            State temp = board[i][j][atTurn];
            printf("%c ", (temp == ALIVE ? '1' : '0'));
        }

        printf("\n");
    }
}

void printResults(Grid board, int boardsCount, int rows, int columns) {

    for (int i = 0; i < boardsCount; ++i) {
        printf("Generation %d:\n", i);
        printBoard(board, rows, columns, i);

        printf("\n");
    }
}

int getInt(char message[]) {

    int value;

    printf("%s", message);

    if (scanf("%d", &value) != 1) {
        fprintf(stderr, "ERROR: Entered value must be numeric.\n");
        return -1;
    }
    return value;
}

Boolean fillTheBoard(Grid board, int rows, int cols) {
    State cellState;
    int value;
    for (int row = 1; row <= rows; ++row) {
        for (int col = 1; col <= cols; ++col) {
            value = getInt("Enter cell: ");
            if (checkCellValue(value)) {
                if (value == 1) {
                    cellState = ALIVE;
                } else {
                    cellState = DEAD;
                }
                board[row][col][0] = cellState;
            } else {
                fprintf(stderr, "ERROR: Invalid cell value entered (0|1).");
                return FALSE;
            }
        }
    }
    return TRUE;
}

Boolean checkCellValue(int value) {
    if (value != 0 || value != 1)
        return FALSE;
    return TRUE;
}

Boolean checkBoardValues(int rows, int cols, int generations) {
    if (rows < 0 || cols < 0 || generations < 0) {
        fprintf(stderr, "ERROR: Rows/Columns/Generations has to be positive number.\n");
        return FALSE;
    }

    if (rows > MAXROW) {
        fprintf(stderr, "ERROR: Rows maximum is %d .\n", MAXROW);
        return FALSE;
    }
    if (rows > MAXCOL) {
        fprintf(stderr, "ERROR: Columns maximum is %d .\n", MAXCOL);
        return FALSE;
    }

    if (rows > MAXGEN) {
        fprintf(stderr, "ERROR: Generations maximum is %d .\n", MAXGEN);
        return FALSE;
    }

    return TRUE;

}