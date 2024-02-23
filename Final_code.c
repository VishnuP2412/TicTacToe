/*This code is developed to run a tic-tac-toe game without any kind of graphics*/
//everything seems done except to check if the game is over or not and to choose the winner


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


void game( int x);
void print(int g[][3]);
void check(int g[][3], int x);


char *p1,*p2;


void main()
{
    int sp;
    int c;
    p1=malloc(100);
    p2=malloc(100);
    error:
    if(c!=1)
    {
     printf("\n\n");
    } 
    printf("Press 1 to start the game and 2 to see the rules  \n");
    scanf("%d", &c);
    if(c==2)
    {
        printf("\nRules:\n1. The first player to get 3 of their marks in a row(vertial, horizontal or diagonal) is considered the winner and the game is over.\n2. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie");
    }
    if(c!=1)
    {
        goto error;
    }
    printf("\nEnter a player 1 name: ");
    //reads name of player 1
    while((getchar())!='\n');
    fgets(p1,100, stdin);
    printf("\nEnter a player 2 name: ");
    //reads name of player 2
    fgets(p2, 100, stdin);
    if((strlen(p1)==0)||(strlen(p2)==0))
    {
        printf("\nInvalid Name. Try again");
        goto  error;
    }
    srand(time(0));
    sp=rand();
    //printf("\nNUmber is %d", sp);
    if(sp%2==0)
    {
        printf("\nPlayer 1 will start using the symbol 'x'");
        sp=1;
    }
    else
    {
        printf("\nPlayer 2 will start using the symbol 'x'");
        sp=0;
    }
    printf("enter row first, then column and the range is 1-3");
    printf("\n--------------------------------------------------\n");
    printf("Lets start the game.\n");
    game(sp);
}


void game(int x)
{
    int g[3][3];
    int i,j;
    int ct,t;
    int u=0;
    char a;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            g[i][j]=0;
        }
    }
    print(g);
    for(ct=1;ct<=9;ct++)
    {
        try:
        printf("enter where you want to place your mark: ");
        if(u==0)
        {
            //while((getchar())!='\n');
            a='\0';
            u++;
        }
        scanf("%d %d", &i, &j);
        if(ct%2!=0 && g[i-1][j-1]==0)
        {
            g[i-1][j-1]=1;
            print(g);
        }
        else if(ct%2==0 &&  g[i-1][j-1]==0)
        {
            g[i-1][j-1]=2;    
            print(g);
        }
        else
        {
            printf("invalid move try again \n");
            goto try;
        }
        if(ct >= 5)
        {
            check(g,x);
        }
    }
}


void print(int g[][3])
{
    int i, j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(g[i][j]==1)
            {
                printf(" x ");
            }
            else if(g[i][j]==2)
            {
                printf(" o ");
            }
            else
            {
                printf(" - ");
            }
        }
        printf("\n");
    }
}


void check(int g[][3],int x)
{
    if(x==1)
    {
     if (g[0][0]==g[1][1] && g[0][0]==g[2][2])
     {
      if(g[0][0]==1)
       {
         printf("\n Winner is %s", p1);
         exit(0);
       }
      else
      if(g[0][0]==2)
       {
         printf("\n Winner is %s", p2);
         exit(0);
       }
     }
     else
     if (g[0][0]==g[0][1] && g[0][0]==g[0][2])
     {
      if(g[0][0]==1)
       {
         printf("\n Winner is %s", p1);
         exit(0);
       }
      else
      if(g[0][0]==2)
       {
         printf("\n Winner is %s", p2);
         exit(0);
       }
     }
     else
     if (g[0][0]==g[1][0] && g[0][0]==g[2][0])
     {
      if(g[0][0]==1)
       {
         printf("\n Winner is %s", p1);
         exit(0);
       }
      else
      if(g[0][0]==2)
       {
         printf("\n Winner is %s", p2);
         exit(0);
       }
     }
     else
     if (g[1][0]==g[1][1] && g[1][0]==g[1][2])
     {
      if(g[1][0]==1)
       {
         printf("\n Winner is %s", p1);
         exit(0);
       }
      else
      if(g[1][0]==2)
       {
         printf("\n Winner is %s", p2);
         exit(0);
       }
     }
     else
     if (g[0][1]==g[1][1] && g[0][1]==g[2][1])
     {
      if(g[0][1]==1)
       {
         printf("\n Winner is %s", p1);
         exit(0);
       }
      else
      if(g[0][1]==2)
       {
         printf("\n Winner is %s", p2);
         exit(0);
       }
     }
     else
     if (g[0][2]==g[1][1] && g[0][2]==g[2][0])
     {
      if(g[0][2]==1)
       {
         printf("\n Winner is %s", p1);
         exit(0);
       }
      else
      if(g[0][2]==2)
       {
         printf("\n Winner is %s", p2);
         exit(0);
       }
     }
     else
     if (g[0][2]==g[1][2] && g[0][2]==g[2][2])
     {
      if(g[0][2]==1)
       {
         printf("\n Winner is %s", p1);
         exit(0);
       }
      else
      if(g[0][2]==2)
       {
         printf("\n Winner is %s", p2);
         exit(0);
       }
     }
     else
     if (g[2][0]==g[2][1] && g[2][0]==g[2][2])
     {
      if(g[2][0]==1)
       {
         printf("\n Winner is %s", p1);
         exit(0);
       }
      else
      if(g[2][0]==2)
       {
         printf("\n Winner is %s", p2);
         exit(0);
       }
     }
    }
    else 
    if(x==0)
    {
         if (g[0][0]==g[1][1] && g[0][0]==g[2][2])
     {
      if(g[0][0]==1)
       {
         printf("\n Winner is %s", p2);
         exit(0);
       }
      else
      if(g[0][0]==2)
       {
         printf("\n Winner is %s", p1);
         exit(0);
       }
     }
     else
     if (g[0][0]==g[0][1] && g[0][0]==g[0][2])
     {
      if(g[0][0]==1)
       {
         printf("\n Winner is %s", p2);
         exit(0);
       }
      else
      if(g[0][0]==2)
       {
         printf("\n Winner is %s", p1);
         exit(0);
       }
     }
     else
     if (g[0][0]==g[1][0] && g[0][0]==g[2][0])
     {
      if(g[0][0]==1)
       {
         printf("\n Winner is %s", p2);
         exit(0);
       }
      else
      if(g[0][0]==2)
       {
         printf("\n Winner is %s", p1);
         exit(0);
       }
     }
     else
     if (g[1][0]==g[1][1] && g[1][0]==g[1][2])
     {
      if(g[1][0]==1)
       {
         printf("\n Winner is %s", p2);
         exit(0);
       }
      else
      if(g[1][0]==2)
       {
         printf("\n Winner is %s", p1);
         exit(0);
       }
     }
     else
     if (g[0][1]==g[1][1] && g[0][1]==g[2][1])
     {
      if(g[0][1]==1)
       {
         printf("\n Winner is %s", p2);
         exit(0);
       }
      else
      if(g[0][1]==2)
       {
         printf("\n Winner is %s", p1);
         exit(0);
       }
     }
     else
     if (g[0][2]==g[1][1] && g[0][2]==g[2][0])
     {
      if(g[0][2]==1)
       {
         printf("\n Winner is %s", p2);
         exit(0);
       }
      else
      if(g[0][2]==2)
       {
         printf("\n Winner is %s", p1);
         exit(0);
       }
     }
     else
     if (g[0][2]==g[1][2] && g[0][2]==g[2][2])
     {
      if(g[0][2]==1)
       {
         printf("\n Winner is %s", p2);
         exit(0);
       }
      else
      if(g[0][2]==2)
       {
         printf("\n Winner is %s", p1);
         exit(0);
       }
     }
     else
     if (g[2][0]==g[2][1] && g[2][0]==g[2][2])
     {
      if(g[2][0]==1)
       {
         printf("\n Winner is %s", p2);
         exit(0);
       }
      else
      if(g[2][0]==2)
       {
         printf("\n Winner is %s", p1);
         exit(0);
       }
     }
    }
}
