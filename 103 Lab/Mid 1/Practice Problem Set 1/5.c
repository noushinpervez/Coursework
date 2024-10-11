#include<stdio.h>
int main()
{
    int sec, h, m, s, min;
	printf("Input seconds: ");
	scanf("%d", &sec);

	s = sec % 60;
	min = sec / 60;
	m = sec % 60;
	h = min / 60;

	if(min < 24)
        printf("%d: %d: %d", h, min, s);
    else
        printf("%d: %d: %d", h, m, s);
}
