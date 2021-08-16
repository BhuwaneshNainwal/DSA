
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
const int M = 22;
const int chkprc = 1e-9;  // Check for precision error in double

/*
	LCA using depth
	O(log) time for finding LCA

*/


int par[N][M];
int depth[N] = {0};
vector<int> gr[N];

void dfs(int cur , int parent)
{
	// par[cur] = parent;
	for(auto x : gr[cur])
	{
		if(x != parent)
		{
			depth[x] = depth[cur] + 1;
			dfs(x , cur);
		}
	}
	return;
}

//Sparse table
void sparse_table(int cur , int parent)
{
	par[cur][0] = parent;
	for(int j = 1 ; j < M ; j++)
		par[cur][j] = par[par[cur][j - 1]][j - 1]; 

	for(auto x : gr[cur])
	{
		if(x != parent)
			sparse_table(x , cur);
	}
}

//Binary Lifting is being used

int LCA_using_depth(int u , int v)
{
	if(u == v)
		return u;
	
	if(depth[u] < depth[v])
		swap(depth[u] , depth[v]);

	int diff = depth[u] - depth[v];

	for(int i = M - 1 ; i >= 0 ; i--)
	{
		if((diff >> i) & 1)
			u = par[u][i];
	}

	if(u == v)
		return u;

	for(int i = M - 1 ; i >= 0 ; i--)
	{
		if(par[u][i] != par[v][i])
		{
			u = par[u][i];
			v = par[v][i];
		}
	}

	//Standing on different node
	return par[u][0];

}

void solve()
{
	int i , j , k , n , m , ans = 0 , cnt = 0 , sum = 0;
	cin >> n;

	for(int i = 1 ; i < n ; i++)
	{
		int x , y;
		cin >> x >> y;
		gr[x].pb(y);
		gr[y].pb(x);
	}	

	dfs(1 , 0);
	sparse_table(1 , 0);
	cout << LCA_using_depth(6 , 4);
	// cout << lca_brute(18 , 16) << "\n";

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