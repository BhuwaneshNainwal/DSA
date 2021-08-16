
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


	
bool dfs(int node , int parent , int color , vci gr[] , vci &vis)
{
	vis[node] = color;
	for(auto nbr : gr[node])
	{
		if(vis[nbr] == 0)
		{
			bool subprblm = dfs(nbr , node , 3 - color , gr , vis);
			if(!subprblm)
				return false;
		}
		else if(nbr != parent && vis[nbr] == color)
			return false;
	}
	return true;
}


void solve()
{
	
	int n;
	cin >> n;

	int l , r , v;

	vci gr[N];
	vci vis(N , 0);

	//2d vector
	vector<vector<int>> vc;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> l >> r >> v;
		vc.pb({l , r , v});	
	}


	sort(vc.begin() , vc.end());

	for(int i = 0 ; i < n ; i++)
	{
		for(int  j = i + 1 ; j < n ; j++)
		{
			if(vc[j][0] <= vc[i][1] && vc[i][2] == vc[j][2])
			{
				gr[i].pb(j);
				gr[j].pb(i);
			}
		}
	}
	

	bool ans = true;
	for(int i = 0 ; i < n ; i++)
	{

		if(vis[i] != 0)
			continue;

		bool check = dfs(i , -1 , 1 , gr , vis);
		if(!check)
		{
			ans = false;			
			break;
		}
	}
	if(ans)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
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

    while(T--)
    {
        solve();
    }

    return 0;
}