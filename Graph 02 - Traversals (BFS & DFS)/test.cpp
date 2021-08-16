//I am adding header file for using cout and cin

#include<iostream>
using namespace std;


void local()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main()
{
	local();
	
	int a = 4;
	int b = 2;
	int c = a % b;
	cout << c;
}