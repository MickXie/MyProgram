#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 
int main() {
int s[5][40];
int t=0;
srand(time(NULL));
for(int i=0;i<5;i++){
for(int j=0;j<40;j++){
s[i][j]=( (100-1) * (double)rand()/RAND_MAX )+1;
}
}
for(int i=0;i<5;i++){
	t=0;
for (int j=0;j<40;j++){
t=s[i][j]+t; 
cout<<"第"<<i+1<<"科第"<<j+1<<"位同學成績為:"<<s[i][j]<<endl;
}
cout<<"第"<<i+1<<"科總分為:"<<t<<endl; 
} 
return 0;
}

