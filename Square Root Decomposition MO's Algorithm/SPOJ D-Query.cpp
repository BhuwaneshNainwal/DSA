
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

int fre[10000];
int distinct;

struct query
{
	int L;
	int R;
	int q_no;
	int block_no;

	bool operator < (query &q2)
	{
		if(block_no < q2.block_no)
			return 1;

		else if (block_no > q2.block_no)
			return 0;
		else
			return R < q2.R;
	}
};

void Add(int elem)
{
	if(fre[elem] == 0)
		distinct++;
	fre[elem]++;
}

void Remove(int elem)
{	
	fre[elem]--;
	if(fre[elem] == 0)
		distinct--;

}

void Adjust(int &curr_l , int &curr_r , query &q , vector<int> &ar)
{
	while(curr_l < q.L)
	{
		Remove(ar[curr_l]);
		curr_l++;
	}

	while(curr_l > q.L)
	{
		curr_l--;
		Add(ar[curr_l]);
	}

	while(curr_r < q.R)
	{	
		curr_r++;
		Add(ar[curr_r]);
	}

	while(curr_r > q.R)
	{	
		Remove(ar[curr_r]);
		curr_r--;
	}	
}	

void solve(vector<query> &queries , vector<int> &ar , int q)
{
	vector<int> answer(q1);

	sort(queries.begin(), queries.end());
	memset(fre , 0 , sizeof(fre));
	distinct = 0;

	int curr_l = queries[0].L;
	int curr_r = queries[0].R;


	for(int i = queries[0].L ; i <= queries[0].R ; i++)
	{
		Add(ar[i]);
	}

	answer[queries[0].q_no] = distinct;
	for(int i = 1 ; i < queries.size() ; i++)
	{
		Adjust(curr_l , curr_r , queries[i] , ar);
		answer[queries[i].q_no] = distinct;
	}

	for(int i = 0 ; i < answer.size(); i++)
		cout << answer[i] << " ";
}

void solve()
{
	
	int n , q;
	vector<query> queries(n);
	cin >> n;	
	vci ar(n);
	for(int i = 0 ; i < n ; i++)
		cin >> ar[i];
	int rn = sqrt(n);

	cin >> q;
		
	for(int i = 0 ; i < q ; i++)
	{
		int u , v;
		cin >> u >> v;
		queries[i].L = u - 1;
		queries[i].R = v - 1;
		queries[i].q_no = i;
		queries[i].block_no = u / rn;
	}

	solve(queries , ar , q);


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