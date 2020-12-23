#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream.h>
#include <graphics.h>

#define  sx  50
#define  sy  50
#define  det 8
#define  true 1
#define  false 0

main(){
  int dot[sx][sy];
  int dir,x,y,i,j,tno,px,py;
  int driver,mode;

  randomize();
  driver=DETECT;
  mode=0;
  initgraph(&driver,&mode,"c:\\tc\\bgi");

  for(i=0;i<sx;i++)
    for(j=0;j<sy;j++)
      dot[i][j]=false;

  for(i=0;i<sx;i++) {
    dot[i][0]=true;
    dot[i][sx-1]=true;
  }

  for(j=0;j<sy;j++) {
    dot[0][j]=true;
    dot[sy-1][j]=true;
  }

  tno=(sx*2)+((sy-2)*2);

  do{
    do{
      do {
        x=rand() % sx;
        y=rand() % sy;
      } while(dot[x][y]!=true);

      px=x;
      py=y;

      dir=rand() % 4;
      switch (dir){
        case 0: {
          y--;
          if(y<0) y=0;
          break;
        }
        case 1: {
          x++;
          if(x>sx-1) x=sx-1;
          break;
        }
        case 2: {
          y++;
          if(y>sy-1) y=sy-1;
          break;
        }
        case 3: {
          x--;
          if(x<0) x=0;
          break;
        }
      }//end of switch
    } while(dot[x][y]==true);

    line(10+(px-1)*det,10+(py-1)*det,10+(x-1)*det,10+(y-1)*det);
    dot[x][y]=true;
    tno++;
  } while(tno<sx*sy);

  rectangle(10-det,10-det,(sx-1)*det+2,(sy-1)*det+2);
  getch();
  return 0;
}
