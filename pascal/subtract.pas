program menha;
Uses CRT;
Var
   i,l,h,max  : integer;
   r : boolean;
   a,b : string;
   ap,bp,d,temp : array[1..255] of integer;


begin
  clrscr;
  write('Enter the 1st num. ==>');
  readln(a);
  write('Enter the 2nd num. ==>');
  readln(b);

  l:=length(a);
  h:=length(b);

  for i:=1 to l do
    ap[i]:=ord(a[l-i+1])-48;

  for i:=1 to h do
    bp[i]:=ord(b[h-i+1])-48;

  if l>h then max:=l else max:=h;
  {Declining...}
  i:=1;
  if l<h then r:=true
  else
   if l=h then
    repeat
     if ap[i]<bp[i] then r:=true else if ap[i]=bp[i] then i:=i+1 else break;
    until r=true;

  if r=true then
  for i:=1 to max do
  begin
    temp[i]:=ap[i];
    ap[i]:=bp[i];
    bp[i]:=temp[i];
  end;

  for i:=1 to max do
    if ap[i]<bp[i] then
    begin
      ap[i]:=ap[i]+10;
      ap[i+1]:=ap[i+1]-1;
    end;

  for i:=1 to max do
    d[i]:=ap[i]-bp[i];

  if d[max]=0 then max:=max-1;

  write('the delination! is ==>');
  if r=true then write('-');
  for i:=max downto 1 do
   write(d[i]);

  readln;
end.
