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
	if (row > 7 || col > 7 || row < 0 || col < 0){
		return false;
	}
	if (board[row][col] != EMPTY)
	{
		return false;
	}
	if (!isValidMoveAvailable(size, board, disc)){
		return false;
	}

	// diagonals 
	int i = 0;
	int j = 0;

	if (board[row+1][col+1] != disc && board[row+1][col+1] != EMPTY) {
		while((row + i) < 7 || (col + j) < 7){
		 	i ++;
			j ++;
			if (board[row + i][col + j] == disc){
				return true;
		  	}
			else if (board[row + i][col + j] == EMPTY){
                                break;
                        }

		}
	}

        i = 0;
        j = 0;

	if (board[row-1][col-1] != disc && board[row-1][col-1] != EMPTY) {
                while((row - i) > 0 || (col - j) > 0){
                        i ++;
                        j ++;
                        if (board[row - i][col - j] == disc){
                                return true;
                        }
                        else if (board[row - i][col - j] == EMPTY){
                                break;
                        }

                }
        }

        i = 0;
        j = 0;

	if (board[row-1][col+1] != disc && board[row-1][col+1] != EMPTY) {
                while((row - i) > 0 || (col + j) < 7){
                        i ++;
                        j ++;
                        if (board[row - i][col + j] == disc){
                                return true;
                        }
                        else if (board[row - i][col + j] == EMPTY){
                                break;
                        }

                }
        }



	i = 0;
        j = 0;

	if (board[row+1][col-1] != disc && board[row+1][col-1] != EMPTY) {
                while((row + i) < 7 || (col - j) > 0){
                        i ++;
                        j ++;
                        if (board[row + i][col - j] == disc){
                                return true;
                        }
                        else if (board[row + i][col - j] == EMPTY){
                                break;
                        }

                }
        }

	// Up/down
	
	i = 0;

	if (board[row+1][col] != disc && board[row+1][col] != EMPTY) {
                while((row + i) < 7){
                        i ++;
                        if (board[row + i][col] == disc){
                                return true;
                        }
                        else if (board[row + i][col] == EMPTY){
                                break;
                        }

                }
        }

	i = 0;
	
        if (board[row-1][col] != disc && board[row-1][col] != EMPTY) {
                while((row - i) > 0){
                        i ++;
                        if (board[row - i][col] == disc){
                                return true;
                        }
                        else if (board[row - i][col] == EMPTY){
                                break;
                        }

                }
        }

	// Left/right
	
	j = 0;
        if (board[row][col+1] != disc && board[row][col+1] != EMPTY) {
                while((col + i) < 7){
                        j ++;
                        if (board[row][col + j] == disc){
                                return true;
                        }
                        else if (board[row][col + j] == EMPTY){
                                break;
                        }

                }
        }

        j = 0;
        if (board[row][col-1] == disc && board[row][col-1] != EMPTY) {
                while((col - i) > 0){
                        j ++;
                        if (board[row][col - j] == disc){
                                return true;
                        }
                        else if (board[row][col - j] == EMPTY){
                                break;
                        }

                }
        }
	


} // Is Valid Move

// Places the disc at location row,col and flips the opponent discs as needed
void placeDiscAt(int size, char board[][size], int row, int col, char disc)
{
	if (!isValidMove(size, board, row, col, disc))
	{	
		printf("Is not valid move");
		return;
	}

	board[row][col] = disc;
	
	// diagonals
        int i = 0;
        int j = 0;

        if (board[row+1][col+1] == !disc) {
                while((row + i) < 7 || (col + j) < 7){
                        i ++;
                        j ++;
                        if (board[row + i][col + j] == EMPTY){
                                break;
                        }
			else if (board[row + i][col + j] != disc){
                                board[row + i][col + j] = disc;
                        }
                }
        }
        i = 0;
        j = 0;

        if (board[row-1][col-1] == !disc) {
                while((row - i) > 0 || (col - j) > 0){
                        i ++;
                        j ++;
                        if (board[row - i][col - j] == EMPTY){
                                break;
                        }
			else if (board[row - i][col - j] != disc){
                                board[row - i][col - j] = disc;
                        }
                }
        }
	i = 0;
	j = 0;

        if (board[row-1][col+1] == !disc) {
                while((row - i) > 0 || (col + j) < 7){
                        i ++;
                        j ++;
                        if (board[row - i][col + j] == EMPTY){
                                break;
                        }
			else if (board[row - i][col + j] != disc){
                                board[row - i][col + j] = disc;
                        }
		}
        }
        i = 0;
        j = 0;

        if (board[row+1][col-1] == !disc) {
                while((row + i) < 7 || (col - j) > 0){
                        i ++;
                        j ++;
                        if (board[row + i][col - j] == EMPTY){
                                break;
                        }
			else if (board[row + i][col - j] != disc){
                                board[row + i][col - j] = disc;
                        }
                }
        }
	// Up/down
	i = 0;

        if (board[row+1][col] == !disc) {
                while((row + i) < 7){
                        i ++;
                        if (board[row + i][col] == EMPTY){
                                break;
                        }
			else if (board[row + i][col] != disc){
                                board[row + i][col] = disc;
                        }
                }
        }

        i = 0;

        if (board[row-1][col] == !disc) {
                while((row - i) > 0){
                        i ++;
                        if (board[row - i][col] == EMPTY){
                                break;
                        }
			else if (board[row - i][col] != disc){
                                board[row - i][col] = disc;
                        }
                }
        }
	// Left/right 
        j = 0;
        if (board[row][col+1] == !disc) {
                while((col + i) < 7){
                        j ++;
                        if (board[row][col + j] == EMPTY){
                                break;
                        }
			else if (board[row][col + j] != disc){
                                board[row][col + j] = disc;
                        }
                }
        }

        j = 0;
        if (board[row][col-1] == !disc) {
                while((col - i) > 0){
                        j ++;
                        if (board[row][col - j] == EMPTY){
                                break;
                        }
			else if (board[row][col - j] != disc){
                                board[row][col - j] = disc;
                        }
                }
        }
} // placeDiscAt

// Returns true if the board is fully occupied with discs; false otherwise
bool isBoardFull(int size, char board[][size])
{
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (board[i][j] == EMPTY){
				return false;
			}
		}	
	}

	return true;
}

// Returns true if either the board is full or a valid move is not available for either disc;
// false otherwise
bool isGameOver(int size, char board[][size])
{
	// if board is full
	if (isBoardFull(size, board)) {
		return true;
	}
	//return true; // REPLACE THIS WITH YOUR IMPLEMENTATION
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
