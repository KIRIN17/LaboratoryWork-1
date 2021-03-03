#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>
#include "functions.h"

struct Arr//структура,описывающая динамический массив
{
	void* values;
	int count;
	size_t forcreate;
};

void* forinit;//указатель для выделения памяти для объекта в куче

struct Arr* Create(int count,size_t forcreate,void* forinit){
	
	struct Arr* arr = malloc(sizeof(struct Arr));
	arr->count = count;
	arr->forcreate = forcreate;
	arr->values = malloc(forcreate*count);
	
	for (size_t i = 0; i < (size_t)count;i++)
	{
		int8_t* pos = (int8_t*)arr->values + i*forcreate;
		memcpy((void*)pos,forinit,forcreate);
	}
	
	return arr;
}

struct Arr* DoubleCreate(int count,size_t forcreate,FILE* stream){
	
	forinit=malloc(forcreate);
	*(double*)forinit = 1;
	
	struct Arr* ResArr = Create(count,forcreate,forinit);
	for (size_t i = 0; i < (size_t)count;i++)
	{
		if(fscanf(stream,"%lf",(double*)(ResArr->values+i*(forcreate)))!=1){
			free((double*)ResArr->values);
			free(ResArr);
			free(forinit);
			return 0;
		}
	}
	free(forinit);
	return ResArr;
}

struct Arr* IntCreate(int count,size_t forcreate,FILE* stream){
	
	forinit=malloc(forcreate);
	*(int*)forinit = 1;
	
	struct Arr* ResArr = Create(count,forcreate,forinit);
	for (size_t i = 0; i < (size_t)count;i++)
	{
		if(fscanf(stream,"%d",(int*)(ResArr->values+i*(forcreate)))!=1){
			free((int*)ResArr->values);
			free(ResArr);
			free(forinit);
			return 0;
		}
	}
	free(forinit);
	return ResArr;
}

int is_positive(double example){
	if(example > 0){
		return 1;
	}
	return 0;
}

struct Arr* DoubleWhere(struct Arr* example,int(*is_positive)(double)){
	int sizeofRes = 0;
	for (int i = 0; i < example->count; ++i)
	{
		if(is_positive(*(double*)(example->values + i*example->forcreate)) == 1)
			sizeofRes++;
	}
	if (sizeofRes == 0){
		return 0;
	}
	struct Arr* Res;
	forinit = malloc(example->forcreate);
	*(double*)forinit = 1;
	Res = Create(sizeofRes,example->forcreate,forinit);
	int index = 0;
	for (int i = 0; i < example->count;i++)
	{	
		if(is_positive(*(double*)(example->values + i*example->forcreate)) == 1){
			*(double*)(Res->values+index*(Res->forcreate)) = *(double*)(example->values+i*(example->forcreate));
			index++;
		}
	}
	free(forinit);
	return Res;
}

int is_even(int example){
	if(example%2 == 0){
		return 1;
	}else{
		return 0;	
	}
}

struct Arr* IntWhere(struct Arr* example,int(*is_even)(int)){
	int sizeofRes = 0;
	for (int i = 0; i < example->count; ++i)
	{
		if(is_even(*(int*)(example->values + i*example->forcreate)) == 1)
			sizeofRes++;
	}
	if (sizeofRes == 0){
		return 0;
	}
	struct Arr* Res;
	forinit = malloc(example->forcreate);
	*(int*)forinit = 1;
	Res = Create(sizeofRes,example->forcreate,forinit);
	int index = 0;
	for (int i = 0; i < example->count;i++)
	{	
		if(is_even(*(int*)(example->values + i*example->forcreate)) == 1){
			*(int*)(Res->values+index*(Res->forcreate)) = *(int*)(example->values+i*(example->forcreate));
			index++;
		}
	}
	free(forinit);
	return Res;
}

void BubbleSortDouble(struct Arr* example){
	int count = example->count;
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			if((*(double*)(example->values+i*example->forcreate))<=(*(double*)(example->values+j*example->forcreate))){
				double t = *(double*)(example->values+i*example->forcreate);
				*(double*)(example->values+i*example->forcreate) = *(double*)(example->values+j*example->forcreate);
				*(double*)(example->values+j*example->forcreate) = t;
			}
		}
	}
}	

void BubbleSortInt(struct Arr* example){
	int count = example->count;
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			if((*(int*)(example->values+i*example->forcreate))<=(*(int*)(example->values+j*example->forcreate))){
				int t = *(int*)(example->values+i*example->forcreate);
				*(int*)(example->values+i*example->forcreate) = *(int*)(example->values+j*example->forcreate);
				*(int*)(example->values+j*example->forcreate) = t;
			}
		}
	}
}

struct Arr* ConcatenationDouble(struct Arr* first,struct Arr* second){
	struct Arr* Res;
	forinit = malloc(first->forcreate);
	*(double*)forinit = 1;
	Res = Create(first->count+second->count,first->forcreate,forinit);
	int index = 0;
	for (int i = 0; i < first->count; ++i)
	{
		*(double*)(Res->values + index*Res->forcreate) = *(double*)(first->values + i*first->forcreate);
		index++;
	}
	for (int i = 0; i < second->count; ++i)
	{
		*(double*)(Res->values + index*Res->forcreate) = *(double*)(second->values + i*second->forcreate);
		index++;	
	}
	return Res;
}

struct Arr* ConcatenationInt(struct Arr* first,struct Arr* second){
	struct Arr* Res;
	forinit = malloc(first->forcreate);
	*(int*)forinit = 1;
	Res = Create(first->count+second->count,first->forcreate,forinit);
	int index = 0;
	for (int i = 0; i < first->count; ++i)
	{
		*(int*)(Res->values + index*Res->forcreate) = *(int*)(first->values + i*first->forcreate);
		index++;
	}
	for (int i = 0; i < second->count; ++i)
	{
		*(int*)(Res->values + index*Res->forcreate) = *(int*)(second->values + i*second->forcreate);
		index++;	
	}	
	return Res;
}

void* SQRDouble(void* example){
	double a = *(double*)example;
	double b = *(double*)example;
	*(double*)example = a*b;
	return (void*)(example);
}

void MapDouble(struct Arr* example,void*(*SQR)(void*)){
	for (int i = 0; i < example->count; ++i)
	{
		*(double*)(example->values + i*(example->forcreate))=*(double*)(SQR((double*)(example->values + i*(example->forcreate))));
	}
}

void* SQRInt(void* example){
		int a = *(int*)example;
		int b = *(int*)example;
		*(int*)example = a*b;
		return (void*)(example);
}

void MapInt(struct Arr* example,void*(*SQR)(void*)){
	for (int i = 0; i < example->count; ++i)
	{
		*(int*)(example->values + i*(example->forcreate))=*(int*)(SQR((int*)(example->values + i*(example->forcreate))));
	}	
}

void PrintLine(){
	printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
}

void PrintLine1(){
	printf("\n\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\'LINE'\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
}

void PrintArrayDouble(struct Arr* arr){
	for (int i = 0; i < arr->count; ++i)
	{
		printf("%lf ",*(double*)(arr->values+i*arr->forcreate));
	}
}

void PrintArrayInt(struct Arr* arr){

	for (int i = 0; i < arr->count; ++i)
	{
		printf("%d ",*(int*)(arr->values+i*arr->forcreate));
	}	
}

int WHATAREWETESTING(FILE* stream){
	int N;
	int M;
	struct Arr* first;
	struct Arr* second;
	struct Arr* Ev1;//эти два объекта используются
	struct Arr* Ev2;//для демонстрации функций IntWhere/DoubleWhere
	struct Arr* Conc;//этот объект используется для демонстрации работы функции Concatenation

	printf("\t\t\tDEMONSTRATION FOR INT\n");
	printf("Reading count of elements for first INT array . . .\n");
	if(fscanf(stream,"%d",&N)!=1){//создание первого экземпляра типа int
		printf("\t\t\tINVALID INPUT ! ! ! (wrong size of first INT array)\n");
		return -1;
	}
	printf("Size if first array = %d\n",N);

	
	printf("Reading %d elements for first INT array . . .\n",N);
	first = IntCreate(N,(sizeof(int)),stream);
	if(first == 0){
		printf("\t\t\tINVALID INPUT ! ! ! (wrong data for first INT array)\n");
		free(first);
		//free(forinit);
		return -1;
	}
	
	
	//создание второго экземпляра типа int
	printf("Reading count of elements for second INT array . . .\n");
	if(fscanf(stream,"%d",&M)!=1){
		free((int*)(first->values));
		free(first);
		//free(forinit);
		printf("\t\t\tINVALID INPUT ! ! ! (wrong size of second INT array)\n");
		return -1;
	}
	
	printf("Reading %d elements for second INT array . . .\n",M);
	second = IntCreate(M,(sizeof(int)),stream);
	if(second == 0){
		printf("\t\t\tINVALID INPUT ! ! ! (wrong data for second INT array)\n");
		free(second);
		free((int*)(first->values));
		free(first);
		//free(forinit);
		return -1;
	}
	
	printf("Where is even?(first)\n");
	Ev1 = IntWhere(first,is_even);//демонстрация работы функции IntWhere
	if(Ev1==0){
		printf("There are no even numbers in the first array\n");
	}else{
		PrintArrayInt(Ev1);	
	}
	PrintLine();
	
	printf("Where is even?(second)\n");
	Ev2 = IntWhere(second,is_even);
	if(Ev2==0){
		printf("There are no even numbers in the second array\n");
	}else{
		PrintArrayInt(Ev2);	
	}
	PrintLine();

	printf("First array before sort:\n");//демонстрация работы функции BubbleSortInt
	PrintArrayInt(first);
	BubbleSortInt(first);
	printf("\nFirst array after sort:\n");
	PrintArrayInt(first);
	PrintLine();

	printf("Second array before sort:\n");
	PrintArrayInt(second);
	BubbleSortInt(second);
	printf("\nSecond array after sort:\n");
	PrintArrayInt(second);
	PrintLine();

	Conc = ConcatenationInt(first,second);//демонстрация работы функции ConcatenationInt
	printf("first array :\n");//пустые массивы невозможны в силу проверки ввода
	PrintArrayInt(first);
	printf("\nsecond array :\n");
	PrintArrayInt(second);
	printf("\n");
	printf("Concatenation of first and second :\n");
	PrintArrayInt(Conc);
	PrintLine();
	
	printf("Map for first :\n");//демонстрация работы функции MapInt
	MapInt(first,SQRInt);
	PrintArrayInt(first);
	PrintLine();


	printf("Map for second :\n");//демонстрация работы функции MapInt
	MapInt(second,SQRInt);
	PrintArrayInt(second);
	PrintLine();

	free((int*)(first->values));
	free((int*)(second->values));
	if(Ev1!=0){
		free((int*)(Ev1->values));	
		free(Ev1);
	}
	if(Ev2!=0){
		free((int*)(Ev2->values));	
		free(Ev2);
	}
	free((int*)(Conc->values));
	free(first);
	free(second);
	free(Conc);
	free(forinit);
	
	//////////////////////////////////////////////////////////////////////////////////////////

	printf("\t\t\tDEMONSTRATION FOR DOUBLE\n");
	
	printf("Reading count of elements for first DOUBLE array . . .\n");//создание первого экземпляра типа double
	if(fscanf(stream,"%d",&N)!=1){
		printf("\t\t\tINVALID INPUT ! ! ! (wrong size of first DOUBLE array)\n");
		return -1;
	}
	printf("Size if first DOUBLE array = %d\n",N);

	printf("Reading %d elements for first DOUBLE array . . .\n",N);
	
	first = DoubleCreate(N,(sizeof(double)),stream);
	if(first == 0){
		printf("\t\t\tINVALID INPUT ! ! ! (wrong data for first DOUBLE array)\n");
		free(first);
		//free(forinit);
		return -1;
	}

	printf("Reading count of elements for second DOUBLE array . . .\n");//создание второго экземпляра типа double
	if(fscanf(stream,"%d",&M)!=1){
		free((double*)(first->values));
		free(first);
		//free(forinit);
		printf("\t\t\tINVALID INPUT ! ! ! (wrong size of second DOUBLE array)\n");
		return -1;
	}

	printf("Reading %d elements for second DOUBLE array . . .\n",N);
	second = DoubleCreate(M,(sizeof(double)),stream);
	if(second == 0){
		printf("\t\t\tINVALID INPUT ! ! ! (wrong data for second DOUBLE array)\n");
		free(second);
		free((double*)(first->values));
		free(first);
		//free(forinit);
		return -1;
	}
	
	printf("Where is positive?(first)\n");//демонстрация работы функции DoubleWhere
	Ev1 = DoubleWhere(first,is_positive);
	if(Ev1==0){
		printf("There are no positive numbers in the first array\n");
	}else{
		PrintArrayDouble(Ev1);	
	}
	PrintLine();
	
	printf("Where is positive?(second)\n");
	Ev2 = DoubleWhere(second,is_positive);
	if(Ev2==0){
		printf("There are no positive numbers in the second array\n");
	}else{
		PrintArrayDouble(Ev2);	
	}
	PrintLine();
	
	printf("First array before sort:\n");//демонстрация работы функции BubbleSortDouble
	PrintArrayDouble(first);
	BubbleSortDouble(first);
	printf("\nFirst array after sort:\n");
	PrintArrayDouble(first);
	PrintLine();

	printf("Second array before sort:\n");
	PrintArrayDouble(second);
	BubbleSortDouble(second);
	printf("\nSecond array after sort:\n");
	PrintArrayDouble(second);
	PrintLine();
	
	Conc = ConcatenationDouble(first,second);//демонстрация работы функции ConcatenationDouble
	printf("first array :\n");//пустые массивы невозможны в силу проверки ввода
	PrintArrayDouble(first);
	printf("\nsecond array :\n");
	PrintArrayDouble(second);
	printf("\n");
	printf("Concatenation of first and second :\n");
	PrintArrayDouble(Conc);
	PrintLine();
	
	printf("Map for first :\n");//демонстрация работы функции MapDouble
	MapDouble(first,SQRDouble);
	PrintArrayDouble(first);
	PrintLine();

	printf("Map for second :\n");//демонстрация работы функции MapDouble
	MapDouble(second,SQRDouble);
	PrintArrayDouble(second);
	PrintLine();
	
	//Очистка памяти в случае успешного выполнения всех функций
	free((double*)(first->values));
	free((double*)(second->values));
	if(Ev1!=0){
		free((double*)(Ev1->values));	
		free(Ev1);
	}
	if(Ev2!=0){
		free((double*)(Ev2->values));	
		free(Ev2);
	}
	free((double*)(Conc->values));
	free(first);
	free(second);
	free(Conc);
	free(forinit);
	
	return 0;
}