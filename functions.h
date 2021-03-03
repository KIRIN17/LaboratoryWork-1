#ifndef FUNCTIONS
#define FUNCTIONS

struct Arr;//структура,описывающая динамический массив

struct Arr* Create(int count,size_t forcreate,void* forinit);//выделение памяти для экземпляра

struct Arr* DoubleCreate(int count,size_t forcreate,FILE* stream);//создание double экземпляра

struct Arr* IntCreate(int count,size_t forcreate,FILE* stream);//создание int экземпляра

int is_positive(double example);

struct Arr* DoubleWhere(struct Arr* example,int(*is_positive)(double));

int is_even(int example);

struct Arr* IntWhere(struct Arr* example,int(*is_even)(int));//для целых проверяется чётность,для действительных - знак

void BubbleSortDouble(struct Arr* example);

void BubbleSortInt(struct Arr* example);

//Случаи пустых массивов(по одному или одновременно) невозможны в силу проверки данных на входе
struct Arr* ConcatenationDouble(struct Arr* first,struct Arr* second);

struct Arr* ConcatenationInt(struct Arr* first,struct Arr* second);

void* SQRDouble(void* example);

void MapDouble(struct Arr* example,void*(*SQR)(void*));

void* SQRInt(void* example);

void MapInt(struct Arr* example,void*(*SQR)(void*));

void PrintLine();

void PrintLine1();

void PrintArrayDouble(struct Arr* arr);

void PrintArrayInt(struct Arr* arr);

int WHATAREWETESTING(FILE* stream);

#endif // FUNCTIONS