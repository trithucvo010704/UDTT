#include<bits/stdc++.h>
#include<vector>
using namespace std;

void show(int n , map<char,string> bailam){
	for(pair<char,string> it :bailam){
		cout <<it.first <<"==> "<<it.second <<"\t";
	}
    cout << endl;
}
void Try(int k , int n , map<char,string> &bailam,vector<string> nguoi , vector<char> vitri , int &cnt){
    int dd[100] ;
    for (int i = 0 ; i < n ; i++){
        if(dd[i] == 0){
        	pair<char,string> temp = make_pair(vitri[k],nguoi[i]);
            bailam.insert(temp); 
            if(k == n - 1){
                show(n ,bailam);
                cnt++;
            }
            else{
                dd[i] = 1;
                Try(k + 1 , n ,bailam, nguoi , vitri,cnt);
                dd[i] = 0;

            }
        }
    }
}

int main(){
    map<char, string> mp;

    vector<string> nguoi = {"Tung","Cuc","Truc","Mai"} ;
    int n = nguoi.size();
    vector<char> vitri = {'A','B','C','D'} ;
    int cnt = 0 ;
    Try(0,n,mp,nguoi,vitri,cnt);
    cout << "So cach chon: " << cnt << endl;
    cout<<vitri[0]<<endl;
    return 0;
}