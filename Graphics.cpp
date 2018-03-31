#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
   srand(time(NULL));
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   int x,y,z;
   int i,j,xs,ys,State[100],xpos[100],ypos[100];
   //-----------HANGMAN-------------//
   setlinestyle(DASHED_LINE, 5,10);
   line(0, 300, 650, 300);
   setcolor(DARKGRAY);
   setlinestyle(DASHED_LINE, 2,8);
   line(0, 305, 650, 305);
   setcolor(RED);
   line(100, 290, 100, 150); //main line
   setcolor(RED);
   //Pillars
   line(80, 290, 100, 240);
   line(120, 290, 100, 240);
   setcolor(RED);
   line(100, 150, 200, 150);
   line(105, 200, 150, 155);
   setcolor(BROWN);
   line(199, 158, 200, 180);
   setcolor(DARKGRAY);
   circle(200, 190, 10);
   line(200, 200, 200, 235);
   line(200, 200, 220, 225);
   line(200, 200, 180, 225);
   line(200, 230, 210, 260);
   line(200, 230, 190, 260);

   //-------------MOON-------------//
   setcolor(YELLOW);
   setfillstyle(SOLID_FILL, YELLOW);
   circle(getmaxx() - 75, 75, 35);
   floodfill(getmaxx() - 75, 75, YELLOW);
   setcolor(WHITE);
   //-----------STARS------------//
   for (i=0,xs=0;xs<600;xs+=10,i++)
   {
       ys = rand() % 140;
       putpixel(xs,ys,YELLOW);
       xpos[i] = xs;
       ypos[i] = ys;
       State[i] = rand() % 2;
   }
   for (x=200,y=500,z=0;x<500;x+=10,z+=22)
   {
       bar(150, 400, x, y-50);
       delay(100);
       settextstyle(SCRIPT_FONT, HORIZ_DIR, 4);
       outtextxy(255,350,"Loading...");
   }
   outtextxy(125,350,"Press any key to continue!");
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   outtextxy(110,60,"Welcome to Hangman!");
   setlinestyle(DASHED_LINE, 2,3);
   rectangle(100,105,480,55);
   settextstyle(BOLD_FONT, HORIZ_DIR, 2);
   outtextxy(280,180,"A Project by:");
   setlinestyle(SOLID_LINE,5,1);
   line(280, 200, 435, 200);
   line(280, 202, 435, 202);
   settextstyle(SCRIPT_FONT, HORIZ_DIR,3);
   outtextxy(320,220,"Alieldin Ayman");
   setfillstyle(SOLID_FILL,LIGHTBLUE);
   bar(570,180,610,240);//Blue-shirt
   setfillstyle(SOLID_FILL,WHITE);
   bar(595,225,599,230);//Button
   bar(520,190,570,240);//Hand
   bar(550,190,560,160);//Thumb
   //Three black lines in hand
   setfillstyle(SOLID_FILL,BLACK);
   setcolor(BLACK);
   bar(520,230,535,235);
   bar(520,215,535,220);
   bar(520,200,535,205);
   //-----ANIMATING THE STARS----//
   while (1)
   {
    if(kbhit())
    {
        break;
    }
    for (i=0;i<100;i++)
    {
       if (State[i]==1)
       {
          State[i]=0;
          putpixel(xpos[i],ypos[i],YELLOW);
       }
       else if (State[i]==0)
       {
          State[i]=1;
          putpixel(xpos[i],ypos[i],BLACK);
       }
        delay(40);
    }
   }
   system("cls");
   closegraph();
   return 0;
}
