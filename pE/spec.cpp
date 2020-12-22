#include <tcframe/spec.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace tcframe;


class ProblemSpec : public BaseProblemSpec {
protected:
    int n, k;
    vector<long long> p;
    int ans;

    void InputFormat() {
        LINE(n, k);
        LINE(p % SIZE(n));
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

    void rnd1(int n, long long lim){
        p.resize(n);
        for(int i=0;i<n;i++){
           p[i] = rnd.nextLongLong(0, lim);
        }
    }
  

    void BeforeTestCase(){
        p.clear();
    }

    void TestCases() {
        for(int i=0;i<10;i++){
            CASE(k=rnd.nextInt(1, 2), n=rnd.nextInt(k+1, 10), rnd1(n, 100));
        }
        for(int i=0;i<20;i++){
            CASE(k=rnd.nextInt(1, 100), n=rnd.nextInt(k+1, 100), rnd1(n, (long long)1e3));
        }
        for(int i=0;i<20;i++){
            CASE(k=rnd.nextInt(1, 500), n=rnd.nextInt(k+1, 500), rnd1(n, (long long)1e9));
        }
        for(int i=0;i<50;i++){
            CASE(k=rnd.nextInt(1, 50000), n=rnd.nextInt(k+1, 50000), rnd1(n, (long long)1e9));
        }
        
    }
};