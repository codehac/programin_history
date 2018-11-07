#include<bits/stdc++.h>
using namespace std;
int  a[100005];
int b[100005];
long long bit[100005];
const int maxn=100005;
void update(int id,int val){
    while(id<=maxn ){
      bit[id]+=val;
      id+=(id&-id);
    }
}
long long query(int id){
  long long sum=0;
  while(id>0){
    sum+=bit[id];
    id-=(id&-id);
  }
  return sum;
}

int main(){
int t;
scanf("%d",&t);
while(t--){
    int n;
  //      printf("hi\n");
scanf("%d",&n);
//printf("hello\n");
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    b[i]=a[i];
}
sort(b,b+n);
for(int i=0;i<n;i++){
    int val=lower_bound(b,b+n,a[i])-b;
          a[i]=val;
}
long long sum=0;
memset(bit,0,sizeof(bit));

for(int i=0;i<n;i++){
sum+=query(a[i]);
update(a[i]+1,b[a[i]]);
}

printf("%lld\n",sum);
 }
return 0;
}
