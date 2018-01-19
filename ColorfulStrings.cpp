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

class ColorfulStrings {
public:
	string getKth(int n, int k);
};

vs res;
int a[10];
bool mark[10];

bool ok(int i) {
	vi p;
	FOR(k,0,i) {
		int tmp = 1;
		FOR(t,k,i) {
			tmp *= a[t];
			p.pb(tmp);
		}
	}
	
	REP(k,0,sz(p) - 1)
		REP(t,k + 1,sz(p)) if (p[k] == p[t]) return 0;
		
	return 1;
}

void attempt(int i, int n) {
	if (i == n) {
		string str = "";
		REP(k,0,n) str += (char)(a[k] + '0');
		res.pb(str);
		
		return;
	}
	
	FOR(k,1,9) if (!mark[k]) {
		a[i] = k;
		mark[k] = 1;
		if (ok(i)) attempt(i + 1,n);
		mark[k] = 0;
	}
}

string ColorfulStrings::getKth(int n, int k) {
	if (n == 1)
		if (k > 10) return "";
		else {
			string str = "";
			str += (char)(k - 1 + '0');
			return str;
		}

	if (n >= 10) return "";
	
	memset(mark,0,sizeof(mark));
	res.clear();
	attempt(0,n);
	
	if (k > sz(res)) return "";
	return res[k - 1];
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	ColorfulStrings *obj;
	string answer;
	obj = new ColorfulStrings();
	clock_t startTime = clock();
	answer = obj->getKth(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	
	int p0;
	int p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 4;
	p2 = "238";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 4;
	p1 = 2000;
	p2 = "";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 5;
	p1 = 1;
	p2 = "23457";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 2;
	p1 = 22;
	p2 = "52";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 6;
	p1 = 464;
	p2 = "257936";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
