
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
const int M = 22;
const int N = 1e4;
const int chkprc = 1e-9;  // Check for precision error in double

/*

	It is O(log n) algorithm based on sparse table and Euler tour.

*/


vector<int> gr[N];
int par[N][M] , dep[N] , tin[N] , tout[N];
int timer;

void dfs(int cur , int parent)
{
	tin[cur] = ++timer;
	for(auto x : gr[cur])
	{
		if(x != parent)
		{
			dep[x] = dep[parent] + 1;
			dfs(x , cur);
		}
	}
	tout[cur] = timer;
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

bool is_ancestor(int u , int v)
{
	return tin[u] <= tin[v] && tout[u] >= tin[v];
}


int LCA_using_time(int u , int v)
{
	if(is_ancestor(u , v))
		return u;

	if(is_ancestor(v , u))
		return v;
	
	for(int i = M - 1 ; i >= 0 ; i--)
	{
		if(!is_ancestor(par[u][i] , v))
			u = par[u][i];

	}

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


	timer = 0;

	//0 is the universal parent
	tin[0] = 0;
	tout[0] = n + 1; 
	dfs(1 , 0);

	sparse_table(1 , 0);
	cout << LCA_using_time(3 , 8);

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