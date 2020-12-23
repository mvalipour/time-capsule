#include <stdio.h>
#include <conio.h>

int Minp(int a)
{
   return (a%2==0)?1:-1;
}
float Determinane(float arr[10][10], int n);
void main(){

  float arr[10][10];

  while(1)
  {
     clrscr();
     // reading dimention
     int n = 11;
     while(n > 10)
     {
	printf("Please enter dimention of matrix: ");
	scanf("%d", &n);
	fflush(stdin);
     }

     // reading matrix
     printf("Enter the matrix bellow (seprate each cell by space)\n");
     for(int i = 0 ; i < n ; i++)
     {
	printf("row %d: ", i+1);
	for(int j = 0 ; j< n;j++)
	{
	   scanf("%f",&arr[i][j]);
	}
     }
     // compute the deteminane
     printf("\nDeterminane of your matrix is : %f\n" ,Determinane(arr, n));
     // asking for try again
     char ch =0;
     printf("Do you want to try again? (y/n): ");
     ch = getch();
     if(ch != 'y' && ch!='Y')
	break;
  }
}

float Determinane(float arr[10][10], int m){

    if(m==2)
      {float dr = arr[0][0]*arr[1][1] - arr[0][1]*arr[1][0];
      return dr;}
    float d= 0.0;
    int b = 0, x = 0, y = 0;
    float narr[10][10];

    for(int a = 0 ; a < m ; a++)
    {
       x = 0; y = -1;
       for(int i = 0 ; i< m ; i++)
       {
	  for(int j =0 ; j< m ; j++)
	  {
	     if(i==b || j==a)
		continue;
	     y++;
	     if(y == m-1){ y = 0 ; x ++;}
	     narr[x][y] = arr[i][j];
	  }
       }
       d += Minp(a+b)*arr[b][a] * Determinane(narr, m-1);
    }
    return d;
}
