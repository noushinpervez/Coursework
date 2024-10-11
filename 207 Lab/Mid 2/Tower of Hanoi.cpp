#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from, char to, char middle)
{
	if (n > 0)
	{
        towerOfHanoi(n - 1, from, middle, to);
        cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;
        towerOfHanoi(n - 1, middle, to, from);
	}
}

int main()
{
	int n = 5;
	towerOfHanoi(n, 'X', 'Z', 'Y');
	return 0;
}
