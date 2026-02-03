//***************************************************
// Filename: othello.c
//
// Author(s): Your Name(s)
//***************************************************

#include "othello.h"

// Delaney and Jeni

// Constructs and returns a string representation of the board
// IMPORTANT: DO NOT MAKE ANY CHANGES TO THIS FUNCTION
char *toString(int size, char board[][size])
{
	char *str = (char *)calloc(3 * (size + 1) * (size + 1), sizeof(char));
	char *ptr = str;

	for (int i = 0; i < size; i++)
	{
		ptr += sprintf(ptr, (i == 0 ? "%3d" : "%2d"), i);
	}
	sprintf(ptr, "\n");
	ptr++;

	for (int i = 0; i < size; i++)
	{
		sprintf(ptr, "%1d", i);
		ptr++;
		for (int j = 0; j < size; j++)
		{
			sprintf(ptr, "%2c", board[i][j]);
			ptr += 2;
		}
		sprintf(ptr, "\n");
		ptr++;
	}

	return str;
}

// Initializes the board with start configuration of discs
// Ssee project specifications for initial board configuration
void initializeBoard(int size, char board[][size])
{
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			board[i][j] = EMPTY;
		}
	}
	board[3][3] = BLACK;
	board[4][4] = BLACK;
	board[3][4] = WHITE;
	board[4][3] = WHITE;
	// COMPLETE THIS FUNCTION
}

// Returns true if a valid move for disc is available; false otherwise
// Use isValidMove() to implement this function
bool isValidMoveAvailable(int size, char board[][size], char disc)
{
        
	// return false; // REPLACE THIS WITH YOUR IMPLEMENTATION
}

// Returns true if moving the disc to location row,col is valid; false otherwise
bool isValidMove(int size, char board[][size], int row, int col, char disc)
{
	if (row > 7 or col > 7 or row < 0 or col < 0){
		return false;
	}
	if (board[row][col] != EMPTY)
	{
		return false;
	}
	
	if (disc == BLACK){
		// top to bottom, check rows
		for (int i = 0; i <= 7; i++){
		if (i < row and board[i][col] == BLACK){
			if(board[row-1][col] == WHITE){
				return true;
			}
		}
                if (i >= row and board[i][col] == BLACK){
                        if(board[row+1][col] == WHITE){
                                return true;
                        }
                }
		} // for
	                
		// left to right, check cols
		for (int j = 0; j <= 7; j++){
                if (j < col and board[row][j] == BLACK){
                        if(board[row][col-1] == WHITE){
                                return true;
                        }
                }
                if (j >= col and board[row][j] == BLACK){
                        if(board[row][col+1] == WHITE){
                                return true;
                        }
                }
                } // for

		// top left to bottom right diagonal
		int i = row;
		int j = col;
		while (i <= 7 or j <= 7){
			if (board[row+1][col+1] == WHITE and board[i][j] == BLACK){
				return true;
			}		
			else{
				break;
			}
			i ++;
			j ++;
			
		} // while

                i = row;
                j = col;
                while (i >= 0 or j >= 0){
                        if (board[row-1][col-1] == WHITE and board[i][j] == BLACK){
                                return true;
                        }
                        else{
                                break;
                        }
                        i --;
                        j --;

                } // while
		

		// top right to bottom left
		int i = row;
		int j = col;
                while (i >= 0 or j <= 7){
                        if (board[row-1][col+1] == WHITE and board[i][j] == BLACK){
                                return true;
                        }
                        else{
                                break;
                        }
                        i --;
                        j ++;

                } // while

                int i = row;
                int j = col;
                while (i <= 7 or j >= 0){
                        if (board[row+1][col-1] == WHITE and board[i][j] == BLACK){
                                return true;
                        }
                        else{
                                break;
                        }
                        i ++;
                        j --;

                } // while	

	} // if BLACK
	
}

// Places the disc at location row,col and flips the opponent discs as needed
void placeDiscAt(int size, char board[][size], int row, int col, char disc)
{
	if (!isValidMove(size, board, row, col, disc))
	{
		return;
	}

	// COMPLETE REST OF THIS FUNCTION
}

// Returns true if the board is fully occupied with discs; false otherwise
bool isBoardFull(int size, char board[][size])
{
	return false; // REPLACE THIS WITH YOUR IMPLEMENTATION
}

// Returns true if either the board is full or a valid move is not available for either disc;
// false otherwise
bool isGameOver(int size, char board[][size])
{
	return true; // REPLACE THIS WITH YOUR IMPLEMENTATION
}

// If there is a winner, it returns the disc (BLACK or WHITE) associated with the winner.
// In case of a tie, it returns TIE. When called before the game is over, it returns 0.
char checkWinner(int size, char board[][size])
{
	if (!isGameOver(size, board))
	{
		return 0;
	}

	return TIE; // REPLACE THIS WITH YOUR IMPLEMENTATION
}
