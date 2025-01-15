#include<bits/stdc++.h> 
using	 namespace std ; 
int n,a[100] ,cot[100],d1[100],d2[100]; int cnt = 0; 
// trong do cot la mang danh dau cot 
// d1 duogn cheo xuoi 
// d2 duong cheo nguoc 
int c[100][100];
void inkq(){
    memset(c,0,sizeof(c));
	for( int i = 1; i<= n ; i++){
		c[i][a[i] ] = 1 ; 
	}
    for( int i = 1; i<= n ; i++){
        for( int j = 1; j<= n ; j++){
            cout << c[i][j] ; 
        }
        cout << endl ; 
    }
    cout << endl ;
}
void Try( int i ){// xet kha nang nam quan hau cua i 
    for( int j = 1 ;j <= n ; j++){// ktra cac cot cua j hay dg cheo quan ly j no co quan hau nao nam trne chua 
        if( cot[j] == 1 && d1[i-j+n] == 1  && d2[i+j-1] == 1) {
            cot[j] = d1[i-j-n] = d2[i+j-1] = 0; // danh dau da lam 
            a[i] = j ; 
            if( i == n ){
                inkq() ; 
                cnt++  ;
            }
            else {
                Try( i+1 ) ; 
            }
            // back track 
            cot[j] = d1[i-j+n] = d2[i+j-1] = 1;
        }
    }
}
int main(){
    cin >> n ; 
    for( int i = 1 ; i<= 99 ; i++ ){
        cot[i] = d1[i] = d2[i] = 1;
    }
    
    Try(1) ; 
    cout << cnt<<endl ;
}