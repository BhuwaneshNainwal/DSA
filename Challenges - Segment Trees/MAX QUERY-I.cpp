
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


vector<int> vc[400005];

void merge(int ind , int i , int j)
{
	int k = 0 , l = 0;
	int len1 = vc[i].size();
	int len2 = vc[j].size();
	// int size = len1 + len2;
	while(k < len1 && l < len2)
	{
		if(vc[i][k] < vc[j][l])
			vc[ind].pb(vc[i][k++]);
		else
			vc[ind].pb(vc[j][l++]);
	}

	while(k < len1)
		vc[ind].pb(vc[i][k++]);
		
	while(l < len2)
		vc[ind].pb(vc[j][l++]);	
}

void build(int *arr ,  int ind, int s , int e)
{
	if(s == e)
	{
		// seg[ind] = arr[s];
		vc[ind].pb(arr[s]);
		return;
	}

	int mid = (s + e) / 2;
	build(arr ,  2 * ind , s , mid);
	build(arr ,  2 * ind + 1 , mid + 1 , e);
	merge(ind , 2 * ind , 2 * ind + 1);
}

/*
	Point update
	TC - O(log n) 
*/


/*
	O(log n)
*/
int range_query_point(int *arr , int ind , int qs , int qe , int k , int ss , int se)
{
		//No overlap at all
	if(qe < ss ||qs > se)
		return 0;
	
	if(ss >= qs && se <= qe)
	{
		int index = lower_bound(vc[ind].begin() , vc[ind].end() , k) - vc[ind].begin();
		return vc[ind].size() - index;
	}


	//Partial overlap
	int mid = (ss + se) / 2;
	int left = range_query_point(arr , 2 * ind , qs , qe , k , ss , mid);
	int right = range_query_point(arr , 2 * ind + 1 , qs , qe , k , mid + 1 , se);

	return left + right;
}
void solve()
{
	int n;
	cin >> n;
	int arr[n];
	
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];
	
	build(arr , 1 , 0 , n - 1);

	int q;
	cin >> q;
	while(q--)
	{
		int l , r , k;
		cin >> l >> r >> k;
		l -- , r --;
		cout << range_query_point(arr , 1  , l , r , k , 0 , n - 1) << "\n";
	}

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