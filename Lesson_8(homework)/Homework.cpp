#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

struct Reting
{
	int rating : 1;
};

struct Student
{
	char full_name[100];
	Reting reting_student[10];
};

int main()
{


	return 0;
}