#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 3 
#define MAX_COLS 3

char Board[MAX_ROWS][MAX_COLS]; 

void initializeBoard() {
	for (int i = 0; i < MAX_ROWS; i++) {
		for (int  j = 0; j < MAX_COLS; j++) {
			Board[i][j] = ' '; 
		}
	}
}
void drawBoard() { 
	printf("\t\t\t\t\t| %c | %c | %c |\n", Board[0][0], Board[0][1], Board[0][2]); 
	printf("\t\t\t\t\t| %c | %c | %c |\n", Board[1][0], Board[1][1], Board[1][2]); 
	printf("\t\t\t\t\t| %c | %c | %c |\n", Board[2][0], Board[2][1], Board[2][2]); 
}
void playerMove(char player)  {
	int row, col; 
	printf("\n\t\t\t\tPlayer %c Enter your move (row, colum): ", player);  
	scanf("%d %d", &row, &col); 
	if (row >= 1 && row <= 3 &&  col >= 1 && col <= 3 && Board[row - 1][col - 1] == ' ') {
		Board[row - 1][col - 1] = player; 
	} 
	else {
		printf("\t\t\t\tInvaid move! Try again\n"); 
		playerMove(player); 
	}
}
int checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][0] != ' ') {
            return 1; // Row match
        }
        // Check columns
        if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i] && Board[0][i] != ' ') {
            return 1; // Column match
        }
    }

    // Check diagonals
    if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[0][0] != ' ') {
        return 1; // Main diagonal match
    }
    if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && Board[0][2] != ' ') {
        return 1; // Reverse diagonal match
    }

    return 0; // No winner
}

int main() {
	char currentPlyaer = 'x'; 
	int moves = 0; 

	initializeBoard(); 

	while(1) {
		drawBoard(); 
		playerMove(currentPlyaer);
		moves++;
		
		if (checkWinner()) {
		  	drawBoard(); 
			printf("\t\t\t\t\tPlayer %c wins !", currentPlyaer); 
			break; 
		}
		if (moves == 9) {
			drawBoard(); 
			printf("\t\t\t\t\tIt a draws \n"); 
			break; 
		}
		currentPlyaer = (currentPlyaer == 'x') ? 'o' : 'x'; 
		system("clear"); 
	}
	return 0; 
}
