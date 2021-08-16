#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        ll presum[n + 1];
        presum[0] = 0;
        for(int i = 0; i < n; i++)
        {

            cin >> arr[i];
            presum[i + 1] = arr[i] + presum[i];
        }
        map<ll, ll>m;
        for(int i = 1; i < n; i++)
        {
            m[i] = -1;
        }
        m[0] = 0;
        int l = 0, r = 0;
        for(int i = 1; i <= n; i++)
        {
            ll mod = presum[i] % n;
            if(m[mod] != -1)
            {
                l = m[mod];
                r = i;
                break;
            }
            else
            {
                m[mod] = i;
            }
        }

        cout << r - l << endl;
        for(int i = l; i < r; i++)
        {
            cout << i + 1 << " ";

        }
        cout << endl;
    }
}