#include<bits/stdc++.h>
using namespace std;
int a[30005];
vector<int>v[100005];

int main(){
int n;
scanf("%d",&n);

for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    b[i]=a[i];
}
sort(b,b+n);
for(int i=1;i<=n;i++){
    a[i]=upper_bound(b+1,b+n+1)-b+1
}
int q;
scanf("%d",&q);
while(q--){
  int x,y,z;
  scanf("%d%d%d",&x,&y,&z);
  int low=1;
  int high=n;
  int ans;
  while(low<=high){
    int mid=(low+high)>>1;
    int k=query(1,1,n,x,y,mid);
    if(k>=z){
        ans=mid;
        high=mid-1;
    }
    else
        low=mid+1;
  }
  printf("%d\n",b[ans-1]);
}
return 0;
}
