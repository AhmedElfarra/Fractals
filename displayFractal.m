% To get best results, set the dimensions of your fractal matrix to 600 by
% 600
julia = importdata('julia.dat'); % change filename 'julia.dat' to the filename that you have outputted your data
mandelbrot = importdata('Mandelbrot.dat');
% Create your color map, Google "matlab colormap" and click on first link for other colormap
% schemes
cmap = jet(81); % change this number "81" to the max number of iterations in your program + 1

imwrite(julia, colormap(gray), 'julia.png'); % feel free to change 'julia.png' to the output filename of your choosing
imwrite(mandelbrot, colormap(gray), 'Mandelbrot.png'); % feel free to change 'julia.png' to the output filename of your choosing

j = imread('julia.png');
m = imread('Mandelbrot.png');
imshow(j), figure, imshow(m)
