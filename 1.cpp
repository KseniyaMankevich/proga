#include<iostream>
using namespace std;
void vivod(int*, int);
void vvodrandom(int*, int);
void vvodconsol(int*, int);
int function(int*, int);
int main(){
  int n,kol; 
  cout<<"Vvedi kol-vo elementov massiva: ";  cin>>n;
  int *mas = new int[n];
  int vibor1, vibor2;
  while(1){
    cout<<"\n Vvedite nomer punkta:\n";
    cout<<"Vvod------>1"<<endl
          <<"Vivod ishodnogo massiva----->2"<<endl
		  <<"Work with massiv------>3"<<endl
		  <<"Vivod result massiva----->4"<<endl
		  <<"Exit------>5"<<endl;
    cin>>vibor1;
    switch (vibor1){
      case 1:
		  {
			system("cls");
			cout<<"Choose the way of enter:\n";
			cout<<"random enter= 1"<<endl;
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
         vivod(mas, n); 	       break;
     case  3:
       system("cls");
	   cout<<"Work with massiv:"<<endl;
       kol=function(mas, n);
	   break;
      case 4:
         system("cls");
		 cout<<"Result massiv:"<<endl;
         vivod(mas, n-kol); 	       break;
      case 5:
        system("cls");
        cout<<"Good-Bye!";
        delete [] mas;
        exit(1);	        break;
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
int function(int *mas, int length)
{
  int k=0, index=0, first;
  int max=mas[0];
  for(int i=0;i<length;i++)
  {
    if(mas[i]>max)
	{
		max=mas[i];
	    index=i;
	}
  }
  for(int i=index+1; i<length;)
  {
	 first = mas[i];
	 while(first >= 10 || first <= -10)
    {
       
        first/=10;
    }
	 cout << "Number " << mas[i] << ", first cifra " << abs(first)<<endl;
	  if(first%2 == 0 )
	 {
		  k++;
		  length--;
		  for (int j = i; j < length; j++)
		  {
			  mas[j] = mas[j + 1];
		  }
		  continue;
	 }
	  i++;
  }
  cout<<"Kol-vo udal elementov massiva="<<k<<endl;
  return k;
}



 

