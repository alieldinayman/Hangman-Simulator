#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
   srand(time(NULL));
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   int i,j,x,y,State[100],xpos[100],ypos[100],z,state;
   //PLACING THE STARS//
   for (i=0,x=0;x<600;x+=10,i++)
   {
       y = rand() % 140;
       putpixel(x,y,YELLOW);
       xpos[i] = x;
       ypos[i] = y;
       State[i] = rand() % 2;
   }
   //ANIMATING THE STARS//
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
   closegraph();
   return 0;
}
