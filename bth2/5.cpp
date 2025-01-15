#include<bits/stdc++.h>
using namespace std;

void show( vector<int> a , int k ){
    for( int i = 1;  i<=k; i++ ){
        cout<<a[i]<<" ";
    }
    cout << endl;
}
void Try(int dinhlinh , vector<int> &a , int k , int n ){
    for( int i = a[dinhlinh -1] +1; i <= n-k +dinhlinh ; i++ ){
        a[dinhlinh] = i;
        if( dinhlinh == k ){
            show(a , k );
        }else{
            Try( dinhlinh + 1 , a , k , n );
        }
    }
}
int main(){
    int n = 5 , k = 3 ; 
    vector<int> a(n+1);

    a[0] = 0 ;// loai bo truong hop 1 
    Try( 1 , a , k , n );
}