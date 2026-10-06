#include <stdio.h>
#include <string.h>

char a[5][5];

void makekey(char key[])
{
    int used[26]={0},i,j,k=0;
    char c;

    for(i=0;key[i];i++)
    {
        c=key[i];
        if(c=='J') c='I';
        if(!used[c-'A'])
        {
            a[k/5][k%5]=c;
            used[c-'A']=1;
            k++;
        }
    }

    for(c='A';c<='Z';c++)
        if(c!='J' && !used[c-'A'])
        {
            a[k/5][k%5]=c;
            used[c-'A']=1;
            k++;
        }
}

void pos(char c,int *r,int *col)
{
    int i,j;
    if(c=='J') c='I';

    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            if(a[i][j]==c)
            {
                *r=i;
                *col=j;
            }
}

int main()
{
    char key[30],text[100];
    int ch,i,r1,r2,c1,c2;

    printf("Enter key: ");
    scanf("%s",key);
    makekey(key);

    printf("1. Plain to Cipher\n2. Cipher to Plain\n");
    scanf("%d",&ch);

    printf("Enter text: ");
    scanf("%s",text);

    for(i=0;text[i];i+=2)
    {
        pos(text[i],&r1,&c1);
        pos(text[i+1],&r2,&c2);

        if(r1==r2)
        {
            if(ch==1)
            {
                c1=(c1+1)%5;
                c2=(c2+1)%5;
            }
            else
            {
                c1=(c1+4)%5;
                c2=(c2+4)%5;
            }
        }
        else if(c1==c2)
        {
            if(ch==1)
            {
                r1=(r1+1)%5;
                r2=(r2+1)%5;
            }
            else
            {
                r1=(r1+4)%5;
                r2=(r2+4)%5;
            }
        }

        if(r1==r2)
            printf("%c%c",a[r1][c1],a[r2][c2]);
        else if(c1==c2)
            printf("%c%c",a[r1][c1],a[r2][c2]);
        else
            printf("%c%c",a[r1][c2],a[r2][c1]);
    }

    return 0;
}
