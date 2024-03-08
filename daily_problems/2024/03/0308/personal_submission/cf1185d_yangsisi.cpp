#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 10 ;
#define endl '\n' 
int a[N];

int main(){
	int n ; cin >> n ;
	map<int,int> mp ;
	for(int i=1;i<=n;i++) cin >> a[i]  , mp[a[i]] = i ;
	sort(a+1,a+1+n) ;
	if(n<=3){
		cout << 1 << endl ;
		return 0;
	}
	// 删1
	bool tag = true ;
	for(int i=4;i<=n;i++){
		if(a[i] - a[i-1] != a[3] - a[2]){
			tag = false;
			break ;
		}
	} 
	if(tag){
		cout << mp[a[1]] << endl;
		return 0 ;	
	}
	tag = true ;
	// 删2
	for(int i=4;i<=n;i++){
		if(a[i]-a[i-1]!=a[3]-a[1]){
			tag = false;
			break ;
		}
	} 
	if(tag){
		cout << mp[a[2]] << endl ;
		return 0 ;
	}
	// 12 23 13
	int idx = 0 ;
	int d = a[2] - a[1] ;
	for(int i=3;i<=n;i++){
		if(a[i] != a[1] + (i-1)*d){
			idx = i ;// 找到第一不满足的地方 
			break ;
		}
	}
	if(idx==0){
		cout << mp[a[1]] << endl ;
		return 0;
	}
	if(idx==n){
		cout << mp[a[n]] << endl ;
		return 0 ;
	}
	// 判断删除idx之后是否满足
	tag = true ;
	for(int i=3;i<=n;i++){
		if(i != idx){
			if(a[i]-a[i-1]!=a[2]-a[1]) {
				tag = false;
				break ;
			}
		}else{
			if(a[i+1]-a[i-1]!=a[2]-a[1]){
				tag = false;
				break;
			}else{
				i ++ ;
			}
		}
	} 
	if(tag) cout << mp[a[idx]] <<endl ;
	else cout << -1 << endl ;
}
