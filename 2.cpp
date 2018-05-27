//Ёлементы массива, сумма цифр которых чЄтна€, расположить в пор€дке возрастани€ суммы цифр элементов, не наруша€ пор€дка следовани€ других элементов. 
#include <iostream>
using namespace std;
void vivod(int*, int);
void vvodrandom(int*, int);
void vvodconsol(int*, int);
void function(int*, int);
int sumDigistsInNumber(int* number);
void sortNumbers(int* array, int length);
int main(){
  int n; 
  cout<<"Vvedi kol-vo elementov massiva: ";  cin>>n;
  int *mas = new int[n];
  int vibor1, vibor2;
  while(1){
    cout<<"\n Vvedite nomer punkta:\n";
    cout<<"Vvod------>1"<<endl
          <<"Vivod ishodnogo massiva----->2"<<endl
		  <<"Work with massiv------>3"<<endl
		  <<"Exit------>4"<<endl;
    cin>>vibor1;
    switch (vibor1){
      case 1:
		  {
			system("cls");
			cout<<"Choose the way of enter:\n";
			cout<<"random enter = 1"<<endl;
			cout<<"consol enter = 2"<<endl;
			cin>>vibor2;
			switch (vibor2)
			{
				case(1):{
					system("cls");
					vvodrandom(mas, n); break;
					}	
				case(2):{
					system("cls");
					vvodconsol(mas, n); break;
					}
			}
		  } break;
      case 2:
         system("cls");
		 cout<<"Ishodnyy massiv:"<<endl;
         vivod(mas, n); 	     break;
     case  3:
       system("cls");
	   cout<<"Work with massiv:"<<endl;
       function(mas, n);        break;
      case 4:
        system("cls");
        cout<<"Good-Bye!";
        delete [] mas;
        exit(1);	            break;
    }
  }
 cout<<endl;
 system("pause");
}
void vvodrandom(int *mas, int n){
     for(int i = 0; i < n; i++)
     *(mas + i) =-100 + rand() % 201;
 }
void vvodconsol(int *mas, int n){
	cout<<"Enter massiv"<<endl;
    for(int i = 0; i < n; i++)
    cin>>*(mas + i);
 }
void vivod(int *mas, int n){
  for(int i = 0; i < n; i++)
  cout<<*(mas + i)<<' ';
  cout<<endl;
}
void function(int *array, int length)
{
	cout << "Array before sort" << endl;
	vivod(array, length);
	sortNumbers(array, length);
    cout << "Array after sort" << endl;
	vivod(array, length);	
}
int sumDigistsInNumber(int* number)
{
	int value = abs( *number);
	int sumDigits = 0;
	int currentDigit;
	do
	{
		currentDigit = value % 10;
		sumDigits += currentDigit;
		value /= 10;
	} while (value != 0);
	return sumDigits;
}
void sortNumbers(int* array, int length)
{	
		bool flag = true;
		int* currentPosition;
		while (flag)
		{
			flag = false;
			currentPosition = 0;
			for (int* nextPosition = array; nextPosition < array + length; nextPosition++)
			{
				if ((sumDigistsInNumber(nextPosition) % 2) == 0)
				{
						if (currentPosition != 0 && sumDigistsInNumber(currentPosition) > sumDigistsInNumber(nextPosition))
						{
							int temp = *nextPosition;
							*nextPosition = *currentPosition;
							*currentPosition = temp;
							flag = true;
						}
					currentPosition = nextPosition;
				}
			}
		}
}



 



