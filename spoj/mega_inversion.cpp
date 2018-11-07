#include <bits/stdc++.h>
#define f(i,a,b) for(int i = a; i <= b; i++)

typedef long long ll;
using namespace std;
int N;

vector<ll> T1(100005, 0), T2(100005, 0);

void update(vector<ll> &t, int x, ll v)
{
    while(x>0)
    {
        t[x] += v;
        x -= x&-x;
    }
}

ll query(vector<ll> &t, int x)
{
    ll ret = 0;
    while(x <= N)
    {
        ret += t[x];
        x += x&-x;
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    ll ans = 0;
    f(i,1,N)
    {
        int x;
        scanf("%d", &x);
        update(T1, x, 1);
        int q = query(T1, x+1);
        update(T2, x, q);
        ans += query(T2, x+1);
    }
    cout << ans;
}
