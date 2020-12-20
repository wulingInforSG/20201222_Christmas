#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    vector<int> A;
    vector<int> sum;

    void InputFormat() {
        LINES(A);
    }

    void OutputFormat() {
        LINE(sum);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(640000000);
    }

};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void TestCases() {
    	vector <int> tmp;
    	for(int t=0;t<99-70;t++){
    		tmp.clear();
    		tmp.push_back(1000);
     		for(int i = 0;i<1000*2;i++){
    			tmp.push_back(rnd.nextInt(1,1e3));
			}
			CASE(A = tmp);   		
		}
   		for(int t=0;t<99-30;t++){
    		tmp.clear();
    		tmp.push_back(1e6);
     		for(int i = 0;i<1e6*2;i++){
    			tmp.push_back(rnd.nextInt(1,1e3));
			}
			CASE(A = tmp);   		
		}
    }
};
