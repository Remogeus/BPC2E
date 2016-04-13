%
% numsep(num) = out
% 
% alias jak separovat čísla a znaky od sebe užitím buněk
% tyhle komenty jsou stejně výplň... funguje to na 70 řádků a minimum má být 200
% ve zkratce - funkce přijme string, převede ho na buňky a separuje tak jednotlivé
% znaky na vstupu, na výstupu je vektor složený z rozdělených hodnot ze vstupu
%
function[out] = numsep(num)
tmp = [];
tmp = cellstr(reshape(tmp, 1, [])');
tmp = cell2mat(tmp);
out = tmp';