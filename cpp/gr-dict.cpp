#include <conio.h>
#include <dos.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <graphics.h>
#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <string.h>

#define menunum 6

int occ,ocp;

void wordbox(char[]);
void print(int *,int,char[],int);
void selbox(int,int);
void onlineprint(long);
void grwindow(char[]);
void textbox(int,int,char []);
void clearpage();
void printresults();
int getofflinestring(int* ,char []);
char character(int);
int getstring(char[]);

class dictionary{
public:
 int msgbox(char[]);
 void beep();
 char adress[21];
 int menu();
 int onlinesearch();
 int offlinesearch();
 int wordadd();
 int deleteword();
 void about();
 dictionary();
}dic;
//
struct key{
 char name[21];
 long num;
}sosk[61];


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void main(){
int dr=VGA,md=VGAHI;
initgraph(&dr,&md,"c:\\tc\\bgi");
while(1){
 switch(dic.menu()){
 case 0 : dic.onlinesearch();break;
 case 1 : dic.offlinesearch(); break;
 case 2 : dic.wordadd(); break;
 case 3 : dic.deleteword(); break;
 case 4 : dic.about();break;
 case 5:  exit(0);break;
 };// end switch*/
};// end while
}                 //  MAIN
////////////////////////////////

char character(int a){
 char ch;
 while(1){
 ch=getch();
 if( ((ch==0)||(ch==13)) &&(a==1)) return ch;
 if( ((ch==0)||(ch==13)) &&(a==0)) ch=getch();
 else
  if((isalpha(ch))||(ch==27)||(ch==8)||(ch=='+')) return ch;
 }
}                    // CHARACTER
// 
void onlineprint(long n){
char a[21];
int x=occ,y=ocp;
char ch,mean[850];
int ln=0;
ifstream f(dic.adress);
clearpage();

f.seekg(n);
f.getline(a,31,')');
strcat(a,")");
f.getline(mean,860,'\n');
f.get(ch);
occ=1;ocp=0;
wordbox(a);
print(&ln,3,mean,25);
dic.beep();
getch();
occ=x;ocp=y;
}                       // ONLINE PRINT
//+++++++++++++++++++++++++++++++++++++
void selbox(int x, int y){
int i,j;
setcolor(WHITE);
for(j=0;j<60;j++)
 for(i=0;i<4;i++)
 outtextxy(32+i+((j/20)*175),35+((j%20+1)*18),">");
setcolor(LIGHTMAGENTA);
for(i=0;i<4;i++)
 outtextxy(32+i+((y)*175),35+((x)*18),">");

}                     // SELBOX
//---------------------------------
void wordbox(char a[]){
setfillstyle(1,LIGHTGRAY);
bar(42+(ocp*175),37+(occ*18),172+(ocp*175),50+(occ*18));
setfillstyle(1,LIGHTBLUE);
bar(40+(ocp*175),35+(occ*18),170+(ocp*175),48+(occ*18));
setcolor(WHITE);
outtextxy(43+(ocp*175),36+(occ*18),a);
}                     // WORDBOX
//%%%%%%%%%%%%%%%%%%%%%%%%%%%
void print(int *ln,int t,char mean[],int lim){
char kert[31],bink[101];
int q=0,j=0,lne=*ln;
setcolor(WHITE);
if((occ+(strlen(mean)/100))<lim){
    setfillstyle(1,DARKGRAY);
    bar(42,27+(t*15),632,37+((t+(strlen(mean)/100))*15));
    setfillstyle(1,CYAN);
    bar(40,25+(t*15),630,35+((t+(strlen(mean)/100))*15));
    strcpy(kert,"");                      // *** PRINTING LINE BY LINE
    q=0;
     while(1) { // I
     strcpy(bink,""); strcat(bink,kert);
      while(1){  //II
      strcpy(kert," ");j=0;
       while(mean[q]!=' '){
	if(q>=strlen(mean))break; // III
	kert[j]=mean[q]; q++;j++;strcat(kert," ");}// III
	     q++;
	     if(strlen(bink)+j<100) {strcat(bink,kert);} else break;
	     } // II
     outtextxy(43,23+(t+lne)*15,bink);
     lne++;
      if(q>=strlen(mean))break;};//end while I        // ** END OF PRINT
     if(strcmp(kert," ")!=0) outtextxy(43,23+(t+lne)*15,kert);
     }// end if
*ln=lne;
}                      // PRINT
//////////////////////////
int dictionary::offlinesearch(){
 ifstream f;
 int i=0,ln=0,oldsame=0,newsame=0,k=0,bool=0,nextpage=0;
 char ch,sword[31],a[31],mean[861],kert[31],bink[87];
 char sameword[31],samemean[860];
 strcpy(sword,"");
	 /// drawing the main page
 occ=0;
 ocp=0;
 grwindow("::. Offline Search .::");
 textbox(30,30,"Enter The address : ");
 if(getofflinestring(&i,sword)==-1) return 0;
			/// rest
strcat(sword," ");
 if(strcmp(sword," ")!=0) adress[7]=sword[0];
 f.open(adress);
 while(!f.eof()){
  ln=0;
  if(nextpage==1) { setfillstyle(1,YELLOW);  bar(1,32,640,419); nextpage=0;}
  f.getline(a,31,'(');
  f.getline(mean,860,'\n');
  f.get(ch);
  if(stricmp(a,sword)==0){          // COMPELETLY SAME
  bool=1;
  setfillstyle(1,LIGHTCYAN);             // print
  setcolor(56);

  occ++;
  wordbox(a);
  setfillstyle(1,CYAN);
  setcolor(15);
  if(strlen(mean)<86){
   bar(140,25+(occ*15),638,35+(occ*15));
   outtextxy(143,23+occ*15,mean);
   }
  if(strlen(mean)>=86){
  print(&ln,occ,mean,20);
  occ+=strlen(mean)/86;
   }

  if(occ>=25)  {ocp++; occ=0;
		if(ocp>4){
		 ch=getch();
		 if(ch==13) { occ=0; nextpage=1; }
		 else break;}
		}
  } // end of complete same
 else{
 if(bool==0){                             // NOT SAME
  for(k=0;k<strlen(sword);k++)
    if(tolower(sword[k])!=tolower(a[k])) { newsame=k; break; }
   if(newsame>=oldsame){
    strcpy(sameword,a);
    strcpy(samemean,mean);
    oldsame=newsame;
    }
  }} // end of not same
 }; // end while file
 if(bool==0){  // printing the samest word
    occ++;
    wordbox(sameword);
    setfillstyle(1,CYAN);
    setcolor(15);

   if(strlen(samemean)<86){
   bar(140,40,638,50);
   outtextxy(143,38,samemean);
   }
  if(strlen(samemean)>=86){
  occ=1;
  print(&ln,occ,samemean,20);
  }// end if
 }

 if(occ<25) getch();
 f.close();
}                    // OFFLINESEARCH
////////////////////
dictionary::dictionary(){
 strcpy(adress,"c:\\dic\\a.txt");
}
////////////////
int dictionary::onlinesearch(){
	  /// declating the parameters
 ifstream f;
 int j=0,i=0,b=1,k;
 int v,sel=1,full=0;
 long fpointer;
 int nextpage=0,letch=1;
 char ch='a',se[21],a[21],ext[860],bach,bink[87],kert[31];

	 /// drawing the main page
 occ=0;
 ocp=0;

/* outtextxy(30,465,"ESC");
 outtextxy(30,420,"Arrow Keys");
 outtextxy(30,435,"Plus '+'");
 outtextxy(30,450,"Enter");
 setcolor(RED);
 outtextxy(100,465,"Exit Online Search");
 outtextxy(100,420,"Move Througth Words");
 outtextxy(100,435,"Next Page");
 outtextxy(100,450,"View Meaning");*/
 grwindow("::. Online Search .::");
 textbox(30,30,"Enter The Word : ");

	    ///******* MAIN BODY

strcpy(se,"");
while(1){
 if((letch==1)&&(strlen(se)<30)) ch=character(0);
 else         letch=1;
 i++;
 if(ch==27) break;                // user press ESC to exit
 if((ch==8)&&(i>1))  {se[i-2]='\0';i-=2;}  // user press BSPC
 else{
      // user pressed any key
   strcat(se," ");
   se[i-1]=ch;  }

 clearpage();
 textbox(30,30,"Enter The Word : ");
 outtextxy(162,32,se);
 occ=0;
 nextpage=0;
 if((i==1)&&(ch!=8)) adress[7]=ch;    // select the specified file
 f.close();  f.open(adress);
 ocp=0;
	      /// searching in curent file
 while(! f.eof()){
 full=0;
 if(nextpage==1)
  {
  clearpage();
  nextpage=0;
  }

 if(strcmp(se,"")==0)
  break;
 fpointer=f.tellg();
 strcpy(a,"");
 f.getline(a,21,')');
 f.get(bach);
 strcpy(ext,"");
 strcat(a,")");
 f.getline(ext,860,'\n');
 f.get(bach); // for ignoring next empty line
 b=1;

  for(j=0;j<strlen(se);j++)
   if(tolower(a[j])!=tolower(se[j]))
    {
     b=0;
     break;
    }

  setfillstyle(1,LIGHTCYAN);
  setcolor(56);

  if((strlen(a)>=strlen(se))&&(b==1))
   {
    occ++;
    //wordbox(a);
    strcpy(sosk[ocp*20 + occ].name,a);
    sosk[ocp*20 + occ].num=fpointer;
    }

  if(occ>=20)
  {
   setfillstyle(1,CYAN);
   setcolor(15);
   sel=0;
   ocp++;

   if(ocp>2)
   {
    full=1;
    printresults();
    selbox(1,0);
    ch='+';
    while(ch=='+')
    {
     ch=character(1);
     while(ch==0)
     {
	ch=getch();
	switch(ch)
	{
	 case 72 : sel--; if(((getpixel(42+((sel/20)*175),28+((sel%20+1)*18))==WHITE)||(sel<1))&&(sel%20!=0)) sel++; break;
	 case 80 : sel++; if(((getpixel(42+((sel/20)*175),28+((sel%20+1)*18))==WHITE)||(sel>=60))) sel--; break;
	 case 77 : sel+=20; if((getpixel(42+((sel/20)*175),28+((sel%20+1)*18))==WHITE)||(sel>=60)) sel-=20; break;
	 case 75 : sel-=20; if((getpixel(42+((sel/20)*175),28+((sel%20+1)*18))==WHITE)||(sel<1)) sel+=20; break;
	}// end swi.

	selbox(sel%20 +1,sel/20);
	ch=character(1);
	if(ch==13)
	{
	onlineprint(sosk[sel+1].num);
	clearpage();
	printresults();
	sel=1;
	selbox(1,0);
	ch=character(1);
	}
     }; // end while ch==0


     if(ch=='+')
     {
      nextpage=1;
      occ=0; ocp=0;
      letch=1;
      break;
     }
   };// end while ch==+
  if(ch!='+') { letch=0; break; }
  }// end if ocp>4
  occ=0;
  }// end of occ>35
 }// end of eof

 if((full==0)&&(occ>0)){
  selbox(1,0);
  printresults();
  ch=character(1);
  sel=0;
  while(ch==0){
	ch=getch();
	switch(ch){
	 case 72 : sel--; if(((getpixel(42+((sel/20)*175),28+((sel%20+1)*18))==WHITE)||(sel<1))&&(sel%20!=0)) sel++; break;
	 case 80 : sel++; if(((getpixel(42+((sel/20)*175),28+((sel%20+1)*18))==WHITE)||(sel>=60))) sel--; break;
	 case 77 : sel+=20; if((getpixel(42+((sel/20)*175),28+((sel%20+1)*18))==WHITE)||(sel>=60)) sel-=20; break;
	 case 75 : sel-=20; if((getpixel(42+((sel/20)*175),28+((sel%20+1)*18))==WHITE)||(sel<1)) sel+=20; break;
	 }// end swi.
	selbox(sel%20 +1,sel/20);
	ch=character(1);
	if(ch==13)
	{
	onlineprint(sosk[sel+1].num);
	clearpage();
	printresults();
	sel=1;
	selbox(1,0);
	ch=character(1);
	}
       }; // end while ch==0

 letch=0;
 } // end of if full=0

if((full==0)&&(occ==0)){
 occ=1;
 dic.msgbox("No Matches Found !");
 letch=1;
 }// end of no mathces

};//main while

}
		///  ONLINE SERACH
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int dictionary::deleteword(){
	  /// declating the parameters
 ifstream f;
 ofstream temp("c:\\dic\\temp.txt");
 int j=0,i=0,b=1,k;
 int v,sel=1,full=0;
 long fpointer,tempp;
 unsigned int counter=0;
 struct key sosk[61];
 int nextpage=0,letch=1;
 char ch='a',se[21],a[21],ext[900],bach,bink[87],kert[31];

	 /// drawing the main page
 occ=0;
 ocp=0;

 setfillstyle(1,YELLOW);
 bar(0,0,640,480);
 setcolor(56);
 setlinestyle(0,1,2);
 setfillstyle(1,15);
 bar3d(250,10,630,30,5,1);
 settextstyle(10,0,1.5);
 outtextxy(5,-5,"DELETE WORD");
 settextstyle(2,0,4);
 setfillstyle(1,LIGHTRED);
 bar(0,420,640,480);
 setfillstyle(1,15);
 bar(30,450,40,460);
 outtextxy(32,450,"X   Press ESC to Exit.");

	    ///******* MAIN BODY

strcpy(se,"");
while(1){
 if((letch==1)&&(strlen(se)<30)) ch=getch();
 else         letch=1;
 i++;
 if(ch==27) break;                // user press ESC to exit
 if((ch==8)&&(i>1))  {se[i-2]='\0';i-=2;}  // user press BSPC
 else
  if(isalpha(ch)){    // user pressed any key
   strcat(se," ");
   if(isprint(ch)) se[i-1]=ch;
   }
 setfillstyle(1,YELLOW);
 bar(1,35,640,419);
 setfillstyle(1,15);
 setcolor(56);
 bar3d(250,10,630,30,5,1);
 outtextxy(255,15,se);
 occ=0;
 nextpage=0;
 if((i==1)&&(ch!=8)) adress[7]=ch;    // select the specified file
 f.close();  f.open(adress);
 counter=0;
 ocp=0;
	      /// searching in curent file
 while(! f.eof()){
 full=0;
 counter++;
 if(nextpage==1)
  {
  setfillstyle(1,YELLOW);
  bar(1,32,640,419);
  nextpage=0;
  }

 if(strcmp(se,"")==0)
  break;
 strcpy(a,"");
 fpointer=f.tellg();
 f.getline(a,21,')');
 f.get(bach);
 strcpy(ext,"");
 strcat(a,")");
 f.getline(ext,860,'\n');
 f.get(bach); // for ignoring next empty line
 b=1;

  for(j=0;j<strlen(se);j++)
   if(tolower(a[j])!=tolower(se[j]))
    {
     b=0;
     break;
    }

  setfillstyle(1,LIGHTCYAN);
  setcolor(56);

  if((strlen(a)>=strlen(se))&&(b==1))
   {
    occ++;
    wordbox(a);
    sosk[ocp*20 + occ].num=fpointer;
    }

  if(occ>=20)
  {
   setfillstyle(1,CYAN);
   setcolor(15);
   sel=0;
   ocp++;

   if(ocp>2)
   {
    full=1;
    selbox(1,0);
    ch='+';
    while(ch=='+')
    {
     ch=getch();
     while(ch==0)
     {
	ch=getch();
	switch(ch)
	{
	 case 72 : sel--; if(((getpixel(42+((sel/20)*175),28+((sel%20+1)*18))==YELLOW)||(sel<1))&&(sel%20!=0)) sel++; break;
	 case 80 : sel++; if(((getpixel(42+((sel/20)*175),28+((sel%20+1)*18))==YELLOW)||(sel>=60))) sel--; break;
	 case 77 : sel+=20; if((getpixel(42+((sel/20)*175),28+((sel%20+1)*18))==YELLOW)||(sel>=60)) sel-=20; break;
	 case 75 : sel-=20; if((getpixel(42+((sel/20)*175),28+((sel%20+1)*18))==YELLOW)||(sel<1)) sel+=20; break;
	}// end swi.

	selbox(sel%20 +1,sel/20);
	ch=getch();
     }; // end while ch==0

     if(ch==13)
     {
      dic.msgbox("ARE YOU SURE ?(y/n)");
      ch=getch();
      if((ch=='y')&&(ch=='Y')){
      f.close();
      f.open(adress);
      while(! f.eof())
       {
	tempp=f.tellg();
	f.getline(ext,900,'\n');
	f.get(bach);

	if(tempp!=sosk[sel+1].num)
	 temp << ext << endl << endl;
       }
      temp.close();
      dic.msgbox("Deleting Successful !");
      getch();
      return 0;
     }}// end of ch==13
     if(ch=='+')
     {
      nextpage=1;
      occ=0; ocp=0;
      letch=1;
      break;

     }
   };// end while ch==+
  if(ch!='+') { letch=0; break; }
  }// end if ocp>4
  occ=0;
  }// end of occ>20
 }// end of eof
 if(full==0){
  selbox(1,0);
  ch=getch();
  sel=1;
  while(ch==0){
	ch=getch();
	switch(ch){
	 case 72 : sel--; if(((getpixel(42+((sel/20)*175),28+((sel%20+1)*18))==YELLOW)||(sel<1))&&(sel%20!=0)) sel++; break;
	 case 80 : sel++; if(((getpixel(42+((sel/20)*175),28+((sel%20+1)*18))==YELLOW)||(sel>=60))) sel--; break;
	 case 77 : sel+=20; if((getpixel(42+((sel/20)*175),28+((sel%20+1)*18))==YELLOW)||(sel>=60)) sel-=20; break;
	 case 75 : sel-=20; if((getpixel(42+((sel/20)*175),28+((sel%20+1)*18))==YELLOW)||(sel<1)) sel+=20; break;
	 }// end swi.
	selbox(sel%20 +1,sel/20);
	ch=getch();
       }; // end while ch==0

    if(ch==13)
     {
      f.close();
      f.open(adress);
      while(! f.eof())
       {
	tempp=f.tellg();
	f.getline(ext,861,'\n');
	f.get(bach);

	if(tempp!=sosk[sel+1].num)
	 temp << ext << endl << endl;

       }
      temp.close();
      return 0;
     }

 letch=0;
 } // end of if full=0
//} // end of eof
};//main while

}
			// DELET WORD
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int dictionary::menu(){

		 /// declerating the parameters
 char ch ,men[menunum][31];
 int  occ=0,i,col[menunum];
 strcpy(men[0],"  Online Search ");
 strcpy(men[1]," Offline Search ");
 strcpy(men[2],"  Add new word  ");
 strcpy(men[3],"   Delete word  ");
 strcpy(men[4],"     About      ");
 strcpy(men[5],"      Quit      ");
 for(i=1;i<menunum;i++) col[i]=LIGHTBLUE;

	 /// draWING THE MAIN PAGE

setfillstyle(1,YELLOW);
bar(1,1,640,480);
setcolor(BROWN);
setfillstyle(1,LIGHTRED);
fillellipse(-20,240,100,350);
settextstyle(7,1,7);
outtextxy(-10,20,"w e l c o m e");
settextstyle(10,0,4);
outtextxy(100,0,"D I C T I O N A R Y");
settextstyle(2,0,4);
setcolor(56);
outtextxy(100,7,"G    R    A    P    H    I    C    A    L        V    E    R    S    I    O    N");
settextstyle(7,0,2);
setcolor(15);
col[0]=BLACK;
			   //** SHODOW
setfillstyle(1,LIGHTGRAY);
for(i=0;i<menunum;i++) bar(173,103+i*45,403,138+i*45);

			 // PRIMARY MENU
for(i=0;i<menunum;i++){
 setfillstyle(1,col[i]);
 bar(170,100+i*45,400,135+i*45);
 outtextxy(175,105+i*45,men[i]);
 }
			//  LOOPED MENU
while(1){
for(i=0;i<menunum;i++) col[i]=LIGHTBLUE;
ch=getch();
switch(ch){
  case 72 /*up*/ : occ--; if(occ<0)occ=menunum-1;break;
  case 80 /*dn*/ : occ++; if(occ>menunum-1)occ=0;break;
  case 13        : return occ;
  }// end switch

col[occ]=BLACK;
for(i=0;i<menunum;i++){
 setfillstyle(1,col[i]);
 bar(170,100+i*45,400,135+i*45);
 outtextxy(175,105+i*45,men[i]);
 }
}// end while
//return occ;
}                         // MENU
//////////////////////////
int dictionary::wordadd(){
char userword[30]={""},usermean[861]={""};
char dword[31],dmean[861],adrs[30],bach,abre[10]={""};
char  sel,ch=0;

ifstream f;
ofstream temp;

 setfillstyle(1,YELLOW);
 bar(0,0,640,480);
 setcolor(56);
 setlinestyle(0,1,2);
 setfillstyle(1,15);
 bar3d(250,10,630,30,3,1);
 settextstyle(10,0,1.5);
 outtextxy(5,-5,"ADD WORD");
 settextstyle(2,0,4);
 setfillstyle(1,LIGHTRED);
 bar(0,420,640,480);
 setfillstyle(1,15);
 bar(30,450,40,460);
 outtextxy(32,450,"X   Press ESC to Exit.");


if(getstring(userword)==-1)
 return 0;
strcat(userword," ");
adress[7]=userword[0];

if(getstring(usermean)==-1) return 0;

if(getstring(abre)==-1) return 0;
if((strcmp(userword,"")==0)||(strcmp(usermean,"")==0)){
 getch();
 return 0;
 }

f.close();
f.open(adress);

strcpy(dword,"");
strcpy(dmean,"");

temp.open("temp.txt");

while(!f.eof()){
f.getline(dword,30,'(');
f.getline(dmean,860,'\n');
f.get(bach);

if(stricmp(userword,dword)>0){
temp<<dword;
temp<<"(";
temp<<dmean;
temp.put(13);
temp.put(bach);
 }
 else{
   temp<<userword;
   temp<<"(";
   temp<<abre;
   temp<<") ";
   temp<<usermean;
   temp.put(13);
   temp.put(bach);
   break;}
}//end of while

temp<<dword;
temp<<"(";
temp<<dmean;
temp.put(13);
temp.put(bach);

while (!f.eof()){
f.getline(dword,30,'(');
f.getline(dmean,860,'\n');
f.get(bach);

temp<<dword;
temp<<"(";
temp<<dmean;
temp.put(13);
temp.put(bach);
}

temp.close();
f.close();
ch=getch();

if((ch=='y')||(ch=='Y')){
	remove(adress);
	rename("temprory.txt",adress);
	getch();
	return 0;

      }
 f.close();
 }//end of addword           // WORD ADD
///////////////////////////

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void dictionary::about(){
setfillstyle(1,YELLOW);
bar(0,0,640,480);
setcolor(RED);
setlinestyle(0,0,THICK_WIDTH);

		     /// ARM
line(300,10,300,110);
line(340,10,340,110);
line(270,30,270,160);
line(370,30,370,160);
line(240,50,240,120);
line(400,50,400,120);
line(240,120,300,120);
line(400,120,340,120);
line(300,120,320,140);
line(340,120,320,140);
line(270,160,320,120);
line(370,160,320,120);
line(300,10,320,20);
line(340,10,320,20);

arc(270,110,53,90,80);
arc(370,110,90,128,80);
arc(240,170,48,90,120);
arc(400,170,90,132,120);


settextstyle(6,0,6);
outtextxy(80,145,"KHARAZMY UNIVERSITY");
settextstyle(7,0,3);
outtextxy(60,250,"Programmer : Mohammad valipour");
settextstyle(7,0,2);
outtextxy(60,300,"Copy right   March.2005");
getch();
}                            // ABOUT
/////////////
int getstring(char s[]){
char ch;
ch=character(1);
strcpy(s,"");
int i=0;
if(ch==27) return -1;
if(ch==13) return 0;

while(1){
 strcat(s," ");
 if((ch==8)&&(i>0))
  s[i]='\0';
 else if(ch!=0){
  s[i]=ch;
  cout << ch;
  i++;
  }
ch=character(1);
if((ch==27)||(ch==13)) break;
}// end of while
if(ch==27) return -1;
}                       // GETSTRING
////////////////////////////
int dictionary::msgbox(char s[]){
setfillstyle(1,LIGHTGRAY);
bar(300-4*strlen(s),220,340+4*strlen(s),260);
bar(303-4*strlen(s),223,343+4*strlen(s),263);
setfillstyle(1,WHITE);
bar(303-4*strlen(s),223,337+4*strlen(s),257);
setcolor(WHITE);
line(300-4*strlen(s),220,300-4*strlen(s),260);
line(300-4*strlen(s),220,340+4*strlen(s),220);
line(337+4*strlen(s),223,337+4*strlen(s),257);
line(303-4*strlen(s),257,337+4*strlen(s),257);
setcolor(BLACK);
outtextxy(330-4*strlen(s),235,s);
line(303-4*strlen(s),223,337+4*strlen(s),223);
line(303-4*strlen(s),223,303-4*strlen(s),257);
line(340+4*strlen(s),220,340+4*strlen(s),260);
line(300-4*strlen(s),260,340+4*strlen(s),260);

dic.beep();
}                        // MESSAGE BOX
///////////////
void dictionary::beep(){
 int i;
 for(i=0;i<3;i++){
  sound(800);
  delay(70);
  nosound();
  delay(70);
  }                        // BEEP
}////
void grwindow(char s[]){
setfillstyle(1,LIGHTGRAY);
settextstyle(2,0,4);
bar(5,5,635,475);
setfillstyle(1,WHITE);
bar(8,20,632,472);
setcolor(BLACK);
outtextxy(10,6,s);
outtextxy(623,7,"X");
line(8,20,632,20);
line(8,20,8,472);
line(635,5,635,475);
line(629,8,629,17);
line(620,17,629,17);
line(5,475,635,475);
setcolor(WHITE);
line(620,8,620,17);
line(620,8,629,8);

line(5,5,635,5);
line(5,5,5,475);

}                  // GRAPHIC WINDOW
//////////////////
void textbox(int x1,int y1, char s[]){
 setfillstyle(1,WHITE);
 bar(x1+130,y1,x1+400,y1+15);
 setcolor(BLUE);
 outtextxy(x1,y1,s);
 rectangle(x1+130,y1,x1+400,y1+15);
}                    // TEXTBOX
/////////////////////
int getofflinestring(int *a,char sword[]){
char ch;
int i=*a;
  ch=getch(); while(ch!=13){  // GET THE WORD
	      if(ch==27) return -1;
	      if(ch==0) getch();
	      if((ch==8)&&(i>=1)) {i--; sword[i]='\0'; }
	      else
	       if((ch>32)&&(ch<127)&&(strlen(sword)<30)) {
		strcat(sword," ");
		sword[i]=ch; i++;
		 }
	      if(strlen(sword)<30){
		textbox(30,30,"Enter The address : ");
		outtextxy(162,32,sword);
	       }
	      ch=getch();
	      }
}                   // GET OFLINE STRING
///////////////
void clearpage(){
setfillstyle(1,WHITE);
bar(10,50,630,420);
}                   // CLEAR PAGE
////////////////
void printresults(){
int a=occ,b=ocp;
int i,j;
for(i=0;i<b;i++)
 for(j=1;j<=a;j++){
  occ=j;
  ocp=i;
  wordbox(sosk[ocp*20 + occ].name);
 }
occ=a;
ocp=b;
}                    // PRINT RESULTS
//////////////////////
