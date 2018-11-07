#include<bits/stdc++.h>
using namespace std;
const int maxn =200005;


int a[maxn];
int b[maxn];
int bit[maxn];
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
int main(){
int t,n;
scanf("%d",&t);
while(t--){
    scanf("%d",&n);
    memset(bit,0,sizeof(bit));

    for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
            b[i]=a[i];
    }
   // printf("hello");
    sort(b,b+n);
   // printf("hi");
    for(int i=0;i<n;i++){
     int v=lower_bound(b,b+n,a[i])-b;
     a[i]=v+1;
    }
    //printf("hello");
long long sum=0;

  for(int i=n-1;i>=0;i--){
     long long q=query(a[i]-1);
      sum+=q;
      update(a[i],1);
  }

printf("%lld\n",sum);

}
return 0;
}
