#include<bits/stdc++.h>
using namespace std ; 

bool Boyer_Moore_Horspool(string P, string T) {
	int v = strlen(P), i = v - 1;
	while (i < strlen(T)) {
		int k = v – 1;
		while (k > -1 && T[i] == P[k]){
			i--; k--;
		}
		if (k < 0) {
			return true;
		}
		else {
			int x = char_in_string(T[i], P);
			if (x < 0) {
				i = i + v;
			}
			else {
				i = i + v – x – 1;
			}
		}
	}
	return false;
}