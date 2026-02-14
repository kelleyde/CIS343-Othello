//***************************************************
// Filename: othello.c
//
// Author(s): Your Name(s) Delaney and Jeni
//***************************************************

#include "othello.h"

int topLbotR(int size, char board[][size], int row, int col, char disc);
int topRbotL(int size, char board[][size], int row, int col, char disc);
int botLtopR(int size, char board[][size], int row, int col, char disc);
int botRtopL(int size, char board[][size], int row, int col, char disc);
int Up(int size, char board[][size], int row, int col, char disc);
int Down(int size, char board[][size], int row, int col, char disc);
int Left(int size, char board[][size], int row, int col, char disc);
int Right(int size, char board[][size], int row, int col, char disc);

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
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if (i == size / 2 && j == size / 2){
				board[i][j] = BLACK;
				board[i-1][j-1] = BLACK;
				board[i-1][j] = WHITE;
				board[i][j-1] = WHITE;
			}
			else{
			board[i][j] = EMPTY;
			}
		}
	}
	
	// COMPLETE THIS FUNCTION
}

// Returns true if a valid move for disc is available; false otherwise
// Use isValidMove() to implement this function
bool isValidMoveAvailable(int size, char board[][size], char disc){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == EMPTY) {
				if (isValidMove(size, board, i, j, disc)){
					return true;
				}
			}
		}
	} 
	return false;
}

// Returns true if moving the disc to location row,col is valid; false otherwise
bool isValidMove(int size, char board[][size], int row, int col, char disc)
{

	if (row > size || col > size || row < 0 || col < 0){
		return false;
	}
	if (board[row][col] != EMPTY)
	{
		return false;
	}

        if (row == 0 && col == 7){
                if(Left(size, board, row, col, disc) ||
                Down(size, board, row, col, disc) ||
                topRbotL(size, board, row, col, disc)){
                        return true;
                }
                return false;
        }
        else if (row == 0 && col == 0) {
                if(Right(size, board, row, col, disc) ||
                Down(size, board, row, col, disc) ||
                topLbotR(size, board, row, col, disc)){
                        return true;
                }
                return false;
        }
        else if (row == 7 && col == 0){
                if(Right(size, board, row, col, disc) ||
                Up(size, board, row, col, disc) ||
                botLtopR(size, board, row, col, disc)){
                        return true;
                }
                return false;
        }
        else if (row == 7 && col == 7){
                if(Left(size, board, row, col, disc) ||
                Up(size, board, row, col, disc) ||
                botRtopL(size, board, row, col, disc)){
                        return true;
                }
                else{
                return false;
                }
        }
        else if (col == 0) {
                if(Right(size, board, row, col, disc) ||
                Up(size, board, row, col, disc) ||
                Down(size, board, row, col, disc) ||
                topLbotR(size, board, row, col, disc) ||
                botLtopR(size, board, row, col, disc)){
                        return true;
                }
                else{
                return false;
                }
        }
        else if (col == 7) {
                if(Left(size, board, row, col, disc) ||
                Up(size, board, row, col, disc) ||
                Down(size, board, row, col, disc) ||
                topRbotL(size, board, row, col, disc) ||
                botRtopL(size, board, row, col, disc)){
                        return true;
                }
                return false;
        }
        else if (row == 0) {
                if(Left(size, board, row, col, disc) ||
                Right(size, board, row, col, disc) ||
                Down(size, board, row, col, disc) ||
                topRbotL(size, board, row, col, disc) ||
                topLbotR(size, board, row, col, disc)){
                        return true;
                }
                return false;
        }
        else if (row == 7) {
                if(Left(size, board, row, col, disc) ||
                Right(size, board, row, col, disc) ||
                Up(size, board, row, col, disc) ||
                botLtopR(size, board, row, col, disc) ||
                botRtopL(size, board, row, col, disc)){
                        return true;
                }
                else{
                return false;
                }
        }
        
                if(Left(size, board, row, col, disc) ||
                Right(size, board, row, col, disc) ||
                Up(size, board, row, col, disc) ||
                Down(size, board, row, col, disc) ||
                topLbotR(size, board, row, col, disc) ||
                botRtopL(size, board, row, col, disc) ||
                topRbotL(size, board, row, col, disc) ||
                botLtopR(size, board, row, col, disc)){
                        return true;
                }
                return false;

} // Valid Move

int topLbotR(int size, char board[][size], int row, int col, char disc){
	// diagonals 
	int i = 1;
	int j = 1;

	if (board[row+1][col+1] != disc && board[row+1][col+1] != EMPTY) {
		while((row + i) < size || (col + j) < size){
			if (board[row + i][col + j] == disc){
				return 1;
		  	}
			else if (board[row + i][col + j] == EMPTY){
                                break;
                        }
		 	i ++;
			j ++;
		}
	}
        return 0;
}

int botRtopL(int size, char board[][size], int row, int col, char disc){
        int i = 1;
        int j = 1;

	if (board[row-1][col-1] != disc && board[row-1][col-1] != EMPTY) {
                while((row - i) >= 0 || (col - j) >= 0){
                        if (board[row - i][col - j] == disc){
                                return 1;
                        }
                        else if (board[row - i][col - j] == EMPTY){
                                break;
                        }
                        i ++;
                        j ++;

                }
        }
        return 0;
}

int botLtopR(int size, char board[][size], int row, int col, char disc){
        int i = 1;
        int j = 1;

	if (board[row-1][col+1] != disc && board[row-1][col+1] != EMPTY) {
                while((row - i) >= 0 || (col + j) < size){
                        if (board[row - i][col + j] == disc){
                                return 1;
                        }
                        else if (board[row - i][col + j] == EMPTY){
                                break;
                        }
                        i ++;
                        j ++;
                }
        }
        return 0;
}


int topRbotL(int size, char board[][size], int row, int col, char disc){
	int i = 1;
        int j = 1;

	if (board[row+1][col-1] != disc && board[row+1][col-1] != EMPTY) {
                while((row + i) < size || (col - j) >= 0){
                        if (board[row + i][col - j] == disc){
                                return 1;
                        }
                        else if (board[row + i][col - j] == EMPTY){
                                break;
                        }
                        i ++;
                        j ++;
                }
        }
        return 0;
}

	// Up/down
int Up(int size, char board[][size], int row, int col, char disc){	
	int i = 1;

	if (board[row-1][col] != disc && board[row-1][col] != EMPTY) {
                while((row - i) >= 0){
                        if (board[row - i][col] == disc){
                                return 1;
                        }
                        else if (board[row - i][col] == EMPTY){
                                break;
                        }
                        i ++;
                }
        }
        return 0;
}

int Down(int size, char board[][size], int row, int col, char disc){
	int i = 1;
	
        if (board[row+1][col] != disc && board[row+1][col] != EMPTY) {
                while((row + i) < size){
                        if (board[row + i][col] == disc){
                                return 1;
                        }
                        else if (board[row + i][col] == EMPTY){
                                break;
                        }
                        i ++;
                }
        }
        return 0;
}
	// Left/right
int Right(int size, char board[][size], int row, int col, char disc){	
	int j = 1;
        if (board[row][col+1] != disc && board[row][col+1] != EMPTY) {
                while((col + j) < size){
                        if (board[row][col + j] == disc){
                                return 1;
                        }
                        else if (board[row][col + j] == EMPTY){
                                break;
                        }
                        j ++;
                }
        }
        return 0;
}

int Left(int size, char board[][size], int row, int col, char disc){
        int j = 1;
        if (board[row][col-1] != disc && board[row][col-1] != EMPTY) {
                while((col - j) >= 0){
                        if (board[row][col - j] == disc){
                                return 1;
                        }
                        else if (board[row][col - j] == EMPTY){
                                break;
                        }
                        j ++;
                }
        }

	return 0;
} 

// Places the disc at location row,col and flips the opponent discs as needed
void placeDiscAt(int size, char board[][size], int row, int col, char disc)
{
	if (!isValidMove(size, board, row, col, disc))
	{	
		return;
	}
	
	size = size - 1; 	

	board[row][col] = disc;

	// // diagonals
        int i = 0;
        int j = 0;

        if (board[row+1][col+1] != disc && board[row+1][col+1] != EMPTY) {
                while((row + i) <= size || (col + j) <= size){
                        i ++;
                        j ++;
                        if (board[row + i][col + j] == EMPTY){
                                break;
                        }
			else if (board[row + i][col + j] == disc){
				while ((row + i) != row || (col + j) != col){
					i --;
					j --;
					board[row + i][col + j] = disc;
				}
                                break;
                        }
                }
        }
        i = 0;
        j = 0;

        if (board[row-1][col-1] != disc && board[row-1][col-1] != EMPTY) {
                while((row - i) >= 0 || (col - j) >= 0){
                        i ++;
                        j ++;
                        if (board[row - i][col - j] == EMPTY){
                                break;
                        }
                        else if (board[row - i][col - j] == disc){
                                while ((row - i) != row || (col - j) != col){
                                        i --;
                                        j --;
                                        board[row - i][col - j] = disc;
                                }
                                break;
                        }
                }
        }
	i = 0;
	j = 0;

        if (board[row-1][col+1] != disc && board[row-1][col+1] != EMPTY) {
                while((row - i) >= 0 || (col + j) <= size){
                        i ++;
                        j ++;
                        if (board[row - i][col + j] == EMPTY){
                                break;
                        }
                        else if (board[row - i][col + j] == disc){
                                while ((row - i) != row || (col + j) != col){
                                        i --;
                                        j --;
                                        board[row - i][col + j] = disc;
                                }
                                break;
                        }
		}
        }
        i = 0;
        j = 0;

        if (board[row+1][col-1] != disc && board[row+1][col-1] != EMPTY) {
                while((row + i) <= size || (col - j) >= 0){
                        i ++;
                        j ++;
                        if (board[row + i][col - j] == EMPTY){
                                break;
                        }
                        else if (board[row + i][col - j] == disc){
                                while ((row + i) != row || (col - j) != col){
                                        i --;
                                        j --;
                                        board[row + i][col - j] = disc;
                                }
                                break;
                        }
                }
        }
	// Up/down
	i = 0;

        if (board[row+1][col] != disc && board[row+1][col] != EMPTY) {
                while((row + i) <= size){
                        i ++;
                        if (board[row + i][col] == EMPTY){
                                break;
                        }
                        else if (board[row + i][col] == disc){
                                while ((row + i) != row){
                                        i --;
                                        board[row + i][col] = disc;
                                }
                                break;
                        }
                }
        }

        i = 0;

        if (board[row-1][col] != disc && board[row-1][col] != EMPTY) {
                while((row - i) >= 0){
                        i ++;
                        if (board[row - i][col] == EMPTY){
                                break;
                        }
                        else if (board[row - i][col] == disc){
                                while ((row - i) != row){
                                        i --;
                                        board[row - i][col] = disc;
                                }
                                break;
                        }
                }
        }
	// // Left/right 
        j = 0;
        if (board[row][col+1] != disc && board[row][col+1] != EMPTY) {
                while((col + j) <= size){
                        j ++;
                        if (board[row][col + j] == EMPTY){
                                break;
                        }
                        if (board[row][col + j] == disc){
                                while ((col + j) != col){
                                        j --;
                                        board[row][col + j] = disc;
                                }
                                break;
                        }
                }
        }

        j = 0;
        if (board[row][col-1] != disc && board[row][col-1] != EMPTY) {
                while((col - j) >= 0){
                        j ++;
                        if (board[row][col - j] == EMPTY){
                                break;
                        }
                        if (board[row][col - j] == disc){
                                while ((col - j) != col){
                                        j --;
                                        board[row][col - j] = disc;
                                }
                                break;
                        }
                }
        }

        return;
} // placeDiscAt

// Returns true if the board is fully occupied with discs; false otherwise
bool isBoardFull(int size, char board[][size])
{
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
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
	if (isBoardFull(size, board)) {
		return true;
	}

	if (!isValidMoveAvailable(size, board, BLACK) &&
	    !isValidMoveAvailable(size, board, WHITE)) {
		return true;
	}

	return false;
}

// If there is a winner, it returns the disc (BLACK or WHITE) associated with the winner.
// In case of a tie, it returns TIE. When called before the game is over, it returns 0.
char checkWinner(int size, char board[][size])
{
	if (!isGameOver(size, board)) {
		return 0;
	}

	int blackCount = 0;
	int whiteCount = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == BLACK) {
				blackCount++;
			}
			else if (board[i][j] == WHITE) {
				whiteCount++;
			}
		}
	}

	if (blackCount > whiteCount) {
		return BLACK;
	}
	else if (whiteCount > blackCount) {
		return WHITE;
	}
	else {
		return TIE;
	}
}
