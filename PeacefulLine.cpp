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


class PeacefulLine {
public:
	string makeLine(vector <int> x) {
		int a[26];
		memset(a,0,sizeof(a));
		FOR(i,0,sz(x)) a[x[i]] ++;
		FOR(i,0,26) if (a[i] - 1 > sz(x) - a[i]) return "impossible";
		return "possible";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	PeacefulLine *obj;
	string answer;
	obj = new PeacefulLine();
	clock_t startTime = clock();
	answer = obj->makeLine(p0);
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
	
	vector <int> p0;
	string p1;
	
	{
	// ----- test 0 -----
	int t0[] = {1,2,3,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "possible";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {1,1,1,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "impossible";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1,1,2,2,3,3,4,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "possible";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {3,3,3,3,13,13,13,13};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "possible";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {3,7,7,7,3,7,7,7,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "impossible";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {25,12,3,25,25,12,12,12,12,3,25};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "possible";
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	int t0[] = {3,3,3,3,13,13,13,13,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "possible";
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
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
