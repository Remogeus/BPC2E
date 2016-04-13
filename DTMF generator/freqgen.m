%
% freqgen(num,v) = freq
% 
% protože blbější název funkce mě nenapadl...
% ahem... funkce na vstupu vezme vektor separovaných hodnot a porovná 
% je s tabulkou jednotlivých pozic na číselníku pro DTMF
% pak vytvoří masku z pozic, kde daná hodnota je, a z tohoto pak vyhodí matici
% 2xN, kde N je velikost vstupního čísla a která je plná frekvencí pro jednotlívá 
% čísla a řádky separují frekvence pod 1000 Hz a nad 1000 Hz
%
function[freq] = freqgen(num, v)
freq = [];
lookup_table = ['1' '2' '3' 'A'; '4' '5' '6' 'B'; '7' '8' '9' 'C'; '*' '0' '#' 'D'];
high_freq = [1209, 1336, 1477, 1633];
low_freq = [697, 770, 852, 941];
for i = 1:v
  mask = lookup_table == num(i);
  [r, c] = find(mask == 1);
  freq(1,i) = high_freq(1,c);
  freq(2,i) = low_freq(1,r);
end