#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<cstring>
#include<iomanip>

using namespace std;

string *regrow_s(string *, int , string);

int *regrow_i(int *, int, int);

float *regrow_f(float *, int, float);

char *regrow_c(char *, int, float);

void string_copy(string *, int , string *);

void int_copy(int *, int, int *);

void float_copy(float *, int, float *);

void char_copy(char *, int, char *);

void display(string*, int *, int *, float *, char *, int);

int menu(int);

int findRoll(string *, int, string, int);

void choice_3(string *, int *, int *, float *, char *, int, float);

void choice_5(string *, int *, int *, float *, char *, int, float);

void choice_6(string *, int *, int *, float *, char *, int);

string *shrink_s(string *, int, int);

int *shrink_i(int *, int, int);

float *shrink_f(float *, int, int);

char *shrink_c(char *, int, int);

char updateGrade(float);

int main()
{
	//Variables and Pointers declaration

	string *rollNumber = NULL;

	int *computerMarks = NULL, *mathMarks = NULL;

	float *percentage = NULL;

	char *grade = NULL;
	

	int size = 0, marks1 = -1, marks2 = -1;

	char choice = '\0', temp = '\0';
	
	string roll;

	float percent = NULL;

	bool isFound = false;

	//Data reading from file

	ifstream fin("Records.txt");

	while (!fin.eof())
	{
		fin >> roll;

		rollNumber = regrow_s(rollNumber, size, roll);					//Regrow function of Roll Number called

		fin >> marks1;

		computerMarks = regrow_i(computerMarks, size, marks1);					//Regrow function of CS Marks called			

		fin >> marks2;

		mathMarks = regrow_i(mathMarks, size, marks2);					//Regrow function of Math Marks called

		fin >> percent;

		percentage = regrow_f(percentage, size, percent);					//Regrow function of percentage called

		fin >> temp;

		grade = regrow_c(grade, size, percent);					//Regrow function of grade called
		
		if (marks1 != -1)
			size++;
	}

	if (marks1 != -1)
		size--;

	if (size != 0)
	{
		display(rollNumber, computerMarks, mathMarks, percentage, grade, size);

		cout << "\n\nRECORD IN THE BACKEND FILE.........\n";

		string *cont = new string();

		cout << "\n\nPress ENTER to continue : ";
		getline(cin, *cont);

		delete cont;
		cont = NULL;
	}

	fin.close();

	//Start Screen Printing
	
	system("cls");

	for (int count = 0; count < 40; count++)
	{
		cout << ">< ";
	}
	cout << endl << endl;

	cout << setw(70) <<  "STUDENT GRADE REPORT" << endl << endl;

	for (int count = 0; count < 40; count++)
	{
		cout << ">< ";
	}
	cout << endl << endl << endl << endl;

	cout << setw(68) << "HELLO THERE!\n\n" << setw(66.99999999999999) << "WELCOME\n\n\n";

	cout << "Do you want to enter a student's marks in record!\n";
	cout << "Press Y/y to add an entry\nPress N/n to continue to other options\n";
	cout << "Enter you choice : ";
	cin >> choice;

	while (choice != 'N' && choice != 'n' && choice != 'Y' && choice != 'y')
	{
		cout << "INVALID INPUT!!!\n";
		cout << "Press Y/y to add an entry\nPress N/n to exit the application\n";
		cout << "Enter you choice : ";
		cin >> choice;
	}

	while (true)
	{
		isFound = false;

		//Student Entries

		if (choice == 'Y' || choice == 'y')
		{

			system("cls");

			for (int count = 0; count < 40; count++)
			{
				cout << ">< ";
			}
			cout << endl << endl;

			cout << setw(70) << "STUDENT GRADE REPORT" << endl << endl;

			for (int count = 0; count < 40; count++)
			{
				cout << ">< ";
			}
			cout << endl << endl << endl << endl;

			cout << "Student Data Entry.......\n\n";

			cout << "Enter the Roll Number of the student : ";					//Roll Number Entry
			cin >> roll;

			for (int count = 0; count < size; count++)					//Checking Roll Number if already exists
			{
				if (roll == rollNumber[count])
				{
					isFound = true;
					break;
				}
			}

			if (isFound == false)
			{
				rollNumber = regrow_s(rollNumber, size, roll);					//Regrow function of Roll Number called

				cout << "\nEnter the Computer Science marks of Roll Number " << roll << " : ";					//CS Marks Entry
				cin >> marks1;

				while (marks1 < 0 || marks1 > 100)
				{
					cout << "INVALID INPUT!\nThe Marks should be in range from 1 to 100\n";
					cout << "\nEnter the Computer Science marks of Roll Number " << roll << " again : ";
					cin >> marks1;
				}

				computerMarks = regrow_i(computerMarks, size, marks1);					//Regrow function of CS Marks called			

				cout << "\nEnter the Mathematics marks of Roll Number " << roll << " : ";					//Maths Marks Entry
				cin >> marks2;

				while (marks2 < 0 || marks2 > 100)
				{
					cout << "INVALID INPUT!\nThe Marks should be in range from 1 to 100\n";
					cout << "\nEnter the Computer Science marks of Roll Number " << roll << " again : ";
					cin >> marks2;
				}

				mathMarks = regrow_i(mathMarks, size, marks2);					//Regrow function of Math Marks called

				percent = marks1 + marks2;

				percent /= 200;

				percent *= 100;					//Percentage calculated

				percentage = regrow_f(percentage, size, percent);					//Regrow function of percentage called

				grade = regrow_c(grade, size, percent);					//Regrow function of grade called

				size++;

				cout << "\n\nNEW STUDENT RECORD ADDED!";
			}

			else
			{
				cout << "\n\nStudent already exists in the records.....\n";
			}
			

			string *cont = new string();

			cout << "\n\nPress ENTER to continue : ";
			cin.ignore();
			getline(cin, *cont);

			delete cont;
			cont = NULL;

			system("cls");

			//Asking for more entries

			for (int count = 0; count < 40; count++)
			{
				cout << ">< ";
			}
			cout << endl << endl;

			cout << setw(70) << "STUDENT GRADE REPORT" << endl << endl;

			for (int count = 0; count < 40; count++)
			{
				cout << ">< ";
			}
			cout << endl << endl << endl << endl;

			cout << "Do you want to add more students?\n";
			cout << "Enter Y/y to continue adding student\n";
			cout << "Enter N/n to move on to other options\n";
			cout << "You choice : ";
			cin >> choice;

		}

		else if (choice == 'N' || choice == 'n')
		{
			break;
		}

	}

	isFound = false;

	display(rollNumber, computerMarks, mathMarks, percentage, grade, size);					//Record display function

	string *cont = new string();

	cout << "\n\nPress ENTER to continue : ";
	cin.ignore();
	getline(cin, *cont);

	delete cont;
	cont = NULL;


	system("cls");

	//Asking for further advanced options

	for (int count = 0; count < 40; count++)
	{
		cout << ">< ";
	}
	cout << endl << endl;

	cout << setw(70) << "STUDENT GRADE REPORT" << endl << endl;

	for (int count = 0; count < 40; count++)
	{
		cout << ">< ";
	}
	cout << endl << endl << endl << endl;

	cout << "Do you want to perform further operations?\n";
	cout << "Press Y/y to continue to further operations\nPress N/n to terminate this application and save the record for later use\n";
	cout << "Enter you choice : ";
	cin >> choice;

	while (choice != 'N' && choice != 'n' && choice != 'Y' && choice != 'y')
	{
		cout << "INVALID INPUT!!!\n";
		cout << "Press Y/y to add an entry\nPress N/n to exit the application\n";
		cout << "Enter you choice : ";
		cin >> choice;
	}

	if (choice != 'N' && choice != 'n')
	{
		do
		{
			int index = -1;

			display(rollNumber, computerMarks, mathMarks, percentage, grade, size);

			//Menu Display function called

			choice = menu(choice);

			if (choice == 1)
			{
				cout << "\n\nEnter the Roll Number of the student to find it in the records : ";
				cin >> roll;

				index = findRoll(rollNumber, size, roll, index);

				while (index == -1)
				{
					cout << "\n\nRoll Number not found!!!!\nEnter the correct Roll Number : ";
					cin >> roll;

					index = findRoll(rollNumber, size, roll, index);
				}

				cout << "\n\nRoll Number found!!!\n";

				cout << "\n\nEnter the updated Roll Number : ";
				cin >> roll;

				*(rollNumber + index) = roll;

				cout << "\n\nROLL NUMBER UPDATED.....\n";

				string *cont = new string();

				cout << "\n\nPress ENTER to continue : ";
				cin.ignore();
				getline(cin, *cont);

				delete cont;
				cont = NULL;

			}

			else if (choice == 2)
			{
				cout << "\n\nEnter the Roll Number of the student to change its computer marks : ";
				cin >> roll;

				index = findRoll(rollNumber, size, roll, index);

				while (index == -1)
				{
					cout << "\n\nRoll Number not found!!!!\nEnter the correct Roll Number : ";
					cin >> roll;

					index = findRoll(rollNumber, size, roll, index);
				}

				cout << "\n\nRoll Number found!!!\n";

				cout << "\n\nEnter the updated CS marks : ";
				cin >> marks1;

				*(computerMarks + index) = marks1;

				percent = *(computerMarks + index) + *(mathMarks + index);

				percent /= 200;

				percent *= 100;

				*(percentage + index) = percent;

				*(grade + index) = updateGrade(percent);

				cout << "\n\nCS Marks of " << roll << " updated.....\n";

				string *cont = new string();

				cout << "\n\nPress ENTER to continue : ";
				cin.ignore();
				getline(cin, *cont);

				delete cont;
				cont = NULL;

			}

			else if (choice == 3)
			{
				choice_3(rollNumber, computerMarks, mathMarks, percentage, grade, size, percent);

				cout << "\n\nCS Marks of all students updated.....\n";

				string *cont = new string();

				cout << "\n\nPress ENTER to continue : ";
				cin.ignore();
				getline(cin, *cont);

				delete cont;
				cont = NULL;
			}

			else if (choice == 4)
			{
				cout << "\n\nEnter the Roll Number of the student to change its maths marks : ";
				cin >> roll;

				index = findRoll(rollNumber, size, roll, index);

				while (index == -1)
				{
					cout << "\n\nRoll Number not found!!!!\nEnter the correct Roll Number : ";
					cin >> roll;

					index = findRoll(rollNumber, size, roll, index);
				}

				cout << "\n\nRoll Number found!!!\n";

				cout << "\n\nEnter the updated Maths marks : ";
				cin >> marks2;

				*(mathMarks + index) = marks2;

				percent = *(computerMarks + index) + *(mathMarks + index);

				percent /= 200;

				percent *= 100;

				*(percentage + index) = percent;

				*(grade + index) = updateGrade(percent);

				cout << "\n\nMaths Marks of " << roll << " updated.....\n";

				string *cont = new string();

				cout << "\n\nPress ENTER to continue : ";
				cin.ignore();
				getline(cin, *cont);

				delete cont;
				cont = NULL;
			}

			else if (choice == 5)
			{
				choice_5(rollNumber, computerMarks, mathMarks, percentage, grade, size, percent);

				cout << "\n\nCS Marks of all students updated.....\n";

				string *cont = new string();

				cout << "\n\nPress ENTER to continue : ";
				cin.ignore();
				getline(cin, *cont);

				delete cont;
				cont = NULL;
			}

			else if (choice == 6)
			{
				choice_6(rollNumber, computerMarks, mathMarks, percentage, grade, size);

				cout << "\n\nRecords have been sorted percentage wise.....\n";

				string *cont = new string();

				cout << "\n\nPress ENTER to continue : ";
				cin.ignore();
				getline(cin, *cont);

				delete cont;
				cont = NULL;
			}

			else if(choice == 7)
			{
				cout << "\n\nEnter the Roll Number of the student to remove it from the records : ";
				cin >> roll;

				index = findRoll(rollNumber, size, roll, index);

				while (index == -1)
				{
					cout << "\n\nRoll Number not found!!!!\nEnter the correct Roll Number : ";
					cin >> roll;

					index = findRoll(rollNumber, size, roll, index);
				}

				cout << "\n\nRoll Number found!!!\n";

				rollNumber = shrink_s(rollNumber, size, index);

				computerMarks = shrink_i(computerMarks, size, index);

				mathMarks = shrink_i(mathMarks, size, index);

				percentage = shrink_f(percentage, size, index);

				grade = shrink_c(grade, size, index);

				size--;

				cout << "\n\nRoll Number Deleted....\n";

				string *cont = new string();

				cout << "\n\nPress ENTER to continue : ";
				cin.ignore();
				getline(cin, *cont);

				delete cont;
				cont = NULL;
				
			}

			else if (choice == 8)
			{
				system("cls");

				for (int count = 0; count < 40; count++)
				{
					cout << ">< ";
				}
				cout << endl << endl;

				cout << setw(70) << "STUDENT GRADE REPORT" << endl << endl;

				for (int count = 0; count < 40; count++)
				{
					cout << ">< ";
				}
				cout << endl << endl << endl << endl;

				cout << "Student Data Entry.......\n\n";

				cout << "Enter the Roll Number of the student : ";					//Roll Number Entry
				cin >> roll;

				for (int count = 0; count < size; count++)					//Checking Roll Number if already exists
				{
					if (roll == rollNumber[count])
					{
						isFound = true;
						break;
					}
				}

				if (isFound == false)
				{
					rollNumber = regrow_s(rollNumber, size, roll);					//Regrow function of Roll Number called

					cout << "\nEnter the Computer Science marks of Roll Number " << roll << " : ";					//CS Marks Entry
					cin >> marks1;

					while (marks1 < 0 || marks1 > 100)
					{
						cout << "INVALID INPUT!\nThe Marks should be in range from 1 to 100\n";
						cout << "\nEnter the Computer Science marks of Roll Number " << roll << " again : ";
						cin >> marks1;
					}

					computerMarks = regrow_i(computerMarks, size, marks1);					//Regrow function of CS Marks called			

					cout << "\nEnter the Mathematics marks of Roll Number " << roll << " : ";					//Maths Marks Entry
					cin >> marks2;

					while (marks2 < 0 || marks2 > 100)
					{
						cout << "INVALID INPUT!\nThe Marks should be in range from 1 to 100\n";
						cout << "\nEnter the Computer Science marks of Roll Number " << roll << " again : ";
						cin >> marks2;
					}

					mathMarks = regrow_i(mathMarks, size, marks2);					//Regrow function of Math Marks called

					percent = marks1 + marks2;

					percent /= 200;

					percent *= 100;					//Percentage calculated

					percentage = regrow_f(percentage, size, percent);					//Regrow function of percentage called

					grade = regrow_c(grade, size, percent);					//Regrow function of grade called

					size++;

					cout << "\n\nNEW STUDENT RECORD ADDED!";
				}

				else
				{
					cout << "\n\nStudent already exists in the records.....\n";
				}


				string *cont = new string();

				cout << "\n\nPress ENTER to continue : ";
				cin.ignore();
				getline(cin, *cont);

				delete cont;
				cont = NULL;
			}

			else if (choice == 0)
			{
				break;
			}

			display(rollNumber, computerMarks, mathMarks, percentage, grade, size);

		} while (true); 
		
		ofstream fout("Records.txt");

		for (int count = 0; count < size; count++)
		{
			fout << *(rollNumber + count);
			fout << "\t\t";
			fout << *(computerMarks + count);
			fout << "\t\t";
			fout << *(mathMarks + count);
			fout << "\t\t";
			fout << *(percentage + count);
			fout << "\t\t";
			fout << *(grade + count) << endl;
		}

		cout << "\n\nYour record have been stored in a file for later use.\n";

		fout.close();
		
	}

	cout << "\n\nBye, Have a great time sir.........\n\n";
	
	delete[] rollNumber, computerMarks, mathMarks, percentage, grade;

	rollNumber = NULL, computerMarks = NULL, mathMarks = NULL, percentage = NULL, grade = NULL;

	system("PAUSE");
	return 0;
}

string *regrow_s(string *rollNumber, int size, string roll)
{
	string *array = new string[size + 1];

	string_copy(rollNumber, size, array);

	delete[] rollNumber;
	rollNumber = NULL;

	*(array + size) = roll;

	return array;
}

void string_copy(string *oldArray, int size, string *newArray)
{
	for (int count = 0; count < size; count++)
	{
		*(newArray + count) = *(oldArray + count);
	}
}

int *regrow_i(int *marks, int size, int marks2)
{
	int *array = new int[size + 1];

	int_copy(marks, size, array);

	delete[] marks;
	marks = NULL;

	*(array + size) = marks2;

	return array;
}

void int_copy(int *oldArray, int size, int *newArray)
{
	for (int count = 0; count < size; count++)
	{
		*(newArray + count) = *(oldArray + count);
	}
}

float *regrow_f(float *percentage, int size, float percent)
{
	float *array = new float[size + 1];

	float_copy(percentage, size, array);

	delete[] percentage;
	percentage = NULL;

	*(array + size) = percent;

	return array;
}

void float_copy(float *oldArray, int size, float *newArray)
{
	for (int count = 0; count < size; count++)
	{
		*(newArray + count) = *(oldArray + count);
	}
}

char *regrow_c(char *grade, int size, float percent)
{
	char *array = new char[size + 1];

	char_copy(grade, size, array);

	delete[] grade;
	grade = NULL;

	if (percent > 90.0 && percent <= 100.0)
	{
		*(array + size) = 'A';
	}

	else if (percent >= 75.0 && percent <= 90.0)
	{
		*(array + size) = 'B';
	}

	else if (percent >= 60.0 && percent < 75.0)
	{
		*(array + size) = 'C';
	}

	else if (percent >= 50.0 && percent < 60.0)
	{
		*(array + size) = 'D';
	}

	else if (percent < 50)
	{
		*(array + size) = 'F';
	}

	return array;
}

void char_copy(char *oldArray, int size, char *newArray)
{
	for (int count = 0; count < size; count++)
	{
		*(newArray + count) = *(oldArray + count);
	}
}

void display(string *rollNumber, int *computerMarks, int *mathMarks, float *percentage, char *grade, int size)
{
	int temp = 0, num = 0;

	system("cls");

	for (int count = 0; count < 40; count++)
	{
		cout << ">< ";
	}
	cout << endl << endl;

	cout << setw(70) << "STUDENT GRADE REPORT" << endl << endl;

	for (int count = 0; count < 40; count++)
	{
		cout << ">< ";
	}
	cout << endl << endl << endl << endl;

	cout << "Let's look into records\n\n";

	cout << "Roll Number" << setw(20) << "CS Marks" << setw(20) << "Maths Marks" << setw(20) << "Percentage" << setw(20) << "Grade\n";

	for (int count = 0; count < size; count++)
	{
		cout << *(rollNumber + count);
		cout << setw(22);
		cout << *(computerMarks + count);
		cout << setw(16);
		cout << *(mathMarks + count);
		cout << setw(23);
		cout << *(percentage + count);
		cout << setw(21);
		cout << *(grade + count) << endl;
	}

	if (size == 0)
	{
		cout << "\n\nAs you can see your record is empty....\n";
	}

}

int menu(int choice)
{

	cout << endl << endl << endl << endl;

	cout << "1. Press 1 to update Roll Number of a particular Student\n";
	cout << "2. Press 2 to update marks of a particular student for CS\n";
	cout << "3. Press 3 to update marks of CS for all students who are already enrolled\n";
	cout << "4. Press 4 to update marks for Mathematics\n";
	cout << "5. Press 5 to update marks of Mathematics for all students who are already enrolled\n";
	cout << "6. Press 6 to sort the record in ascending order on the basis of percentages\n";
	cout << "7. Press 7 to delete the record of a particular student\n";
	cout << "8. Press 8 to add another student\n";
	cout << "9. Press 0 to terminate the program\n\n";
	cout << "Enter your choice : ";
	cin >> choice;

	while (choice > 9 || choice < 0)
	{
		cout << "\n\nINVALID CHOICE\n\nEnter the valid input : ";
		cin >> choice;
	}

	return choice;
}

int findRoll(string *rollNumber, int size, string roll, int index)
{
	for (int i = 0; i < size; i++)
	{
		if (*(rollNumber + i) == roll)
		{
			index = i;
		}
	}

	return index;
}

void choice_3(string *rollNumber, int *computerMarks, int *mathMarks, float *percentage, char *grade, int size, float percent)
{
	cout << "\n\nLet's Update the CS marks of all student : \n\n";

	for (int i = 0; i < size; i++)
	{
		cout << "Enter the updated marks of " << *(rollNumber + i) << " : ";
		cin >> *(computerMarks + i);

		percent = *(computerMarks + i) + *(mathMarks + i);

		percent /= 200;

		percent *= 100;

		*(percentage + i) = percent;

		if (percent > 90.0 && percent <= 100.0)
		{
			*(grade + i) = 'A';
		}

		else if (percent >= 75.0 && percent <= 90.0)
		{
			*(grade + i) = 'B';
		}

		else if (percent >= 60.0 && percent < 75.0)
		{
			*(grade + i) = 'C';
		}

		else if (percent >= 50.0 && percent < 60.0)
		{
			*(grade + i) = 'D';
		}

		else if (percent < 50)
		{
			*(grade + i) = 'F';
		}
	}
}

void choice_5(string *rollNumber, int *computerMarks, int *mathMarks, float *percentage, char *grade, int size, float percent)
{
	cout << "\n\nLet's Update the Maths marks of all student : \n\n";

	for (int i = 0; i < size; i++)
	{
		cout << "Enter the updated marks of " << *(rollNumber + i) << " : ";
		cin >> *(mathMarks + i);

		percent = *(computerMarks + i) + *(mathMarks + i);

		percent /= 200;

		percent *= 100;

		*(percentage + i) = percent;

		if (percent > 90.0 && percent <= 100.0)
		{
			*(grade + i) = 'A';
		}

		else if (percent >= 75.0 && percent <= 90.0)
		{
			*(grade + i) = 'B';
		}

		else if (percent >= 60.0 && percent < 75.0)
		{
			*(grade + i) = 'C';
		}

		else if (percent >= 50.0 && percent < 60.0)
		{
			*(grade + i) = 'D';
		}

		else if (percent < 50)
		{
			*(grade + i) = 'F';
		}
	}
}

void choice_6(string *rollNumber, int *computerMarks, int *mathMarks, float *percentage, char *grade, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (*(percentage + i) > *(percentage + j))
			{
				swap(*(percentage + i), *(percentage + j));
				swap(*(rollNumber + i), *(rollNumber + j));
				swap(*(computerMarks + i), *(computerMarks + j));
				swap(*(mathMarks + i), *(mathMarks + j));
				swap(*(grade + i), *(grade + j));
			}
		}
	}
}

string *shrink_s(string *rollNumber, int size, int index)
{
	string *array = new string[size - 1];

	for (int i = index; i < size - 1; i++)
	{
		*(rollNumber + i) = *(rollNumber + i + 1);
	}

	string_copy(rollNumber, size - 1, array);

	delete[] rollNumber;
	rollNumber = NULL;

	return array;
}

int *shrink_i(int *marks, int size, int index)
{
	int *array = new int[size - 1];

	for (int i = index; i < size - 1; i++)
	{
		*(marks + i) = *(marks + i + 1);
	}

	int_copy(marks, size, array);

	delete[] marks;
	marks = NULL;

	return array;
}

float *shrink_f(float *percentage, int size, int index)
{
	float *array = new float[size - 1];

	for (int i = index; i < size - 1; i++)
	{
		*(percentage + i) = *(percentage + i + 1);
	}

	float_copy(percentage, size, array);

	return array;
}

char *shrink_c(char *grade, int size, int index)
{
	char *array = new char[size - 1];

	for (int i = 0; i < size - 1; i++)
	{
		*(grade + i) = *(grade + i + 1);
	}

	char_copy(grade, size, array);

	delete[] grade;
	grade = NULL;

	return array;
}

char updateGrade(float percent)
{
	if (percent > 90.0 && percent <= 100.0)
	{
		return 'A';
	}

	else if (percent >= 75.0 && percent <= 90.0)
	{
		return 'B';
	}

	else if (percent >= 60.0 && percent < 75.0)
	{
		return 'C';
	}

	else if (percent >= 50.0 && percent < 60.0)
	{
		return 'D';
	}

	else if (percent < 50)
	{
		return 'F';
	}
}