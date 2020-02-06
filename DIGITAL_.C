#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
struct time t;
void display(int,int,int);
void main()
{
  int gr=DETECT,gm,hr,min,sec,err,i;
  initgraph(&gr,&gm,"c:\\turboc3\\bgi");
  err=graphresult();
  clrscr();
  if(err!=0)
  {
    printf("%s",grapherrormsg(err));
  }
  settextstyle(4,0,7);
  while(!kbhit())
  {
    gettime(&t);
    hr=t.ti_hour;
    min=t.ti_min;
    sec=t.ti_sec;
    i++;
    display(100,100,hr);
    display(200,100,min);
    display(300,100,sec);
    sound(500);
    delay(30);
    nosound();
    delay(940);
    cleardevice();
  }
  getch();
}
void display(int x,int y,int z)
{
char str[3];
itoa(z,str,10);
settextstyle(7,0,7);
setbkcolor(1);
setcolor(13);
outtextxy(180,100,":");
outtextxy(280,100,":");
outtextxy(x,y,str);
setcolor(14);
rectangle(90,90,380,200);
rectangle(70,70,400,220);
setcolor(6);
outtextxy(20,250,"BY Rakesh Kumar Rk");
}
