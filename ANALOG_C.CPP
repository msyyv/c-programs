#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define PI 3.147
void clocklayout();
void sechand();
void hrhand();
void minhand();
int maxx,maxy;
void main()
{
int gd=DETECT,gm,error;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
error=graphresult();
if(error!=0)
{
printf("%s",grapherrormsg(error));
}
while(!kbhit())
{
clocklayout();
sechand();
minhand();
hrhand();
sleep(1);
cleardevice();
}
}
void clocklayout()
{
int x,y,r,i;
float j;
maxx=getmaxx();
maxy=getmaxy();
for(i=1;i<5;i++)
{
setcolor(YELLOW);
circle(maxx/2,maxy/2,120-i);
}
pieslice(maxx/2,maxy/2,0,360,5);
x=maxx/2;
y=maxy/2;
r=100;
setcolor(MAGENTA);
for(j=PI/6;j<=(2*PI);j+=(PI/6))
{
pieslice(x,y,0,360,4);
x=(maxx/2)+r*cos(j);
y=(maxy/2)+r*sin(j);
}
x=maxx/2;
y=maxy/2;
r=100;
setcolor(RED);
for(i=PI/30;j<(2*PI);j+=(PI/30))
{
pieslice(x,y,0,360,2);
x=(maxx/2)+r*cos(j);
y=(maxy/2)+r*sin(j);
}
}
void sechand()
{
struct time t;
int r=80,x=maxx/2,y=maxy/2,sec;
float o;
maxx=getmaxx();
maxy=getmaxy();
gettime(&t);
sec=t.ti_sec;
o=sec*(PI/30)-(PI/2);
setcolor(YELLOW);
line(maxx/2,maxy/2,x+r*cos(o),y+r*sin(o));
}
void hrhand()
{
int r=50,hr,min;
int x,y;
struct time t;
float o;
maxx=getmaxx();
maxy=getmaxy();
x=maxx/2;
y=maxy/2;
gettime(&t);
hr=t.ti_hour;
min=t.ti_min;
if(hr<=12) o=(hr*(PI/6)-(PI/2))+((min/12)*(PI/30));
if(hr>12) o=((hr-12)*(PI/6)-(PI/2))+((min/12)*(PI/30));
setcolor(15);
line(maxx/2,maxy/2,x+r*cos(o),y+r*sin(o));
}
void minhand()
{
int r=60,min;
int x,y;
float o;
struct time t;
maxx=getmaxx();
maxy=getmaxy();
x=maxx/2;
y=maxy/2;
gettime(&t);
min=t.ti_min;
o=(min*(PI/30)-(PI/2));
setcolor(RED);
line(maxx/2,maxy/2,x+r*cos(o),y+r*sin(o));
}
