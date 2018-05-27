//Определить, сколько слов в строке начинается цифрой. Вывести такие слова на экран. Заменить первое такое слово заданной подстрокой.
#include <cstring> 
#include <iostream> 
using namespace std;
int function(char *, char *);
int main() {
	int choice;
	int length; 
	char* str; 
	char* separators = "!?,./*-+\n\t ";
	while (1) {
		cout << "\n Enter your option:\n";
		cout << "input------>1" << endl
			<< "output----->2" << endl
			<< "work with string------>3" << endl
			<< "exit------>4" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			cout << "Input the length of string:" << endl;
			cin >> length; 
			fflush(stdin);
			cout << "Input your string:" << endl;
			str = new char[2*length+1]; 
			cin.getline(str, length +1);
			fflush(stdin);
			cout << "Your string:" << endl << str<<endl;
			break;
		case 2:
			system("cls");
			puts(str);
			cout<<endl;
			break;
		case  3:
			system("cls");
			function(str, separators);
			cout<<endl;
			break;
		case  4:
			system("cls");
			cout << "Good-Bye!";
			delete[] str;
			exit(1);
			break; 
		cout << endl;
		system("pause");
		}
	}
}

int function(char *str, char *separators)
{
	char* substr = new char[strlen(str) * 2 + 1]; 
	cout << "Input string for replace:" << endl;
	fflush(stdin);
	cin.getline(substr, strlen(str) + 1);
	cout << "String :" << str << endl;
	cout << "SubString:"<< substr << endl;
	int count = 0;
	char* currentPosition = str;
	while (currentPosition)
	{
		currentPosition = currentPosition + strspn(currentPosition, separators);
		int len = strcspn(currentPosition, separators);		
		if (!len) break;
		if (*currentPosition >= '0' && *currentPosition <= '9') 
		{
			count++; 
			char* temp = new char[len + 1];
			strncpy(temp, currentPosition, len);		
			temp[len] = '\0'; 
			cout << count << " word =  " << temp << endl;
			delete[] temp;
			if (count == 1)
			{
				int lengthSubstr = strlen(substr);
				strcat(substr, currentPosition + len);
				strcpy(currentPosition, substr);
				len = lengthSubstr; 
			}
		}
		currentPosition = currentPosition + len; 
	}
	cout << "Quantity of words with first char digit =  " << count << endl;
	if(count!=0) {
	cout << "String after replace of first word with first digit char to another text:\n" << str << endl;
	}
	delete[] substr;
	return count;
}







