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

const LL INF = 1000000000000000LL;

class MagicalGirlLevelThreeDivTwo {
public:
	int theCount(vector <string> first, int n, long long lo, long long hi);
};

int K;
LL num[105], len[105];
vs b;

int calc(int n, LL lo, LL hi) {
	int res = 0;
	if (n < K) {
		FOR(i,lo,hi) res += (b[n][i] == '1');
		return res;
	}

	int x = n - 1;
	LL head = 0, tail;
	while (x >= 0) {
        tail = head + len[x] - 1;
        
        if (head > INF) break;
        
        if (tail < lo || head > hi) {
        	x -= K;
            head = tail + 1;
            continue;
        }
        
        if (lo <= head && tail <= hi) res += num[x];
        else if (head <= lo && hi <= tail) res += calc(x,lo - head,hi - head);
        else if (head < lo) res += calc(x,lo - head,tail - head);
        else if (tail > hi) res += calc(x,0,hi - head);
        
        head = tail + 1;
        x -= K;
	}
		
	return res;
}

int MagicalGirlLevelThreeDivTwo::theCount(vector <string> a, int n, long long lo, long long hi) {
	K = sz(a);
	REP(i,0,K) {
		len[i] = a[i].length();	
		int cnt = 0;
		REP(k,0,a[i].length()) cnt += (a[i][k] == '1');
		num[i] = cnt;
	}
	
	FOR(i,K,n) {
		num[i] = len[i] = 0;
		
		int x = i - 1;
		while (x >= 0) {
			num[i] += num[x];
			len[i] += len[x];
			
			if (len[i] > INF) break;
			x -= K;
		}		
	}
	
	b = a;
	return calc(n,lo,hi);
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, long long p2, long long p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	MagicalGirlLevelThreeDivTwo *obj;
	int answer;
	obj = new MagicalGirlLevelThreeDivTwo();
	clock_t startTime = clock();
	answer = obj->theCount(p0, p1, p2, p3);
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
	
	vector <string> p0;
	int p1;
	long long p2;
	long long p3;
	int p4;
	
	{
	// ----- test 0 -----
	string t0[] = {"101","01"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	p2 = 2ll;
	p3 = 5ll;
	p4 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"01","10"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	p2 = 4ll;
	p3 = 5ll;
	p4 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"1","11","111"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 46;
	p2 = 10000ll;
	p3 = 11000ll;
	p4 = 1001;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"0","00","000"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 46;
	p2 = 10000ll;
	p3 = 11000ll;
	p4 = 0;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"00110110101101001111101101001011010011111011010010"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 100;
	p2 = 999999999999915ll;
	p3 = 1000000000000000ll;
	p4 = 50;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"10000","011011001011000001101000010100000111000110110","000001010001011000001101110","100100000110100001010000","011011010","01100000010101101110000011100011001000","0001010","010011000","000101001","00","1"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 91;
	p2 = 123456ll;
	p3 = 123654ll;
	p4 = 76;
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