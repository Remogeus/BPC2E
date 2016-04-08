% computation
[x,y] = meshgrid(0:5:100, 0:5:90);
map = [0, 0, 0;
       0, 0, 1;
       0, 1, 0;
       1, 0, 0];
z = (((x./3.6).^2)/9.81).*sind(2*y);
X = x(1,:);
Y = y(:,1);
mdeg = 45;
sddeg = 10;
mvel = 90;
sdvel = 3;
degdist = mdeg + sddeg*randn(10000,1);
veldist = mvel + sdvel*randn(10000,1);
tradist = (((veldist./3.6).^2)/9.81).*sind(2*degdist);

% plotting
figure()
surf(X,Y,z)
ylim([0 max(Y)])
grid on
title('d = f(v0, alpha)')
xlabel('v0[km/h]')
ylabel('alpha[°]')
zlabel('d[m]')
colorbar
caxis([0,85])


figure()
mesh(X,Y,z)
ylim([0 max(Y)])
grid on
title('d = f(v0, alpha)')
xlabel('v0[km/h]')
ylabel('alpha[°]')
zlabel('d[m]')
colormap([0 0 0])

figure()
[C,h] = contour(X,Y,z);
v = 10:10:100;
clabel(C,h,v, 'background', 'r');
ylim([0 max(Y)])
grid on
title('d = f(v0, alpha)')
xlabel('v0[km/h]')
ylabel('alpha[°]')
zlabel('d[m]')
colormap([0 0 1])

figure()
colormap(map)
meshc(X,Y,z)
view(60, 25)
ylim([0 max(Y)])
grid on
title('d = f(v0, alpha)')
xlabel('v0[km/h]')
ylabel('alpha[°]')
zlabel('d[m]')
colorbar
caxis([0,85])

figure()
hist(tradist, 50);
grid on
title('Histogram of trajectory')
ylabel('count')
xlabel('d[m]')

figure()
hist(degdist, 50);
grid on
title('Histogram of angle')
ylabel('count')
xlabel('alpha[°]')

figure()
hist(veldist, 50);
grid on
title('Histogram of velocity')
ylabel('count')
xlabel('v0[km/h]')