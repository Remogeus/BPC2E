close all
fid = fopen('earth.dat', 'r') ;
e_mask = fread(fid, [361 721]); 
fclose(fid) ;
[lon,lat] = meshgrid(-180:0.5:180, -90:0.5:90);
c = e_mask;

[x,y,z] = cart2spher(lon, lat);

ground = [1,1,0;0,0,1];

figure(1)
mesh(lon,lat,0*lon,c)
xlabel('lon')
ylabel('lat')
axis equal
colormap(ground)
view(0,90)


figure(2)
mesh(x,y,z,c)
title('Striped ball')
xlabel('x')
ylabel('y')
zlabel('z')
axis equal
colormap(ground)
view(45,20)

[lon,lat] = meshgrid(-135:0.5:35, 15:0.5:90);
[xpart,ypart,zpart] = cart2spher(lon, lat);

fid = fopen('NATemp1985.dat', 'r');
t85_mask = fread(fid,inf, 'float32'); 
fclose(fid);
t85_mask = (reshape(t85_mask, [] ,size(lat,2)));

fid = fopen('NATemp2010.dat', 'r');
t10_mask = fread(fid,inf, 'float32'); 
fclose(fid);
t10_mask = (reshape(t10_mask, [] ,size(lat,2)));

tdif = t10_mask - t85_mask;

figure(3)
mesh(lon,lat,0*lon,t85_mask)
xlabel('LONGITUDE')
ylabel('LATITUDE')
title('Northen Atlantic Temperature 1985')
xlim([-135 35]);
ylim([15 90]);
axis equal
colormap('jet')
colorbar
set(gca, 'xtick', -120:20:35)
view(0,90)

figure(4)
mesh(lon,lat,0*lon,t10_mask)
xlabel('LONGITUDE')
ylabel('LATITUDE')
title('Northen Atlantic Temperature 2010')
xlim([-135 35]);
ylim([15 90]);
axis equal
colormap('jet')
colorbar
set(gca, 'xtick', -120:20:35)
view(0,90)

figure(5)
mesh(lon,lat,0*lon,tdif)
xlabel('LONGITUDE')
ylabel('LATITUDE')
title('Northen Atlantic Temperature - difference 2010 - 1985')
xlim([-135 35]);
ylim([15 90]);
axis equal
colormap('jet')
colorbar
set(gca, 'xtick', -120:20:35)
view(0,90)

e_mask(211:361, 91:431) = e_mask(211:361, 91:431) .* t85_mask;

figure(6)
mesh(x,y,z,e_mask)
xlabel('x')
ylabel('y')
zlabel('z')
title('Northen Atlantic Temperature 1985')
colormap('jet')
colorbar
view(45,20)

e_mask(211:361, 91:431) = e_mask(211:361, 91:431) .* t10_mask;

figure(7)
mesh(x,y,z,e_mask)
xlabel('x')
ylabel('y')
zlabel('z')
title('Northen Atlantic Temperature 2010')
colormap('jet')
colorbar
view(45,20)

figure(8)
mesh(xpart,ypart,zpart,tdif)
xlabel('x')
ylabel('y')
zlabel('z')
title('Northen Atlantic Temperature - difference 2010 - 1985')
colormap('jet')
colorbar
view(45,20)