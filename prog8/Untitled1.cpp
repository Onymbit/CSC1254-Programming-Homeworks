#include <iostream>
#include <cmath>
int main() {
  for(int k=1;k<=1000;k++){
  	int help=0;
  int n=k;
  //std::cin>>n;
  for (int i = 1; i <= n;i++) {
    for (int j = 0; j < n; j +=i){
      help++;
      //std::cout<<i<<" "<<j<<"\n";
  	}
  }
  std::cout<<n<<":"<<help<<":"<<2*n*log(log(n)/log(2))/log(2)<<"\n";
  }
  
}
