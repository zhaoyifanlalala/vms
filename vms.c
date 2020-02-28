//模拟售货机项目
#include<stdio.h>


int money;
char sale = '=';
//char goods[100] = {'Juice', 'Cola', 'Tea', 'Water', 'Coffee'};
char choice[5] = {'A', 'B', 'C', 'D', 'E'};
int price[5] = {10, 6, 5, 8, 7}; 

int main(){
    printf("*---------------------------*\n");
	printf("|     Vending   Machine     |\n");
	printf("*---------------------------*\n");



    printf("*---------------------------*\n");
    printf("|                    [$%2d]  |\n", money);
    printf("|                           |\n");
    printf("|           [=%c=]           |\n", sale);
    printf("*---------------------------*\n");
    printf("What would you like to do?\n");
	printf(" 1. Read product information\n");
	printf(" 2. Insert coin\n"); 
	printf(" 3. Press product button\n");
	printf(" 4. Press return button\n");
	printf(" 9. Open service menu (code required)\n");
	printf(" 0. Quit\n\n");
	printf("Your choice:");
}