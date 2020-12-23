#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream.h>
#include <fstream.h>
#include <string.h>

class dictionary {
 public :
  char address[21];
  int i,j;
  int same,same1;
    // functions
  void online();
  void offline();
  dictionary();
}dic;
///////////////////////
dictionary::dictionary(){
 strcpy(address,"c:\\dic\\ .txt");
 same=0;
 same1=0;
 i=0;
 j=0;
}
///////////////////////
void dictionary::offline(){
 // definiing parameters

 char dicsame[31];
 int bool=0;
 char myword[31],meaning[861],meanbox[861],first,dicword[31];
 char bach;

   // getting the word
 clrscr();
 textcolor(5);
 textbackground(15);
 gotoxy(2,5);
 cout << "Enter the word you want to search :   " ;
 cin >> myword;
 strcat(myword," ");
 address[7]=myword[0];    //searching the address

       // searching the word

ifstream f(address);

if(!f) { cout<< "the file is not found"; getch(); exit(0);}
myword[0]-=32;
  strcpy(meanbox,"");
   while(!f.eof()){
     f.getline(dicword,31,'(');
     f.getline(meanbox,860,'\n');
     f.get(bach);
     if(strcmp(myword,dicword)==0)  bool=1;
     if(bool==0){
     for(i=0;i<strlen(dicword);i++){
     if(myword[i]!=dicword[i])
      break;
      }//end for
     same=i;
  if(same>same1){
    strcpy(meaning,meanbox);
    same1=same;
    strcpy(dicsame,dicword);
     }
  }// end if I
  else
   if(strcmp(dicword,myword)==0)
    cout << dicword << " : " << meanbox << endl;
     else { getch(); break; }
  }// end of file while
f.close();
if(bool==0) cout << dicsame << " : " << meanbox;
getch();
}// end of  offline

//////////////////////////
void dictionary::online(){
ifstream f;

char wordbox[31],dicword[31],meanbox[860],ch;
int bool,occ=0,letch=1;
char bach;

strcpy(wordbox,"");

while(1){
clrscr();
cout << "Enter the word : "<< wordbox ;

if(letch==1) ch=getche();
else letch=1;

if (ch==27)  //ESC code
 break;

if(ch==8){           //backspace code
   i--;
   wordbox[i]='\0';
   i--;
 }


if(ch!=8)
{strcat(wordbox," ");
wordbox[i]=ch;}

address[7]=wordbox[0];
f.close();
f.open(address);

clrscr(); occ=0;
cout << "Enter the word : "<< wordbox << endl << endl;
while(!f.eof()){
f.getline(dicword,31,'(');
f.getline(meanbox,860,'\n');
f.get(bach);

bool=0;

for (j=0;j<strlen(wordbox);j++)
 if(tolower(dicword[j])!=tolower(wordbox[j])){
   bool=1;
   break;}


 if(bool==0){
 cout<<wordbox<< " : " <<meanbox << endl;
  occ+=(strlen(wordbox)+strlen(meanbox))/80 +1;   //for u can see every 35 line in each page
  }


 if(occ>=35) { ch=getche();
  if(ch==13) occ=0;
  if (ch!=13){
   letch=0;
   break;   }
   }
 // getch();break;}
 };// end of while file
if(occ<35){
 ch=getch();
 letch=0;  }

i++;
}//end of main while
f.close();
} // end of online
//////////////////////////

void main(){
int code;

while(1){
clrscr();
textcolor(15);
textbackground(1);
cout<<"1:search offline"<<endl;
cout<<"2:search online"<<endl;
cout<<"10:exit"<<endl;
cout<<"enter code  : ";
cin >> code;

switch(code){
case 1:dic.offline();
	break;

case 2:dic.online();
	break;

case 10:exit(0);

}//end of switch
}//end of while
}
