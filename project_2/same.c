#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 80
#define RIGHT 1
#define UP 2
#define LEFT 3
#define DOWN 4
#define DELETE_I 0
#define DELETE_J 0

char (*tidy(char board[][SIZE], int *maxi, int *maxj))[SIZE] {
	int i, j, indexj, change, changemax=0;
	indexj=0;
	static char newBoard[SIZE][SIZE];
	for(j=0;j<=*maxj;j++) {	//	Fill newBoard with spaces
		for(i=0;i<=*maxi;i++) {
			newBoard[i][j]=' ';
		}
	}
	for(j=0;j<=*maxj;j++) {	//	Move to newBoard
		change=0;
		for(i=0;i<=*maxi;i++) {
			if(board[i][j]!=' ') {
				newBoard[change][indexj]=board[i][j];
				change++;
				changemax=(changemax>change) ? changemax:change;
			}
		}
		if(change!=0) {indexj++;}
	}
	*maxi=changemax-1;
	*maxj=indexj-1;
	return newBoard;
}

void delete(char tidiedBoard[][SIZE], int *maxi, int *maxj, char item, int i, int j) {
	tidiedBoard[i][j]=' ';
	if(tidiedBoard[i][j+1]==item && j+1<=*maxj) {	//	right
		delete(tidiedBoard, &*maxi, &*maxj, item, i, j+1);
	}
	if(tidiedBoard[i+1][j]==item && i+1<=*maxi) {	//	up
		delete(tidiedBoard, &*maxi, &*maxj, item, i+1, j);
	}
	if(tidiedBoard[i][j-1]==item && j-1>=0) {	//	left
		delete(tidiedBoard, &*maxi, &*maxj, item, i, j-1);
	}
	if(tidiedBoard[i-1][j]==item && i-1>=0) {	//	down
		delete(tidiedBoard, &*maxi, &*maxj, item, i-1, j);
	}
}

int main() {
	int i=0, j=0, maxj=0, maxi, rightj;
	char input[SIZE][SIZE], inputX, board[SIZE][SIZE];
	while ((inputX=getchar())!=EOF) {	//	Get the input
			input[i][j]=inputX;
			if(inputX=='\n') {i++;j=-1;}
			j++;
			maxj=(maxj>j) ? maxj:j;
	}
	maxi=i-1;
	maxj--;
	for(i=0;i<=maxi;i++) {	//	Fill empty parts with spaces
		j=0;
		while(input[i][j]!='\n') {j++;}
		for(j=j;j<=maxj;j++) {
			input[i][j]=' ';
		}
	}
	for(i=maxi;i>=0;i--) {	//	Flip it over
		for(j=0;j<=maxj;j++) {
			board[maxi-i][j]=input[i][j];
		}
	}
	char (*tidiedBoard)[SIZE]=tidy(board, &maxi, &maxj);	//	First Tidy
	delete(tidiedBoard, &maxi, &maxj, tidiedBoard[DELETE_I][DELETE_J], DELETE_I, DELETE_J);	//	Remove
	memcpy(board, tidiedBoard, sizeof board);	//	Copy to array board
	char (*final)[SIZE]=tidy(board, &maxi, &maxj);	//	Second Tidy 	
	for(i=maxi;i>=0;i--) {	//	Remove spaces in the endings and Print
		for(rightj=maxj;rightj>=0;rightj--) {
			if(final[i][rightj]!=' ') {
				for(j=0;j<=rightj;j++) {
					printf("%c" , final[i][j]);
				}
				break;
			}
		}
		printf("\n");
	}
	return 0;
}
