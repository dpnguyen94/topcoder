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
typedef vector<int> 	vi;
typedef vector<vi> 		vvi;
typedef vector<string> 	vs;
typedef pair<int, int> 	pii;
typedef pair<pii, int> 	piii;

struct vertex {
	int r, c, t;
} u, v;

class NumberLabyrinthDiv2 {
public:
	int getMinimumNumberOfMoves(vector <string> board, int r1, int c1, int r2, int c2, int K);
};

int d[55][55][55];
int offx[]= {0,0,-1,1}, offy[] = {-1,1,0,0};
queue<vertex> q;

int NumberLabyrinthDiv2::getMinimumNumberOfMoves(vector <string> a, int r1, int c1, int r2, int c2, int k) {
	int n = sz(a), m = a[0].length();
	memset(d,-1,sizeof(d));
	while (!q.empty()) q.pop();
	
	d[r1][c1][k] = 0;
	u.r = r1, u.c = c1, u.t = k;
	q.push(u);
	
	int r, c, t, x, y;
	while(!q.empty()) {
		u = q.front();
		q.pop();
		
		r = u.r, c = u.c, t = u.t;
		if (a[r][c] == '.') {
			if (t == 0) continue;
			FOR(num,1,9) 
				REP(i,0,4) {
					x = r + offx[i] * num;	
					y = c + offy[i] * num;
					
					if (x < 0 || x > n - 1 || y < 0 || y > m - 1 
						|| d[x][y][t - 1] != -1) continue;
					
					d[x][y][t - 1] = d[r][c][t] + 1;
					v.r = x, v.c = y, v.t = t - 1;
					q.push(v);
				}
		}
		else {
			REP(i,0,4) {
				x = r + offx[i] * (a[r][c] - '0');
				y = c + offy[i] * (a[r][c] - '0');
				
				if (x < 0 || x > n - 1 || y < 0 || y > m - 1 
					|| d[x][y][t] != -1) continue;
				
				d[x][y][t] = d[r][c][t] + 1;
				v.r = x, v.c = y, v.t = t;
				q.push(v);
			}
		}
	}
	
	int res = INT_MAX;
	FOR(i,0,k) if (d[r2][c2][i] != -1) res = min(res,d[r2][c2][i]);
	
	if (res == INT_MAX) return -1;
	return res;
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, int p2, int p3, int p4, int p5, bool hasAnswer, int p6) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1 << "," << p2 << "," << p3 << "," << p4 << "," << p5;
	cout << "]" << endl;
	NumberLabyrinthDiv2 *obj;
	int answer;
	obj = new NumberLabyrinthDiv2();
	clock_t startTime = clock();
	answer = obj->getMinimumNumberOfMoves(p0, p1, p2, p3, p4, p5);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p6 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p6;
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
	
	vector <string> p0;
	int p1;
	int p2;
	int p3;
	int p4;
	int p5;
	int p6;
	
	{
	// ----- test 0 -----
	string t0[] = {"...2","....","3..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 0;
	p3 = 2;
	p4 = 3;
	p5 = 0;
	p6 = -1;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"...2","....","3..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 0;
	p3 = 2;
	p4 = 3;
	p5 = 1;
	p6 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"...3","....","2..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 0;
	p3 = 2;
	p4 = 3;
	p5 = 3;
	p6 = 3;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"55255",".0.0.","..9..","..3..","3.9.3","44.44"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 2;
	p3 = 4;
	p4 = 2;
	p5 = 10;
	p6 = 6;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"920909949","900020000","009019039","190299149","999990319","940229120","000409399","999119320","009939999"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	p2 = 3;
	p3 = 1;
	p4 = 1;
	p5 = 50;
	p6 = 10;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
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
