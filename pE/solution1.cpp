#include<iostream>
#include<algorithm>
using namespace std;

int p[100005];

int check(int r, int n, int k){
	int a = 0;
	int s, i;
	for(i = 0;i < n;){
		s = p[i] + r;
		a++;
		if(a > k){
			return 0;
		}
		if(p[n-1] <= s){
			return 1;
		}
		while(p[i] <= s){
			i++;
		}
	}
}

int main(){
	int n, k, r, l, t;
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		cin >> p[i];
	}
	sort(p, p + n);
	r = p[n-1] - p[0];
	if(k != 1){
		l = 1;
		while(check(r-1, n, k)){
			t = (l + r) / 2;
			if(check(t, n, k)){
				r = t;
			}else{
				l = t + 1;
			}
			if(l == r){
				break;
			} 
		}
	}
	cout << r << endl;
}
