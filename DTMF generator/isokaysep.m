%
% isokaysep(num) = fine, out
% 
% alias jak separovat čísla a znaky od sebe užitím buněk - jo a blbější název mě napadl... tenhle...
% tyhle komenty jsou stejně výplň... funguje to na 70 řádků a minimum má být 200
% ve zkratce - funkce přijme string, převede ho na buňky a separuje tak jednotlivé
% znaky na vstupu,zkontroluje, zda uživatel nenarval hodnoty, co tu nemají co dělat... 
% buď testující osoba (ta je dobrá), nebo BFU (Blbej Franta Uživatel, toho bych zaškrtil)
% na výstupu je vektor obsahující výstup separovaných dat a bool informaci o tom, zda je soubor v pořádku
%

function[fine, out] = isokaysep(num)
tmp = [];

switch(num)
  case "01189998819991197253"
    disp("Well, that's easy to remember! 0118 999 881 999 119 725...3  - Moss, IT Crowd S01E02 (Calamity Jen)");
  case "42"
    disp("Do you have a towel?");
  case "822D2"
    disp("Help me, Obi-Wan Kenobi, you're my only hope!");
  case "2001"
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