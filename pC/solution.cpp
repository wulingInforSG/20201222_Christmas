#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct line{
	vector<string> lic;
	vector<long long> price;
	vector<long long> num; 
};
int main(){
	long long S, T;
	cin >> S >> T;
	line L;
	while(T--){
		string cmd;
		cin >> cmd;
		if(cmd == "Leave"){
			if(L.num.size() != 0){
				L.lic.erase(L.lic.begin());
				L.num.erase(L.num.begin());
				L.price.erase(L.price.begin());
			}else{
				S++;
			}
		}else if(cmd == "Car"){
			string l;
			long long n, p;
			cin >> l ;
			cin >> n >> p;
			if(L.num.size() < n){
				L.lic.push_back(l);
				L.num.push_back(n);
				L.price.push_back(p);
			}
		}else if(cmd == "Price"){
			long long pr;
			cin >> pr;
			for(int i = L.num.size() - 1; i >= 0; i--){
				if(pr <= L.price[i]){
					L.lic.pop_back();
					L.num.pop_back();
					L.price.pop_back();
				}else{
					break;
				}
			}
		}
		while(S!=0 && L.num.size()!=0){
			L.lic.erase(L.lic.begin());
			L.num.erase(L.num.begin());
			L.price.erase(L.price.begin());
			S--;
		}
		/*if(L.lic.size() == 0){
			cout << "empty" << endl;
		}else{
			for(long long i = 0; i < L.lic.size() - 1; i++){
				cout << L.lic[i] << " ";
			}
			cout << L.lic.back() << endl;
		}*/
	}
	if(L.lic.size() == 0){
		cout << "empty" << endl;
	}else{
		for(long long i = 0; i < L.lic.size() - 1; i++){
			cout << L.lic[i] << " ";
		}
		cout << L.lic.back() << endl;
	}
}
