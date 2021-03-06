#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <memory.h>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define REP(i,a,b) 		for (int i=(a),_b=(b);i<_b;i++)
#define FOR(i,a,b) 		for (int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,a,b) 		for (int i=(a),_b=(b);i>=_b;i--)
#define TR(c,it) 		for (typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define pb 				push_back
#define mp 				make_pair
#define sz(c) 			int((c).size())
#define all(c) 			(c).begin(), (c).end()

typedef long long 		LL;
typedef unsigned long long 	ULL;
typedef pair<int, int> 	ii;
typedef pair<ii, int> 	iii;
typedef vector<int> 	vi;
typedef vector<vi> 		vvi;
typedef vector<string> 	vs;
typedef vector<ii> 	    vii;
typedef vector<vii> 	vvii;

class TwoRegisters {
public:
	string minProg(int r);
};

vi y;

int calc(int x, int y) {
    int cnt = 0;
    while (x > 0 && y > 0)
        if (x > y) {
            cnt += x / y;
            x %= y;
        }
        else {
            cnt += y / x;
            y %= x;
        }
        
    if (x + y != 1) return INT_MAX;
    
    return cnt - 1;
}

string str(int x, int y) {
    string s = "";

    while (x > 0 && y > 0) 
        if (x > y) {
            FOR(i,1,x / y) s += 'X';
            x %= y;
        }
        else {
            FOR(i,1,y / x) s += 'Y';            
            y %= x;
        }
        
    if (x + y != 1) return "Z";
    
    s.resize(sz(s) - 1);
    reverse(all(s));
    return s;
}


string TwoRegisters::minProg(int r) {
	if (r == 1) return "";

	y.clear();
    int best = INT_MAX, t;
    REP(i,1,r) {
        t = calc(r,i);
        if (t < best) {
            y.clear();
            best = t;
        }
        if (t == best) y.pb(i);
    }
    
    string res = "Z", s;
    REP(i,0,sz(y)) {
        s = str(r,y[i]);
        if (s < res) res = s;
    }
    
    return res;		
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	TwoRegisters *obj;
	string answer;
	obj = new TwoRegisters();
	clock_t startTime = clock();
	answer = obj->minProg(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	string p1;
	
	{
	// ----- test 0 -----
	p0 = 10;
	p1 = "XXYYX";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = "XX";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 20;
	p1 = "XYYYYXX";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 34;
	p1 = "XYXYXYX";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
