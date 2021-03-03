/*
Тип коллекции - динамический массив
Типы хранимых элементов - целые и вещественные числа
Операции - Сортировка,map,where,конкатенация
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>
#include "functions.h"

struct Arr
{
	void* values;
	int count;
	size_t forcreate;
};

void* forinit;

int main(void)
{
	FILE* test;
	printf("\t\t\tTEST0.TXT\n");
	test = fopen("test0.txt","r");
	int res = WHATAREWETESTING(test);
	if(res == 0){
		printf("\t\t\t ALL CORRECT ! ! !\n");
	}else{
		printf("\t\tPLEASE CHECK FILE 'test0.txt' AND TRY AGAIN\n");
	}
	PrintLine1();

	printf("\t\t\tTEST1.TXT\n");
	test = fopen("test1.txt","r");
	res = WHATAREWETESTING(test);
	if(res == 0){
		printf("\t\t\t ALL CORRECT ! ! !\n");
	}else{
		printf("\t\tPLEASE CHECK FILE 'test1.txt' AND TRY AGAIN\n");
	}
	PrintLine1();

	
	printf("\t\t\tTEST2.TXT\n");
	test = fopen("test2.txt","r");
	res = WHATAREWETESTING(test);
	if(res == 0){
		printf("\t\t\t ALL CORRECT ! ! !\n");
	}else{
		printf("\t\tPLEASE CHECK FILE 'test2.txt' AND TRY AGAIN\n");
	}
	PrintLine1();

	
	printf("\t\t\tTEST3.TXT\n");
	test = fopen("test3.txt","r");
	res = WHATAREWETESTING(test);
	if(res == 0){
		printf("\t\t\t ALL CORRECT ! ! !\n");
	}else{
		printf("\t\tPLEASE CHECK FILE 'test3.txt' AND TRY AGAIN\n");
	}
	PrintLine1();

	printf("\t\t\tTEST4.TXT\n");
	test = fopen("test4.txt","r");
	res = WHATAREWETESTING(test);
	if(res == 0){
		printf("\t\t\t ALL CORRECT ! ! !\n");
	}else{
		printf("\t\tPLEASE CHECK FILE 'test4.txt' AND TRY AGAIN\n");
	}
	PrintLine1();
	
	printf("\t\t\tTEST5.TXT\n");
	test = fopen("test5.txt","r");
	res = WHATAREWETESTING(test);
	if(res == 0){
		printf("\t\t\t ALL CORRECT ! ! !\n");
	}else{
		printf("\t\tPLEASE CHECK FILE 'test5.txt' AND TRY AGAIN\n");
	}
	PrintLine1();

	
	printf("\t\t\tTEST6.TXT\n");
	test = fopen("test6.txt","r");
	res = WHATAREWETESTING(test);
	if(res == 0){
		printf("\t\t\t ALL CORRECT ! ! !\n");
	}else{
		printf("\t\tPLEASE CHECK FILE 'test6.txt' AND TRY AGAIN\n");
	}
	PrintLine1();
	
	
	printf("\t\t\tTEST7.TXT\n");
	test = fopen("test7.txt","r");
	res = WHATAREWETESTING(test);
	if(res == 0){
		printf("\t\t\t ALL CORRECT ! ! !\n");
	}else{
		printf("\t\tPLEASE CHECK FILE 'test7.txt' AND TRY AGAIN\n");
	}
	PrintLine1();
	
	
	printf("\t\t\tTEST8.TXT\n");
	test = fopen("test8.txt","r");
	res = WHATAREWETESTING(test);
	if(res == 0){
		printf("\t\t\t ALL CORRECT ! ! !\n");
	}else{
		printf("\t\tPLEASE CHECK FILE 'test8.txt' AND TRY AGAIN\n");
	}
	PrintLine1();
	
	fclose(test);
	
	return 0;
}