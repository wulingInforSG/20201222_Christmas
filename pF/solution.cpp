#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e6 + 1;
int tag[MAXN];
int extra[MAXN];
int V[MAXN];
int T[MAXN];
int sum[MAXN];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	

	
	for(int i=1;i <= N;i++){
		cin >> V[i];
	}
	for(int i=1;i <= N;i++){
		cin >> T[i];
		if(T[i] < 0)T[i] == 0;
		sum[i] = sum[i-1] + T[i];
	}

	for(int i=1 ; i <= N;i++){
		int t = V[i];
		int id = upper_bound(sum+1,sum+N+1,t+sum[i-1]) - sum;//第i日雪人體積+前幾日溫度總和 
		//cout << "id:" <<id<<endl;第id日融化完 
		tag[i]++;
		tag[id]--;//第i日存在，第id日融化(因tag為前綴和) 
		extra[id] += t-(sum[id-1]-sum[i-1]);//第id日剩餘為體積-第i~id日的溫度 
	}

	for(int i=1;i <= N;i++){
		tag[i] += tag[i-1];//第i日雪人數為前幾日雪人-今日融化數 
		cout << tag[i]*T[i] + extra[i];
		if(i == N){
			cout << endl;
		}else{
			cout << " ";
		}
	}
	return 0;
}
