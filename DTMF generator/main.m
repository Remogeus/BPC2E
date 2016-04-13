% DTMF generátor
% Tohle na 200 řádků nebude, ani kdybych se postavil na hlavu...
fine = 0;
while(fine == 0)
  prompt = "Input number: "; 
  % test, zda nezadal uživatel nepovolené znaky (známe BFU a jejich schopnost 
  % rozbít cokoli, i to nerozbitné) 
  num = input(prompt, 's');
  num = numsep(num);
  fine = isokay(num); 
  % isokay? isnotokay? nenapadl mě lepší název na testovací funkci
end  
prompt = "Input samplerate (default 8000) : ";
srate = input(prompt);

if ((max(size(srate))) == 0) 
% protože Matlab bere odentrování promptu bez inputu jako prázdný vektor
  srate = 8000;
end

prompt = "Input amplitude (default 0.8): ";
amp = input(prompt);

if ((max(size(amp))) == 0)
  amp = 0.8;
end

prompt = 'Write filename (wav is added automatically, default file.wav): ';
filename = input(prompt, 's');

if ((max(size(filename))) == 0)
  filename = 'file';
end
clear prompt

filename = [filename '.wav']
v = max(size(num)); 
% nastavitelná velikost... to až budete vytáčet číslo na britskou zdravotní 
% službu, však víte - 0118 999 881 999 119 725...3, tak se to bude hodit
freq = freqgen(num, v); 
% freqgen funkce (nastavuje hodnoty dle tabulky DTMF)... kterou jsem našel v
% jedné z přednášek... myslím z první
sig = generate(srate, amp, freq,v); % a samotný generátor signálu

audiowrite(filename, sig, srate); 
% skvělé, že Matlab má funkci na ukládání WAVu, nerad bych se s tím štval manuálně