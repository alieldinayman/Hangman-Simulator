//HANGMAN SIMULATOR BY: Alieldin Ayman
//DEDICATED TO: Dr. Marwa El-Shenawy
//COMPUTER ENGINEERING YEAR (1) PROJECT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>

//Words to be used in the game (Global Variable)
char Words[][16] = //16 is the maximum word length
    {
	"APPLE","ANIMAL","BALLOON","BUILDING","CUCUMBER","CANDLE","DOLPHIN","DINASOUR","ELEPHANT","ENERGY","FAMILY","FLOWER","GEOGRAPHY","GIRAFFE",
	"HAPPINESS","HALLOWEEN","ICECREAM","ISLAND","JACKET","JUICE","KANGAROO","KINGDOM","LIQUID","LEVEL","MONKEY","MILITARY","NEWSPAPER","ORANGE",
	"PENGUIN","PIRATE","QUEEN","RESTAURANT","SHARK","SUPER","TRAIN","UMBRELLA","VOCABULARY","WIZARD","XILIPHONE","ZOMBIE"
    };

void WelcomeScr()
{
   int x,y,z;
   int i,j,xs,ys,State[100],xpos[100],ypos[100];
   //-----------HANGMAN-------------//
   setlinestyle(DASHED_LINE, 5,10);
   line(0, 300, 650, 300);
   setcolor(DARKGRAY);
   setlinestyle(DASHED_LINE, 2,8);
   line(0, 305, 650, 305);
   setcolor(RED);
   line(100, 290, 100, 150); //Main Line
   setcolor(RED);
   //Pillars
   line(80, 290, 100, 240);
   line(120, 290, 100, 240);
   setcolor(RED);
   line(100, 150, 200, 150);//Step 2
   line(105, 200, 150, 155);//Step 3
   setcolor(BROWN);
   line(199, 158, 200, 180);//Step 4
   setcolor(DARKGRAY);
   circle(200, 190, 10);//Step 5
   line(200, 200, 200, 235);//Step 6
   line(200, 200, 220, 225);//Step 7
   line(200, 200, 180, 225);//Step 8
   line(200, 230, 210, 260);//Step 9
   line(200, 230, 190, 260);//Step 10

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
   //---------LOADING BAR---------//
   for (x=200,y=500;x<500;x+=10)
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
    }
   }
}

void Gamegfx()
{
   int x,y,z;
   int i,j,xs,ys,State[100],xpos[100],ypos[100];
   //-----------HANGMAN-------------//
   setcolor(WHITE);
   setlinestyle(DASHED_LINE, 5,10);
   line(0, 300, 650, 300);
   setcolor(DARKGRAY);
   setlinestyle(DASHED_LINE, 2,8);
   line(0, 305, 650, 305);
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
      settextstyle(SCRIPT_FONT, HORIZ_DIR, 3);
      outtextxy(200,400,"Starting Lives: 10");
      setcolor(RED);
      line(100, 290, 101, 150); //main line
      setcolor(RED);
      //Pillars
      line(80, 290, 100, 240);
      line(120, 290, 100, 240);
}

void Drawf(int i)
{
 switch (i)
 {
     case 9 :
      setcolor(WHITE);
      outtextxy(200,400,"Remaining Lives: 9");
      setcolor(RED);
      line(100, 150, 200, 150);//Step 2
     break;
     case 8 :
      setcolor(WHITE);
      outtextxy(200,400,"Remaining Lives: 8");
      setcolor(RED);
      line(105, 200, 150, 155);//Step 3
     break;
     case 7 :
      setcolor(WHITE);
      outtextxy(200,400,"Remaining Lives: 7");
      setcolor(BROWN);
      line(199, 158, 200, 180);//Step 4
     break;
     case 6 :
     setcolor(WHITE);
     outtextxy(200,400,"Remaining Lives: 6");
     setcolor(DARKGRAY);
     circle(200, 190, 10);//Step 5
     break;
     case 5 :
     setcolor(WHITE);
     outtextxy(200,400,"Remaining Lives: 5");
     setcolor(DARKGRAY);
     line(200, 200, 200, 235);//Step 6
     break;
     case 4 :
     setcolor(WHITE);
     outtextxy(200,400,"Remaining Lives: 4");
     setcolor(DARKGRAY);
     line(200, 200, 220, 225);//Step 7
     break;
     case 3 :
     setcolor(WHITE);
     outtextxy(200,400,"Remaining Lives: 3");
     setcolor(DARKGRAY);
     line(200, 200, 180, 225);//Step 8
     break;
     case 2 :
     setcolor(WHITE);
     outtextxy(200,400,"Remaining Lives: 2");
     setcolor(DARKGRAY);
     line(200, 230, 210, 260);//Step 9
     break;
     case 1 :
     setcolor(WHITE);
     outtextxy(200,400,"Remaining Lives: 1");
     setcolor(DARKGRAY);
     line(200, 230, 190, 260);//Step 10
     break;
 }
}

void Checkf(char X,int AG,int r,int NL,int Length,char *Hidden, int *Lives,int *Count)
{
    int i;
    int Found = 0;
    for (i=0;i<Length;i++)
    {
	if (X==Words[r][i] && Hidden[i]=='*' && NL == 0)
	{
	    Hidden[i] = X;
	    *Count = *Count + 1;
	    Found = 1;
	}
    }
    if (!Found && !AG && NL == 0)
    *Lives = *Lives - 1;
}

int RandomIndex()
{
    int X;
    X = rand() % 40;
    return X;
}

int Letterf(char X)
{
    if ((X >= 'a' && X <= 'z') || (X >= 'A' && X <= 'Z'))
    {
	return 0;
    }
    else
    {
	printf("Warning: Only letters are allowed!\n\n");
	return 1;
    }
}

char Capitalizef(char X)
{
    if (X>='a' && X<='z')
	X = X - 32;
    return X;
}

int main(void)
{
    int gd = DETECT, gm,maxx,maxy;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    srand(time(NULL)); //For generating a random seed every time we run the game.
    WelcomeScr();
    //GAME START//
    GAME:
    cleardevice();
    Gamegfx();
    //------------------------------------------------------------------------------------//
    int r = RandomIndex();
    int i;
    int NL = 0; //Not Letters for Letterf
    char Again; //For playing again (Y/N)
    char Guessed[40];
    int j=0;
    int Lives = 10;
    int Count = 0;
    char Hidden[20];
    char Guessing;
    int Length = strlen(Words[r]);
    //printf("\t%s -> %d\n",Words[r],Length); //Cheat Mode

    //-----------------------Printing a hidden overview of the word-----------------------//
    for (i=0;i<Length;i++)
    {
	Hidden[i] = '*';
	printf("%c ",Hidden[i]);
    }

    //-----------------------Looping the game-----------------------//
    while (Count!=Length)
    {
	int AG = 0; //Already Guessed
	printf("\nEnter a letter: ");
	scanf(" %c",&Guessing);
	Guessing = Capitalizef(Guessing);
	Guessed[j]=Guessing;
	if (j>0)
	{
	    for (i=0;i<j;i++)
	    {
		if (Guessing==Guessed[i])
		{
		    AG++;
		}
	    }
	}
	j++;
	system ("cls");
	NL = Letterf(Guessing);
	Checkf(Guessing,AG,r,NL,Length,Hidden,&Lives,&Count);
	Drawf(Lives);
	if (Lives<=0)
	{
	    system ("cls");
	    setcolor(WHITE);
	    settextstyle(SCRIPT_FONT, HORIZ_DIR, 4);
        outtextxy(158,350,"You ran out of lives!");
        setlinestyle(SOLID_LINE,1,1);
        line(198,188,196,186);
        line(204,188,202,186);
        line(196,188,198,186);
        line(202,188,204,186);
        setcolor(RED);
        line(198,192,202,192);
	    setcolor(WHITE);
	    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
	    outtextxy(300,160,"THE WORD WAS: ");
	    setcolor(LIGHTRED);
	    outtextxy(300,205,Words[r]);
	    break;
	}
	for (i=0;i<Length;i++)
	{
	   printf("%c",Hidden[i]);
	}
	    printf("\nLetters Guessed:");
	for (i=0;i<j;i++)
	{
	    printf(" %c",Guessed[i]);
	}
	if (AG)
	{
	    printf("\nWarning: Letter already guessed!");
	}
    }
    //-----------------------End of Loop-----------------------//
    if (Lives>0)
    {
        setcolor(LIGHTRED);
        setcolor(LIGHTGREEN);
        settextstyle(SCRIPT_FONT, HORIZ_DIR, 4);
        outtextxy(250,350,"You win!");
        setcolor(WHITE);
	    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
	    outtextxy(300,160,"THE WORD WAS: ");
	    setcolor(LIGHTRED);
	    outtextxy(300,205,Words[r]);
    }
    getchar();
    setcolor(LIGHTBLUE);
    settextstyle(SCRIPT_FONT, HORIZ_DIR, 3);
    outtextxy(180,400,"Try again? Y(es)/N(o)");
    printf("\n");
    scanf("%c",&Again);
    while (Again != 'y' || Again != 'Y' || Again != 'n' || Again !='N')
    {
        if (Again=='y' || Again=='Y')
        {
        system("cls");
        goto GAME;
        }
        else if (Again=='n' || Again == 'N')
        exit(EXIT_SUCCESS);
        else scanf("%c",&Again);
    }
    closegraph();
    return 0;
}
