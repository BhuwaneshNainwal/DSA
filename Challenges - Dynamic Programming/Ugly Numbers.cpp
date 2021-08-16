
/*
	à¥
		JAI SHREE RAM

		Hare Krishna Hare Krishna Krishna Krishna Hare Hare
		Hare Rama Hare Rama Rama Rama Hare Hare
	
												à¥
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

	
int ugly[100002];

void uglyNumber(int n)
{

	ugly[0] = 1;

	int next_multiple_two = 2 , next_multiple_three = 3 , next_multiple_five = 5;
	int i = 0 , j = 0 , k = 0;
	for(int l = 1 ; l < n ; l++)
	{
		int next_ugly = min3(next_multiple_two , next_multiple_five , next_multiple_three);

		ugly[l] = next_ugly;

		if(next_ugly == next_multiple_two)
		{
			i++;
			next_multiple_two = ugly[i] * 2; 
		}


		if(next_ugly == next_multiple_three)
		{
			j++;
			next_multiple_three = ugly[j] * 3; 
		}

		if(next_ugly == next_multiple_five)
		{
			k++;
			next_multiple_five = ugly[k] * 5; 
		}
	}

}
void solve()
{
	
	int n;
	cin >> n;	
	cout << ugly[n - 1] << "\n";
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
    cin>>T;

    uglyNumber(10005);
    while(T--)
    {
        solve();
    }

    return 0;
}