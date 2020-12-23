#include <conio.h>
#include <dir.h>
#include <dos.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <graphics.h>
#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <string.h>


void grwindow(char []);
void dr_drv(char []);
void dr_fold(struct ffblk);
int x=0,y=0;


void main(){
int dr=0,md;
initgraph(&dr,&md,"c:\\tc\\bgi");
char path[61]={""};
char temp[61]={""};
int save, disk, disks, xp=0 ,yp=0 ;
char ch;
struct ffblk ffblk;
char names[3][10][15];
int done,i=0,j;

settextstyle(2,0,4);
while(1){
if(strcmp(path,"")==0){
 grwindow("My computer");
   /* save original drive */
   save = getdisk();
   /* print number of logic drives */
   disks = setdisk(save);
   /* print the drive letters available */
   for (disk = 0;disk < 26;++disk)
   {
      setdisk(disk);
      if (disk == getdisk()){
	strcpy(names[y][x]," :");
	names[y][x][0]=disk + 'a'-32;
	dr_drv(names[y][x]);  y++; if(y>2){ x++; y=0; } if(x==9) break; }
   }
   setdisk(save);
 } //////////////////// END OF MY COMP

else {
   grwindow(path);
   strcpy(temp,path);
   strcat(temp,"\\*.*");
   done = findfirst(temp,&ffblk,FA_DIREC);
   while (!done)
   {
      i++;

      if((strcmp(ffblk.ff_name,".")!=0) && (strcmp(ffblk.ff_name,"..")!=0)) {
       strcpy(names[y][x],ffblk.ff_name);
       dr_fold(ffblk);
       y++; if(y>2){ x++; y=0; } if(x==9) break;
       }
      done = findnext(&ffblk);
   }
 } ////////// END OF PATH

setlinestyle(1,0,1);
setcolor(LIGHTGRAY);
rectangle(45+yp*180,45+xp*45,187+yp*180,87+xp*45);

ch=getch();

while(ch==0){
  ch=getch();
  setlinestyle(0,0,1);
  setcolor(WHITE);
  rectangle(45+yp*180,45+xp*45,187+yp*180,87+xp*45);
  switch(ch){
   case 72 : xp--; if(xp<0)  xp++;break;
   case 80 : xp++; if(xp>x) xp--;break;
   case 77 : yp++; if(yp>2)  yp--;break;
   case 75 : yp--; if(yp<0)  yp++;break;
   } // end of swi.
  setlinestyle(1,0,1);
  setcolor(LIGHTGRAY);
  rectangle(45+yp*180,45+xp*45,187+yp*180,87+xp*45);

  ch=getch();
 }// ens of arrow
if(ch==13) {
 if(strcmp(path,"")!=0)  strcat(path,"\\");
 strcat(path,names[yp][xp]);
 xp=yp=0;
 }
if(ch==27) break;
if(ch==8) { for(j=strlen(path);j>0;j--)
		if(path[j]=='\\'){
		 path[j]='\0'; break; }
	   if(j==0) strcpy(path,"");
	   }
x=0;
y=0;
setlinestyle(0,0,1);
} // end of while

}
//
void grwindow(char s[]){
 setfillstyle(1,LIGHTGRAY);
 bar(5,5,635,475);
 setfillstyle(1,LIGHTBLUE);
 bar(8,8,632,22);
 setfillstyle(1,WHITE);
 bar(8,25,632,472);
 setcolor(BLACK);
 line(8,25,632,25);
 line(8,25,8,472);
 line(635,5,635,475);
 line(629,10,629,19);
 line(620,19,629,19);
 line(5,475,635,475);
 setcolor(WHITE);
 outtextxy(13,9,s);
 outtextxy(623,9,"X");
 line(620,10,620,19);
 line(620,10,629,10);

 line(5,5,635,5);
 line(5,5,5,475);

}                  // GRAPHIC WINDOW
//^^^^^
void dr_drv(char dr[]){

setfillstyle(1,LIGHTGRAY);
bar(52+y*180,52+x*45,82+y*180,82+x*45);
setfillstyle(1,DARKGRAY);
bar(51+y*180,51+x*45,81+y*180,81+x*45);
setfillstyle(1,LIGHTRED);
bar(50+y*180,50+x*45,80+y*180,80+x*45);

setcolor(BLACK);
outtextxy(85+y*180,60+x*45, dr);
setcolor(RED);
outtextxy(52+y*180,53+x*45,"Disk");
outtextxy(52+y*180,63+x*45,"Drive");

}
//////////
void dr_fold(struct ffblk f){
char s[25];

setfillstyle(1,LIGHTGRAY);
bar(52+y*180,52+x*45,82+y*180,82+x*45);
setfillstyle(1,DARKGRAY);
bar(51+y*180,51+x*45,81+y*180,81+x*45);


int a=strlen(f.ff_name);
if(f.ff_name[a-4]=='.'){
 setfillstyle(1,BLUE);
 bar(50+y*180,50+x*45,80+y*180,80+x*45);
 setcolor(LIGHTBLUE);
 outtextxy(57+y*180,58+x*45,"Data");
 }
else{
setfillstyle(1,YELLOW);
bar(50+y*180,50+x*45,80+y*180,80+x*45);}

setcolor(BLACK);
outtextxy(85+y*180,58+x*45, f.ff_name);
if((f.ff_fsize > 0)&& (f.ff_fsize < 1000)){
 setcolor(LIGHTGRAY);
 ltoa(f.ff_fsize,s,10);
 strcat(s," Bytes");
 outtextxy(85+y*180,68+x*45,s);
 }
if((f.ff_fsize > 1000) && (f.ff_fsize < 1000000)){
 setcolor(LIGHTGRAY);
 ltoa(f.ff_fsize/1000,s,10);
 strcat(s," KBs");
 outtextxy(85+y*180,68+x*45,s);
 }
if(f.ff_fsize > 1000000){
 setcolor(LIGHTGRAY);
 ltoa(f.ff_fsize/1000000,s,10);
 strcat(s," MBs");
 outtextxy(85+y*180,68+x*45,s);
 }

}
