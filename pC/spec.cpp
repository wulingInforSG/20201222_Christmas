#include <tcframe/spec.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace tcframe;


class ProblemSpec : public BaseProblemSpec {
protected:
    vector<string> ans;
    vector<string> cmd;
    vector<string> f;
    int s, t;

    void InputFormat() {
        LINE(s, t);
        LINES(cmd, f) % SIZE(t);
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
    string shu_string = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
    string gen(int n){
        rnd.shuffle(shu_string.begin(), shu_string.end());
        return shu_string.substr(0, n);
    }

    void rnd1(int t){
        cmd.resize(t);
        f.resize(t);
        for(int i=0;i<t-10;i++){
            switch(rnd.nextInt(1, 2)){
                case 1:
                    cmd[i] = "Car";
                    f[i] += gen(6) + " ";
                    f[i] += to_string(rnd.nextInt(1, 1e9)) + " " + to_string(rnd.nextInt(1, 1e9));
                    break; 
                case 2:
                    cmd[i] = "Price";
                    f[i] = to_string(rnd.nextInt(1, 1e9));
                    break;
            }
        }
        for(int i=t-10;i<t;i++){
            cmd[i] = "Leave";
            f[i] = "";
        }
    }
  

    void BeforeTestCase(){
        cmd.clear();
        f.clear();
    }

    void TestCases() {
        for(int i=0;i<100;i++){
            CASE(s=rnd.nextInt(1, 1e2), t=rnd.nextInt(1, 2*1e3), rnd1(t));
        }
    }
};