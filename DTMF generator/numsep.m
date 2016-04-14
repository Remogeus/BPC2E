%
% numsep(num) = out
% 
% alias jak separovat čísla a znaky od sebe užitím buněk
% tyhle komenty jsou stejně výplň... funguje to na 70 řádků a minimum má být 200
% ve zkratce - funkce přijme string, převede ho na buňky a separuje tak jednotlivé
% znaky na vstupu, na výstupu je vektor složený z rozdělených hodnot ze vstupu
%
% jo a je plný eastereggů na různá čísla
function[out] = numsep(num)
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