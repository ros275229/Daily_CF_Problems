#include <bits/stdc++.h>
using namespace std;
typedef long long LL ;

const int N = 2e5 + 5 ;
	
void solve() {
	int r,b,k ; cin >> r >> b >>  k ;
	if(r>b) swap(r,b) ;
	if(k==1){
		cout << "REBEL" << endl ;
		return  ;
	}
	int gd = __gcd( r , b ) ;
	r /= gd ;
	b /= gd ;
	int s = (b-2)/r + 1 ;// 在两个b之间的a的个数
	if(s>=k){
		cout << "REBEL" << endl ;
	} else{
		cout << "OBEY" << endl ;
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
