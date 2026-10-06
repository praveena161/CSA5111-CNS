#include <stdio.h>
int main(){
    char text[100];
    int k, i, choice;
    printf("1. Plain to Cipher\n");
    printf("2. Cipher to Plain\n");
    scanf("%d", &choice);
    printf("Enter text: ");
    scanf(" %[^\n]", text);
    printf("Enter key: ");
    scanf("%d", &k);
    for(i = 0; text[i] != '\0'; i++){
        if(text[i] >= 'A' && text[i] <= 'Z') {
            if(choice == 1)
                text[i] = (text[i] - 'A' + k) % 26 + 'A';
            else
                text[i] = (text[i] - 'A' - k + 26) % 26 + 'A';
        }
        else if(text[i] >= 'a' && text[i] <= 'z'){
            if(choice == 1)
                text[i] = (text[i] - 'a' + k) % 26 + 'a';
            else
                text[i] = (text[i] - 'a' - k + 26) % 26 + 'a';
        }
    }
    printf("Result: %s", text);
    return 0;
}
