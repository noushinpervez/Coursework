#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    printf("Enter a string: ");
    gets(s);

    int l = 0;
    while(s[l] != '\0')
        l++;

    printf("%d", l);
}
