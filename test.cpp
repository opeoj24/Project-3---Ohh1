/**
 * test.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 *
 * Opeyemi Ojubanire
 * opeoju
 *
 * Project that allows you to play the fun game called ohhi!
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_rows_are_different();
void test_cols_are_different();
void test_board_has_no_duplicates();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_solve_balance_row();
void test_solve_balance_column();
void test_board_is_solved();
void test_check_valid_input();
void test_check_valid_move();

// declare more test functions here

void startTests() {
    test_count_unknown_squares();
    test_row_has_no_threes();
    test_col_has_no_threes_of_color();
    test_board_has_no_threes();
    test_rows_are_different();
    test_cols_are_different();
    test_board_has_no_duplicates();
    test_solve_three_in_a_row();
    test_solve_three_in_a_column();
    test_solve_balance_row();
    test_solve_balance_column();
    test_board_is_solved();
    test_check_valid_input();
    test_check_valid_move();
    // add your calls to test functions here
}


void test_count_unknown_squares() {
    cout << "testing count_unknown_squares" << endl;
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"XOXO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << endl;

    string test_board_2[] = {"XOXO",
                             "XXOO",
                             "OXOX",
                             "OOXX"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << count_unknown_squares(board, size_2) << endl;
    
    string test_board_3[] = {"XO",
                             "OO"};
    int size_3 = 2;
    read_board_from_string(board, test_board_3, size_3);
    cout << count_unknown_squares(board, size_3) << endl;
    
    string test_board_4[] = {"XOXO--",
                             "--OOXX",
                             "-XX---",
                             "OXXOXO",
                             "XX--OO",
                             "OXOO--"};
    int size_4 = 6;
    read_board_from_string(board, test_board_4, size_4);
    cout << count_unknown_squares(board, size_4) << endl;
    
    string test_board_5[] = {"XOXO--XO",
                             "--OOXX-O",
                             "-XX---OO",
                             "OXXOXO--",
                             "XX--OOXO",
                             "OXOO--XX",
                             "--OXOX-X",
                             "OOXX-OX-"};
    int size_5 = 8;
    read_board_from_string(board, test_board_5, size_5);
    cout << count_unknown_squares(board, size_5) << endl;
    // add more tests here
}

// define more test functions here
void test_row_has_no_threes() {
    cout << "testing row_has_no_threes" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = {"XOXO",
                             "XXXO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << row_has_no_threes_of_color(board, size_1, 1, RED) << "\n";
    
    string test_board_2[] = {"XOXO",
                             "XXOO",
                             "---X",
                             "--O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << row_has_no_threes_of_color(board, size_2, 1, RED) << "\n";
    
    string test_board_3[] = {"XOXO",
                             "XOOO",
                             "---X",
                             "--O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << row_has_no_threes_of_color(board, size_3, 1, BLUE) << "\n";
    
    string test_board_4[] = {"XOXO",
                             "OXOX",
                             "XOOX",
                             "OOXX"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << row_has_no_threes_of_color(board, size_4, 2, BLUE) << "\n";
    

}

void test_col_has_no_threes_of_color() {
    cout << "testing col_has_no_threes" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = {"XOXO",
                             "XXXO",
                             "--XX",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << col_has_no_threes_of_color(board, size_1, 2, RED) << "\n";
    

    string test_board_2[] = {"XOXO",
                             "XXXO",
                             "--XX",
                             "--O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << col_has_no_threes_of_color(board, size_2, 1, BLUE) << "\n";
    
    
    string test_board_3[] = {"XOXOXO",
                             "--XO-X",
                             "-XOOXX",
                             "--O---",
                             "XXOO-O",
                             "---XXO"};
    int size_3 = 6;
    read_board_from_string(board, test_board_3, size_3);
    cout << col_has_no_threes_of_color(board, size_3, 3, RED) << "\n";
    
    string test_board_4[] = {"O-OX",
                             "OX--",
                             "O-X-",
                             "X--O"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << col_has_no_threes_of_color(board, size_4, 0, BLUE) << "\n";
    
}

void test_board_has_no_threes() {
    cout << "testing board_has_no_threes" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = {"XOXO",
                             "XXXO",
                             "--XX",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_threes(board, size_1) << "\n";
    
    string test_board_2[] = {"OX-O",
                             "---X",
                             "XX-O",
                             "OO-X"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_threes(board, size_2) << "\n";
    
    string test_board_3[] = {"XOOO",
                             "XOXO",
                             "OOXX",
                             "--O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_has_no_threes(board, size_3) << "\n";
    
    string test_board_4[] = {"XO-O",
                             "----",
                             "--XX",
                             "--O-"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << board_has_no_threes(board, size_1) << "\n";
    
    
}

void test_rows_are_different() {
    cout << "testing rows_are_different" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = {"XOXO",
                             "XXXO",
                             "XOXO",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << rows_are_different(board, size_1, 0, 2) << "\n";
    
    string test_board_2[] = {"XOX-",
                             "O-XX",
                             "XXOO",
                             "X-O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << rows_are_different(board, size_2, 1, 3) << "\n";
    
    string test_board_3[] = {"XOX-",
                             "OOXX",
                             "OOXX",
                             "X-O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << rows_are_different(board, size_3, 1, 2) << "\n";
    
    string test_board_4[] = {"-OX-",
                             "XX--",
                             "OXX-",
                             "X-O-"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << rows_are_different(board, size_4, 2, 3) << "\n";
    

}

void test_cols_are_different() {
    cout << "testing cols_are_different" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = {"XXXO",
                             "XXXO",
                             "OOXO",
                             "OOO-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << cols_are_different(board, size_1, 0, 1) << "\n";

 
    string test_board_2[] = {"X-XO",
                             "OX--",
                             "X-XO",
                             "OOX-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << cols_are_different(board, size_2, 0, 1) << "\n";
    
    string test_board_3[] = {"---O",
                             "-O--",
                             "XXOO",
                             "OO--"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << cols_are_different(board, size_3, 2, 3) << "\n";
    
    string test_board_4[] = {"XOXO",
                             "OXOX",
                             "XOXO",
                             "OXOX"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << cols_are_different(board, size_4, 0, 2) << "\n";
}

void test_board_has_no_duplicates() {
    cout << "testing board_has_no_duplicates" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = {"XOXO",
                             "XXXO",
                             "XOXO",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_duplicates(board, size_1)<< "\n";

    int board1[MAX_SIZE][MAX_SIZE];
    string test_board_2[] = {"XOXO",
                             "XOOX",
                             "OXXO",
                             "--O-"};
    int size_2 = 4;
    read_board_from_string(board1, test_board_2, size_2);
    cout << board_has_no_duplicates(board1, size_2)<< "\n";
}

void test_solve_three_in_a_row() {
    cout << "Testing solve_three_in_a_row" << endl;
        int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = {"OXOX",
                             "-OO-",
                             "-OX-",
                             "----"};
    int size_1 = 4;
    
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_row(board, size_1, 1,1 );
    
    string test_board_2[] = {"OXOX",
                             "-XX-",
                             "-OX-",
                             "----"};
    int size_2 = 4;
    
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_row(board, size_2, 1,1 );
    
    string test_board_3[] = {"----",
                             "-O-O",
                             "----",
                             "--O-"};
    int size_3 = 4;
    
    read_board_from_string(board, test_board_3, size_3);
    solve_three_in_a_row(board, size_3, 1,1 );
    
    string test_board_4[] = {"XX--",
                             "--O-",
                             "-XX-",
                             "--O-"};
    int size_4 = 4;
    
    read_board_from_string(board, test_board_4, size_4);
    solve_three_in_a_row(board, size_4, 2, 1);

}

void test_solve_three_in_a_column() {
    cout << "Testing solve_three_in_a_column" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = {"X---",
                             "-XO-",
                             "OXX-",
                             "X---"};
    int size_1 = 4;
    
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_column(board, size_1, 1, 1);
    
    string test_board_2[] = {"O---X-",
                             "-OO-X-",
                             "OOX-O-",
                             "X--O-X",
                             "X-XX-O",
                             "---X-X"};
    int size_2 = 6;
    
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_column(board, size_2, 1, 1);
    
    string test_board_3[] = {"----",
                             "OO--",
                             "-OO-",
                             "--O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
   solve_three_in_a_column(board, size_3, 1, 1);
    
}

void test_solve_balance_row() {
    cout << "Testing solve_balance_row" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = {"----",
                             "--OO",
                             "-XX-",
                             "OO--"};
    int size_1 = 4;
    
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_row(board, size_1, 2, 1);
    
    string test_board_2[] = {"----",
                             "OO--",
                             "-OO-",
                             "--O-"};
    int size_2 = 4;
    
    read_board_from_string(board, test_board_2, size_2);
    solve_balance_row(board, size_2, 2, 1);
}

void test_solve_balance_column() {
    cout << "Testing solve_balance_column" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = {"O-OX",
                             "--OX",
                             "-OX-",
                             "OO--"};
    int size_1 = 4;
    
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_column(board, size_1, 2, 1);
    
    string test_board_2[] = {"O--X",
                             "--OO",
                             "OOX-",
                             "X---"};
    int size_2 = 4;
    
    read_board_from_string(board, test_board_2, size_2);
    solve_balance_column(board, size_2, 0, 1);
}
void test_board_is_solved(){
    cout << "Testing board_is_solved" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = {"XXOO",
                             "XOXO",
                             "OOXX",
                             "OXOX"};
    int size_1 = 4;
    
    read_board_from_string(board, test_board_1, size_1);
    cout << board_is_solved(board, size_1) << "\n";
    
    string test_board_2[] = {"OXXO",
                             "XOXO",
                             "OOOX",
                             "XXOX"};
    int size_2 = 4;

    read_board_from_string(board, test_board_2, size_2);
    cout << board_is_solved(board, size_2) << "\n";
}

void test_check_valid_input(){
    cout << "Testing check_valid_input" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    int row = 0;
    int col = 0;
    string test_board_1[] = {"X--O",
                             "-OX-",
                             "O-XX",
                             "OXO-"};
    int size_1 = 4;
    
    read_board_from_string(board, test_board_1, size_1);
    cout << check_valid_input(size_1, 2, 'B', 'A', row, col) << "\n";
    
   
    string test_board_2[] = {"X-OO",
                             "-OX-",
                             "O-XX",
                             "OXO-"};
    int size_2 = 4;
    
    read_board_from_string(board, test_board_2, size_2);
    cout << check_valid_input(size_1, 1, 'Z', 'A', row, col) << "\n";
    
    string test_board_3[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_3 = 4;
    
    read_board_from_string(board, test_board_3, size_3);
    cout << check_valid_input(size_3, 2, 'B', 'X', row, col) << "\n";
    
    string test_board_4[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_4 = 4;
    
    read_board_from_string(board, test_board_4, size_4);
    cout << check_valid_input(size_4, 2, 'Z', 'X', row, col) << "\n";
    
}
void test_check_valid_move() {
    cout << "check_valid_move" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    int board1[MAX_SIZE][MAX_SIZE];
    string test_board_orginal[] = {"O-OX",
                                   "--OX",
                                   "-OX-",
                                   "OO--"};
    
    string test_board_current[] = {"O-OX",
                                  "X-OX",
                                  "-OXO",
                                  "OO--"};
    
    int size_1 = 4;
    
    read_board_from_string(board, test_board_orginal, size_1);
    read_board_from_string(board1, test_board_current, size_1);
    cout << check_valid_move(board, board1, size_1, 0, 1, BLUE);
    
}

