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

const double INF = 1e18;

class FoxPlayingGame {
public:
	double theMax(int nA, int nB, int paramA, int paramB);
};

double vmin[55][55], vmax[55][55];

double FoxPlayingGame::theMax(int nA, int nB, int paramA, int paramB) {
	double scoreA = paramA / 1000.0, scoreB = paramB / 1000.0;			
	
	FOR(i,0,nA) vmin[i][0] = vmax[i][0] = i * scoreA;
	FOR(i,0,nB) vmin[0][i] = vmax[0][i] = 0;
	
	FOR(i,1,nA) 
		FOR(k,1,nB) {
			vmin[i][k] = INF;
			
			vmin[i][k] = min(vmin[i][k],vmin[i - 1][k] + scoreA);
			vmin[i][k] = min(vmin[i][k],vmin[i][k - 1] * scoreB);
			vmin[i][k] = min(vmin[i][k],vmax[i][k - 1] * scoreB);
			
			vmax[i][k] = -INF;
			vmax[i][k] = max(vmax[i][k],vmax[i - 1][k] + scoreA);
			vmax[i][k] = max(vmax[i][k],vmax[i][k - 1] * scoreB);
			vmax[i][k] = max(vmax[i][k],vmin[i][k - 1] * scoreB);
		}
		
	return vmax[nA][nB];
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, double p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	FoxPlayingGame *obj;
	double answer;
	obj = new FoxPlayingGame();
	clock_t startTime = clock();
	answer = obj->theMax(p0, p1, p2, p3);
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
		res = fabs(p4 - answer) <= 1e-9 * max(1.0, fabs(p4));
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
	int p2;
	int p3;
	double p4;
	
	{
	// ----- test 0 -----
	p0 = 5;
	p1 = 4;
	p2 = 3000;
	p3 = 2000;
	p4 = 240.0;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 3;
	p2 = 2000;
	p3 = 100;
	p4 = 6.0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 4;
	p1 = 3;
	p2 = -2000;
	p3 = 2000;
	p4 = -8.0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 5;
	p1 = 5;
	p2 = 2000;
	p3 = -2000;
	p4 = 160.0;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 50;
	p1 = 50;
	p2 = 10000;
	p3 = 2000;
	p4 = 5.62949953421312E17;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 41;
	p1 = 34;
	p2 = 9876;
	p3 = -1234;
	p4 = 515323.9982341775;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
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
