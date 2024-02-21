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

void Fill_Students_Rating(Student student[], int size_1, int size_2)
{
	for (int i = 0; i < size_1; i++)
	{
		for (int j = 0; j < size_2; j++)
		{
			student[i].rating_student[j].rating = rand() % 2;
		}
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
		} while (rating < 0 || rating>1);
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

void Show_Debtor(const Student students[], int size_1, int size_2)
{
	cout << "Debtor:\n";
	for (int i = 0; i < size_1; i++)
	{
		for (int j = 0; j < size_2; j++)
		{
			if (students[i].rating_student[j].rating == 0)
			{
				cout << students[i].full_name << endl;
				break;
			}
		}
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
	int counter = 5;

	strcpy(students[0].full_name, "Loniuk Mykola Mykhailovych");
	strcpy(students[1].full_name, "Roma Pavlyuk Olegovich");
	strcpy(students[2].full_name, "Ilya Mazar Schumacherovich");
	strcpy(students[3].full_name, "Artem Levchuk Hvorovych");
	strcpy(students[4].full_name, "Sasha Dovych Petrovych");

	Fill_Students_Rating(students, counter, 10);

	int user_input;
	char str_student[100];
	int user_input_rating;
	int user_input_index_rating;
	do
	{
		do
		{
			cout << "Enter what do you want to know:\n1 - Add student\n2 - Add rating student\n3 - Show students\n4 - Show rating student\n5 - Show debtor\n";
			cin >> user_input;
			if (user_input < -1 || user_input>5)
			{
				cout << "Error!\n";
			}
		} while (user_input < -1 || user_input>5);
		if (user_input == -1)
		{
			break;
		}
		switch (user_input)
		{
		case 1:
			cin.ignore();
			if (counter > 10)
			{
				cout << "Many students!\nStop!\n";
				break;
			}
			cin.getline(str_student, 100);
			Add_Student(students, str_student, counter);
			counter++;

			break;
		case 2:
			do
			{
				cout << "Enter index student:\n";
				cin >> user_input_rating;
			} while (user_input_rating < counter - 1 || user_input>10);
			Add_Rating_Student(students, user_input_rating - 1, 10);
			break;
		case 3:
			Show_Students(students, counter, 10);
			break;
		case 4:
			do
			{
				cout << "Enter index student of rating:\n";
				cin >> user_input_index_rating;
			} while (user_input < 0 || user_input>counter - 1);
			Show_Rating(students, user_input_index_rating - 1, 10);
			break;
		case 5:
			Show_Debtor(students, counter, 10);
		default:
			break;
		}
	} while (user_input != -1);

	return 0;
}