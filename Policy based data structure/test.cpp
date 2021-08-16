#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int>s;
    pair<set<int>::iterator, bool> ret;
    s.insert(1);
    s.insert(5);
    s.insert(10);
    s.insert(3);
    ret = s.insert(10);
    cout<<ret.second<<endl;
    return 0;
}