
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
	log2 takes lot of time.
	log2(n) = log(n / 2) + 1
*/


struct sparse_table
{
	vector<vector<int>> mat; // 2-d matrix;
	int n , m;				//size and log
	vector<int> p2;

	void init(int _n , int _m)
	{
		n = _n;
		m = _m;
		mat.resize(n);
		p2.resize(n + 1);
		for(int i = 0 ; i < n ; i++)
			mat[i].resize(m);
		
		//log2n
		for(int i = 1 ; i <= n ; i++)
			p2[i] = p2[i / 2] + 1;
	}

	void build(int a[])
	{
		for(int i = 0 ; i < n ; i++)
			mat[i][0] = a[i];
		
		for(int j = 1 ; j < m ; j++)
		{
			for(int i = 0 ; i + (1 << j) <= n ; i++)
				mat[i][j] = min(mat[i][j - 1] , mat[i + 1 << (j - 1)][j - 1]);
		}
	}

	int query(int l , int r)
	{
		int pw = p2[r - l];
		
		//Starting pow and ending pow
		return min(mat[l][pw] , mat[r - (1 << pw) + 1][pw]);
	}



};


void solve()
{
	int i , j , k , n , m , ans = 0 , cnt = 0 , sum = 0;	

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