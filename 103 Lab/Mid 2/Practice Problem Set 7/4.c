#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    printf("Enter a string: ");
    gets(s);

    int l = 0, v = 0, c = 0;
    while(s[l] != '\0')
    {
        if((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z'))
        {
            if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u')
                v++;
            else
                c++;
        }
        l++;
    }

    printf("Vowels: %d\n", v);
    printf("Consonents: %d", c);
}
