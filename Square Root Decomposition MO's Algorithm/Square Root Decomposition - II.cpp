
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



void update(int *blocks , int *arr , int i , int val , int rn)
{
	int block_id = i / rn;
	blocks[block_id] += (val - arr[i]);
	arr[i] = val;
}

int query(int *blocks , int *arr , int l , int r , int rn)
{
	int ans = 0;
	
	while(l < r && l != 0 && l % rn != 0)
	{
		ans += arr[l];		
		l++;
	}	

	//Middle part
	while(l + rn <= r)
	{
		int block_id = l / rn;
		ans += blocks[block_id];
		l += rn;
	}

	while(l <= r)
	{
		ans += arr[l];
		l++;
	}

	return ans;

}

void solve()
{
	int arr[] = {1 , 3 , 5 , 2 , 7 , 6 , 3 , 1 , 4 , 8};
	int n = sizeof(arr) / sizeof(int);

	int rn = sqrt(n);
	int *blocks = new int[rn + 1]{0};

	//Build the array
	int block_id = -1;
	for(int i = 0 ; i < n ; i++)
	{
		if(i % rn == 0)
		{
			block_id++;
		}
		blocks[block_id] += arr[i];
	}

	int l , r;
	// cin >> l >> r;
	
	update(blocks , arr , 2 , 15 , rn);
	cout << query(blocks , arr , 2 , 8 , rn);
	

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