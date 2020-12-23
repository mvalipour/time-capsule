#include <conio.h>
#include <iostream.h>

#define M 3
#define P 2
#define N 4

struct vectorP
{
   int a[P];
};
struct vectorN
{
   int a[N];
};

void set_mat(int);
vectorP set_vectorP();
vectorN set_vectorN();
void print_res(vectorN []);
int vector_mult(vectorP,vectorP);
void matrix_mult(vectorN [],vectorP [],vectorP []);

vectorP mat1[M],mat2[N];
vectorN res[M];
void main()
{
   clrscr();
   set_mat(M);
   set_mat(N);
   matrix_mult(res,mat1,mat2);
   print_res(res);
   getch();
}
void set_mat(int n)
{
   if(n == M)
   {
     for(int i=0 ; i < M ; i++)
     {
	cout << "enter The row : "<< i+1 << endl;
	mat1[i] = set_vectorP();
     }
     cout << "   this matrix finished !!" << endl;
   }
   else
   {
     for(int i=0 ; i < N ; i++)
     {
	cout << "enter The column : "<< i+1 << endl;
	mat2[i] = set_vectorP();
     }
     cout << "   this matrix finished !!" << endl;
   }
}
vectorP set_vectorP()
{
   vectorP vect;
   for(int i=0 ; i<P ; i++)
      cin >> vect.a[i];
   return vect;
}
vectorN set_vectorN()
{
   vectorN vect;
   for(int i=0 ; i<N ; i++)
      cin >> vect.a[i];
   return vect;
}
void print_res(vectorN res[])
{
   for(int i=0 ; i<M ; i++)
   {
      for(int j=0 ; j<N ; j++)
	 cout << res[i].a[j] << "  ";
      cout << endl;
   }
}
int vector_mult(vectorP a,vectorP b)
{
  int sum=0;
  for(int i=0 ; i<P ; i++)
     sum +=a.a[i] * b.a[i];
  return sum;
}
void matrix_mult(vectorN res[],vectorP mat1[],vectorP mat2[])
{
   for(int i=0 ; i< M ; i++)
   {
      vectorN temp;
      for(int j=0 ; j<N ; j++)
	 temp.a[j] = vector_mult(mat1[i],mat2[j]);
      res[i] = temp;
   }
}
