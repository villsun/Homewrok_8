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
	Reting rating_student[10];
};

void Fill_Rating(Student& student, int size)
{
	for (int i = 0; i < size; i++)
	{
		student.rating_student[i].rating = rand() % 2;
	}
}

void Show_Rating(const Student& student, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << student.rating_student[i].rating << " ";
	}
	cout << endl;
}

double GPA(Student& student, int size)
{
	int counter_rating = 0;
	for (int i = 0; i < size; i++)
	{
		counter_rating += student.rating_student[i].rating;
	}

	double GPA = counter_rating / 1.0 / 10;
	return GPA;
}

void Show_Student(const Student& student, int size)
{
	cout << student.full_name << endl;
	Show_Rating(student, size);
}

void Add_Student(Student students[], char* full_name_student, int index)
{
	strcpy(students[index].full_name, full_name_student);
}

void Add_Rating_Student(Student students[], int index, int size)
{
	int rating;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter rating to student(0 or 1):\n";
		do
		{
			cin >> rating;
			if (rating < 0 || rating>1)
			{
				cout << "Error!\n";
			}
		} while (rating<0 || rating>1);
		students[index].rating_student[i].rating = rating;
	}
}

void Show_Rating(const Student student[], int index, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << student[index].rating_student[i].rating << ' ';
	}
	cout << endl;
}

void Show_Student(const Student student[], int index, int size)
{
	cout << student[index].full_name << endl;
	Show_Rating(student, index, size);
}

void Show_Students(const Student students[], int size_1, int size_2)
{
	for (int i = 0; i < size_1; i++)
	{
		Show_Student(students, i, size_2);
	}
}

int main()
{
	srand(static_cast<unsigned>(time(0)));

	// Завдання 1

	/*const int SIZE = 10;
	Student student_1;

	strcpy(student_1.full_name, "Loniuk Mykola Mykhailovych");
	Fill_Rating(student_1, SIZE);

	Show_Student(student_1, SIZE);

	double GPA_student = GPA(student_1, SIZE);
	cout << "GPA = " << GPA_student << endl;*/

	// Завдання 2

	const int SIZE = 10;
	Student students[10];
	

	/*Show_Students(students, SIZE, SIZE);*/
	Show_Student(students, 0, SIZE);
	Show_Rating(students, 0, SIZE);

	



	return 0;
}