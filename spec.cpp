#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

const int MAX_ARR = 1000000;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, Q;
    vector<int> A;
    vector<int> L, R;
    vector<long long> sum;

    void InputFormat() {
        LINE(N, Q);
        LINE(A % SIZE(N));
        LINES(L, R) % SIZE(Q);
    }

    void OutputFormat() {
        LINES(sum) % SIZE(Q);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(1 <= N && N <= 100);
        CONS(1 <= Q && Q <= 100);
        CONS(eachElementBetween(A, -MAX_ARR, MAX_ARR));
        CONS(eachElementBetween(L, -MAX_ARR, MAX_ARR));
        CONS(eachElementBetween(R, -MAX_ARR, MAX_ARR));
        CONS(isLessThan(L, R));
    }

    void Subtask1() {
        Points(100);
    }

private:
    bool eachElementBetween(const vector<int>& v, int lo, int hi) {
        for (int x : v) {
            if (x < lo || x > hi) {
                return false;
            }
        }
        return true;
    }

    bool isLessThan(vector<int>& u, vector<int>& v) {
        for (int i = 0; i < u.size(); i++) {
            if (u[i] > v[i]) return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void TestGroup1() {
        Subtasks({1});
        CASE(N=100, Q=100, createArr(-3, 3), createLR());
        CASE(N=100, Q=100, createArr(-10, 10), createLR());
        CASE(N=100, Q=100, createArr(-1000, 1000), createLR());
        CASE(N=100, Q=100, createArr(-1000000, 1000000), createLR());
    }

private:
    void createArr(int l, int r){
        A = {};
        for(int i = 0; i < N; i++){
            A.push_back(rnd.nextInt(l, r));
        }
    }

    void createLR(){
        L = {};
        R = {};
        for(int i = 0; i < Q; i++){
            int l = rnd.nextInt(1, N), r = rnd.nextInt(1, N);
            if(l > r) swap(l, r);
            L.push_back(l);
            R.push_back(r);
        }
    }
};