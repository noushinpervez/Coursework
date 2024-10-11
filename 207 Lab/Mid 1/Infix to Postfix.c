#include <stdio.h>

int stack[50];
int top=-1;
int decimal=0;

int isDigit(char ch)
{
    if(ch>='0' && ch<='9')
        return 1;
    else
        return 0;
}

int pop()
{
    return(stack[top--]);
}

int push(int value)
{
    if(decimal==1)
    {
        int num;
        num=pop();
        stack[++top]=value+10*num;
    }
    else if(decimal==0)
    {
        stack[++top]=value;
        decimal=1;
    }
}

int isoperand(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        return 1;
    else
        return 0;

}

int postfix()
{
    char postfix[50], ch;
    char infix[50];
    int p = 0;
    int i=0,op1,op2;
    printf("Enter the Postfix Expression: ");
    fgets(postfix,100,stdin);
    printf("Result : ");

    while((ch=postfix[i++]) != '\n')
    {
    if(isDigit(ch))
        push(ch-'0');
    else if(ch==' ')
        decimal=0;
    else
    {
        decimal=0;
        op2=pop();
        op1=pop();
        if(p == 0)
        {
            printf("%d %c %d",op1,ch,op2);
            p++;
        }
        else
            printf("%c %d",ch,op2);
        switch(ch)
        {
            case '+':push(op1+op2);
            break;
            case '-':push(op1-op2);
            break;
            case '*':push(op1*op2);
            break;
            case '/':push(op1/op2);
            break;

            default:
                 printf("Input invalid\n");
                 break;
        }
    }
    }
    printf(" = %d\n",stack[top]);
}

int infixtopostfix()
{
    char postfix[50], ch;
    char infix[50];
    char temp,x;
    int i=0,j=0;
    printf("Enter the Postfix Expression: ");
    fgets(postfix,100,stdin);
    printf("Result : ");
    while((ch=postfix[i++]) != '\n')
    {
        if(isDigit(ch))
        postfix[j++]=temp;
        else if(ch==' ')
        decimal=0;

        else if(ch=='(')
         push(ch-'0');
        else if(ch==')')
            {
         while((x=pop())!='(')
         {
          postfix[j++]=x;
           }
          }
        else
        {  while(prcd(a[top])>=prcd(temp))
            {postfix[j++]=pop();}
                push(temp);
        }
        i++;
    }
    while(top!= -1)
    postfix[j++]=pop();
    postfix[j]='\0';
}

int main()
{
    infixToPostfix();
    postfix();
}
