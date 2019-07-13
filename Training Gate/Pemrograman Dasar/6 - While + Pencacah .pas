var
 n,c : longint;
begin
c := 0;
while(not eof(input)) do begin
 readln(n);
 c := c+n;
end;
writeln(c);
end.