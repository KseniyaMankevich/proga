#include <iostream>
#include <iomanip>
using namespace std;
const int MIN_NUMBER_TO_DELETE_2FIRST_DiGITS = 100;
class NaturalNumber
{
	int number;
public:
	NaturalNumber();			
	void shownumber();
	bool isPrimeNumber();
    int delete2FirstDigits();
};
NaturalNumber::NaturalNumber() {			
    cout<<"Enter the number: ";  cin>>number;				
  }
void NaturalNumber :: shownumber() {
		cout << "Number = " << number << ", ?prime number : " << boolalpha << isPrimeNumber();
		if (isPrimeNumber() && number >= MIN_NUMBER_TO_DELETE_2FIRST_DiGITS)
		{
			cout << "-Number without 2 first digits: " << delete2FirstDigits();
		}
		cout << endl;
	}
bool NaturalNumber :: isPrimeNumber() {
		if (number == 1 || !(number % 2))
		{
			return false;
		}
		double last = sqrt(number);
		for (int i = 3; i <= last; i +=2)
		{
			if (!(number % i))
			{
				return false;
			}
		}
		return true;
	}
int NaturalNumber :: delete2FirstDigits() {
	    int temp = number;
		int result = 0;
		int multi = 1;
		while (temp > 99)
		{
     		result += (temp % 10) * multi;
			temp = (temp / 10);
			multi *= 10;			
		}
		return result;
}
void showNaturalNumberArray(NaturalNumber*, int); 
int main() {
	int count;
	cout << "Input how many NaturalNumber objects in array you want to create(any integer number > 0):" << endl;
	cin>>count;
	NaturalNumber* array = new NaturalNumber [count];
	showNaturalNumberArray(array,count);
	delete[] array;
	system("pause");
}
void showNaturalNumberArray(NaturalNumber* array, int count) { 
 for (NaturalNumber* pointer = array; pointer < array +count; pointer++) { 
    pointer->shownumber(); 
 } 
}
