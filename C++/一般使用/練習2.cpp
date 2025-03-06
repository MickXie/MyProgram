#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std; 
int main() {
long long int c,d,e,f;
int a[1000]={},b[1000]={},g[1000]={},h[1000]={}; 
cin>>c;
cin>>d;
for(int i=1;i<=c;i++){
cin>>a[i]>>b[i]; 	
g[i]=b[i]*b[i]*b[i]+(a[i]-d)*(a[i]-d)*(a[i]-d)*(a[i]-d)*(a[i]-d);
g[i]=h[i];	
}
sort(h,h+c);
for(int i=1;i<=c;i++){
if(g[i]==h[c]){
f=i;
break;	
}
}
cout<<g[c];
	
return 0;
}

