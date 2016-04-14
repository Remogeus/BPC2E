%
% isokay(out) = fine
% 
% vlastně jo, blbější mě napadl... tenhle...
% tohle je jen outovací funkce na uživatele, kteří mi do programu chtějí
% narvat hodnoty, co tu nemají co dělat... buď outující osoba (ta je dobrá),
% nebo BFU (Blbej Franta Uživatel, toho bych zaškrtil)
%

function[fine, out] = isokay(num)
tmp = [];

if(strcmp(num, "01189998819991197253") == 1)
  disp("Well, that’s easy to remember! 0118 999 881 999 119 725…3  - Moss, IT Crowd S01E02 (Calamity Jen)");
end
if(strcmp(num, "42") == 1)
  disp("Do you have a towel?");
end
if(strcmp(num, "822D2") == 1)
  disp("Help me, Obi-Wan Kenobi, you're my only hope!");
end
if(strcmp(num, "2001") == 1)
  disp("I'm afraid, Dave, I can't let you do that");
end
tmp = cellstr(reshape(num, 1, [])');
tmp = cell2mat(tmp);
out = tmp';

lookup_table = ['1' '2' '3' 'A'; '4' '5' '6' 'B'; '7' '8' '9' 'C'; '*' '0' '#' 'D'];
v = max(size(out));
fine = 1;
if(min(size(out)) == 0)
  fine = 0;
end
 for i = 1:v
  mask = lookup_table == out(i);
  [r, c] = find(mask == 1);
  if(min(size(r)) == 0)
    fine = 0;
  end
end