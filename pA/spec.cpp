#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    string ans;
    int n, idx, val;
    vector<int> a;
    void InputFormat() {
        LINE(n);
        LINE(a % SIZE(n));
        LINE(idx, val);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:    
    void rnda(int n){
        a.resize(n);
        for(int i=0;i<n;i++){
            a[i] = rnd.nextInt(1, 1e9);
        }
    }

    void BeforeTestCase(){
        a.clear();
    }

    void TestCases() {
        for(int i=0;i<100;i++){
            CASE(n = rnd.nextInt(1, 1e4), idx = rnd.nextInt(1, n), val = rnd.nextInt(1, 1e9), rnda(n));
        }
    }
};