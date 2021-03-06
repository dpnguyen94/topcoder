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

class EnclosingRectangle {
public:
	int smallestArea(vector <string> X, vector <string> Y);
};

vi x, y;

int EnclosingRectangle::smallestArea(vector <string> X, vector <string> Y) {
	x.clear();
	y.clear();
	
	string s = "";
	REP(i,0,sz(X)) s += X[i];
	int t = 0;
	REP(i,0,sz(s)) if (isdigit(s[i])) {
		t = t * 10 + (s[i] - '0');		
		if (i == sz(s) - 1 || s[i + 1] == ' ') {
			x.pb(t);
			t = 0;
		}
	}		
	s = "";
	REP(i,0,sz(Y)) s += Y[i];
	REP(i,0,sz(s)) if (isdigit(s[i])) {
		t = t * 10 + (s[i] - '0');
		if (i == sz(s) - 1 || s[i + 1] == ' ') {
			y.pb(t);
			t = 0;
		}
	}
	
	vi a = x, b;
	int cnt = sz(x) / 2, res = INT_MAX;
	sort(all(a));
	REP(i,0,sz(a))
		REP(k,i,sz(a)) {
			b.clear();
			REP(t,0,sz(x)) if (x[t] >= a[i] && x[t] <= a[k]) b.pb(y[t]);
			
			sort(all(b));
			
			int z, tmp;
			REP(t,0,sz(b)) {
				z = t + cnt - 1;
				if (z > sz(b) - 1) break;				
				
				tmp = (a[k] - a[i] + 2) * (b[z] - b[t] + 2);
				res = min(res,tmp);
			}			
		}		
		
	return res;
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	EnclosingRectangle *obj;
	int answer;
	obj = new EnclosingRectangle();
	clock_t startTime = clock();
	answer = obj->smallestArea(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	
	vector <string> p0;
	vector <string> p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"100 200"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"100 200"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"10 11 13 10 11 13"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"5 5 5 15 16 17"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 10;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"5 6 6 7 7 8 8 9"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"7 6 8 5 9 6 8 7"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 16;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"4496 6443 2837 557 4098 1083 3466 1250 6126 ","3135 7598 9274 9180 5128 741 7625 8316 414 ","9071 8753 5509 1080 2797 906 3805 698 947 ","8645 9640 2596 6883 1845 9169 3922 4792 7919 ","7389 9397 4901 1343 3347 6366 9118 3148 780 ","4541 9479 483 1174 9615 8900 3067 5397 9879 ","7440 8948 846 8881 7602 6760 3327 5197 9017 ","5463 6781 2478 6270 5392 9420 9069 3609 6401 ","1810 6680 6787 9840 1031 1916 5415 1168 5154 ","2727 8834 9125 3961 4289 4750 5524 5118 5258 ","2652 7020 9770 5866 3386 6447 7960 3889 2158 ","6717"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"6801 8243 9390 2156 5505 5509 3442 6663 1294 ","9979 1008 5644 7516 5442 5909 4550 2431 2779 ","419 4744 8155 7800 2944 4169 1633 1464 7353 ","5365 1548 3073 8596 4461 2540 4664 5057 1870 ","4782 4028 8003 9175 2592 4520 2420 6955 519 ","2141 1580 5170 9138 4268 9724 1093 5633 9820 ","3411 9789 6200 7661 2296 8644 8259 8631 4342 ","574 530 6664 8812 161 8141 6210 2803 3209 ","8090 6380 3498 3014 7650 7062 8853 5939 4578 ","8647 4020 4844 3362 4930 9447 1346 6162 8242 ","9276 6967 589 6960 5467 8768 9018 8155 3886 ","7274"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 37305252;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"5481    3318      5721      9019 ","1618       9762  1654     2275 ","5361    307 6833             9456  ","7473 6088 9685 2725"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"1181     7762        3889    7015 ","    5445   9063        2510           8229 ","   4390      6454   9197    708 ","  2221    9012     2665      8308"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 25959465;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"1242 9594 6816 833 6587 7183 9355 7087 ","  ","8675 5944 786 3597 1327 9884 7138 8073 ","","3017 5468 331 8136"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"1105 7791 7865 8119 ","9950 8261 5988 1708 ","1615 5400 487 4837 4712 5777 3819 ","","5063 5143 5990 2895 4375",""};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 18598707;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	string t0[] = {"100"," 200"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"100 2","00"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
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
