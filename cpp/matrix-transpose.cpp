#include <stdio.h>
#include <conio.h>
#include <iostream.h>
int GetDimension();
void AddMatrices();
void GetAMatrix(float data[100][100], int dim);
void PrintMatrix(float data[100][100], int dim);
void Taranahad();

void main()
{
   float data[100][100];
   clrscr();
   int resume = 1;
   while(resume)
   {

     // get function
     int f = 0;
     cout << "\n1. Add two matrices.\n";
     cout << "2. Taranahad.\n";
     cout << "0. Exit\n";
     cout << "\nyour choice:";
     cin  >> f;
     switch(f)
     {
	case 1:
	       AddMatrices();
	       break;
	case 2:
	Taranahad();
	       break;
	case 0:
		resume = 0; break;
     }
   }
}
int GetDimension()
{
   int dim=0;
 // get dimension
     while(dim<1 || dim>99)
     {
	clrscr();
	cout << "Enter the dimension of matrix(1 to 99):";
	cin >> dim;
     }
   return dim;
}
void AddMatrices()
{
   float data1[100][100], data2[100][100],data3[100][100];
   int dim = GetDimension();
   cout << "First Matrix:\n";
   GetAMatrix(data1, dim);
   clrscr();
   cout << "second Matrix:\n";
   GetAMatrix(data2, dim);
    for(int i=0 ; i<dim ; i++)
     {
	for(int j=0 ; j<dim ; j++)
	{
	    data3[i][j] = data2[i][j]+data1[i][j];
	}
     }
   clrscr();
   PrintMatrix(data1, dim);
   cout << "+\n\n";
   PrintMatrix(data2, dim);
   cout << "-----------------------\n";
   PrintMatrix(data3, dim);
   cout << "\nPress any key to continue;";
   getch();
}
void GetAMatrix(float data[100][100], int dim)
{
    // get data
     for(int i=0 ; i<dim ; i++)
     {
	for(int j=0 ; j<dim ; j++)
	{
	    cout << "Enter data in row "<<i+1<<" and column "<<j+1<<" : ";
	    cin >> data[i][j];
	}
     }
}
void PrintMatrix(float data[100][100], int dim)
{
     // print dat
     for(int i=0 ; i<dim ; i++)
     {
	for(int j=0 ; j<dim ; j++)
	{
	    cout << data[i][j]; cout <<"\t";
	}
	cout << "\n";
     }
     cout << "\n";

}
void Taranahad()
{
float data1[100][100], data2[100][100];
   int dim = GetDimension();
   cout << "First Matrix:\n";
   GetAMatrix(data1, dim);
    for(int i=0 ; i<dim ; i++)
     {
	for(int j=0 ; j<dim ; j++)
	{
	    data2[i][j] = data1[j][i];
	}
     }
   clrscr();
   PrintMatrix(data1, dim);
   cout << "-----------------------\n";
   PrintMatrix(data2, dim);
   cout << "\nPress any key to continue;";
   getch();
}
