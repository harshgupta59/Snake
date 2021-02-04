#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
bool gameOver; 
const int width = 40;
const int height = 20;
int x,y,fruitX,fruitY,score,difficulty;
int tailX[100],tailY[100];
int nTail;
enum eDirection {STOP = 0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void Setup()
{
    gameOver=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitX=rand()%width;
    fruitY=rand()%height;
}
void Draw()
{
    system("cls");
    cout<<"SNAKE GAME"<<"\n";
     cout<<"USE following keys"<<"\n";
    cout<<"   w   "<<"\n";
    cout<<"a  +  d"<<"\n";
    cout<<"   s   "<<"\n";
    cout<<"w - UP "<<"\n";
    cout<<"a - LEFT"<<"\n";
    cout<<"S - DOWN"<<"\n";
    cout<<"d - RIGHT"<<"\n"; 
    for(int i=0;i<width+1;i++)
    {
        cout<<"#";
    }
    cout<<"\n";
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
                cout<<"#";
            if(i==y&&j==x)
                cout<<"O";
            else if(i==fruitY&&j==fruitX)
                cout<<"F";
            else
            {  
				bool print=false;
            	for(int k=0;k<nTail;k++)
            	{
            		if(tailX[k]==j&&tailY[k]==i)
            		{
            			cout<<"o";
            			print=true;
					}
				}
				if(!print)
                cout<<" ";
            }
            if(j==width-1)
                cout<<"#";
        }
        cout<<"\n";
    }
     for(int i=0;i<width+1;i++)
    {
        cout<<"#";
    }
    cout<<"\n";
    cout<<"SCORE:"<<score;
    cout<<"\n";
    cout<<"Press X to exit"<<endl;
}
void Input()
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'a':
            dir=LEFT;
            break;
        case 'd':
            dir=RIGHT;
            break;
        case 'w':
            dir=UP;
            break;
        case 's':
            dir=DOWN;
            break;
        case 'x':
            gameOver=true;
            break;
        }
    }
}
void Logic()
{
    
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<nTail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }

    switch(dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
    }
	 if(difficulty==2)
 	 {
 		if(x>width||x<0||y>height||y<0)
            gameOver=true;
     }
      if(difficulty==1)
       {
            if(x>=width)
            x=0;
            else
			{ 
            if(x<0)
            x=width-1;
        	}
            if(y>=height)
            y=0;
            else
            {
			if(y<0)
            y=height-1;
        	}
       }
            for(int i=0;i<nTail;i++)
            	if(tailX[i]==x&&tailY[i]==y)
            	gameOver=true;
            if(x==fruitX&&y==fruitY)
            {

                score+=10;
                fruitX=rand()%width;
                fruitY=rand()%height;
                nTail++;
            }
}
int main()
{
	cout<<"enter difficulty level\n";
    cout<<"Press 1. for EASY\n";
    cout<<"Press 2. for HARD\n";
	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
    cin>>difficulty;
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
       if(difficulty==1)
       Sleep(60);
    }
    system("cls");
    cout<<"\n";
    cout<<"SCORE:"<<score<<"\n";
    cout<<"* * * G A M E  O V E R * * *";
    return 0;
}

