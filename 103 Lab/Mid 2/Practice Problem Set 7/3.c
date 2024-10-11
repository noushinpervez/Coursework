#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    printf("Enter a string: ");
    gets(s);

    int l = 0, a = 0, d = 0, sc = 0;
    while(s[l] != '\0')
    {
        if((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z'))
            a++;
        else if(s[l] >= '0' && s[l] <= '9')
            d++;
        else
            sc++;

        l++;
    }

    printf("Alphabets: %d\n", a);
    printf("Digits: %d\n", d);
    printf("Special Characters: %d", sc);
}

