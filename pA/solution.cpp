#include <iostream>

const int MAXN = 1e5;

using namespace std;

void edit(int* a, int idx, int val){
    *(a+idx-1) = val;
}

int main(){
    int a[MAXN];
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int idx, val;
    cin >> idx >> val;
    edit(a, idx, val);
    if(a[idx-1] == val){
        cout << "AC" << endl;
    } else {
        cout << "WA" << endl;
    }
}