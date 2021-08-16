
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


vci add(vci ans , vci temp)
{

	reverse(ans.begin() , ans.end());
	reverse(temp.begin() , temp.end());
	while(temp.size() < ans.size())
		temp.pb(0);
	while(ans.size() < temp.size())
		ans.pb(0);
	int carry = 0;
	int i;
	for(i = 0 ; i < ans.size() ; i++)
	{
		int t = (carry + ans[i] + temp[i]);
		ans[i] = t % 10;
		carry = t / 10;
	}
	while(carry)
	{
		ans[i++] = ans[i] + carry % 10;
		carry = carry / 10;
	}
	while(ans.back() == 0)
		ans.pop_back();
	reverse(ans.begin() , ans.end());
	return ans;
}


vci subtract(vci arr1, vci arr2)
{
	reverse(arr1.begin() , arr1.end());
	reverse(arr2.begin() , arr2.end());

    while(arr2.size() < arr1.size())
        arr2.pb(0);
    int borrow = 0;

    for(int i = 0 ; i < arr1.size() ; i++)
    {
        if(borrow)
        {
            if(arr1[i] == 0)
            {
                arr1[i] = 9;
                borrow = 1;
            }
            else
            {
                arr1[i] = arr1[i] - 1;
                borrow = 0;
            }
        }

        if(arr1[i] < arr2[i])
        {
            borrow = 1;
            arr1[i] = arr1[i] + 10 - arr2[i];

        }
        else if(arr1[i] == arr2[i])
            arr1[i] = 0;
        else
            arr1[i] = arr1[i] - arr2[i];
    }
    int i = arr1.size() - 1;
    while(i >= 1 && arr1[i] == 0)
    {
        arr1.pop_back();
        i--;
    }

    reverse(arr1.begin(), arr1.end());
    return arr1;
}


vci multiply(vci arr1 , vci arr2)
{
	if(arr1.size() < arr2.size())
		swap(arr1 , arr2);

	vci ans(2 * arr1.size() , 0);
	
	reverse(arr1.begin() , arr1.end());
	int shift = arr2.size() - 1;

	for(int i = 0 ; i < arr2.size() ; i++)
	{
		vci temp(ans.size() , 0);
		int carry = 0;
		int ind = shift; 
		for(int j = 0 ; j < arr1.size() ; j++)
		{
			temp[ind++] = (carry + arr2[i] * arr1[j]) % 10;
			carry = (carry + arr2[i] * arr1[j]) / 10;
		}
		while(carry)
		{
			temp[ind++] = carry % 10;
			carry = carry / 10;
		}
		reverse(temp.begin() , temp.end());
		ans = add(temp , ans);
		shift--;
	}

	
	return ans;
}

//f(x) = 3 * x ^ 2 - x + 10;
//g(x) = 4 * x ^ 3 + 2 * x ^ 2 - 5 * x + 4
// n(x) = 4 * x ^ 3 + 5 * x ^ 2 - 6 * x + 14;

void solve()
{

	string n;
	cin >> n;
	vci arr1; 
	for(int i = 0 ; i < n.size() ; i++)
		arr1.pb(n[i] - '0');
	
	vci square = multiply(arr1 , arr1);
	vci cube = multiply(square , arr1);
	vci temp = {4};

	vci ans = multiply(cube , temp);
	
	// for(auto val : ans)
	// 	cout << val;
	temp = {5};
	ans = add(ans , multiply(square , temp));

	temp = {1 , 4};
	ans = add(temp, ans);
	temp = {6};
	ans = subtract(ans , multiply(arr1 , temp));

	for(auto val : ans)
		cout << val;
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