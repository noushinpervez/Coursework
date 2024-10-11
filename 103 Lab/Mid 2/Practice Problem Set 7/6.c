#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    printf("Enter the string: ");
    gets(s);

    int l = 0, i, flag = 0;
    while(s[l] != '\0')
        l++;
    for(i = 0; i < l / 2; i++)
    {
        if(s[i] != s[l -  i - 1])
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
        printf("Not a palindrome");
    else
        printf("Palindrome");
}
