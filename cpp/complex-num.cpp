#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream.h>

float sqr(float);

class Complex
{
   float a;
   float b;
 public :
   Complex();
   void Get();
   float Length();
   Complex Reverse();
   Complex Add(Complex num);
   Complex Mines(Complex num);
   Complex Mult(Complex num);
   Complex Div(Complex num);
   void Print();
}

Complex::Complex()
{
   a = 0;
   b = 0;
}
void Complex::Get()
{
   cout << "Enter the real part : ";
   cin >> a;
   cout << "Enter the image part : ";
   cin >> b;
}
float Complex::Length()
{
   return sqrt(sqr(a) + sqr(b));
}

Complex Complex::Reverse()
{
   Complex res;
   res.a = a;
   res.b = -1 * b;
   return res;
}
Complex Complex::Add(Complex num)
{
   Complex res;
   res.a = a + num.a;
   res.b = b + num.b;
   return res;
}
Complex Complex::Mines(Complex num)
{
   Complex res;
   res.a = a - num.a;
   res.b = b - num.b;
   return res;
}
Complex Complex::Mult(Complex num)
{
   Complex res;
   res.a = (a*num.a) - (b*num.b);
   res.b = (a*num.b) + (num.a*b);
   return res;
}
Complex Complex::Div(Complex num)
{
   Complex res;
   float s = sqr(num.a) + sqr(num.b);
   Complex mult = Mult(num.Reverse());
   res.a = mult.a / s;
   res.b = mult.b / s;
   return res;
}
void Complex::Print()
{
   cout << a << " +i " << b << endl;
}
float sqr(float a)
{
   return a*a;
}

void main()
{
   Complex num1,num2,num3;
   num1.Get();
   num2.Get();
   num3 = num1.Mult(num2);
   num3.Print();
   getch();
}
