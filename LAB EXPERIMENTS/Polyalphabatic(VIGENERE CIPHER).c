#include <stdio.h>

int main()
{
    char text[100],key[100];
    int ch,i,j=0,k;

    printf("1. Plain to Cipher\n");
    printf("2. Cipher to Plain\n");
    scanf("%d",&ch);

    printf("Enter text: ");
    scanf("%s",text);

    printf("Enter key: ");
    scanf("%s",key);

    for(i=0;text[i];i++)
    {
        k=key[j]-'A';

        if(ch==1)
            text[i]=(text[i]-'A'+k)%26+'A';
        else
            text[i]=(text[i]-'A'-k+26)%26+'A';

        j++;

        if(key[j]=='\0')
            j=0;
    }

    printf("Result: %s",text);

    return 0;
}
