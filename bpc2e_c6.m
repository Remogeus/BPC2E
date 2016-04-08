Temp = [-1.1 -0.3  7.6 12.7 19.2 27.6 29.3 29.1 22.4 14.2 8.1  0.5
		-2.1 -1.1  5.4 11.0 18.4 23.9 32.5 26.0 19.4 11.8 6.2 -0.5  
		-0.3 -1.3  9.9 13.7 20.3 22.0 28.4 28.1 20.2 14.6 7.3  0.4  
		 1.1 -0.7 10.6 14.0 17.5 25.0 27.3 30.2 23.2 10.9 5.2  0.0  
		-8.6 -2.5  5.1 12.2 15.2 25.0 25.3 28.3 24.9  9.2 1.5  0.2  
		-3.1 -0.3  4.6 12.3 14.0 28.6 29.0 32.5 22.0 12.3 9.1  4.3  
		-2.5  0.8  7.7 11.4 17.2 21.9 29.0 26.9 17.1 13.3 3.1  0.6  
		-1.0 -1.1 17.3 26.6 28.0 32.9 37.1 38.5 29.4 14.3 8.0  0.9  
		 0.0  2.6  7.8 10.9 19.1 28.8 28.1 28.1 18.5 13.8 6.0  1.5  
		 0.2  1.4  8.6 10.0 18.1 25.5 32.5 27.0 20.4 12.0 2.0  2.5  
		-0.7 -0.1  6.1 13.0 18.4 24.1 31.9 29.0 21.6 11.0 5.3  3.0  
		-5.4  3.3 11.6 12.8 16.9 23.8 28.7 29.0 23.4 13.7 3.8  4.1  
		-3.8  0.8 13.1 12.6 13.7 23.7 26.3 25.8 20.8 14.9 6.7  1.3  
		-1.2  0.0  8.6 15.9 15.6 26.6 29.2 26.6 20.8 15.1 4.1 -7.4  
		-2.5  2.5  8.8 11.7 19.8 27.3 33.3 25.4 22.9 14.1 4.1  2.9  
		-6.4 -6.3  2.5 13.8 19.1 27.6 28.1 23.2 20.1 12.0 5.1  0.8];
    
LTAvT = [-1.2 0.4  8.8 12.5 18.1 25.3 29.1 28.7 20.9 12.0 3.9  0.5]; 

Temp(8,3:9) = Temp(8,3:9) - 10;
Month = 1:size(Temp,2);
V = reshape(Temp', 1, []);
DeviationMat = Temp - (ones(16,1)*LTAvT);
Deviation = reshape(DeviationMat',1,[]);


% plotting of temperatures in one chart (one line - one year)
figure()
subplot(2,2,1)
plot(Month,Temp(1:16, :),'b')
hold on
plot(Month,LTAvT, 'r')
grid on
xlim([1 12])         
title('MONTH''S TEMPERATURES')
xlabel('MONTH IN YEAR')
ylabel('TEMPERATURE [°C]')
hold off

% plotting of temperatures in one chart (one line - all years)

subplot(2,2,2)
hold on
plot(1:size(V,2),V, 'b')
plot(1:size(V,2), Deviation, 'g')
grid on
xlim([1 size(V,2)])
title('TEMPERATURES DURING ALL PERIODS')
xlabel('MONTH IN PERIOD')
ylabel('TEMPERATURE [°C]')
hold off

% plot of maximum/average/minimum temperatures

subplot(2,2,3)
plot(Month,max(Temp(1:16, :)),'r', 'LineWidth',2)
hold on
plot(Month,LTAvT, 'k', 'LineWidth',3)
plot(Month,min(Temp(1:16, :)), 'b', 'LineWidth',2)
grid on
xlim([1 12])        
title('MONTH''S TEMPERATURES')
xlabel('MONTH IN YEAR')
ylabel('TEMPERATURE [°C]')
hold off

% plot of deviation of temperatures with average value
subplot(2,2,4)
plot(Month,DeviationMat(1:16, :),'bo', 'MarkerSize', 5, 'LineWidth', 1)
hold on
plot(Month,sum(DeviationMat)/16, 'r:s', 'MarkerSize', 5 ,'LineWidth', 2)
grid on
xlim([0 13])        
title('DEVIATIONS OF MONTH''S TEMPERATURES')
xlabel('MONTH IN YEAR')
ylabel('DEVIATION OF TEMPERATURE [°C]')
hold off