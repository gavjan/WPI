#include <stdio.h>
#include <stdlib.h>
#define ROWS 8
#define COLUMNS 8

void write(char item[][COLUMNS+1]){
	int i,j;
	for(i=1;i<=ROWS;i++) {
		for(j=1;j<=COLUMNS;j++) {
			printf(" %c", item[i][j]);
		}
		printf("\n");
	}
    printf(" a b c d e f g h\n");
}

int checkHorizontal(char item[][COLUMNS+1], int Y,int X) {
	if(item[Y][X+2]=='-') {return 0;}
	if(item[Y][X]!='-') {
		if(item[Y][X] == item[Y][X+4]) {
			if(item[Y][X+1]!='-') {
				if(item[Y][X+1] == item[Y][X+3]){
					return 1;
				}
			}
		
		}
	}
		return 0;
}
int leftDiagonal(char item[][COLUMNS+1], int Y,int X) {
	if(item[Y+2][X+2]=='-') {return 0;}
	if(item[Y][X]!='-') {
		if(item[Y][X] == item[Y+4][X+4]) {
			if(item[Y+1][X+1]!='-') {
				if(item[Y+1][X+1] == item[Y+3][X+3]){
					return 1;
				}
			}
		
		}
	}
		return 0;
}
int rightDiagonal(char item[][COLUMNS+1], int Y,int X) {
	if(item[Y+2][X-2]=='-') {return 0;}
	if(item[Y][X]!='-') {
		if(item[Y][X] == item[Y+4][X-4]) {
			if(item[Y+1][X-1]!='-') {
				if(item[Y+1][X-1] == item[Y+3][X-3]){
					return 1;
				}
			}
		
		}
	}
		return 0;
}

int main()
{
	int i,j,step,changeX,changeY,inputX;
	char item[ROWS+1][COLUMNS+1],input[3];
	for(i=1;i<=ROWS;i++) {
		for(j=1;j<=COLUMNS;j++) {
			item[i][j]='-';
		}
	}
	
	

for(step=1;step!=-1;step++) {
	write(item);
	changeX=0;
	changeY=0;
	input[1]=0;
	input[2]=0;
	printf("%d:\n", ((step-1)%2)+1==0 ? 1:((step-1)%2)+1 );
	i=0;
	while ((inputX=getchar())!=EOF && inputX!='\n'){
		if (i<3){
			input[i]=(char)inputX;
			i++;
		}
	}
	
	if (inputX==EOF) {break;}
	if (i==0 && inputX=='\n') {step--; continue;}
	
	if((int)input[1]!=0){step--; continue;}
		
	if(input[0]=='=') {break;}
	
	if((int)input[0]>='a' && (int)input[0]<='h'){changeX = (int)input[0]-96;}
	else {step--;continue;}
	
	if(changeX!=0) {
		
		
		for(changeY=8;changeY>=1;changeY--) {
			if(item[changeY][changeX]=='-') {
				item[changeY][changeX]='0'+(((step-1)%2)+1==0 ? 1:((step-1)%2)+1);
				break;
			}
		}
			if(changeY==0) {step--;continue;}
	}

	
	if(changeX!=0){
		
	
		
		
		if(changeX<=4) {
			for(i=1;i<=changeX;i++) {
				if(checkHorizontal(item,changeY,i)){
					write(item);
					printf("%d.\n", ((step-1)%2)+1==0 ? 1:((step-1)%2)+1 );
					return 0;
				}
			}
		}
		else {
			for(i=8;i>=changeX;i--){
				if(checkHorizontal(item,changeY,i-4)){
					write(item);
					printf("%d.\n", ((step-1)%2)+1==0 ? 1:((step-1)%2)+1 );
					return 0;
				}
			}
		}
		
		if(changeY<=4) {
			if(item[changeY][changeX]==item[changeY+4][changeX]) {
				if(item[changeY+1][changeX]==item[changeY+3][changeX]) {
					write(item);
					printf("%d.\n", ((step-1)%2)+1==0 ? 1:((step-1)%2)+1 );
					return 0;
				}
				
				
			}
		
		}
		
	if(abs(changeX-changeY)<=3) {
		
		if((changeX-changeY)>=0) {
			j=changeX-changeY+1;
			for(i=1;i<=4-(changeX-changeY);i++) {
				if(leftDiagonal(item,i,j)) {
					write(item);
					printf("%d.\n", ((step-1)%2)+1==0 ? 1:((step-1)%2)+1 );
					return 0;
				}
				j++;
				
			}
		}
		else {
			i=changeY-changeX+1;
			for(j=1;j<=4-(changeY-changeX);j++) {
				if(leftDiagonal(item,i,j)) {
					write(item);
					printf("%d.\n", ((step-1)%2)+1==0 ? 1:((step-1)%2)+1 );
					return 0;
				}
				i++;
				
			}
		}
	}
	
	if(changeX+changeY>=6 && changeX+changeY<=12) {
		
		if((changeX+changeY)<=8) {
			j=changeX+changeY-1;
			for(i=1;i<=changeX+changeY-5;i++) {
				if(rightDiagonal(item,i,j)) {
					write(item);
					printf("%d.\n", ((step-1)%2)+1==0 ? 1:((step-1)%2)+1 );
					return 0;
				}
				j--;
				
			}
		}
		
		if((changeX+changeY)>=9) {
			i=changeX+changeY-8;
			for(j=8;j>=(changeX+changeY)-4;j--) {
				if(rightDiagonal(item,i,j)) {
					write(item);
					printf("%d.\n", ((step-1)%2)+1==0 ? 1:((step-1)%2)+1 );
					return 0;
				}
				i++;
				
			}
		}
	}
	
	
	}

	
		
}





	return 0;
}

