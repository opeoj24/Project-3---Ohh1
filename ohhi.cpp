/**
 * ohhi.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 *
 * Opeyemi Ojubanire
 * opeoju
 *
 * Project that allows you to play the fun game called ohhi!
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

/**
 * --------------------------------------------------------
 * ---------- UTILITY FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    
    int unksquare = 0;
    for (int i = 0; i < size; i++) {
        for( int j = 0; j < size; j++) {
            if( board[i][j] == UNKNOWN) {
                unksquare++;
            }
        }
    }

    return unksquare;
}


/**
 * --------------------------------------------------------
 * --------- VALIDITY CHECKING FUNCTIONS ------------------
 * --------------------------------------------------------
 */

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    //counts if rows has three of the same color
    for (int i = 0; i < size - 2; i++ ) {
    if ((board[row][i] == color) && (board[row][i + 1] == color)
               && (board[row][i + 2] == color)) {
                return false;
        }
    }
    
    return true;
    }


bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
   // counts if column has three of the same color
    for(int i = 0; i < size - 2; i++) {
           if((board[i][col] == color) && (board[i + 1][col] == color)
              && (board[i + 2][col] == color)) {
               return false;
              }
       }

    return true;
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {

    for (int i = 0; i < size; i++) {
    if (!row_has_no_threes_of_color(board, size, i, RED) ||
        (!row_has_no_threes_of_color(board, size, i, BLUE))) {
        return false;
    }
        if (!col_has_no_threes_of_color(board, size, i, RED) ||
        (!col_has_no_threes_of_color(board, size, i, BLUE))) {
            return false;
        }
            
        }

    return true;
    }

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    
    int countrow = 0;
    for (int i = 0; i < size; i++ ) {
        if((board[row1][i] == UNKNOWN) || (board[row2][i] == UNKNOWN)) {
            return true;
        }
        else if(board[row1][i] == board[row2][i]) {
            countrow++;
        }
        //checks if the rows are different
    }
    if(countrow == size) {
        return false;
    }
    else{
        return true;
        }
 
    return true;
}

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    
    int countcol = 0;
    for (int i = 0; i < size; i++ ) {
        if((board[i][col1] == UNKNOWN) || (board[i][col2] == UNKNOWN)) {
            return true;
        }
        else if(board[i][col1] == board[i][col2]) {
            countcol++;
        }
        // checks if the columns are different
    }
    if (countcol == size) {
        return false;
    }
    else{
        return true;
    }
    
    return true;
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {

    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size;  j++) {
            if (!rows_are_different(board, size, i, j)) {
                return false;
            }
            if (!cols_are_different(board, size, i, j)) {
                return false;
            }
        }
    }
   
    return true;
}


/**
 * --------------------------------------------------------
 * ---------- SOLVING FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
     
    if ( size == 2){
        return;
        //checking  each condition
    }
    for (int i = 0; i < size - 2; i++) {
           if (board[row][i] == board[row][i + 1] &&
               board[row][i] == RED) {
               if (board[row][i + 2] == UNKNOWN) {
                   mark_square_as(board, size, row, i + 2,opposite_color(RED), announce);
                   // assigns color to square for each
               }
        
           }
           if (board[row][i] == board[row][ i + 1] &&
               board[row][i] == BLUE) {
               if (board[row][i + 2] == UNKNOWN){
                   mark_square_as(board, size, row, i + 2, opposite_color(BLUE), announce);
               }
           }
               else if (board[row][i] == board[row][i+2] &&
                        board[row][i] == RED) {
                   if (board[row][i + 1] == UNKNOWN) {
                   mark_square_as(board, size, row, i + 1, opposite_color(RED), announce);
               }
           }
             if (board[row][i] == board[row][i + 2] &&
                board[row][i] == BLUE) {
               if (board[row][i + 1] == UNKNOWN) {
                   mark_square_as(board, size, row, i + 1, opposite_color(BLUE), announce);
               }
            }
               else if (board[row][i + 1] == board[row][i + 2] &&
                        board[row][i + 1] == RED) {
                   if ( board[row][i] == UNKNOWN) {
                   mark_square_as(board, size, row, i , opposite_color(RED), announce);
               }
           }
           if (board[row][i + 1] == board[row][ i + 2] &&
               board[row][i + 1] == BLUE) {
               if (board[row][i] == UNKNOWN) {
                   mark_square_as(board, size, row, i, opposite_color(BLUE), announce);
            
               }
           }
       }
       return;
   }


void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    if (size == 2){
        return;
        //checking each condition
    }
    for (int i = 0; i < size - 2; i++) {
           if (board[i][col] == board[i + 1][col] &&
               board[i][col] == RED) {
               if (board[i + 2][col] == UNKNOWN) {
                   mark_square_as(board, size, i + 2, col ,opposite_color(RED), announce);
               }
        
           }
           if (board[i][col] == board[i + 1][col] &&
               board[i][col] == BLUE) {
               if (board[i + 2][col] == UNKNOWN){
                   mark_square_as(board, size, i + 2, col, opposite_color(BLUE), announce);
               }
           }
               else if (board[i][col] == board[i + 2][col] &&
                        board[i][col] == RED) {
                   if (board[i + 1][col] == UNKNOWN) {
                   mark_square_as(board, size, i + 1, col, opposite_color(RED), announce);
               }
           }
             if (board[i][col] == board[i + 2][col] &&
                board[i][col] == BLUE) {
               if (board[i + 1][col] == UNKNOWN) {
                   mark_square_as(board, size, i + 1, col, opposite_color(BLUE), announce);
               }
            }
               else if (board[i + 1][col] == board[i + 2][col] &&
                        board[i + 1][col] == RED) {
                   if ( board[i][col] == UNKNOWN) {
                   mark_square_as(board, size, i, col , opposite_color(RED), announce);
               }
           }
           if (board[i + 1][col] == board[i + 2][col] &&
               board[i + 1][col] == BLUE) {
               if (board[i][col] == UNKNOWN) {
                   mark_square_as(board, size, i , col, opposite_color(BLUE), announce);
            
               }
           }
       }
       return;
   }


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    
    int redsquares = 0;
    int bluesquares= 0;
       for (int i = 0; i < size; i++) {
           if (board[row][i] == RED) {
               redsquares++;
           }
           else if (board[row][i] == BLUE) {
               bluesquares++;
           }
           if (redsquares == (size / 2)) {
               for (int i = 0; i < size; i++) {
                if (board[row][i] == UNKNOWN) {
                    mark_square_as(board, size, row, i, BLUE, announce);
                   }
               }
           }
           if (bluesquares == (size / 2)) {
               for (int i = 0; i < size; i++) {
                if (board[row][i] == UNKNOWN) {
                    mark_square_as(board, size, row, i, RED, announce);
                   }
               }
           }
       }
    return;
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    
    int redsquares = 0;
    int bluesquares= 0;
       for (int i = 0; i < size; i++) {
           if (board[i][col] == RED) {
               redsquares++;
           }
           else if (board[i][col] == BLUE) {
               bluesquares++;
           }
           if (redsquares == (size / 2)) {
               for (int i = 0; i < size; i++) {
            if (board[i][col] == UNKNOWN) {
                    mark_square_as(board, size, i, col, BLUE, announce);
                   }
               }
           }
           if (bluesquares == (size / 2)) {
               for (int i = 0; i < size; i++) {
                if (board[i][col] == UNKNOWN) {
                    mark_square_as(board, size, i, col, RED, announce);
                   }
               }
           }
       }
    return;
}


/**
 * --------------------------------------------------------
 * ---------- GAMEPLAY FUNCTIONS --------------------------
 * --------------------------------------------------------
 */

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
        // checks if board meets all conditions and is valid
        if (count_unknown_squares(board, size) == 0 &&
            board_is_valid(board, size)) {
            return true;
    
    }
    
    return false;
}

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    //checks if input is correct
    col_input = toupper(col_input);
    color_char = toupper(color_char);
        if (( row_input >= 1 && row_input <= size) && (col_input >= 'A' &&
       col_input <= 'A' + size - 1) && (color_char == '-' || color_char == 'X' ||
       color_char == 'O')) {
        row = row_input - 1;
        col = col_input - 'A';
        return true;
   }
    cout << "Sorry, that's not a valid input." << endl;
    return false;
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    
    int copiedBoard[MAX_SIZE][MAX_SIZE];
    copy_board(current_board, copiedBoard, size);
    copiedBoard[row][col] = color;
    
    if (original_board[row][col] != UNKNOWN){
        cout << "Sorry, original squares cannot be changed." << endl;
        return false;
    }
    else if (!board_is_valid(copiedBoard, size)) {
        cout << "Sorry, that move violates a rule." << endl;
        return false;
    }
    else {
        return true;
    }
}
 
