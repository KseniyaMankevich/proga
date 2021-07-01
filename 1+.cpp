#include<iostream>
using namespace std;
void vivod(int*, int);
void vvodrandom(int*, int);
void vvodconsol(int*, int);
void function(int*, int);
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
       function(mas, n);        break;
      case 4:
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
void function(int *mas, int length)
{
   int indexMin1 = 0, indexMin2 = 1;
   int min1, min2, temp;
   for (int i = 0; i < length; i++)
   {
	   if (mas[indexMin1] == mas[i])
	   {
		   if (i == length-1)
		   {
			   cout <<"This array contains the same numbers "<<mas[i]<<endl;
			   return;
		   }
		   continue;
	   }
	   indexMin2 = i;
	   if (mas[indexMin2]<mas[indexMin1])
	   {
		   min1 = mas[indexMin2];
		   min2 = mas[indexMin1];
		   temp = indexMin2;
		   indexMin2 = indexMin1;
		   indexMin1 = temp;
	   }
	   else
	   {
		   min1 = mas[indexMin1];
		   min2 = mas[indexMin2];
	   }
	   break;
   }
  for(int i=indexMin2; i<length; i++)
	{ 
	   if (min1 == mas[i] || min2 <= mas[i] )
	   {
		   continue;
	   }
       if (min1 > mas[i])
	   {
		   min2 = min1;
		   min1 = mas[i];   
		   indexMin2 = indexMin1;
		   indexMin1 = i;
		   continue;
	   }
	   if (min2 > mas[i])
	   {
		   min2 = mas[i];
		   indexMin2 = i;
	   }
	}
    cout << "Array with numbers" <<endl;
	vivod(mas, length);
	cout<<"Pervoe minimalnoe= "<<min1<<" , index = "<<indexMin1<<endl;
	cout<<"Vtoroe minimalnoe= "<<min2<<" , index = "<<indexMin2 << endl;
}



 

