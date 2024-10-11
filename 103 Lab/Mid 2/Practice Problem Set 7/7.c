#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    printf("Enter the string: ");
    gets(s);

    int l = 0, i, j;
    while(s[l] != '\0')
        l++;
    for(i = 0; i < l; i++)
    {
        for(j = 0; j <= i; j++)
            printf("%c", s[j]);

        printf("\n");
    }
}
