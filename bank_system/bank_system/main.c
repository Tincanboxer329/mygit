#include <stdio.h>
#include <string.h>
/*
Creator		: Jinkee.Hong 
First wrote : 2023/12/15 
*/

//MACROS 
#define STAR_NUM 80
#define OPTION_NUM 4
#define START_COMMENT "HELLO, WELCOME TO BANKING SERVICE."
#define GUIDE_COMMENT "- PLEASE SELECT THE OPTION -"

//FUNCTIONS
void Star_bar(int star_num);
void Show_Options();
void Disp_middle(int star_nums,char str[]);
int main()
{
	Star_bar(STAR_NUM);
	Disp_middle(STAR_NUM,START_COMMENT);
	Disp_middle(STAR_NUM, GUIDE_COMMENT);
	Star_bar(STAR_NUM);
	Show_Options(OPTION_NUM);
	return 0;
}
void Disp_middle(  int str_length,char str[] )
{

}
void Star_bar(int star_num)
{
	for (int i = 0; i < star_num; i++)
	{
		printf("*");
	}
	printf("\n");
}

void Show_Options()
{
	 
	printf("1. DEPOSIT MONEY\t");
	printf("2. TOTAL BALANCE\t");
	printf("3. TRANSFER MONEY\n");
	printf("4. CREATE ACCOUNT\t");
	printf("5. LOG-IN\n");
	 
}