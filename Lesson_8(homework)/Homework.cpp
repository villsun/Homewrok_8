#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

struct Reting
{
	unsigned int rating : 1;
};

struct Student
{
	char full_name[100];
	Reting reting_student[10];
};

void Fill_Rating(Student& student, int size)
{
	for (int i = 0; i < size; i++)
	{
		student.reting_student[i].rating = rand() % 2;
	}
}

void Show_Rating(const Student& student, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << student.reting_student[i].rating << " ";
	}
	cout << endl;
}

double GPA(Student& student, int size)
{
	int counter_rating = 0;
	for (int i = 0; i < size; i++)
	{
		counter_rating += student.reting_student[i].rating;
	}

	double GPA = counter_rating / 1.0 / 10;
	return GPA;

}

int main()
{
	srand(static_cast<unsigned>(time(0)));
	const int SIZE = 10;
	Student student_1;

	strcpy(student_1.full_name, "Loniuk Mykola Mykhailovych");
	Fill_Rating(student_1, SIZE);

	cout << student_1.full_name << endl;
	Show_Rating(student_1, SIZE);

	double GPA_student = GPA(student_1, SIZE);
	cout << "GPA = " << GPA_student << endl;



	return 0;
}