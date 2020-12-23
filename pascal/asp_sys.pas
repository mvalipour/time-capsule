Program AP_System;
Uses CRT;
Type
    Member   = Record
                Memcode : String[10];
                Name    : String[20];
                Fam     : String[30];
                BNum    : String[2];
                Mar     : String[7];
                Salary  : String[8];
                Age     : String[2];
               End;
    Reg      = Record
                memcode : String[10];
                day     : String[2];
                Hour    : String[2];
                Minute  : String[2];
               End;

Var
   Choice : Byte;
   F      : Text;
   memb   : ^member;
(***********************************************)
Function Little(S : String):String;
Var
   i : Integer;
   p : String;
Begin
p:=s;
For  i:=1 to Length(S) Do
 Begin
  If (Ord(p[i])>=65) And (Ord(p[i])<=90) Then
    p[i]:=chr(Ord(p[i])+32);

 End;
Little:=p;
End;

(**************************************************)
(**********************************************************)
Procedure PageLable(lable : string);
Var I : Integer;
Begin

For i:=1 to 80 do
 Write('=');

 Textcolor(128);
 Writeln('                     ',lable);
 Textcolor(10);

For i:=1 to 80 do
 Write('=');

WriteLN;
End;
(************************************************************)
procedure WriteMember(Var F :Text);
Begin
          New(memb);

          Write('Enter Your Code :');           ReadLn(memb^.memcode);
          Write('Enter Your Name :');           ReadLn(memb^.Name);
          Write('Enter Your FamilyName :');     ReadLn(memb^.Fam);
          Write('Enter Your Baby Number :');    ReadLn(memb^.Bnum);
          Write('Enter Your Marriage :');       ReadLn(memb^.mar);
          Write('Enter Your Salary :');         ReadLn(memb^.Salary);
          Write('Enter Your Age :');            ReadLn(memb^.Age);

          Assign(F,'member.txt');
          Append(F);
          Write(F,Memb^.memcode:10,Memb^.Name:20,Memb^.Fam:30,Memb^.BNum:2,Memb^.Mar:7,Memb^.Salary:8,Memb^.Age:2);
          Close(F);
          Dispose(memb);
End;
(*************************************************************)
Procedure ReadMember(Var F : text);
Var
   Memtemp : member;

Begin
Assign(F,'member.txt');
Reset(F);
While Not EOF(F) Do
 Begin
  Clrscr;
  pagelable('  ** VIEW PROPERTIES ** ');

  WriteLn;
  Read(F,memtemp.Memcode);
   WriteLN('       Code        : ',memtemp.memcode:30);
  Read(F,memtemp.Name);
   WriteLN('       Name        : ',memtemp.name:30);
  Read(F,memtemp.Fam);
   WriteLN('       Family Name : ',memtemp.Fam:30);
  Read(F,memtemp.BNum);
   WriteLN('       Baby Number : ',memtemp.BNum:30);
  Read(F,memtemp.Mar);
   WriteLN('       Marriage    : ',memtemp.Mar:30);
  Read(F,memtemp.Salary);
   WriteLN('       Salary      : ',memtemp.Salary:30);
  Read(F,memtemp.Age);
   WriteLN('       Age         : ',memtemp.Age:30);
  Readln;
 End;
Close(F);
End;
(*****************************************************)
Procedure SearchMember(Var F:Text);
Var
   Choice : Byte;
   temp,memtemp : member;
   b        : Boolean;
   i        : integer;
Begin
b:=false;
WriteLn('1) By Code');
WriteLn('2) By Name');
WriteLn('3) By Family Name');
WriteLn('4) By Baby Number');
WriteLn('5) By Marriage');
WriteLn('6) By Salary');
WriteLn('7) By Age');
ReadLN(Choice);
Write('Enter Your Propertie : ');
Case choice of
1:
  begin
  Readln(Temp.memcode);
  for i:=1 to 10-length(temp.memcode) Do temp.memcode:=' '+temp.memcode;
  end;
2:
  begin
  Readln(Temp.name);
  for i:=1 to 20-length(temp.name) Do temp.name:=' '+temp.name;
  end;
3:
  begin
  Readln(Temp.fam);
  for i:=1 to 30-length(temp.fam) Do temp.fam:=' '+temp.fam;
  end;
4:
  begin
  Readln(Temp.bnum);
  for i:=1 to 2-length(temp.bnum) Do temp.bnum:=' '+temp.bnum;
  end;
5:
  begin
  Readln(Temp.mar);
  for i:=1 to 7-length(temp.mar) Do temp.mar:=' '+temp.mar;
  end;
6:
  begin
  Readln(Temp.salary);
  for i:=1 to 8-length(temp.salary) Do temp.salary:=' '+temp.salary;
  end;
7:
  begin
  Readln(Temp.age);
  for i:=1 to 2-length(temp.age) Do temp.age:=' '+temp.age;
  end;
End;{End of the case}
{Searching ...}
Assign(F,'member.txt');
reset(f);
While Not EOF(F) Do
Begin
    Read(F,memtemp.Memcode);
    Read(F,memtemp.Name);
    Read(F,memtemp.Fam);
    Read(F,memtemp.BNum);
    Read(F,memtemp.Mar);
    Read(F,memtemp.Salary);
    Read(F,memtemp.Age);

   Case Choice of
   1 : If (Little(memtemp.Memcode)=little(temp.memcode)) Then   B := True;
   2 : If (Little(memtemp.Name)=little(temp.Name)) Then         B := True;
   3 : If (Little(memtemp.Fam)=little(temp.Fam)) Then           B := True;
   4 : If (Little(memtemp.BNum)=little(temp.BNum)) Then         B := True;
   5 : If (Little(memtemp.Mar)=little(temp.Mar)) Then           B := True;
   6 : If (Little(memtemp.Salary)=little(temp.Salary)) Then     B := True;
   7 : If (Little(memtemp.Age)=little(temp.Age)) Then           B := True;
   End;{End of Case}

   If B=True Then
   Begin
    B :=False;
    ClrScr;
    PageLable('** SEARCH FOR MEMBER BY...**');
    WriteLn;
    WriteLN('       Code        : ',memtemp.memcode:30);
    WriteLN('       Name        : ',memtemp.name:30);
    WriteLN('       Family Name : ',memtemp.Fam:30);
    WriteLN('       Baby Number : ',memtemp.BNum:30);
    WriteLN('       Marriage    : ',memtemp.Mar:30);
    WriteLN('       Salary      : ',memtemp.Salary:30);
    WriteLN('       Age         : ',memtemp.Age:30);
    Readln;
   End;{End of If .}
End;{End of While}

Close(F);
End;
(******************************************)
Procedure DelMember(Var F :text);
Var
   i          : Integer;
   Choice     : String;
   Temp       : Member;
   FO,SA      : Text;
   root       : string[64];
Begin
Reset(F);
   Write('Enter Number of Member That You Want To Delete :');
   Textcolor(red);
   ReadLn(Choice);
   Textcolor(10);
   {********************}
    Assign(FO,'temp.txt');
    Rewrite(FO);
    writeLn;
    While Not Eof(F) Do
    Begin
    Read(F,temp.Memcode);
    Read(F,temp.Name);
    Read(F,temp.Fam);
    Read(F,temp.BNum);
    Read(F,temp.Mar);
    Read(F,temp.Salary);
    Read(F,temp.Age);

    For i:=1 to 10-length(Choice) Do Choice:=' '+Choice;

    If temp.memcode<>Choice Then
       Begin
       Write(Fo,temp.Memcode:10);
       Write(Fo,temp.Name:20);
       Write(Fo,temp.Fam:30);
       Write(Fo,temp.BNum:2);
       Write(Fo,temp.Mar:7);
       Write(Fo,temp.Salary:8);
       Write(Fo,temp.Age:2);
       End;
    End;

    Close(FO);
   {********************}
ReadLn;
 ClrScr;
 PageLable('** Delete Line **');

WriteLn('1 : Save');
WriteLn('2 : Exit');
WriteLn('-----------------');
Case Readkey of
'1' : Begin
      Reset(FO);
      Rewrite(F);

      While not Eof(FO) Do
       Begin
       Read(Fo,temp.Memcode);
       Read(Fo,temp.Name);
       Read(Fo,temp.Fam);
       Read(Fo,temp.BNum);
       Read(Fo,temp.Mar);
       Read(Fo,temp.Salary);
       Read(Fo,temp.Age);
         {***}
       Write(F,temp.Memcode:10);
       Write(F,temp.Name:20);
       Write(F,temp.Fam:30);
       Write(F,temp.BNum:2);
       Write(F,temp.Mar:7);
       Write(F,temp.Salary:8);
       Write(F,temp.Age:2);
       End;

       close(FO);
       close(F);
      End;{End of 1}
End;{End of case}
reset(f);
End;
(***********************************)
Procedure ChangeMem(Var F: Text);
Var
   FO : Text;
   choice : Char;
   i : Integer;
   Temp,tp : Member;

Begin
Assign(Fo,'temp.txt');
Rewrite(Fo);
Reset(F);
Write('1) Name');
Write('1) Family Name');
Write('1) Baby Number');
Write('1) Marage');
Write('1) Salary');
Write('1) Age');
Choice:=Readkey;
Write('Enter Your Propertie : ');
Case choice of
'1':
    begin
    Readln(Temp.name);
    for i:=1 to 20-length(temp.name) Do temp.name:=' '+temp.name;
    end;
'2':
    begin
    Readln(Temp.fam);
    for i:=1 to 30-length(temp.fam) Do temp.fam:=' '+temp.fam;
    end;
'3':
    begin
    Readln(Temp.bnum);
    for i:=1 to 2-length(temp.bnum) Do temp.bnum:=' '+temp.bnum;
    end;
'4':
    begin
    Readln(Temp.mar);
    for i:=1 to 7-length(temp.mar) Do temp.mar:=' '+temp.mar;
    end;
'5':
    begin
    Readln(Temp.salary);
    for i:=1 to 8-length(temp.salary) Do temp.salary:=' '+temp.salary;
    end;
'6':
    begin
    Readln(Temp.age);
    for i:=1 to 2-length(temp.age) Do temp.age:=' '+temp.age;
    end;
End;{End of the case}

Write('Enter Member Code : ');
ReadLn(temp.memcode);
For i:=1 to 10-length(temp.memcode) Do temp.memcode:=' '+temp.memcode;
(********INPUTING*********)
While Not Eof(F) Do
    Begin
    Read(F,tp.Memcode);
    Read(F,tp.Name);
    Read(F,tp.Fam);
    Read(F,tp.BNum);
    Read(F,tp.Mar);
    Read(F,tp.Salary);
    Read(F,tp.Age);

    If tp.memcode<>temp.memcode Then
       Begin
       Write(Fo,tp.Memcode:10);
       Write(Fo,tp.Name:20);
       Write(Fo,tp.Fam:30);
       Write(Fo,tp.BNum:2);
       Write(Fo,tp.Mar:7);
       Write(Fo,tp.Salary:8);
       Write(Fo,tp.Age:2);
       End
    Else
       Case choice of
       '1':Begin
           Write(Fo,tp.Memcode:10);
           Write(Fo,temp.Name:20);
           Write(Fo,tp.Fam:30);
           Write(Fo,tp.BNum:2);
           Write(Fo,tp.Mar:7);
           Write(Fo,tp.Salary:8);
           Write(Fo,tp.Age:2);
           End;
       '2':Begin
           Write(Fo,tp.Memcode:10);
           Write(Fo,tp.Name:20);
           Write(Fo,temp.Fam:30);
           Write(Fo,tp.BNum:2);
           Write(Fo,tp.Mar:7);
           Write(Fo,tp.Salary:8);
           Write(Fo,tp.Age:2);
           End;
       '3':Begin
           Write(Fo,tp.Memcode:10);
           Write(Fo,tp.Name:20);
           Write(Fo,tp.Fam:30);
           Write(Fo,temp.BNum:2);
           Write(Fo,tp.Mar:7);
           Write(Fo,tp.Salary:8);
           Write(Fo,tp.Age:2);
           End;
       '4':Begin
           Write(Fo,tp.Memcode:10);
           Write(Fo,tp.Name:20);
           Write(Fo,tp.Fam:30);
           Write(Fo,tp.BNum:2);
           Write(Fo,temp.Mar:7);
           Write(Fo,tp.Salary:8);
           Write(Fo,tp.Age:2);
           End;
       '5':Begin
           Write(Fo,tp.Memcode:10);
           Write(Fo,tp.Name:20);
           Write(Fo,tp.Fam:30);
           Write(Fo,tp.BNum:2);
           Write(Fo,tp.Mar:7);
           Write(Fo,temp.Salary:8);
           Write(Fo,tp.Age:2);
           End;
       '6':Begin
           Write(Fo,tp.Memcode:10);
           Write(Fo,tp.Name:20);
           Write(Fo,tp.Fam:30);
           Write(Fo,tp.BNum:2);
           Write(Fo,tp.Mar:7);
           Write(Fo,tp.Salary:8);
           Write(Fo,temp.Age:2);
           End;
        End;{End of Case!!}
    Close(Fo);
    End;{end of while !!}


End;
(*************************************)
Procedure Ent(Var F : Text);
Var
  mem             : string[10];
  H,M,d           : String[2];
  Fo              : text;
  TempO           : Reg;
  Temp            : member;
  Found,foundmem  : Boolean;
  i               : Integer;
Begin
found    :=false;
foundmem :=false;
Assign(Fo,'entrance.txt');

Write('Enter The Member Number : ');
ReadLn(mem);
For i:=1 to 10-Length(mem) Do mem:=' '+mem;

Write('Enter The day : ');
ReadLn(d);
For i:=1 to 2-Length(d) Do d:=' '+d;

Write('Enter The Hour : ');
ReadLn(H);
For i:=1 to 2-Length(H) Do mem:=' '+H;

Write('Enter The Minute : ');
ReadLn(m);
For i:=1 to 2-Length(m) Do m:=' '+m;

(********cheching availability********)
Reset(Fo);
While Not Eof(Fo) Do
Begin
 Read(Fo,TempO.memcode);
 Read(Fo,TempO.Day);
 Read(Fo,TempO.Hour);
 Read(Fo,TempO.Minute);
 If (TempO.memcode=Mem)And(TempO.Day=d) Then
    Begin
    Found :=True;
    Write('This Member is already registered !');
    ReadLn;
    End;
End;

Reset(F);
While Not Eof(F) Do
Begin
 Read(F,temp.Memcode);
 Read(F,temp.Name);
 Read(F,temp.Fam);
 Read(F,temp.BNum);
 Read(F,temp.Mar);
 Read(F,temp.Salary);
 Read(F,temp.Age);
 If Temp.memcode=Mem Then
    Foundmem :=True;

End;
if foundmem=false Then
 Begin
 Write('This Member is not Exist !');
 ReadLn;
 End;
(*******************CHECKED******************)
If (Not Found) and foundmem Then
Begin
 Append(Fo);
 Write(Fo,mem);
 Write(Fo,d);
 Write(Fo,h);
 Write(Fo,m);
 Write('The member registered !');
 Readln;
 Close(Fo);
End;

End;
(*************************************)
Procedure Ext(Var F : Text);
Var
  mem             : string[10];
  H,M,d           : String[2];
  Fo              : text;
  TempO           : Reg;
  Temp            : member;
  Found,foundmem  : Boolean;
  i               : Integer;
Begin
found    :=false;
foundmem :=false;
Assign(Fo,'exit.txt');

Write('Enter The Member Number : ');
ReadLn(mem);
For i:=1 to 10-Length(mem) Do mem:=' '+mem;

Write('Enter The day : ');
ReadLn(d);
For i:=1 to 2-Length(d) Do d:=' '+d;

Write('Enter The Hour : ');
ReadLn(H);
For i:=1 to 2-Length(H) Do mem:=' '+H;

Write('Enter The Minute : ');
ReadLn(m);
For i:=1 to 2-Length(m) Do m:=' '+m;

(********cheching availability********)
Reset(Fo);
While Not Eof(Fo) Do
Begin
 Read(Fo,TempO.memcode);
 Read(Fo,TempO.Day);
 Read(Fo,TempO.Hour);
 Read(Fo,TempO.Minute);
 If (TempO.memcode=Mem)And(TempO.Day=d) Then
    Begin
    Found :=True;
    Write('This Member is already registered !');
    ReadLn;
    Break;
    End;
End;

Reset(F);
While Not Eof(F) Do
Begin
 Read(F,temp.Memcode);
 Read(F,temp.Name);
 Read(F,temp.Fam);
 Read(F,temp.BNum);
 Read(F,temp.Mar);
 Read(F,temp.Salary);
 Read(F,temp.Age);
 If Temp.memcode=Mem Then
    Foundmem :=True;

End;
if foundmem=false Then
 Begin
 Write('This Member is not Exist !');
 ReadLn;
 End;

(*******************CHECKED******************)
If (Not Found) and foundmem Then
Begin
 Append(Fo);
 Write(Fo,mem);
 Write(Fo,d);
 Write(Fo,h);
 Write(Fo,m);
 Write('The member registered !');
 Readln;
 Close(Fo);
End;

End;
(*****************************)
Procedure Report;
Var
   FI,FU  : Text;
   TI,TU  : reg;
   found : boolean;
Begin
Assign(FI,'entrance.txt');
Assign(FU,'exit.txt');
Reset(FI);
Reset(FU);

While Not Eof(FI) Do
Begin
  Read(FI,TI.Memcode);
  Read(FI,TI.day);
  Read(FI,TI.hour);
  Read(FI,TI.Minute);
  While Not Eof(FU) Do
  Begin
    Read(FU,TU.Memcode);
    Read(FU,TU.day);
    Read(FU,TU.hour);
    Read(FU,TU.Minute);

    If (TI.memcode=tu.memcode)and(ti.day=tu.day) Then
    Begin
       Found:=true;
       Break;
    End;
  End;{End of While !!}

  If found Then
  Begin
       Write('The Member ' ,ti.memcode, ' has worked in day ' ,ti.day);
       Write( ' between ',ti.hour,':',ti.minute,' and ',tu.hour,':',tu.minute);
       found:=false;
  End
  Else
  Begin
       Write('The Member ' ,ti.memcode, ' has worked in day ' ,ti.day);
       Write( ' between ',ti.hour,':',ti.minute,' and 24:00');
  End;
End;{End of while !}


Close(FI);
Close(FU);
End;
(******************************)
Procedure WC(Var f : text);{Work calculator!}
Var
   Sal : ^Real;
   i,j : real;
   temp : member;
   m : integer;
   found : boolean;
   FI,FU : text;
   TI,TU : reg;
Begin
Assign(FI,'c:\p1\entrance.txt');
Assign(FU,'c:\p1\exit.txt');
Reset(FI);
Reset(FU);


While not Eof(f) Do
Begin
 Read(F,temp.Memcode);
 Read(F,temp.Name);
 Read(F,temp.Fam);
 Read(F,temp.BNum);
 Read(F,temp.Mar);
 Read(F,temp.Salary);
 Read(F,temp.Age);

 new(sal);
 sal^:=0.0;
 reset(FI);
 reset(FU);
 While Not Eof(FI) Do
 Begin
   Read(FI,TI.Memcode);
   Read(FI,TI.day);
   Read(FI,TI.hour);
   Read(FI,TI.Minute);
   If ti.memcode=temp.memcode Then
   Begin {if !!!}
    While Not Eof(FU) Do
    Begin
      Read(FU,TU.Memcode);
      Read(FU,TU.day);
      Read(FU,TU.hour);
      Read(FU,TU.Minute);

      If (TI.memcode=tu.memcode)and(ti.day=tu.day) Then
      Begin
         Found:=true;
         Break;
      End;
   End;{End of While !!!}

   If found then
   begin
    val(ti.hour,i,m);
    val(tu.hour,j,m);
    sal^:=sal^+j-i;
    val(ti.minute,i,m);
    val(tu.minute,j,m);
    sal^:=sal^+(j-i)/60
   end{End of if}
   else
   Begin
    val(ti.hour,i,m);
    sal^:=Sal^+24-i;
    val(ti.minute,i,m);
    sal^:=sal^+(00-i)/60;
   End;{end of else}

  End;{end of If !!!}
  End;{End of While !!}

WriteLn('The member ',temp.memcode,' has worked ',sal^:5:2,' Hours.');
dispose(sal);
End;{End of While !}

Close(FI);
Close(FU);
End;
(******************************)

(******************************)
Begin
Textbackground(Cyan);
TextColor(10);
ClrScr;


Repeat
ClrScr;

{Showing Menues...}
PageLable('** APSENT / PRESENT SYSTEM **');
 Writeln('   1 : Add Member');
 Writeln('   2 : Delete Member');
 Writeln('   3 : Chang Member Properties');
 Writeln('   4 : Show Member Properties');
 Writeln('   5 : Search Member By ...');
 Writeln('   6 : Entrance Reg.');
 Writeln('   7 : Exit Reg.');
 Writeln('   8 : Report Member`s Activation');
 Writeln('   9 : Report Member`s Work Time');
 Writeln;
 Writeln('   10: Exit');
 Writeln;
 Writeln;
Writeln('---------------------------------------------------');
Write('    Enter Your choice : ');
 Textcolor(4);
 Readln(Choice);
 Textcolor(10);
{End Of Showing Menues.}
Assign(F,'member.txt');

Case Choice of {Main Case ...}

1 :
Begin
 ClrScr;
 PageLable('** ADD MEMBER **');
  WriteLn('Are You Sure You Want To Add A Member ? (Y\N) : ');
  Case Readkey Of
  'Y','y' : WriteMember(F);
  End;
End;{End of 1}

2 :
Begin
 ClrScr;
 PageLable('** REMOVE MEMBER **');
 DelMember(F);
End;{End of 2}

3 :
Begin
 ClrScr;
 PageLable('** CHANGE MEMBER PROPERTIES **');
 ChangeMem(F);
End;{End of 3}

4 : ReadMember(F);

5 :
Begin
 ClrScr;
 PageLable('** SEARCH FOR MEMBER BY...**');
 Searchmember(F);
End;{End of 5}

End; {End of main case.}


Until Choice =10;
End.
