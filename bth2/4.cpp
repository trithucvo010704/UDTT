// N QUAN HAU QUAY LUI
#include<bits/stdc++.h>
#include <string.h>
#include<vector>
using namespace std;
int a[100], banco [100][100] , n , cheo[100], cheosau[100], h[100] ;  
void showkq(int n ){
    memset(banco, 0, sizeof(banco));
    for( int i = 1 ; i<= n ; i++){
        banco[i][a[i]] = 1 ;
    }
    for ( int i = 1 ; i<= n ; i++){
        for(int j = 1 ; j<=n ; j++){
            cout <<banco[i][j]<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
}
void Try( int k ){// xet kha nang nam quan hau cua i 
    for( int j = 1 ;j <= n ; j++){// ktra cac cot cua j hay dg cheo quan ly j no co quan hau nao nam trne chua 
        if( h[j] == 0 && cheo[k-j+n] == 0  && cheosau[k+j-1] == 0) {
            h[j] = cheo[k-j+n] = cheosau[k+j-1] = 1; // danh dau da lam 
            a[k] = j ; 
            if( k == n ){
                showkq(n) ; 

            }
            else {
                Try( k+1 ) ; 
            }
            // back track 
            h[j] = cheo[k-j+n] = cheosau[k+j-1] = 0;
        }
    }
}
int main(){
    n = 8 ; 
    for( int i = 0 ; i<= 99 ; i++ ){
        h[i] = cheo[i] = cheosau[i] = 0;
    }
    
    Try(1) ; 

}