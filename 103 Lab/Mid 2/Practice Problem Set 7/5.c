#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    printf("Enter the string: ");
    gets(s);

    int l = 0, i, j, flag = 0;
    while(s[l] != '\0')
        l++;
    int c[l];
    for(i = 0; i < l; i++)
    {
        flag = 1;
    	if(s[i] != '\0')
    	{
    	    for(j = i + 1; j < l; j++)
            {
                if(s[i] == s[j])
                {
                    flag++;
                    s[j] = '\0';
                }
            }
            printf("'%c' = %d, ", s[i], flag);
    	}
 	}
}
