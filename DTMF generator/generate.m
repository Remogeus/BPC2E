%
% generate(srate, amp, freq,v) = sig
% 
% a samotný generátor signálu... díky bohu, že to nemusím řešit jako v C
% funkce na vstupu přijme sample rate, amplitudu signálu, matici frekvencí a
% velikost, následně si vytvoří úseky o velikosti 50 ms a začne generovat signál
% na výstupu je vektor složený ze spojených hodnot signálu
% 
% poznámka pro mě... otestovat tic-toc

function[sig] = generate(srate, amp, freq,v)
t = 0:1/srate:0.05;
sig = amp*sin(2*pi*freq(1,1)*t) + (amp/5)*sin(2*pi*freq(2,1)*t);
sigz = zeros(1,max(size(t)));
for i = 2:v
  sigtmp = amp*sin(2*pi*freq(1,i)*t) + (amp/5)*sin(2*pi*freq(2,i)*t);
  sig = [sig sigz sigtmp];
end