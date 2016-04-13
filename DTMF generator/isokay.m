%
% isokay(test) = fine
% 
% vlastně jo, blbější mě napadl... tenhle...
% tohle je jen testovací funkce na uživatele, kteří mi do programu chtějí
% narvat hodnoty, co tu nemají co dělat... buď testující osoba (ta je dobrá),
% nebo BFU (Blbej Franta Uživatel, toho bych zaškrtil)
%
function[fine] = isokay(test)
lookup_table = ['1' '2' '3' 'A'; '4' '5' '6' 'B'; '7' '8' '9' 'C'; '*' '0' '#' 'D'];
v = max(size(test));
fine = 1;
if(min(size(test)) == 0)
  fine = 0;
end
 for i = 1:v
  mask = lookup_table == test(i);
  [r, c] = find(mask == 1);
  if(min(size(r)) == 0)
    fine = 0;
  end
end