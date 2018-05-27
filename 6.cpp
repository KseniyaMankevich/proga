//В структуре хранятся результаты соревнований по плаванию: номер заплыва, дистанция, фамилия участника , возраст и его время. Создать массив структур.
//a)	Создать и вывести список участников, упорядоченный в порядке возрастания номера заплыва.
//b)	Вычислить среднее время во всех заплывах.
//c)	По запросу определить участников указанного заплыва, чей возраст старше заданного.
#include <iostream>
using namespace std;
struct competition {
	int id;
	int distance;
	const char* surname;
	int age;
	float time;
};
void clearMemory(competition*);
void output(competition*, int);
void manualFill(competition*, int);
void function1(competition*, int);
void function2(competition*, int);
void function3(competition*, int, int, int);
void printAverageTime(int*, float*, int*, int);
void shapka();
int main()
{
	int members = 0;
	competition*  structMembers = NULL;
	while (true)
	{
		cout << "\n Enter your option:\n" << endl;
		cout << "1: Fill structure" << endl;
		cout << "2: Print structure " << endl;
		cout << "3: Table with id in ascending order" << endl;
		cout << "4: Average time in all swims" << endl;
		cout << "5: Members older than defined age" << endl;
		cout << "6: Exit" << endl;
		int punkt, punkt1;
		cin >> punkt;
		switch (punkt)
		{
		case  1:
			system("cls");
			cout << "Choose how fill structure :" << endl;
			cout << "If manually from console, input = 1" << endl;
			cout << "Predefined values = 2" << endl;
			cin >> punkt1;
			switch (punkt1) {
			case(1):
			{
				system("cls");
				cout << "Input quantity of members (any positive integer > 0) : " << endl;
				cin >> members;
				structMembers = new competition[members];
				manualFill(structMembers, members);
				break;
			}
			case(2):
			{
				system("cls");
				members = 10;
				structMembers = new competition[members];
				structMembers[0].id = 2;
				structMembers[0].distance = 100;
				structMembers[0].surname = "Ivanov";
				structMembers[0].age = 20;
				structMembers[0].time = 45.51;

				structMembers[1].id = 1;
				structMembers[1].distance = 50;
				structMembers[1].surname = "Smirnov";
				structMembers[1].age = 25;
				structMembers[1].time = 23.35;

				structMembers[2].id = 2;
				structMembers[2].distance = 100;
				structMembers[2].surname = "Sidorov";
				structMembers[2].age = 18;
				structMembers[2].time = 42.21;

				structMembers[3].id = 3;
				structMembers[3].distance = 25;
				structMembers[3].surname = "Kuznetsov";
				structMembers[3].age = 21;
				structMembers[3].time = 12.87;

				structMembers[4].id = 2;
				structMembers[4].distance = 100;
				structMembers[4].surname = "Vasiliev";
				structMembers[4].age = 24;
				structMembers[4].time = 40.36;

				structMembers[5].id = 1;
				structMembers[5].distance = 50;
				structMembers[5].surname = "Sokolov";
				structMembers[5].age = 32;
				structMembers[5].time = 30.57;

				structMembers[6].id = 2;
				structMembers[6].distance = 100;
				structMembers[6].surname = "Morozov";
				structMembers[6].age = 35;
				structMembers[6].time = 44.54;

				structMembers[7].id = 3;
				structMembers[7].distance = 25;
				structMembers[7].surname = "Borisov";
				structMembers[7].age = 34;
				structMembers[7].time = 44.54;

				structMembers[8].id = 3;
				structMembers[8].distance = 25;
				structMembers[8].surname = "Orlov";
				structMembers[8].age = 29;
				structMembers[8].time = 13.47;

				structMembers[9].id = 1;
				structMembers[9].distance = 50;
				structMembers[9].surname = "Komarov";
				structMembers[9].age = 25;
				structMembers[9].time = 32.47;
				break;
			}
			}
			break;
		case  2:
			system("cls");
			output(structMembers, members);
			break;
		case  3:
			system("cls");
			function1(structMembers, members);
			break;
		case  4:
			system("cls");
			function2(structMembers, members);
			break;
		case  5:
			system("cls");
			int id, age;
			cout << "Enter id of swim : ";
			cin >> id;
			cout << "Enter age : ";
			cin >> age;
			function3(structMembers, members, id, age);
			break;
		case  6:
			system("cls");
			cout << "Good-Bye!";
			clearMemory(structMembers);
			exit(0);
			break;
		default:
			cout << "Something wrong, bad punct value " << punkt << endl;
		}
	}
	system("pause");
}
void clearMemory(competition* structMembers)
{
	delete[] structMembers;
}
void manualFill(competition* structMembers, int members)
{
	cout << "Manually input elements in array for every position :" << endl;
	for (int i = 0; i < members; i++)
	{
		competition* member = new competition;
		cout << "Input id for " << i + 1 << " member : ";
		while (!(cin >> member->id) || member->id < 1)
		{
			cout << "Wrong value id, try again:  ";
		}
		cout << "Input distance for " << i + 1 << " member : ";
		while (!(cin >> member->distance) || member->distance < 1)
		{
			cout << "Wrong value distance, try again : ";
		}
		cout << "Input surname for " << i + 1 << " member() (MAX LENGTH=12): ";
		member->surname = new char[12];
		while (!(cin >> (char*)member->surname) || strlen(member->surname) < 1 || strlen(member->surname) > 12)
		{
			cout << "Wrong value name, try again : ";
		}
		cout << "Input age for " << i + 1 << " member : ";
		while (!(cin >> member->age) || member->age <= 0)
		{
			cout << "Wrong value age, try again : ";
		}
		cout << "Input time for " << i + 1 << " member : ";
		while (!(cin >> member->time) || member->time <= 0)
		{
			cout << "Wrong value time, try again : ";
		}
		cout << endl;
		structMembers[i] = *member;
	}
}
void shapka()
{
	cout << "|";
	cout.fill('-');
	cout.width(70);
	cout << "|" << endl;

	cout << "|";
	cout.fill(' ');
	cout.width(6);
	cout << "id";
	cout.width(6);
	cout << "|";

	cout.fill(' ');
	cout.width(12);
	cout << "Distance,m";
	cout.width(4);
	cout << "|";

	cout.width(13);
	cout << "Surname";
	cout.width(7);
	cout << "|";

	cout.width(5);
	cout << "Age";
	cout.width(3);
	cout << "|";

	cout.width(9);
	cout << "Time,s";
	cout.width(5);
	cout << "|" << endl;

	cout << "|";
	cout.fill('-');
	cout.width(70);
	cout << "|" << endl;
	cout.fill(' ');
}
void output(competition* structMembers, int members)
{
	cout.setf(ios::fixed);
	cout.precision(2);
	shapka();
	for (int i = 0; i < members; i++)
	{
		competition member = *(structMembers + i);
		cout << "|";
		cout.width(6);
		cout << member.id;
		cout.width(6);
		cout << "|";

		cout.width(9);
		cout << member.distance;
		cout.width(7);
		cout << "|";

		cout.width(12);
		cout << member.surname;
		cout.width(8);
		cout << "|";

		cout.width(5);
		cout << member.age;
		cout.width(3);
		cout << "|";

		cout.width(9);
		cout << member.time;
		cout.width(5);
		cout << "|" << endl;
	}
	cout << "|";
	cout.fill('-');
	cout.width(70);
	cout << "|" << endl;
	cout.fill(' ');
}
void function1(competition* arr, int members)
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < members - 1; i++)
		{
			if ((*(arr + i)).id >(*(arr + i + 1)).id)
			{
				competition temp = *(arr + i + 1);
				*(arr + i + 1) = *(arr + i);
				*(arr + i) = temp;
				flag = true;
			}
		}
	}
	output(arr, members);
}
void function2(competition* arrayPointer, int sizeStruct)
{
	function1(arrayPointer, sizeStruct);
	system("cls");
	int quantityIds = 0;
	int* ids = new int[sizeStruct]();
	float* averageTimes = new float[sizeStruct]();
	int* quantityMembersInEverySwim = new int[sizeStruct]();
	for (int i = 0; i < sizeStruct; i++)
	{
		int currentId = (arrayPointer + i)->id;
		*(ids + quantityIds) = currentId;
		*(averageTimes + quantityIds) += (arrayPointer + i)->time;
		*(quantityMembersInEverySwim + quantityIds) += 1;
		int nextId;
		if (i != sizeStruct - 1)
		{
			nextId = (*(arrayPointer + i + 1)).id;
		}
		if (i == sizeStruct - 1 || currentId != nextId)
		{
			*(averageTimes + quantityIds) = *(averageTimes + quantityIds) / *(quantityMembersInEverySwim + quantityIds);
			quantityIds++;
		}
	}
	cout << "Average time in every swim:" << endl;
	printAverageTime(ids, averageTimes, quantityMembersInEverySwim, quantityIds);
	delete[] ids;
	delete[] averageTimes;
	delete[] quantityMembersInEverySwim;
}
void printAverageTime(int* ids, float* averageTime, int* quantityMembersInEverySwim, int quantity)
{
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "|";
	cout.fill('-');
	cout.width(40);
	cout << "|" << endl;

	cout << "|";
	cout.fill(' ');
	cout.width(6);
	cout << "id";
	cout.width(4);
	cout << "|";

	cout.width(8);
	cout << "members";
	cout.width(2);
	cout << "|";


	cout.width(15);
	cout << "time,s";
	cout.width(5);
	cout << "|" << endl;

	cout << "|";
	cout.fill('-');
	cout.width(40);
	cout << "|" << endl;
	cout.fill(' ');
	for (int i = 0; i < quantity; i++)
	{
		cout << "|";
		cout.width(6);
		cout << *(ids + i);
		cout.width(4);
		cout << "|";

		cout.width(6);
		cout << *(quantityMembersInEverySwim + i);
		cout.width(4);
		cout << "|";

		cout.width(14);
		cout << (*(averageTime + i));
		cout.width(6);
		cout << "|" << endl;
	}
	cout << "|";
	cout.fill('-');
	cout.width(40);
	cout << "|" << endl;
	cout.fill(' ');
}
void function3(competition* arr, int members, int id, int age)
{
	int count = 0;
	competition* tempMembers = new competition[members];
	for (int i = 0; i < members; i++)
	{
		if ((*(arr + i)).id == id)
		{
			if ((*(arr + i)).age > age)
			{
				*(tempMembers + count) = *(arr + i);
				count++;
			}
		}
	}
	cout << "Found " << count << " members from " << id << " swim, whose age is more than " << age << endl;
	if (count > 0)
	{
		output(tempMembers, count);
	}
	clearMemory(tempMembers);
}





















