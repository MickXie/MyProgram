#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
using namespace std; 
int main() {
int s[5];
int t=0;
srand(time(NULL));
for(int i=0;i<5;i++){
s[i]=( (100-1) * (double)rand()/RAND_MAX )+1;
cout<<s[i]<<endl;
}
sort(s,s+5);
for(int i=0;i<5;i++){
cout<<s[i]<<endl;
}
return 0;
}

