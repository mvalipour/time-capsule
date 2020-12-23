uses crt;
type
    sec= array[1..28] of string[40];
var
    arr : sec;
    secsen,secwor : string;
    i,j : integer;
    ls,lw : integer;
    found:boolean;

Function Tar(ch : char;s : string): Byte;
var i:integer;
    t : byte;
Begin
t:=1;
for i:=1 to length(s) do
 if s[i]<ch then
    Inc(t);
tar:=t;
End;

 {'as   wkt sfmdti   rll sciolanor auwenenssnnot llm cx proiayboteeioosasw'}
begin
clrscr;
j:=1;
{Write('Enter the sucured sentense : ');
Readln(secsen);}
secsen:='aetwkhbvi o in mrme  hs a   t r  heeean yefoo a leutretytyn ';
Write('Enter the sucurity word : ');
ReadLn(secwor);
LS:=Length(secsen);
LW:=Length(secwor);
For I:=0 to LW-1 do
 begin
 found:=false;
 j:=1;
 Repeat
  if tar(secwor[j],secwor)=I+1 then
   Begin
   arr[j]:=copy(secsen,I*(LS div LW)+1,(LS div LW));
   Found:=true;
   End
  Else
   Inc(J);
 Until Found;
 end;

For j:=1 to (LS div LW) Do
 For i:=1 to LW Do
   Write(arr[i][j]);


readln;

end.
