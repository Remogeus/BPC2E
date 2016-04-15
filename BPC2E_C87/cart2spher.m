function[x, y, z] = cart2spher(lon, lat)
x = [];
y = [];
z = [];
x = cos(lon*pi/180).*cos(lat*pi/180);
y = sin(lon*pi/180).*cos(lat*pi/180);
z = sin(lat*pi/180);
end