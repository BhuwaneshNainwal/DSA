
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

const int M = 22;
int timer;
int tin[N];
int tout[N];

vector<int> gr[N];


bool is_ancestor(int x , int y)
{
	return (tin[x] <= tin[y] && tout[x] >= tout[y]);

}

//For first type of Euler tour tin[x] >= tin[y] then y lies in the subtree of x
void euler_tour_1(int cur , int par)
{
	// cout << cur << " ";
	tin[cur] = timer++;
	for(auto x : gr[cur])
	{
		if(x != par)
		{
			euler_tour_1(x , cur);
			tin[cur] = timer++;
			// cout << cur << " ";
		}
	}
	return;
}

void euler_tour_2(int cur , int par)
{
	tin[cur] = timer++;
	for(auto x : gr[cur])
	{
		if(x != par)
		{
			euler_tour_2(x , cur);
		}
	}
	tout[cur] = timer++;
	return;
}

void euler_tour_3(int cur , int par)
{
	tin[cur] = ++timer;
	for(auto x : gr[cur])
	{
		if(x != par)
		{
			euler_tour_3(x , cur);
		}
	}

	tout[cur] = timer;
	return;
}


void solve()
{

	int i , j , k , n , m , ans = 0 , cnt = 0 , sum = 0;
	cin >> n; 

	for(int i = 0 ; i < n - 1 ; i++)
	{
		int x , y;
		cin >> x >> y;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	euler_tour_1(1 , 0);
	// cout << tin[2] << " " << tout[2];
	timer = 0;
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