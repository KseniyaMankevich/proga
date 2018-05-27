//В массиве А(N,М) строки расположить в порядке возрастания количества максимальных элементов в каждой строке. Указатели на строки. 
//(Поиск количества максимальных элементов в каждой строке выполнять за один просмотр строки).
#include <iostream>
using namespace std;
int** memory(int, int);
void clearMemory(int**, int, int);
void randomFill(int**, int, int);
void manualFill(int**, int, int);
void output(int**, int, int);
void function(int**, int, int);
void dopArray(int**, int*, int, int);
 int main()
 { 
	int n, m;
	int ** a = 0;
	while (true)
	{
		cout << "\n Choose your option:" << endl;
		cout << "1: Memory for array" << endl;
		cout << "2: Fill array" << endl;
		cout << "3: Output of matrix" << endl;
		cout << "4: Work with matrix" << endl;
		cout << "5: Clear Memory" << endl;
		cout << "6: Exit" << endl;
        int option, option1;		
		cin >> option;
		switch (option)
		{
			case  1:  
				system("cls");
				cout << "Enter n :" << endl;  cin >> n;
				cout << "Enter m :" << endl;  cin >> m;
				a = memory( n, m);
				break;
			case  2:
				system("cls");
				cout << "Choose how to fill matrix :" << endl;
				cout << "if random, input = 1" << endl;
				cout << "if manually from console, input = 2" << endl;
				cin >> option1;
				switch (option1)
				{
						case(1):
						{
								system("cls");
								randomFill(a, n, m);
								break;
						}
						case(2):
						{
								system("cls");
								manualFill(a, n, m);
								break;
						}
				}	
				break;
			case  3:
			   	system("cls");
				output(a, n, m);
				break;
         	case  4:
				system("cls");
				function(a, n, m);
				break;
			case  5: 
				system("cls");
				clearMemory(a, n, m);
				break;
			case  6:
				system("cls");
				cout << "Good-Bye!";
				exit(0); 
				break;
		}
	}
	system("pause");
}

int** memory( int n, int m)
{
	int ** x = new int* [n];
	for (int i = 0; i < n; i++)
	{
		*(x + i) = new int[m];			
	}
	return x;
}
void clearMemory(int** x, int n, int m)
{	
	for (int i = 0; i < n; i++)
	{
		delete[] x[i];
	}
	delete[] x;
}
void randomFill(int** x, int n, int m)
{
	srand(m + n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			x[i][j]   = rand() % 25 - 10;
		}
	}
}
void manualFill(int** x, int n, int m)
{
	cout << " Input elements in array for every position :" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "[" << i+1<< "][" << j+1<< "] = ";
			cin >> *(*(x + i) + j);
		}
	}
}
void output(int** x, int n, int m)
{
	cout << "Array with size [" << n << "][" << m << "] :" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(5);
			cout << *(*(x + i) + j);
		}
		cout << endl;
	}
}
void function(int** x, int n, int m)
{
	cout << "Matrix before sort:" << endl;
	output(x, n, m);
	int* tempArray = new int[n];
	dopArray(x, tempArray, n, m);
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 1; i < n; i++)
		{
				if (*(tempArray + i) < *(tempArray + i - 1))
				{
					int tempQuantity = *(tempArray + i);
					*(tempArray + i) = *(tempArray + i - 1);
					*(tempArray + i - 1) = tempQuantity;

					int* tempPointToRaw = *(x + i);
					*(x + i) = *(x + i - 1);
					*(x + i - 1) = tempPointToRaw;
					flag = true;
				}		  
		}
	}
	delete[] tempArray;
	cout << "Matrix after sort:" << endl;
	output(x, n, m);
}
void dopArray(int** x, int* tempArray, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
			int max = **(x + i);
			int count = 1;
			for (int j = 1; j < m; j++)
			{
				if (max > *(*(x + i) + j))
				{
					continue;
				}
				if (max < *(*(x + i) + j))
				{
					max = *(*(x + i) + j);
					count = 1;
				}
				else
				{
					count++;
				}
			}
			cout << "In the " << i+1 << " raw max = " << max << " , quantity = " << count<< endl;
			*(tempArray + i) = count;
	}
}

