//reyhaneh esmailbeigi(JIGAR :D) ,stdno:8317003

#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int Parse(int);
void PrintBuffer();
void AddBuffer(int);
void RemoveBuffer();

int buffer[100];
int bIndex =0;
int lineNo = 0;

void main()
{
   int n;
   clrscr();
   cout<<"Enter The Number Of The Members :  "<<endl;
   cin>>n;
   cout<< "*** MOODES ***\n";
   clrscr();
   Parse(n);
   getch();
}
//**********

int Parse(int n)
{
   int isParsed = FALSE;
   if(n == 0)
   {
      PrintBuffer();
      return TRUE;
   }

   if(n >= 10)
   {
      AddBuffer(10);
      if(Parse(n-10))
	 isParsed = TRUE;
      RemoveBuffer();
   }
   if(n >= 5)
   {
      AddBuffer(5);
      if(Parse(n-5))
	 isParsed = TRUE;
      RemoveBuffer();
   }
   if(n >= 2)
   {
      AddBuffer(2);
      if(Parse(n-2))
	 isParsed = TRUE;
      RemoveBuffer();
   }

   return isParsed;
}

void AddBuffer(int a)
{
   buffer[bIndex] = a;
   bIndex ++;
}
void RemoveBuffer()
{
   buffer[bIndex - 1] = 0;
   bIndex --;
}
void PrintBuffer()
{
   for(int i =0 ; i<bIndex ; i++)
      cout << " "<<buffer[i] ;
   cout << endl;
   lineNo ++;
   if(lineNo == 24)
   {
      cout << "Press Any Key To Next 25 ...";
      getch();
      clrscr();
      lineNo = 0;
   }
}
