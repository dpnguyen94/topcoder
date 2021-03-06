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

class TheFansAndMeetingsDivTwo {
public:
	double find(vector <int> minJ, vector <int> maxJ, vector <int> minB, vector <int> maxB);
};

int n;
double resJ[55], resB[55];

double TheFansAndMeetingsDivTwo::find(vector <int> minJ, vector <int> maxJ, vector <int> minB, vector <int> maxB) {
	n = sz(minJ);
	FOR(i,1,50) {
		double prob = 0.0;
		REP(k,0,n) if (minJ[k] <= i && i <= maxJ[k]) prob += (1.0 / n) * (1.0 / (maxJ[k] - minJ[k] + 1));
		resJ[i] = prob;
	}
	
	FOR(i,1,50) {
		double prob = 0.0;
		REP(k,0,n) if (minB[k] <= i && i <= maxB[k]) prob += (1.0 / n) * (1.0 / (maxB[k] - minB[k] + 1));
		resB[i] = prob;
	}
	
	double res = 0.0;
	FOR(i,1,50) res += resJ[i] * resB[i];
	
	return res;
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, double p4) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
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
	TheFansAndMeetingsDivTwo *obj;
	double answer;
	obj = new TheFansAndMeetingsDivTwo();
	clock_t startTime = clock();
	answer = obj->find(p0, p1, p2, p3);
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
	
	vector <int> p0;
	vector <int> p1;
	vector <int> p2;
	vector <int> p3;
	double p4;
	
	{
	// ----- test 0 -----
	int t0[] = {1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 0.3333333333333333;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {5,7,7,1,6,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {8,9,7,3,9,5,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {9,12,10,14,50,9,10};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {9,13,50,15,50,12,11};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 0.014880952380952378;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {44};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {47};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {7};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 0.0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1,6,3,1,4,3,5,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {7,8,5,7,9,7,9,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {5,1,5,3,1,2,4,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {9,2,7,9,4,5,4,9};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 0.11562305130385474;
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
