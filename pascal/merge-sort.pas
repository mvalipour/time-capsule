Program Merge_sort;
uses crt;

const n=12;
Type
    Arr = array[1..n] of real;
    DArr = array[1..2*n] of real;
Var
    s,p : arr;
    sum : darr;
    i : integer;

procedure swop(var a,b : real);
var temp : real;
begin
temp:=a;
a:=b;
b:=temp;
end;

procedure sort(var s: arr);
var i,j : integer;
begin
for i:=1 to n-1 do
 for j:=i+1 to n do
 if s[j]<s[i] then
  swop(s[j],s[i]);
End;

procedure merge(s,p : arr;var sum : darr);
var i1,i2,j,k: integer;
begin
i1:=1;
i2:=1;
j:=1;

Repeat
if s[i1]<p[i2] then
 Begin
  sum[j]:=s[i1];
  Inc(i1);
  Inc(j);
 End
 else
 begin
  sum[j]:=p[i2];
  Inc(i2);
  Inc(j);
 End;

until (i1=n+1)or(i2=n+1);

if i1=n+1 Then
 for k:=i2 to n Do
 begin
  sum[j]:=p[k];
  Inc(j);
 End;

if i2=n+1 Then
 for k:=i1 to n Do
 begin
  sum[j]:=s[k];
  Inc(j);
 End;

End;



begin
clrscr;
randomize;

for i:=1 to n do
 Begin
 p[i]:=random;
 s[i]:=random;
 End;
sort(s);
sort(p);
merge(s,p,sum);

for i:=1 to 2*n do
 Begin

 write(sum[i]:8:4);
 if i<=n then
  begin
  write(s[i]:8:4);
  write(p[i]:8:4);
  end;
 writeln;
 End;


readln;

end.
