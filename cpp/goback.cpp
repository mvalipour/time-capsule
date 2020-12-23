#include <iostream.h>
#include <conio.h>

void GoBack(char *s, int step, int n);
int EndsWithTwoW(char *s, int step);

int lines = 0;
void main()
{


   char ch = 'y';
   while(ch == 'y')
   {
      clrscr();
      lines = 0;

      int n;
      cout << "Enter the value of N : ";
      cin >> n;

      char *s;
      GoBack(s, 0, n);

      cout << " >>> "<<lines <<" Result is printed " << endl;

      // asking for try again ...
      cout << "Do you want to try again ? (y/n)";
      ch = getche();
      cout << endl;
      if(ch == 'Y')
	ch = 'y';;
   }

   cout << endl << "********** Thank You! **********" << endl;
   cout << endl << "********** Good Bye ! **********";
   getch();
}

void GoBack(char *s, int step, int n)
{
   if(step == n)
   {
      for(int i = 0 ; i< n ; i++)
	 cout << *(s + i);
      cout << endl;
      lines ++;
      if(lines %40 == 0)
      {
	 cout << "Press Any Key To see The rest ...";
	 getch();
	 clrscr();
      }

      return ;
   }
   //for black
   *(s+step) = 'B';
   GoBack(s, step + 1, n);

   // for white
   if(EndsWithTwoW(s, step))
      return ;
   *(s + step) = 'W';
   GoBack(s, step + 1, n);
}

int EndsWithTwoW(char *s, int step)
{
   if(step < 2)
      return 0;
   if(*(s + step - 1)=='W' && *(s + step - 2) == 'W')
      return 1;
   return 0;
}
