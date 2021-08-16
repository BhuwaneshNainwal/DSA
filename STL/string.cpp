#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define nl << "\n"
using namespace std;



bool compare(string a , string b)
{
	if(a.length() == b.length())
		return a > b;
	return a.length() > b.length();
}
int main()
{
	string s0;

	cin >> s0;

	cout << s0 nl;
	
	//O( length(final string) )

	s0.append(" world!");
	cout << s0 nl;

	string s1 = "Welcome to competitive programming";

	string word = "to";
	int ind = s1.find(word);

	cout << ind nl;

	int len = word.length();
	s1.erase(ind , len + 1);
	cout << s1 nl;

	//same as s2 = ""
	string s2;

	if(s2.empty())
		cout << "string s2 is empty" nl;
	string s3 = "Mango";
	string s4 = "Apple";

	
	//O( max (s3.length() , s4.length()) )		
	

	int diff = s4.compare(s3);
	cout << diff nl;

	// Or

	if(s3 < s4)
		cout << "s4 is greater than s3" nl;
	else if( s3 == s4)
		cout << "Both are equal" nl;
	else
		cout << "s3 is greater" nl;



	//O( length(final string) )

	string s5 = "Hello ";
	
	s5 += "World!";

	cout << s5 nl;

	//o(1)
	string s6 = "H";
	s6.push_back('i'); 
	cout << s6 nl;

	for(int i = 0 ; i < s6.length() ; i++)
		cout << s6[i] << ":";
	cout nl;

	//string:: iterator it

	for(auto it = s6.begin() ; it != s6.end() ; it++)
		cout << (*it) << ":" ;
	cout nl;

	//Range based loops >> C++ 11

	for(auto c : s6)
		cout << c << ":";
	cout nl nl;

	//--------------------------------------------------------------------------//

	// sort
	int n ;
	cin >> n;

	string s7[n];

	for(int i = 0 ; i < n ; i++)
		getline(cin , s7[i]);

	sort(s7 , s7 + n , compare);
	
	for(int i = 0 ; i < n ; i++)
		cout << s7[i] nl;


//---------------------------------------------------------------------------------

// String tokenization

char str[100] = "Today is a new day";
	
char* c = strtok(str , " ");

cout << c << " ";
while(c != NULL)
{
	c = strtok(NULL, " ");
	cout << c << " ";
}

cout nl;

}