// Bai 2 
#include<bits/stdc++.h>
using namespace std ; 
int count( string s ,vector<string>words , string find   ){
	int cnt = 0 ; 
	for( int i = 0 ; i<words.size() ; i++){
		if(words[i]== find ){
			cnt ++; 
		}
	}
	return cnt ; 
	
}
void replaces ( string s, vector<string> &words , string word_replace , string be_replaced ){
	bool flag = false ; 
	for( int i = 0 ; i< words.size() ; i++){
		if( words[i] == be_replaced ){
			words[i] = word_replace ; 
			flag = true ; 
		}
	}
	if ( !flag){
		cout <<"Not have the word in string "<<endl;
	}
}
main(){
	string s= "tuan is child child a child in my mind"; 
	vector<string> words  ;
	string word ; 
	stringstream ss(s) ; 
	int i = 0 ; 
	while(ss >> word){
		words.push_back(word) ;  
	}
	replaces(s,words,"children","child"); 
	cout << "The text after replaced !"<<endl; 
	for( string a :words){
		cout << a <<" " ; 
	}
	
	cout << count(s,words,"child");
	
}