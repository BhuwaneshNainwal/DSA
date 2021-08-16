
/*
	ॐ
		JAI SHREE RAM

		Hare Krishna Hare Krishna Krishna Krishna Hare Hare
		Hare Rama Hare Rama Rama Rama Hare Hare
	
												ॐ
*/

//Written by Bhuwanesh Nainwal
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
pbds;



#define fast            	ios_base::sync_with_stdio(false) , cin.tie(NULL) , cout.tie(NULL)
#define int					long long int
#define vci              	vector<int>
#define vcvci             	vector<vector<int>>
#define vcpi             	vector<pair<int,int>>
#define vcs					vector<string>
#define pb              	push_back
#define mpii             	map<int , int>
#define mpsi             	map<string , int>
#define mpci             	map<char , int>
#define umpii             	unordered_map<int , int>
#define umpsi             	unordered_map<string , int>
#define umpci             	unordered_map<char , int>
#define all(x)				auto it = x.begin() ; it != x.end() ; it++
#define vcc              	vector<char>
#define vcs              	vector<string>
#define sti            		set<int>
#define stc            		set<char>
#define sts            		set<string>
#define pqmx				priority_queue<int>
#define pqmn				priority_queue<int , vi , greater<int>>
#define null            	NULL
#define ff            		first
#define ss              	second
#define stb(x)				__builtin_popcount(x)
#define lzr(x)				__builtin_clz(x)
#define tzr(x)					__builtin_ctz(x)
#define prc(x , y)          fixed << setprecision(y) << x
#define max3(a, b, c)   	max(a, max(b, c))
#define min3(a, b, c)   	min(a, min(b, c))

using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e9;
const int LINF = 1e18;
const int N = 1e4;
const int chkprc = 1e-9;  // Check for precision error in double


/*
	Right side will be used for expansion and left side will be used for contraction.
	Whenever we will get the required window we will update our minimum window length. 

*/

string findWindow(string &s , string &pat)
{
	int sl = s.length();
	int pl = pat.length();

	if(pl > sl)
		return "None";

	//frequency maps
	int fs[256] = {0};
	int fp[256] = {0};

	for(int i = 0 ; i < pl ; i++)
	{
		char ch = pat[i];
		fp[ch]++;
	}

	int cnt = 0;
	int start = 0;

	int min_len = INT_MAX;
	int start_idx = -1;

	//Sliding window (Expansion and Contraction + Update the min length window)
	for(int i = 0 ; i < sl ; i++)
	{
		char ch = s[i];
		fs[ch]++;

		if(fp[ch] != 0 && fs[ch] <= fp[ch])
			cnt++;
		
		if(cnt == pl)
		{
			//Start shirinking the window
			//Loop to remove all unwanted characters

			char temp = s[start];
			//Loop to remove all unwanted characters

			while(fp[temp] == 0 || fs[temp] > fp[temp])
			{
				fs[temp]--;
				start++;
				temp = s[start];
			}

			int window_len = i - start + 1;

			if(window_len < min_len)
			{
				min_len = window_len;
				start_idx = start;
			}

		}
	}

	if(start_idx == -1)
		return "None";
	
	string ans = s.substr(start_idx , min_len);
	return ans;

}
void solve()	
{
	
	string s = "hllloeaeo world";
	string p = "eelo";

	cout << findWindow(s , p);

}

void local()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int32_t main()
{

    fast;
    local();
    int T = 1;
    // cin>>T;

    while(T--)
    {
        solve();
    }

    return 0;
}