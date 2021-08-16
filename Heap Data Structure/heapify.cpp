
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


class Heap
{
public:
    vci a;
    int size = 0;
    Heap(vci &a)
    {
        int n = a.size();
        this -> a = a;
        size = n;
    }

    void heapify()
    {
        for(int i = size - 1 ; i >= 0 ; i--)
        {
            int mx = -INF;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if(left >= size && right >= size)
                continue;
            if(left < size)
                mx = max(mx, a[left]);
            if(right < size)
                mx = max(mx, a[right]);
            if(left < size && a[left] == mx && mx > a[i])
                swap(a[left], a[i]);
            if(right < size && a[right] == mx && mx > a[i])
                swap(a[right], a[i]);
        }
    }

    vci getHeap()
    {
        return a;
    }

    void push(int x)
    {
        if(size >= a.size())
            a.pb(0);
        a[size++] = x;
        int pos = size - 1;
        int parent = (size - 2) / 2;
        while(parent >= 0 && a[parent] < a[pos])
        {
            swap(a[pos], a[parent]);
            pos = parent;
            parent = ((parent - 1) < 0) ? -1 : (parent - 1) / 2;
        }
    }

    void pop()
    {
        if(size == 0)
            return;
        if(size == 1LL)
        {
            a[0] = -INF;
            size--;
            return;
        }
        a[0] = a[size - 1];
        size--;
        int parent = 0;
        int left = 2 * parent + 1;
        int right = 2 * parent + 2;


        while(right < size || left < size)
        {
            int mx = -INF;
            if(left < size && a[left] > mx)
                mx = a[left];
            if(right < size && a[right] > mx)
                mx = a[right];
            if(mx == -INF || mx < a[parent])
                break;

            if(right < size && a[right] == mx)
            {
                swap(a[right], a[parent]);
                parent = right;
                left = 2 * parent + 1;
                right = 2 * parent + 2;
            }
            if(left < size && a[left] == mx)
            {
                swap(a[left], a[parent]);
                parent = left;
                left = 2 * parent + 1;
                right = 2 * parent + 2;
            }
        }
    }

    int top()
    {
        return a[0];
    }

    void heapSort()
    {
        int k = size;
        while(size > 0)
        {
            int val = a[0];
            pop();
            a[size] = val;
        }
        size = k;

    }
};



void solve()
{
    int n;
    cin >> n;

    //Input elements as level order in an array
    vci a(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];

    Heap h(a);
    h.heapify();


    h.push(100);
    h.push(200);
    h.push(100);
    h.push(200); h.push(100);
    h.push(200);


    h.heapSort();
    vci ans = h.getHeap();
    for(int i = 0 ; i < h.size ; i++)
        cout << ans[i] << ' ';
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