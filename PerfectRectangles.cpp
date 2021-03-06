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

class PerfectRectangles {
public:
	int numberOfRectangles(int N, int M, int X0, int A, int B, int Y0, int C, int D);
};

const int MAXN = 2005;

bool f[MAXN][MAXN];
bool mark[MAXN];
int g[MAXN], s[MAXN], fi[MAXN], le[MAXN], ri[MAXN];

int PerfectRectangles::numberOfRectangles(int n, int m, int x, int a, int b, int y, int c, int d) {
	f[x % n + 1][y % n + 1] = 1;
    REP(i,1,m) {
        x = (x * a + b) % n;
        y = (y * c + d) % n;
        f[x + 1][y + 1] = 1;
    }
    
        int t, left, right, res = 0;
    FOR(i,1,n) {
        FOR(k,1,n) if (!f[i][k]) g[k] ++;
        else g[k] = 0;
        
        FOR(k,1,n) if (i < n && !f[i + 1][k]) s[k] = s[k - 1] + 1;
        else s[k] = s[k - 1];
        
        FOR(k,1,n) {
            le[k] = k - 1;
            t = k - 1;
            
            while (t >= 1 && g[t] >= g[k]) t = le[t];
            le[k] = t;
        }
        
        DOW(k,n,1) {
            ri[k] = k + 1;
            t = k + 1;
            
            while (t <= n && g[t] >= g[k]) t = ri[t];
            ri[k] = t;
        }
        
        memset(mark,0,sizeof(mark));
        FOR(k,1,n) {
            fi[k] = k - 1;
            t = k - 1;
            
            while (t >= 1 && g[t] > g[k]) t = fi[t];
            fi[k] = t;
            
            if (g[t] == g[k]) mark[k] = 1;
        }
        
        FOR(k,1,n) if (!mark[k]) {
            left = le[k] + 1;
            right = ri[k] - 1;
            if (s[right] - s[left - 1] < right - left + 1) res ++;
        }        
    }    
    
	return res;
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, bool hasAnswer, int p8) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4 << "," << p5 << "," << p6 << "," << p7;
	cout << "]" << endl;
	PerfectRectangles *obj;
	int answer;
	obj = new PerfectRectangles();
	clock_t startTime = clock();
	answer = obj->numberOfRectangles(p0, p1, p2, p3, p4, p5, p6, p7);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p8 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p8;
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
	int p4;
	int p5;
	int p6;
	int p7;
	int p8;
	
	{
	// ----- test 0 -----
	p0 = 5;
	p1 = 1;
	p2 = 2;
	p3 = 0;
	p4 = 0;
	p5 = 2;
	p6 = 0;
	p7 = 0;
	p8 = 4;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 4;
	p1 = 4;
	p2 = 0;
	p3 = 1;
	p4 = 1;
	p5 = 0;
	p6 = 1;
	p7 = 1;
	p8 = 6;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 1000000;
	p2 = 1;
	p3 = 2;
	p4 = 3;
	p5 = 1;
	p6 = 4;
	p7 = 7;
	p8 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 10;
	p1 = 20;
	p2 = 4;
	p3 = 76;
	p4 = 2;
	p5 = 6;
	p6 = 2;
	p7 = 43;
	p8 = 12;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
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
