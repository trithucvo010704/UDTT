#include<bits/stdc++.h>
using namespace std ; 
bool check( string s){
	int l = 0 ,r = s.size()-1 ; 
	while(l <= r){
		if(s[l] != s[r]){
			return false ; 
		}
		++l ; --r ;
	}
	return true ;
}
string lastest_substring( string s , int k ){
	string result(1,s[k]);
	cout << result <<endl;
	int n = s.size();
	int l = k-1 , r = k+1 ; 
	while(l >= 0 && r < n){
		if(s[l] == s[r]){
			result = s[l] + result + s[r] ; 
			cout<<result<<endl;
			--l ; ++r;			
		}
		else {
			break ; 
		}
	
	} 
	return result ; 
}
main(){
	string s = {"medlolmem"} ; 
	bool kq = check(s) ; 
	if ( kq ){
		cout << "Doi Xung " <<endl ; 
	}
	else {
		int k  ; 
		cout << "Nhap vao so nguyen k : " ; 
		cin >> k ; 
		cout <<"Xau doi xung dai nhat qua tam k :" <<lastest_substring(s,k)<<endl;
	}
}
