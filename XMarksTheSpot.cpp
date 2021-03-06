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


class XMarksTheSpot {
public:
	int count(vvi &b) {
		int T = -1, B = -1, L = -1, R = -1;
		FOR(i,0,sz(b)) {
			FOR(k,0,sz(b[i])) if (b[i][k] == 1) { T = i; break; }
			if (T != -1) break;
		}
		
		REP(i,sz(b) - 1,0) {
			REP(k,sz(b[0]) - 1,0) if (b[i][k] == 1) { B = i; break; }
			if (B != -1) break;
		}
		
		FOR(k,0,sz(b[0])) {
			FOR(i,0,sz(b)) if (b[i][k] == 1) { L = k; break; }
			if (L != -1) break;
		}
		
		REP(k,sz(b[0]) - 1,0) {
			REP(i,sz(b) - 1,0) if (b[i][k] == 1) { R = k; break; }
			if (R != -1) break;
		}
		
		return (B - T + 1) * (R - L + 1);
	}

	int countArea(vector <string> board) {
		vvi b(sz(board));
		FOR(i,0,sz(b)) b[i].resize(board[0].length());
						
		vector<pi> pos;
		FOR(i,0,sz(board))
			FOR(k,0,board[i].length()) {
				if (board[i][k] == '?') pos.pb(mp(i,k));
				if (board[i][k] == 'O') b[i][k] = 1;
			}
		
		int num = sz(pos);
		int cnt = 0;
		FOR(i,0,1<<num) {
			FOR(k,0,num) {
				int z = pos[k].first, t = pos[k].second;
				if ((i & 1<<k) != 0) b[z][t] = 1;
				else b[z][t] = 0;
			}
						
			cnt += count(b);
		}
		
		return cnt;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	XMarksTheSpot *obj;
	int answer;
	obj = new XMarksTheSpot();
	clock_t startTime = clock();
	answer = obj->countArea(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"?.",".O"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"?" "?" "?","?O?","?" "?" "?"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1952;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"...?.","?....",".O...","..?..","....?"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 221;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"OOOOOOOOOOOOOOOOOOOOO"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 21;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"?" "?" "?" "?" "?" "?" "?" "?" "?OO?" "?" "?" "?" "?" "?" "?" "?" "?" "?"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 9963008;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"OOO","O?O","OOO","..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 18;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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
