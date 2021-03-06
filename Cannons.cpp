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

class Cannons {
public:
	string getDirections(vector <int> x, vector <int> y);
};

string Cannons::getDirections(vector <int> x, vector <int> y) {
	string res = "";
	int n = sz(x);
	bool up, down, right, left;
	REP(i,0,n) {
		down = 1;
		REP(k,0,n) if (x[k] == x[i] && y[k] < y[i]) {
			down = 0;
			break;
		}
		if (down) {
			res += 'D';
			continue;
		}

		left = 1;
		REP(k,0,n) if (x[k] < x[i] && y[k] == y[i]) {
			left = 0;
			break;
		}
		if (left) {
			res += 'L';
			continue;
		}

		right = 1;
		REP(k,0,n) if (x[k] > x[i] && y[k] == y[i]) {
			right = 0;
			break;
		}
		if (right) {
			res += 'R';
			continue;
		}
		
		up = 1;
		REP(k,0,n) if (x[k] == x[i] && y[k] > y[i]) {
			up = 0;
			break;
		}
		if (up) {
			res += 'U';
			continue;
		}
									
		return "";
	}
	
	return res;
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, string p2) {
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
	cout << "}";
	cout << "]" << endl;
	Cannons *obj;
	string answer;
	obj = new Cannons();
	clock_t startTime = clock();
	answer = obj->getDirections(p0, p1);
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
	
	vector <int> p0;
	vector <int> p1;
	string p2;
	
	{
	// ----- test 0 -----
	int t0[] = {1,2,2,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,1,3,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "DDLD";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "D";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {-3,0,9,0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,0,0,7,-4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {0,-4,0,5,0,-4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,0,-7,3,3,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "RDDDUL";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {-761813,348943,749420,-444982,993810,-548742,-444982,-761813,993810,363833,728226,28752,461997,544181,776052,-761813,776052,993810,789745,75502,348943,449038,158889,-548742,-659628,75502,363833,917729,993810,158889,776052,728226,367390,-689680,917729,748629,367390,917729,859379,728226};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {393728,835962,-593971,-593971,-36149,-922640,376562,-368880,-368880,-212107,-368880,-595655,-786227,393728,-463260,763742,790220,63191,-212107,-786227,-805377,-912205,-368880,883897,-912205,803745,63191,803745,790220,-212107,-593971,939489,-912205,939489,-291544,790220,795389,835962,795389,763742};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "LLDDLDLDDDDDDDLLURDDDDDLDLLRRLDRDDDDLRDR";
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
