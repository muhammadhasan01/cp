var
 n,c : longint;
begin
 readln(c);
 n := c;
 while(TRUE) do begin
     if c = 1 then begin
         writeln('ya');
         break;
     end;
     if (n mod 2) = 0 then begin
         n := n div 2;
     end else begin
         writeln('bukan');
         break;
     end;
     if n = 1 then begin
         writeln('ya');
         break;
     end;
 end;
 readln;
end.