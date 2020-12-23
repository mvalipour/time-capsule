Program Project;
Uses Crt;
Type
    Uni    = 1..140;
    Year   = 1..4;
    st10 = string[10];
    STD = Record
           Code    : String[6];
           Name    : String[8];
           Fam     : St10;
           Rcode   : Byte;
           Grade   : year;
           Punit   : uni;
           Bunit   : uni;
           SFTerm  : Byte;
           TFTerm  : Byte;
          End;{end of record;}
Var
   ft,fterm : Text;
   choice,ch   : Byte;

Procedure Swop(var a,b : STD);
Var t : STD;
Begin
t:=a;
a:=b;
b:=t;
End;

Procedure Deblank(var s : st10);
var i,l,k:integer;

Begin
i:=1;
l:=Length(s);

for i:=1 to l do
 if s[i]<>' ' Then
   begin
   k:=i-1;
   break;
   end;

delete(s,1,k)

End;

Procedure Reg(var f: Text);
Var
   temp,t : STD;
   found : Boolean;
Begin
ClrScr;
found :=false;
Reset(f);
   {getting information}
Write('Enter the code : ');   ReadLn(t.code);
Write('Enter the Name : ');   ReadLn(t.Name);
Write('Enter the Family : ');   ReadLn(t.fam);
Write('Enter the RCode : ');   ReadLn(t.Rcode);
Write('Enter the Grade : ');   ReadLn(t.Grade);
Write('Enter the Passed Unit : ');   ReadLn(t.Punit);
Write('Enter the non-Passed Unit : ');   ReadLn(t.bunit);
Write('Enter the Num. of seri failed term : ');   ReadLn(t.SFterm);
Write('Enter the Num. of total failed term : ');   ReadLn(t.TFterm);
   {*******************}

While Not Eof(f) Do
 Begin
 Read(f,temp.code);
 Read(f,temp.name);
 ReadLn(f,temp.fam);
 ReadLn(f,temp.Rcode);
 ReadLn(f,temp.Grade);
 ReadLn(f,temp.Punit);
 ReadLn(f,temp.Bunit);
 ReadLn(f,temp.SFTerm);
 ReadLn(f,temp.TFTerm);

 If Temp.code=t.code then
    begin
     Found:=true;
     Break;
    End;
 End;


 if found Then
  Begin
  write('This member is already exist');
  Readln;
  End;
Close(F);

If not found Then
 Begin
 Append(f);
 Write(f,t.code:6);
 Write(f,t.name:8);
 WriteLn(f,t.fam:10);
 WriteLn(f,t.Rcode);
 WriteLn(f,t.Grade);
 WriteLn(f,t.Punit);
 WriteLn(f,t.Bunit);
 WriteLn(f,t.SFTerm);
 WriteLn(f,t.TFTerm);

 Close(F);
 End;

End;

Procedure Upgrade(var f: text);
Var
   temp,t  : STD;
   cha : char;
   tem : text;
Begin
Assign(tem,'c:\temp.txt');
Rewrite(tem);
ClrScr;
Reset(f);
   {getting information}
Write('Enter the code : ');   ReadLn(t.code);
Write('Enter the Name : ');   ReadLn(t.Name);
Write('Enter the Family : ');   ReadLn(t.fam);
Write('Enter the RCode : ');   ReadLn(t.Rcode);
Write('Enter the Grade : ');   ReadLn(t.Grade);
Write('Enter the Passed Unit : ');   ReadLn(t.Punit);
Write('Enter the non-Passed Unit : ');   ReadLn(t.bunit);
Write('Enter the Num. of seri failed term : ');   ReadLn(t.SFterm);
Write('Enter the Num. of total failed term : ');   ReadLn(t.TFterm);
   {*******************}

While Not Eof(f) Do
 Begin
 Read(f,temp.code);
 Read(f,temp.name);
 ReadLn(f,temp.fam);
 ReadLn(f,temp.Rcode);
 ReadLn(f,temp.Grade);
 ReadLn(f,temp.Punit);
 ReadLn(f,temp.Bunit);
 ReadLn(f,temp.SFTerm);
 ReadLn(f,temp.TFTerm);

 If Temp.code=t.code then
    begin
    Write(tem,t.code:6);
    Write(tem,t.name:8);
    WriteLn(tem,t.fam:10);
    WriteLn(tem,t.Rcode);
    WriteLn(tem,t.Grade);
    WriteLn(tem,t.Punit);
    WriteLn(tem,t.Bunit);
    WriteLn(tem,t.SFTerm);
    WriteLn(tem,t.TFTerm);
    End
  Else
    Begin
    Write(tem,temp.code:6);
    Write(tem,temp.name:8);
    WriteLn(tem,temp.fam:10);
    WriteLn(tem,temp.Rcode);
    WriteLn(tem,temp.Grade);
    WriteLn(tem,temp.Punit);
    WriteLn(tem,temp.Bunit);
    WriteLn(tem,temp.SFTerm);
    WriteLn(tem,temp.TFTerm);
    End;
 End;
close(f);
close(tem);

Write('Are you sure you want to  save this change ?(Y/N) : ');ReadLn(cha);
if (cha='y')or(cha='Y') Then
 Begin
 Reset(tem);
 Rewrite(f);
 While not Eof(tem)  do
 Begin
 Read(tem,temp.code);
 Read(tem,temp.name);
 ReadLn(tem,temp.fam);
 ReadLn(tem,temp.Rcode);
 ReadLn(tem,temp.Grade);
 ReadLn(tem,temp.Punit);
 ReadLn(tem,temp.Bunit);
 ReadLn(tem,temp.SFTerm);
 ReadLn(tem,temp.TFTerm);

 Write(f,temp.code:6);
 Write(f,temp.name:8);
 WriteLn(f,temp.fam:10);
 WriteLn(f,temp.Rcode);
 WriteLn(f,temp.Grade);
 WriteLn(f,temp.Punit);
 WriteLn(f,temp.Bunit);
 WriteLn(f,temp.SFTerm);
 WriteLn(f,temp.TFTerm);

 End;
 Close(tem);
 Close(f);
 End;

End;

procedure List(var f:text);
var
   student : array[1..100] of STD;
   temp: STD;
   occ,i,j : integer;
   ch,choice : char;
Begin
Reset(f);
occ:=0;
clrscr;
WriteLn('1 : Incriminal');
WriteLn('2 : Decriminal');
Readln(choice);

While Not Eof(f) do
Begin
Inc(occ);
Read(f,temp.code);
Read(f,temp.name);
ReadLn(f,temp.fam);      Deblank(temp.fam);
ReadLn(f,temp.Rcode);
ReadLn(f,temp.Grade);
ReadLn(f,temp.Punit);
ReadLn(f,temp.Bunit);
ReadLn(f,temp.SFTerm);
ReadLn(f,temp.TFTerm);

student[occ]:=temp
End;

ClrScr;
WriteLn('1 : By Std code.');
WriteLn('2 : By Family.');
ReadLn(ch);

Case choice of
'1' :
 For i:=1 to occ-1 do
  For j:=i+1 to occ do
   Case ch of
   '1' : if student[i].code>student[j].code then
        Swop(student[i],student[j]);
   '2' : if student[i].fam>student[j].fam then
        Swop(student[i],student[j]);

   End;{Case}
'2' :
 For i:=1 to occ-1 do
  For j:=i+1 to occ do
   Case ch of
   '1' : if student[i].code<student[j].code then
        Swop(student[i],student[j]);
   '2' : if student[i].fam<student[j].fam then
        Swop(student[i],student[j]);

   End;{Case}

End;{case}
          {PRINTING}
clrscr;
For i:=1 to occ do
Begin
   Write(student[i].code : 10);
   Write(student[i].Fam  : 15);
   WriteLn(student[i].Name : 10);
End;
Readln;
End;

procedure Failors(var f :text);
Var
   temp : STD;
Begin
clrscr;
Reset(f);
While Not Eof(f) do
Begin
 Read(f,temp.code);
 Read(f,temp.name);
 ReadLn(f,temp.fam);
 ReadLn(f,temp.Rcode);
 ReadLn(f,temp.Grade);
 ReadLn(f,temp.Punit);
 ReadLn(f,temp.Bunit);
 ReadLn(f,temp.SFTerm);
 ReadLn(f,temp.TFTerm);

 if temp.tfterm<>0 Then
    WriteLn(temp.name,temp.fam,' failed in ',temp.tfterm,' terms.');
End;

Readln;
End;

Procedure Unitpas(var f:text ; r : Byte);
var
   temp : STD;
Begin
reset(f);
clrscr;
WriteLn('in group ', r ,'=======>');

While Not Eof(f) do
Begin
 Read(f,temp.code);
 Read(f,temp.name);
 ReadLn(f,temp.fam);
 ReadLn(f,temp.Rcode);
 ReadLn(f,temp.Grade);
 ReadLn(f,temp.Punit);
 ReadLn(f,temp.Bunit);
 ReadLn(f,temp.SFTerm);
 ReadLn(f,temp.TFTerm);

 if temp.rcode=r Then
    WriteLn(temp.name,temp.fam,' has been passed ',temp.Punit,' Units.');
End;

Readln;
End;

Procedure Rided(var f:text);
var
   temp : STD;
Begin
reset(f);
clrscr;
While Not Eof(f) do
Begin
 Read(f,temp.code);
 Read(f,temp.name);
 ReadLn(f,temp.fam);
 ReadLn(f,temp.Rcode);
 ReadLn(f,temp.Grade);
 ReadLn(f,temp.Punit);
 ReadLn(f,temp.Bunit);
 ReadLn(f,temp.SFTerm);
 ReadLn(f,temp.TFTerm);

 if temp.tfterm>=4 Then
    WriteLn(temp.name,temp.fam,' is Rided ,He/she is failed 4 times !!.');
 if temp.sfterm>=3 Then
    WriteLn(temp.name,temp.fam,' is Rided ,He/she is failed 3 times constantly !.');

End;

Readln;
End;


Begin
Assign(FT,'c:\total.txt');
Assign(FTerm,'c:\term.txt');
Reset(Ft);
Reset(Fterm);

Repeat
ClrScr;
            {Main Menu}
WriteLn;
WriteLn('1 : Information Entrance.');
WriteLn('2 : Student Information.');
WriteLn('3 : Failed-student Information.');
WriteLn('4 : Passed-Unit Information.');
WriteLn('5 : Rided-Student Information.');
WriteLn;
WriteLn('10: Exit.');
WriteLn('---------------------------------');
Readln(choice);
           {************}
Case Choice of
1 : Begin
     Repeat
      CLrScr;
      WriteLn('1 : Entrey Registration');
      WriteLn('2 : Term Registration');
      WriteLn('3 : Upgrade Registration');
      WriteLn;
      WriteLn('10: Exit');
      ReadLn(ch);
     Until (ch=10) or (ch=1) or (ch=2) or (ch=3);

     Case ch of
      1 : Reg(ft);
      2 : Reg(fterm);
      3 : Upgrade(ft);
     End;{end of Case}
    End;

2 : List(ft);
3 : Failors(ft);
4 : Begin
    Unitpas(ft,17);
    Unitpas(ft,205);
    Unitpas(ft,206);
    End;
5 : Rided(ft);

End;{End of Case }

Until choice=10;

Close(fterm);
End.
