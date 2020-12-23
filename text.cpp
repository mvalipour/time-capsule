#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>

/**** proto types *///
void filesize();
void linenum();
void wordnum();
void NBCnum();
void repchar();
void difW();
void search();
void show();
void linedel();
void repline();
void repword();
int menu();

void main() {
  while(1)
    switch(menu()) {
      case 1 : filesize(); break;
      case 2 : linenum(); break;
      case 3 : wordnum(); break;
      case 4 : NBCnum(); break;
      case 5 : repchar(); break;
      case 6 : difW(); break;
      case 7 : search(); break;
      case 8 : repword(); break;
      case 9 : linedel(); break;
      case 10: repline(); break;
      case 11: show(); break;
      case 88: exit(0); break;
    }
}
//  FUNCTION DECLIRATIONS
int menu(){
  clrscr();
  int a;
  cout << "1.  file size" << endl;
  cout << "2.  line number" << endl;
  cout << "3.  word number" << endl;
  cout << "4.  non-blank charachters" << endl;
  cout << "5.  repeated charachters" << endl;
  cout << "6.  difrent words" << endl;
  cout << "7.  search word" << endl;
  cout << "8.  replace word" << endl;
  cout << "9.  delete line" << endl;
  cout << "10. replace line" << endl;
  cout << "11. show file" << endl;
  cout << "88. Quit" << endl;
  cout << "---------------------------" << endl;
  cout << "enter your choice : "; cin >> a;
  return a;
}

void linenum(){
  clrscr();
  long int i=0;
  char a[255];
  ifstream f("test.txt");
  while(! f.eof()) {
    f.getline(a,255);
    i++;
  }
  f.close();
  cout << "The line num is : " << i;
  getch();
}

void wordnum(){
  clrscr();
  long int i=0;
  char a[101];
  ifstream f("test.txt");
  while(! f.eof()) {
    f >> a;
    i++;
  }
  f.close();
  cout << "The word num is : " << i;
  getch();
}

void NBCnum(){
  clrscr();
  long int i=0;
  char a;
  ifstream f("test.txt");
  while(! f.eof()) {
    f.get(a);
    if((a>=33) && (a<=125))
    i++;
  }
  f.close();
  cout << "The non-blank characters num is : " << i;
  getch();
}

void filesize(){
  clrscr();
  long int i=0;
  char a;
  ifstream f("test.txt");
  while(! f.eof()) {
    f.get(a);
    i++;
  }
  f.close();
  cout << "The file size is : " << i;
  getch();
}

void repchar(){
  clrscr();
  int i[125],j;
  char a;
  for(j=0;j<125;j++) i[j]=0;
  ifstream f("test.txt");
  while(! f.eof()) {
    f.get(a);
    if((a>=33) && (a<=125))
    i[a]++;
  };
  f.close();
  for(a=0;a<125;a++)
  if(i[a]!=0) cout << a << " : " << i[a] << endl;
  getch();
}

void difW(){
  clrscr();
  int i=0,j,occ=0,bool=0;
  char a[31],s[200][31];
  ifstream f("test.txt");

  while(! f.eof()) {
    f >> a;

    bool=0;
    for(j=0;j<occ;j++)
      if(stricmp(a,s[j])==0) bool=1;

    if((bool==0)) {
      i++;
      strcpy(s[occ],a);
      occ++;
    }
  }

  f.close();
  cout << "number of difrent word : " << i;
  getch();
}

void search(){
  clrscr();
  ifstream f("test.txt");
  char s[31],a[31],ch;
  int col=0,line=1;
  cout << "enter the search word" ;
  gets(s);
  clrscr();
  cout << "      result of : " << s << endl;
  cout <<  "----column----------line------" <<endl;;

  f >> a;
  do { f.get(ch); } while(ch==' ');
  f.seekg(-2,ios::cur);
  f.get(ch);
  col+=strlen(a);

  while(! f.eof()){
    if(stricmp(a,s)==0) {
      cout <<  "\t" << col-strlen(a) << "\t\t" << line << endl;
    }
    if(ch=='\n') {
      col=1; line++;
    }
    f >> a;
    do{ f.get(ch); } while((ch==' ')&&(!f.eof()));
    f.seekg(-2,ios::cur);
    f.get(ch);
    col+=strlen(a);
  }

  f.close();
  getch();
}

void show() {
  clrscr();
  char ch;
  ifstream f("test.txt");
  f.get(ch);
  while(!f.eof()) {
    cout << ch;
    f.get(ch);
  }
  f.close();
  getch();
}

void linedel(){
  clrscr();
  char a[256];
  char path[31];
  int del,ln=0;
  int choice;
  ifstream f("test.txt");
  ofstream t("temp.txt");
  cout << "enter the line you want to delete : ";
  cin >> del;

  f.getline(a,255,'\n'); ln++;
  while(!f.eof()) {
    if(ln!=del)
    t << a << endl;
    f.getline(a,255,'\n'); ln++;
  }
  if(ln!=del)
    t << a;

  f.close();
  t.close();
  // SAVING
  getch();
  clrscr();
  cout << "1. save" << endl;
  cout << "2. save as" << endl;
  cout << "another to exit" << endl;
  cout << "enter your choice  : ";
  cin >> choice;

  switch (choice) {
    case 1:
      remove("test.txt");
      rename("temp.txt","test.txt");
      break;
    case 2:
      cout << "enter the path : ";
      gets(path);
      rename("temp.txt",path);
      break;
  }
}

void repline(){
  clrscr();
  char a[256];
  char path[31],newc[255];
  int del,ln=0;
  int choice;
  ifstream f("test.txt");
  ofstream t("temp.txt");
  cout << "enter the line you want to replace : ";
  cin >> del;
  cout << "Entyer new content : ";
  gets(newc);
  f.getline(a,255,'\n'); ln++;
  while(!f.eof()) {
    if(ln!=del)
    t << a << endl;
    else
    t << newc << endl;

    f.getline(a,255,'\n'); ln++;
  }
  if(ln!=del)
  t << a;
  else
  t << newc;

  f.close();
  t.close();
  //  SAVING
  getch();
  clrscr();
  cout << "1. save" << endl;
  cout << "2. save as" << endl;
  cout << "another to exit" << endl;
  cout << "enter your choice  : ";
  cin >> choice;

  switch (choice){
    case 1:
      remove("test.txt");
      rename("temp.txt","test.txt");
      break;

    case 2:
      cout << "enter the path : ";
      gets(path);
      rename("temp.txt",path);
      break;
  }
}

void repword(){
  clrscr();
  char a[31],ch;
  char path[31],newc[31],oldw[31];
  int choice;
  ifstream f("test.txt");
  ofstream t("temp.txt");
  cout << "enter the word you want to replace : " ;
  gets(oldw);
  cout << "Entyer new word : " ;
  gets(newc);
  f >> a;
  do{ f.get(ch); }while(ch==' ');
  f.seekg(-2,ios::cur);
  f.get(ch);
  while(!f.eof()) {
    if(stricmp(oldw,a)!=0)
    t << a << ch;
    else
    t << newc << ch;
    f >> a;
    do{ f.get(ch); } while(ch==' ');
    f.seekg(-2,ios::cur);
    f.get(ch);
  }
  if(stricmp(oldw,a)!=0)
  t << a;
  else
  t << newc;

  f.close();
  t.close();
  // SAVING
  getch();
  clrscr();
  cout << "1. save" << endl;
  cout << "2. save as" << endl;
  cout << "another to exit" << endl;
  cout << "enter your choice  : ";
  cin >> choice;

  switch (choice) {
    case 1:
      remove("test.txt");
      rename("temp.txt","test.txt");
      break;
    case 2:
      cout << "enter the path : ";
      gets(path);
      rename("temp.txt",path);
      break;
  }
}
