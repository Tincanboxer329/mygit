#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
/*
Creator		: Jinkee.Hong 
First wrote : 2023/12/15 
*/


//MACROS 
#define DEFAULT_INT -9999
#define DEFAULT_CHAR 'ERROR'
#define STAR_NUM 80
#define OPTION_NUM 4
#define OPTION_WIDTH 10
#define WAIT_TIME 30
#define START_COMMENT "HELLO, WELCOME TO BANKING SERVICE."
#define GUIDE_COMMENT "- PLEASE SELECT THE OPTION -"
 
//FUNCTIONS
void Deposit_Money();
int Check_IntType(int int_check);
char* Check_Str(char* str_check);
void prt_seperator_chars(int width, char c, int bool_num);
void Show_Options();
void Disp_Middle(char str[]);
void Select_Opt();

//GLOBAL 
int Balance = 0;

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
	int added_money = DEFAULT_INT;
	system("cls");// ERASE SCREEN
	printf("PLEASE PUT MONEY INTO REGISTER : ");
	scanf("%d", &added_money);
 
	added_money = Check_IntType(added_money);
	
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


	prt_seperator_chars(strlen("ADDED AMOUNT OF MONEY : %d \n"), '*', 1);
	printf("ADDED AMOUNT OF MONEY : %d$\n", Balance);
	prt_seperator_chars(strlen("ADDED AMOUNT OF MONEY : %d\n"), '*', 1);
	printf("TRANSACTION HAS BEEN COMPLETED!\n");

}


//exception handling for str & fix  
char* Check_Str(char* check)
{
	int str_counter = 0;
	int int_counter = 0;
	
	for (int i = 0; i < sizeof(check); i++)
	{
		str_counter++;
	}

	for (int i = 0; i < str_counter; i++)
	{	
		if ((*(check+i) < 97 || *(check + i) > 122) || (*(check + i) >=65|| *(check + i) <= 90)) // FIND OUT LETTERS ARE AVAIL ERROR
		{

		}
		else
		{
			printf("PLEASE MAKE YOUR INPUT AGAIN\n\a");
			printf("%s", check);
		}
	}

	return check;
}

//exception handling for integer  & fix  
int Check_IntType(int check)
{
	while(1)
	{
		if (check < 0) //if unexpected input comes, scanf will not assign any value.
		{
			prt_seperator_chars(strlen("¡äPLEASE MAKE YOUR INPUT CORRECTLY\a\n"), '*', 1);
			printf("¡äPLEASE MAKE YOUR INPUT CORRECTLY\a\n");
			prt_seperator_chars(strlen("¡äPLEASE MAKE YOUR INPUT CORRECTLY\a\n"), '*', 1);

			while (getchar() != '\n') //ERASE REMAINING BUFFER FOR A NEW INPUT
			{
				continue;
			}
			printf("PLEASE PUT MONEY INTO REGISTER : ");
			scanf("%d", &check);
		}
		else
		{
			break;
		}
		 
	}
	return check;
}





void Select_Opt()
{
	int select_num = 0;
	printf("\n¢º CHOOSE THE NUMBER OPTION PLEASE : ");
	scanf("%d", &select_num);
	select_num = Check_Str(select_num);
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