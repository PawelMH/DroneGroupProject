clc;
clear all;
close all;
I=imread('图片_202410212109251.jpg');%Input from camera
figure;
imshow(I);
qmg = rgb2hsv(I);%RGB TO HSV
hzin = 0;    
hwax = 0.1;    
szmin = 0.3;  
saqax = 1;    
vzin = 0.1;       
vzax = 1;       
mask1 = (qmg(:,:,1) >= hzin & qmg(:,:,1) <= hwax) & (qmg(:,:,2) >= szmin & qmg(:,:,2) <= saqax) & (qmg(:,:,3) >= vzin & qmg(:,:,3) <= vzax);
mask2 = (qmg(:,:,1) >= 0.9 & qmg(:,:,1) <= 1) & (qmg(:,:,2) >= szmin & qmg(:,:,2) <= saqax) & (qmg(:,:,3) >= vzin & qmg(:,:,3) <= vzax);
rwsk = mask1 | mask2;
owmg = I;
owmg(repmat(~rwsk, [1, 1, 3])) = 0; 
figure;
imshow(owmg);
owmg=rgb2gray(owmg);
figure;
imshow(owmg);
level=graythresh(owmg);
M1=im2bw(owmg,level);
figure;
imshow(M1);
M1=bwareaopen(M1,500);
[czs, rqi] = imfindcircles(M1, [20 500], 'ObjectPolarity', 'bright', 'Sensitivity', 0.9);%xircle detection
figure;
imshow(I);
hold on;
if ~isempty(czs)
    viscircles(czs, rqi, 'EdgeColor', 'b');
    plot(czs(1,1), czs(1,2), 'r*', 'MarkerSize', 10); 
    fprintf('CircleCenterCoordinates:x=%f，y%f\n',czs(1,1), czs(1,2));%CircleCenter OUTPUT
    edges = edge(M1, 'Canny');
[mm,nn]=size(edges);
xx=[];
yy=[];
for i=1:mm
   x=edges(i,:);
   [ww1,ww2]=find(x==1);
   if isempty(ww2)==0
   xx1=ww2(1);
   xx2=ww2(end);
   xx=[xx,(xx1+xx2)/2];
yy=[yy,i];
 fprintf('PathCoordinates:x=%f，y%f\n',(xx1+xx2)/2, i);%PathOUTPUT
   end
end
figure;
imshow(I);
hold on
plot(xx,yy,'b*')
else
    edges = edge(M1, 'Canny');%Edge Detection
[mm,nn]=size(edges);
xx=[];
yy=[];
for i=1:mm
   x=edges(i,:);
   [ww1,ww2]=find(x==1);
   if isempty(ww2)==0
   xx1=ww2(1);
   xx2=ww2(end);
   xx=[xx,(xx1+xx2)/2];
yy=[yy,i];
 fprintf('PathCoordinates:x=%f，y%f\n',(xx1+xx2)/2, i);%PathOUTPUT
   end
end
figure;
imshow(I);
hold on
plot(xx,yy,'b*')
end