#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int p1=0,p2=0,p3=0;
void clrscr()
{
    system("cls");
}
void delay()
{
    int d,c;
    for (c = 1; c <= 32767; c++)
        for (d = 1; d <= 32767; d++)
                {}
}
int check(char a[9])
{
    int x;
    if(  (a[0]==a[1]&&a[1]==a[2]&&a[0]=='X')||(a[3]==a[4]&&a[4]==a[5]&&a[3]=='X')||(a[6]==a[7]&&a[7]==a[8]&&a[6]=='X')  )
        x=1;
    else if(  (a[0]==a[3]&&a[3]==a[6]&&a[0]=='X')||(a[1]==a[4]&&a[4]==a[7]&&a[1]=='X')||(a[2]==a[5]&&a[5]==a[8]&&a[2]=='X')  )
        x=1;
    else if(  (a[0]==a[4]&&a[4]==a[8]&&a[0]=='X')||(a[2]==a[4]&&a[4]==a[6]&&a[2]=='X')  )
        x=1;
    else if(  (a[0]==a[1]&&a[1]==a[2]&&a[0]=='O')||(a[3]==a[4]&&a[4]==a[5]&&a[3]=='O')||(a[6]==a[7]&&a[7]==a[8]&&a[6]=='O')  )
        x=2;
    else if(  (a[0]==a[3]&&a[3]==a[6]&&a[0]=='O')||(a[1]==a[4]&&a[4]==a[7]&&a[1]=='O')||(a[2]==a[5]&&a[5]==a[8]&&a[2]=='O')  )
        x=2;
    else if(  (a[0]==a[4]&&a[4]==a[8]&&a[0]=='O')||(a[2]==a[4]&&a[4]==a[6]&&a[2]=='O')  )
        x=2;
    else
        x=0;
    return (x);
}
void print(char a[9])
{
    printf("\t\t\t\t %c | %c | %c \n",a[0],a[1],a[2]);
    printf("\t\t\t\t-----------\n");
    printf("\t\t\t\t %c | %c | %c \n",a[3],a[4],a[5]);
    printf("\t\t\t\t-----------\n");
    printf("\t\t\t\t %c | %c | %c \n",a[6],a[7],a[8]);

}
int main()
{
    clrscr();
    int i,j,pos,ch,c,d,b=2,x=0;
    char a[9]={'1','2','3','4','5','6','7','8','9'},q,name1[100],name2[100],change[100];
    printf("\t\tWELCOME TO THE WORLD FAMOUS GAME OF TIC TAC TOE.\n");
    printf("\n");
    printf("Player 1 type you name: ");
    gets(name1);
    printf("\n");
    printf("Player 2 type you name: ");
    gets(name2);
    print(a);
    printf("\n");
    printf("\tNOW THESE ARE THE POSITIONS OF THE 'X' AND 'O' WILL GO \n\tYOU JUST HAVE TO PUT THE NUMBER AS AN INPUT.\n");
    delay();
    delay();
    clrscr();
    printf("\tNOW WE CLEAR THIS AND GET READY TO PLAY. ALRIGHT?\n SO NOW...\n");
    delay();
    pa:
    clrscr();
    printf("\t\tTIC TAC TOE - DEVELOPED BY AVILASH\n\n\n\n\n");
    for(i=0;i<9;i++)
        a[i]=' ';
    print(a);

    for(i=1;i<=9;i++)
    {
        if(i%2!=0)
        {
            cp1:
            printf("\n\n\t%s enter your position: ",name1);
            scanf("%d",&pos);
            if(a[pos-1]!=' '||pos>9||pos<1)
            {
                printf("\nInvalid input! %s Give input again.",name1);
                goto cp1;
            }
            a[pos-1]='X';
            clrscr();
            printf("\t\tTIC TAC TOE - DEVELOPED BY AVILASH\n\n\n\n\n");
            print(a);
            ch=check(a);
            if(ch==1)
            {
                printf("\n\n%s wins!\n",name1);
                if(x%2==0)
                    p1++;
                else
                    p2++;
                x++;
                break;
            }
        }
        else
        {
            cp2:
            printf("\n\n\t%s enter your position: ",name2);
            scanf("%d",&pos);
            if(a[pos-1]!=' '||pos>9||pos<1)
            {
                printf("\nInvalid input! %s Give input again.",name2);
                goto cp2;
            }
            a[pos-1]='O';
            clrscr();
            printf("\t\tTIC TAC TOE - DEVELOPED BY AVILASH\n\n\n\n\n");
            print(a);
            ch=check(a);
            if(ch==2)
            {
                printf("\n\n%s wins!\n",name2);
                if(x%2==0)
                    p2++;
                else
                    p1++;
                x++;
                break;
            }
        }
    }
    if(ch==0)
    {
        printf("\n\nThe game is a draw. You both are really good or equally bad!\n");
        p3++;
        x++;
    }
    printf("\nNo of games = %d\n\nNo of times %s has won = %d\n\nNo of times %s has won = %d\n\nNo of draws = %d\n\n",x,name1,p1,name2,p2,p3);
    vi:
    printf("\nDo you want to play again? (y for yes and n for no) ");
    fflush(stdin);
    scanf("%c",&q);
    if(q=='y'||q=='Y')
    {
        if(x%2!=0)
        {
            for(j=0;name1[j]!='\0';j++)
                change[j]=name1[j];
            change[j]='\0';
            for(j=0;name2[j]!='\0';j++)
                name1[j]=name2[j];
            name1[j]='\0';
            for(j=0;change[j]!='\0';j++)
                name2[j]=change[j];
            name2[j]='\0';
        }
        goto pa;
    }
    else if(q=='n'||q=='N')
        return 0;
    else if(q!='y'||q!='Y'||q!='n'||q!='N')
    {
        clrscr();
        printf("\nEnter a valid input y or n\n");
        goto vi;
    }
    getch();
}
