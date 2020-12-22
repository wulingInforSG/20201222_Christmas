#include <tcframe/spec.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace tcframe;


class ProblemSpec : public BaseProblemSpec {
protected:
    int n, k;
    vector<vector<int>> a;
    string ans;

    void InputFormat() {
        LINE(n, k);
        LINES(a) % SIZE(n);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(64);
    }

};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:

    void rnd1(int n){
        a.resize(n);
        for(int i=0;i<n;i++){
            int t = rnd.nextInt(1, 10);
            for(int j=0;j<t;j++){
                a[i].push_back(rnd.nextInt(1, 100));
            }
        }
    }
  

    void BeforeTestCase(){
        a.clear();
    }

    void TestCases() {
        for(int i=0;i<100;i++){
            CASE(n=rnd.nextInt(1, 1e3), k=rnd.nextInt(1, 1e2), rnd1(n));
        }
    }
};