#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    printf("Enter a string: ");
    gets(s);

    int l = 0;
    while(s[l] != '\0')
    {
        if(s[l] >= 'a' && s[l] <= 'z')
            s[l] -= 32;
        else if(s[l] >= 'A' && s[l] <= 'Z')
            s[l] += 32;

        l++;
    }

    printf("%s", s);
}
