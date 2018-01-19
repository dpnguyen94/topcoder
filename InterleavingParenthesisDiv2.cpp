#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <memory.h>
#include <time.h>
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

#define FOR(i,a,b) 	for (int i=(a),_b=(b);i<_b;i++)
#define REP(i,a,b) 	for (int i=(a),_b=(b);i>=_b;i--)
#define TR(c, it) 	for (typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define pb 		push_back
#define mp 		make_pair
#define sz(c) 		int((c).size())
#define all(c) 		(c).begin(), (c).end()

typedef long long 		LL;
typedef unsigned long long 	ULL;
typedef vector<int> 	vi;
typedef vector<vi> 	vvi;
typedef vector<string> 	vs;
typedef pair<int, int> 	pi;
typedef pair<pi, int> 	pii;


class InterleavingParenthesisDiv2 {
public:
	int countWays(string s1, string s2) {
		return 0;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, string p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	InterleavingParenthesisDiv2 *obj;
	int answer;
	obj = new InterleavingParenthesisDiv2();
	clock_t startTime = clock();
	answer = obj->countWays(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	
	string p0;
	string p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = "(()";
	p1 = "())";
	p2 = 19;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = ")";
	p1 = "(";
	p2 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "(((((";
	p1 = ")))))";
	p2 = 42;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "()(()";
	p1 = "))((())";
	p2 = 10;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "()()()()()()()()()()()()()()()";
	p1 = "()()()()()()()()";
	p2 = 493841617;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "())())))";
	p1 = "))((((";
	p2 = 0;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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
