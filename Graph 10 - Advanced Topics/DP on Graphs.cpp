
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
	Q> Find the smallest height of a node that can be visited from a subtree
	   of x using a single backedge.
*/


/*
	DFS tree - The tree that consists only those edges if we apply dfs.
	
	Span edge - The edge which is the part of dfs traversal.
	Back edge - The edge which is not the part of dfs travesal and generates cycle in
	the original graph.
*/

vector<int> gr[N];
int dp[N];
int depth[N];

vector<bool> visited(N , false);

void dfs(int cur , int par , int dep)
{
	visited[cur] = true;
	dp[cur] = dep;
	depth[cur] = dep;
	for(auto x : gr[cur])
	{
		if(visited[x] == false)
		{
			dfs(x , cur , dep + 1);
			dp[cur] = min(dp[cur] , dp[x]);
		}

		else if(x != par)
		{
			//backedge
			dp[cur] = min(dp[cur] , depth[x]);
		}
	}
}

void solve()
{
	int n , m;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++)
	{
		int x , y;
		cin >> x >> y;
		gr[x].pb(y);
		gr[y].pb(x);
	}
		
	dfs(1 , 0 , 0);
	for(int i = 0 ; i < n ; i++)
		cout << i << " " << dp[i] << "\n";

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