#include <iostream>
#include <stack>
using namespace std;
int main(){
	int n,cap;
	cin>>n>>cap;
	getchar();
	stack<int> stk;
	for(int i=1;i<n+1;i++){
		
		int lastDrop;
		if(stk.empty()) goto skipDropping;
		do{
			lastDrop=stk.top();
			stk.pop();
		}while((lastDrop+i)%5 && !stk.empty());
		
		skipDropping:
		
		char c,last;
		while((c=getchar())!='\n'){
			if(c==' '){
				stk.push(last-'0');
			} 
			last=c;
		}
		stk.push(last-'0');
		if(stk.size()>cap){
			cout<<"Giftoverflow\n";
			return 0;
		}
	}
	cout<<"GiftSentSuccessfully\n";
	return 0;
}
