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

class HoleCakeCuts {
public:
	int cutTheCake(int cakeLength, int holeLength, vector <int> horizontalCuts, vector <int> verticalCuts);
};

int n2;
bool mark[205][205], cutX[205], cutY[205];
int du[] = {-1,0,1,0}, dv[] = {0,1,0,-1};

void dfs(int i, int k) {
	mark[i][k] = 1;

	int u, v;
	REP(t,0,4) {
		u = i + du[t];
		v = k + dv[t];
		
		if (u < 0 || u > n2 || v < 0 || v > n2) continue;
		if (t == 0 && cutX[i]) continue;
		if (t == 1 && cutY[k + 1]) continue;
		if (t == 2 && cutX[i + 1]) continue;
		if (t == 3 && cutY[k]) continue;
		if (mark[u][v]) continue;
		
		dfs(u,v);
	}
}

int HoleCakeCuts::cutTheCake(int n, int m, vector <int> X, vector <int> Y) {
	memset(mark,0,sizeof(mark));
	REP(i,-m,m) 
		REP(k,-m,m) mark[i + n][k + n] = 1;

	memset(cutX,0,sizeof(cutX));
	memset(cutY,0,sizeof(cutY));
	REP(i,0,sz(X)) cutX[X[i] + n] = 1;
	REP(i,0,sz(Y)) cutY[Y[i] + n] = 1;

	n2 = 2 * n - 1;
	int res = 0;	
	REP(i,0,2 * n)
		REP(k,0,2 * n) if (!mark[i][k]) {
			res ++;
			dfs(i,k);
		}
	
	return res;
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	HoleCakeCuts *obj;
	int answer;
	obj = new HoleCakeCuts();
	clock_t startTime = clock();
	answer = obj->cutTheCake(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	vector <int> p2;
	vector <int> p3;
	int p4;
	
	{
	// ----- test 0 -----
	p0 = 5;
	p1 = 3;
	int t2[] = {1,-4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 6;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 10;
	p1 = 5;
	p2.clear() /*{}*/;
	int t3[] = {-2,2};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 4;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 10;
	p1 = 5;
	int t2[] = {1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {-5,5};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 6;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 50;
	p1 = 5;
	int t2[] = {40,-40};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {20,0,-20};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 12;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
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
