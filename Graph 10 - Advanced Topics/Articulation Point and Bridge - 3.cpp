
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
	Finding articulation points and bridges in a graph.

*/


vector<int> gr[N];
int disc[N] = {0} , low[N] = {0} , tme;
vector<pair<int , int>> bridge;
set<int> art_p;

void dfs(int cur , int par)
{
	disc[cur] = low[cur] = tme++;
	int no_of_child = 0;
 	for(auto child : gr[cur])
 	{
 		if(disc[child] == 0)
 		{
 			no_of_child++;
 			dfs(child , cur);
 			low[cur] = min(low[cur] , low[child]);
 		
 			if(par != 0 && low[child] >= disc[cur])
 				art_p.insert(cur);
 			
 			if(low[child] > disc[cur])
 				bridge.pb({cur , child});
 		}
 		else if(child != par)
 		{
 			//Backedge
 			low[cur] = min(low[cur] , disc[child]); 
 		}
 	}

 	//Separate case

 	if(par == 0 && no_of_child >= 2)
 		art_p.insert(cur); 
 	return;
}

void solve()
{
	
	int i , j , k  , n , m , ans = 0 , sum = 0;
	cin >> n >> m;

	for(int i = 0 ; i < m ; i++)
	{
		int x , y;
		cin >> x >> y;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	tme = 1;
	dfs(1 , 0);

	for(auto point : art_p)
		cout << point << " ";
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