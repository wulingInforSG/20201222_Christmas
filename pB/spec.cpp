#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int ans;
    int n, m;
    vector<vector<char>> a;
    vector<int> x;
    vector<int> y;
    void InputFormat() {
        LINE(n, m);
        GRID(a) % SIZE(n, m);
    }

    void OutputFormat() {
        LINE(ans);
        LINES(x, y) % SIZE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:    
    void rnda(int n, int m, bool all_sep){
        a.resize(n, vector<char>(m, '.'));
        if(all_sep){
            for(int i=0;i<n;i+=2){
                for(int j=0;j<m;j+=2){
                    a[i][j] = '*';
                }
            }
        } else {
             for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(rnd.nextInt(1, 2) % 2){
                        a[i][j] = '*';
                    } else {
                        a[i][j] = '.';
                    }
                }
            }
        }
    }

    void rnda1(int n, int m){
        a.resize(n, vector<char>(m));
      
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j] = '*';
            }
        }
        
    }

    void BeforeTestCase(){
        a.clear();
    }

    void TestCases() {
        for(int i=0;i<10;i++){
            CASE(n = rnd.nextInt(1, 100), m = rnd.nextInt(1, 100), rnda(n, m, true));
        }
        for(int i=0;i<40;i++){
            CASE(n = rnd.nextInt(1, 100), m = rnd.nextInt(1, 100), rnda(n, m, false));
        }
        for(int i=0;i<40;i++){
            CASE(n = rnd.nextInt(1, 2*1e3), m = rnd.nextInt(1, 2*1e3), rnda(n, m, false));
        }
        for(int i=0;i<10;i++){
            CASE(n = rnd.nextInt(1e3, 2*1e3), m = rnd.nextInt(1e3, 2*1e3), rnda1(n, m));
        }
    }
};