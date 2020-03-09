#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<iomanip>
using namespace std;
class snake
{
    public:
    int player;
    char playername[20];

    snake()
    {
        player=0;
    }
    void in()
    {
        cout<<"\n\nEnter player name:";
        gets(playername);
    }

    void playerdice(int &);
    void play();

};
void draw_line(int n,char ch);
void draw_line2(int n,char ch);
void draw_line1(int n,char ch);
void board();
void board1(int m,int n);
void gamescore(char name1[],char name2[],int p1, int p2);

int main()
{
snake player1,player2;
system("cls");
draw_line(50,'=');
cout<<"\n\n\n\n\t\tSNAKE LADDER GAME\n\n\n\n";
draw_line(50,'=');
player1.in();
player2.in();
while(player1.player<=100 && player2.player<=100)
{
board();
gamescore(player1.playername,player2.playername,player1.player,player2.player);
player1.play();
player2.play();
getch();
board1(player1.player,player2.player);
getch();
}
system("cls");
cout<<"\n\n\n";
draw_line(50,'+');
cout<<"\n\n\t\tRESULT\n\n";
draw_line(50,'+');
cout<<endl;
gamescore(player1.playername,player2.playername,player1.player,player2.player);
cout<<"\n\n\n";
if(player1.player>=player2.player)
cout<<player1.playername<<" !! You are the winner of the game\n\n";
else
cout<<player2.playername<<" !! You are the winner of the game\n\n";
draw_line(50,'+');
getch();
}

void board1(int m,int n)
{
system("cls");
system("color 3");
cout<<setw(26)<<"SNAKE BOARD"<<endl;
int i,j,k=100;
for(i=0;i<10;i++)
{
for(j=0;j<10;j++)
{
    if(k==m&&k==n)
cout<<setw(3)<<"p1p2";
else
if(k==m)
cout<<setw(3)<<"p1"<<"|";
else
if(k==n)
cout<<setw(3)<<"p2"<<"|";
else
cout<<setw(3)<<k<<"|";
k--;
}
cout<<endl;
draw_line2(40,'|');
cout<<endl;
draw_line1(40,'-');
cout<<endl;
}
}
void draw_line(int n,char ch)
{
for(int i=0;i<n;i++)
cout<<ch;
}

void board()
{
system("cls");
cout<<"\n\n";
draw_line(50,'-');
cout<<"\n\t\tSNAKE AT POSITION\n";
draw_line(50,'-');
cout<<"\n\tFrom 98 to 28 \n\tFrom 95 to 24\n\tFrom 92 to 51\n\tFrom 83 to 19\n\tFrom 73 to 1\n\tFrom 69 to 33\n\tFrom 64 to 36\n\tFrom 59 to 17\n\tFrom 55 to 7\n\tFrom 52 to 11\n\tFrom 48 to 9\n\tFrom 46 to 5\n\tFrom 44 to 22\n\n";
draw_line(50,'-');
cout<<"\n\t\t LADDER AT POSITION\n";
draw_line(50,'-');
cout<<"\n\tFrom 8 to 26\n\tFrom 21 to 82\n\tFrom 43 to 77\n\tFrom 50 to 91\n\tFrom 62 to 96\n\tFrom 66 to 87\n\tFrom 80 to 100\n";
draw_line(50,'-');
cout<<endl;
}

void gamescore(char name1[],char name2[],int p1, int p2)
{
cout<<"\n";
draw_line(50,'~');
cout<<"\n\t\tGAME STATUS\n";
draw_line(50,'~');
cout<<"\n\t--->"<<name1<<" is at position "<<p1<<endl;
cout<<"\t--->"<<name2<<" is at position "<<p2<<endl;
draw_line(50,'_');
cout<<endl;
}

void snake::playerdice(int &score)
{
int dice;
int i,randnum,a;
time_t t;
a=time(&t);
srand(a);
dice=((rand()%6)+1);
cout<<"\nYou got "<<dice<<" Point !! ";
score=score+dice;
switch(score)
{
case 98 :score=28;break;
case 95 :score=24;break;
case 92 :score=51;break;
case 83 :score=19;break;
case 73 :score=1;break;
case 69 :score=33;break;
case 64 :score=36;break;
case 59 :score=17;break;
case 55 :score=7;break;
case 52 :score=11;break;
case 48 :score=9;break;
case 46 :score=5;break;
case 44 :score=22;break;
case 8 :score=26;break;
case 21 :score=82;break;
case 43 :score=77;break;
case 50 :score=91;break;
case 54 :score=93;break;
case 62 :score=96;break;
case 66 :score=87;break;
case 80 :score=100;
}
}
void snake::play()
{
    int lastposition;
    cout<<"\n\n--->" <<playername<<" Now your Turn >> Press any key to play ";
    getch();
    lastposition=player;
    playerdice(player);
    if(player<lastposition)
    cout<<"\n\aOops!! Snake found !! You are at postion "<<playername<<"\n";
    else if(player>lastposition+6)
    cout<<"\nGreat!! you got a ladder !! You are at position "<<playername;

}

void draw_line1(int n,char ch)
{
for(int i=1;i<=n;i++)
if(i%4==0)
cout<<"|";
else
cout<<ch;
}
void draw_line2(int n,char ch)
{
for(int i=1;i<=n;i++)
if(i%4==0)
cout<<ch;
else
cout<<" ";
}


