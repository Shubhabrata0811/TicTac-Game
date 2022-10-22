#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

char sq[10]={'0','1','2','3','4','5','6','7','8','9'};
char sqcheck[10]={'0','1','2','3','4','5','6','7','8','9'};
int checkwin();
void board();
void change(int,char,int);
int checkline (int,int,int);

int main ()
{
	int player=1,choice;
	int i;
	char mark; //'X' or 'O'
	i = -1;
	do
	{

		board();
		player = (player % 2) ? 1 : 2;
		if (player == 1)
            mark = 'X';
        else
            mark = 'O';
		printf("Player %d enter your choice of position :",player);
		scanf("%d",&choice);
		change(choice,mark,player);
		i=checkwin();
		player++;
	}while(i == -1);

	board();

	if (i == 1)
	{
		printf("Player %d WON!!!!",--player);
	}
	else if (i == 0)
		printf("Game Draw!!");
	return 0;
}

void change(int c, char markc, int playerc)
{
	if (sq[c]==sqcheck[c])
		sq[c] = markc;
	else
	{
		printf("Invalid input...!");
		playerc--;
		getch();
	}

}

int checkline(int b1, int b2, int b3)
{
	if (sq[b1]==sq[b2] && sq[b2]==sq[b3])
	{
		return 1;
	}
	else if (sq[1]!=sqcheck[1] && sq[2]!=sqcheck[2] && sq[3]!=sqcheck[3] && sq[4]!=sqcheck[4] && sq[5]!=sqcheck[5] && sq[6]!=sqcheck[6] && sq[7]!=sqcheck[7] && sq[8]!=sqcheck[8] && sq[9]!=sqcheck[9])
	{
		return 0;
	}
}


int checkwin()
{
	int j,r;
	int a2[8][3]={{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};
	for (j=0;j<8;j++)
	{
		r=checkline(a2[j][0],a2[j][1],a2[j][2]);
	}
	return r;

}



void board()
{
	printf("     |     |    \n");
	printf("  %c  |  %c  |  %c  \n",sq[1],sq[2],sq[3]);
	printf("_____|_____|_____\n");
	printf("     |     |    \n");
	printf("  %c  |  %c  |  %c  \n",sq[4],sq[5],sq[6]);
	printf("_____|_____|_____\n");
	printf("     |     |    \n");
	printf("  %c  |  %c  |  %c  \n",sq[7],sq[8],sq[9]);
	printf("     |     |    \n");
}

/*
	the board:
	     |     |
	  1  |  2  |  3
	_____|_____|____
	     |     |
	  4  |  5  |  6
	_____|_____|____
	     |     |
	  7  |  8  | 9
	     |     |
*/
