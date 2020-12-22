#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
	vector<int> n;
	vector<int> s;

	vector<long long> ans;
    void InputFormat() {
        LINES(n, s);
    }

    void OutputFormat() {
        LINES(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(640000000);
    }

};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:

	void BeforeTestCase(){
        n.clear();
        s.clear();
    }
	void rnd1(int t){
		n.resize(t);
		s.resize(t);
		for(int i=0;i<t;i++){
			n[i] = rnd.nextInt(1, 65);
			s[i] = rnd.nextInt(0, n[i]);
		}
		n.push_back(-1);
		s.push_back(-1);
	}
    void TestCases() {
    	for(int i=0;i<100;i++){
			int t = rnd.nextInt(1, 4999);
			CASE(rnd1(t));
		}
    }
};
