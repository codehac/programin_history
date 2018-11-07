#include<bits/stdc++.h>
using namespace std;

struct pow{
long long b;
long long i;
long long r;
}a[500005],c[500005];
long long bit[500005];
const int maxn=500005;
void update(int ind,int val){
  while(ind<=maxn){
    bit[ind]+=val;
    ind+=(ind&-ind);
  }
}

long long query(int ind){
  long long sum=0;
  while(ind>0){
    sum+=bit[ind];
    ind-=(ind&-ind);
  }
  return sum;
}

bool cmp(struct pow x,struct pow y){
    return (x.b<y.b)&&(x.i<y.i)&&(x.r<y.r);
}

int find_value(struct pow x,int n,int m){
    if(n<=m){
      int mid=(n+m)/2;
      if(a[mid].i==x.i && a[mid].b==x.b && a[mid].r==x.r)
         return mid;
      if(a[mid].i<x.i && a[mid].b<x.b && a[mid].r<x.r)
        return find_value(x,mid+1,m);
      else
        return find_value(x,n,mid-1);
    }
    return -1;
}
int main(){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%lld%lld%lld",&a[i].b,&a[i].i,&a[i].r);
    c[i].b=a[i].b;
    c[i].i=a[i].i;
    c[i].r=a[i].r;
}
sort(c,c+n,cmp);
printf("hello");
int d[n];

for(int i=0;i<n;i++){
  d[i]=find_value(a[i],0,n-1)+1;
}
long long sum=0;
for(int i=0;i<n;i++){
    sum+=query(d[i]-1);
    update(d[i],1);
}
printf("%I64d",sum);
return 0;
}
