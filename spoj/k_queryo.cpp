#include <bits/stdc++.h>
using namespace std;

#define pb(a)                   push_back((a))
#define lc                      ((n)<<1)
#define rc                      ((n)<<1|1)

const int N = 4e5+5;
int n,q;
int a[N];
vector<int>v;
vector<int> seg[N];
void build(int n,int b,int e)
{
    if(b==e){
        seg[n].pb(a[b]);
        return;
    }
    int mid = (b+e)/2;
    build(lc,b,mid);
    build(rc,mid+1,e);
    merge(seg[lc].begin() , seg[lc].end(), seg[rc].begin(), seg[rc].end(),back_inserter(seg[n]));
}

int query(int n,int b,int e,int i,int j,int v)
{
    if(b>j || e< i) return 0;
    if(b>=i && e<= j) {
        int k = upper_bound(seg[n].begin(),seg[n].end(), v ) - seg[n].begin();
        return k;
    }
    int mid = (b+e)/2;
    return query(lc,b,mid,i,j,v) + query(rc,mid+1,e,i,j,v);
}


int main()
{

    scanf("%d %d",&n,&q);
    for(int i = 1; i <= n; i ++ ) {
        scanf("%d",&a[i]);
        v.pb(a[i]);
    }
    sort(v.begin(),v.end());
    for(int i = 1;i <= n; i ++ ) {
        a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin() + 1;
    }

    build(1,1,n);

    while(q--) {
        int l,r,x;
        scanf("%d %d %d",&l,&r,&x);
        int low = 1, high = n , mid, ans ;
        while(low <= high) {
            mid = low + high >> 1;
            int k = query(1,1,n,l,r,mid);

            if(k >= x) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        printf("%d\n",v[ans-1]);
    }
    return 0;
}
