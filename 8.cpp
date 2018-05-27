//Из массива удалить все элементы, первая цифра которых чётная, стоящие после первого максимального элемента. Дополнительный массив не использовать.
#include <iostream>
#include <fstream>   	 
using namespace std;    
class Numbers{          			
	int n;           	 	
	int *a;            
public:
	Numbers (int x);
	~Numbers();
	void readFile();
	void outputFile();
	void readOutputFile();
	void show();
	bool isFirstDigitEven(int a);
	void deleteElements();
};

Numbers::Numbers(int x){
	n = x;
	a = new int [n];        		
}

Numbers::~Numbers(){		
	for(int i = 0; i < n; i++)
		delete [] a;
}

void Numbers::readFile(){
	ifstream fin("Array.txt", ios::in); 
	if(!fin){ cout<<"File Array can't be open";  exit(1);}
	for(int i = 0; i < n; i++)
		fin>>a[i];  			
	fin.close();      
}

void Numbers::outputFile(){
	ofstream fout("output.txt", ios::out); 
	if(!fout){ cout<<"File can't be open";  exit(1);}
	for(int i = 0; i < n; i++)
		fout<<a[i]<<' ';  			
	fout.close();      
}

void Numbers::readOutputFile(){
	ifstream out("output.txt", ios::in); 
	if(!out){ cout<<"File can't be open";  exit(1);}
	for(int i = 0; i < n; i++)
		out>>a[i];  			
	out.close();      
}

void Numbers::show(){
	for(int i = 0; i < n; i++){    
		cout<<a[i]<<' ';	
	}  
	cout<<endl;
}

bool Numbers::isFirstDigitEven(int a){
	int k;
	do
	{
		k = a;
		a /= 10;
	} while (a);
	if (k % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Numbers:: deleteElements()
{
	int max = a[0];
	int maxElementIndex = 0;
	for (int i = 0; i< n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			maxElementIndex = i;
		}
	}
	for (int i = maxElementIndex + 1; i < n; i++)
	{
		if (isFirstDigitEven(a[i]))
		{
			for (int j = i; j < n; j++)
				a[j] = a[j + 1];
			i--;
			n--;
		}
	}
}

int main(){
	Numbers ob(10); 			 
	ob.readFile();
	cout<<"Array before sort:"<<endl;
	ob.show();
	ob.deleteElements();
	ob.outputFile();
	ob.readOutputFile();
	cout<<"Array after sort from output.txt:"<<endl;
	ob.show();
	system("pause");
}


