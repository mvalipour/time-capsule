#include <conio.h>
#include <dos.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <graphics.h>
#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
int key[3][3];

void show(int x ,int y){
 bar(220+x*66,140+y*66,284+x*66,204+y*66);

 if(key[x][y]!=0){
  setcolor(WHITE);
  line(220+x*66,140+y*66,220+x*66,204+y*66);
  line(220+x*66,140+y*66,284+x*66,140+y*66);
  setcolor(DARKGRAY);
  line(220+x*66,204+y*66,284+x*66,204+y*66);
  line(284+x*66,140+y*66,284+x*66,204+y*66);

  }

 if(key[x][y]==1) outtextxy(250+x*66,170+y*66,"1");
 if(key[x][y]==2) outtextxy(250+x*66,170+y*66,"2");
 if(key[x][y]==3) outtextxy(250+x*66,170+y*66,"3");
 if(key[x][y]==4) outtextxy(250+x*66,170+y*66,"4");
 if(key[x][y]==5) outtextxy(250+x*66,170+y*66,"5");
 if(key[x][y]==6) outtextxy(250+x*66,170+y*66,"6");
 if(key[x][y]==7) outtextxy(250+x*66,170+y*66,"7");
 if(key[x][y]==8) outtextxy(250+x*66,170+y*66,"8");
}
//
void main(){
int dr=0,md;
int x=0,y=0,i,j,cur;
char ch;
initgraph(&dr,&md,"c:\\tc\\bgi");
setbkcolor(LIGHTBLUE);
setfillstyle(1,LIGHTGRAY);
bar(217,137,420,340);

for(i=0;i<3;i++)
for(j=0;j<3;j++){
 key[i][j]=i*3 +j;
 show(i,j);
 }

ch=getch();
while(ch!=27)
{
  setfillstyle(1,LIGHTGRAY);
  i=x,j=y;

  if(ch==72) y--; if(y<0) y=0;
  if(ch==80) y++; if(y>2) y=2;
  if(ch==75) x--; if(x<0) x=0;
  if(ch==77) x++; if(x>2) x=2;
  key[i][j]=key[x][y];
  key[x][y]=0;
  show(i,j);
  show(x,y);
  ch=getch();
 }

}
