#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
/*
Creator		: Jinkee.Hong 
First wrote : 2023/12/15 
*/

//MACROS 
#define STAR_NUM 80
#define OPTION_NUM 4
#define OPTION_WIDTH 10
#define WAIT_TIME 60
#define START_COMMENT "HELLO, WELCOME TO BANKING SERVICE."
#define GUIDE_COMMENT "- PLEASE SELECT THE OPTION -"

//FUNCTIONS
void Deposit_Money();

void prt_seperator_chars(int width, char c ,int bool_num);
void Show_Options();
void Disp_Middle( char str[]);
void Select_Opt();

//GLOBAL 
int Balance;

int main()
{
	prt_seperator_chars(STAR_NUM, '*', 1);
	Disp_Middle(START_COMMENT);
	Disp_Middle(GUIDE_COMMENT);
	prt_seperator_chars(STAR_NUM, '*', 1);
	Show_Options(OPTION_NUM);
	prt_seperator_chars(STAR_NUM, '*', 1);

	return 0;
}

void Deposit_Money( )
{
	int added_money = 0;
	system("cls");// ERASE SCREEN
	printf("PLEASE PUT MONEY INTO REGISTER : ");
	scanf("%d", &added_money);//make an exception
	
	
	//progress bar
	for (int i = 1; i <= WAIT_TIME; i++)
	{
		if (i == 1)
		{
			for (int i = 0; i < (WAIT_TIME*2); i++)
			{
				printf("-");
			}
			printf("|\n");
		}

		printf("¡Ü");

		if (i == WAIT_TIME)
		{
			printf("|\n");

			for (int i = 0; i < (WAIT_TIME * 2); i++)
			{
				printf("-");
			}
			printf("|\n");
		}
	}
	Balance += added_money;


	prt_seperator_chars(strlen("ADDED AMOUNT OF MONEY : %d\n"), '*', 1);
	printf("ADDED AMOUNT OF MONEY : %d\n", Balance);
	prt_seperator_chars(strlen("ADDED AMOUNT OF MONEY : %d\n"), '*', 1);
	printf("TRANSFACTION HAS BEEN COMPLETED!\n");

}

void Select_Opt()
{
	int select_num = 0;
	printf("\n¢º CHOOSE THE NUMBER OPTION PLEASE : ");
	scanf("%d", &select_num);
	 
	 
	switch (select_num)
	{
		case 1:
			Deposit_Money();
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		default:
			printf("SELECTED %d IS NOT AVAILIABLE OPTION. PLEASE SELECT RIGHT ANSWER AGAIN",select_num);
			break;
	}
	 
}


void Disp_Middle( char str[] )
{
	int n_blank = ((STAR_NUM - strlen(str)) / 2);
	prt_seperator_chars(n_blank, ' ', 0);
	printf("%s\n", str);
}
void prt_seperator_chars(int width, char c, int bool_num)
{
	for (int i = 0; i < width; i++)
	{
		printf("%c",c);
	}
	if (bool_num == 1)
	{
		printf("\n");
	}
	
}

void Show_Options()
{
	printf("1. DEPOSIT MONEY");
	prt_seperator_chars(OPTION_WIDTH, ' ', 0);
	printf("2. TOTAL BALANCE");
	prt_seperator_chars(OPTION_WIDTH, ' ', 0);
	printf("3. TRANSFER MONEY");
	prt_seperator_chars(OPTION_WIDTH, ' ', 1);
	printf("4. CREATE ACCOUNT");
	prt_seperator_chars(OPTION_WIDTH, ' ', 0);
	printf("5. LOG-IN");
	prt_seperator_chars(OPTION_WIDTH, ' ', 0);
	 
	while (1)
	{
		Select_Opt();
	}
}