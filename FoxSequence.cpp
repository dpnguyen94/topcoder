#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <limits.h>
#include <memory.h>

using namespace std;

#define REPF(i,a,b) 	for (int i=(a);i<(b);i++)
#define REPB(i,a,b) 	for (int i=(a);i>(b);i--)
#define FORU(i,a,b) 	for (int i=(a);i<=(b);i++)
#define FORD(i,a,b) 	for (int i=(a);i>=(b);i--)
#define pb 				push_back
#define mp 				make_pair
#define sz(a) 			int((a).size())
#define all(c) 			(c).begin(), (c).end()

typedef long long 		LL;
typedef vector<int> 	vi;
typedef vector<vi> 		vvi;
typedef pair<int, int> 	pii;
typedef pair<pii, int> 	piii;

class FoxSequence {
public:
	string isValid(vector <int> a);
};

string FoxSequence::isValid(vector <int> s) {
	int n = sz(s);
	if (n < 5) return "NO";

	int a = -1, b = -1, c = -1, d = -1;	
	int k = s[1] - s[0];
	if (k <= 0) return "NO";
	REPF(i,1,n) {
		if (s[i] >= s[i - 1] && s[i] - s[i - 1] != k) return "NO";
		if (s[i] < s[i - 1]) {
			a = i - 1;
			k = s[i] - s[i - 1];
			break;
		}
	}
	REPF(i,a + 1,n) {
		if (s[i] < s[i - 1] && s[i] - s[i - 1] != k) return "NO";
		if (s[i] >= s[i - 1]) {
			b = i - 1;
			break;
		}
	}
	REPF(i,b + 1,n) 
		if (s[i] != s[b]) {
			c = i - 1;
			break;
		}
	k = s[c + 1] - s[c];
	if (k <= 0) return "NO";
	REPF(i,c + 1,n) {
		if (s[i] >= s[i - 1] && s[i] - s[i - 1] != k) return "NO";
		if (s[i] < s[i - 1]) {
			d = i - 1;
			k = s[i] - s[i - 1];
			break;
		}
	}
	REPF(i,d + 1,n) 
		if (s[i] - s[i - 1] != k) return "NO";
			
	if (a == -1 || b == -1 || d == -1) return "NO";
	return "YES";
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	FoxSequence *obj;
	string answer;
	obj = new FoxSequence();
	clock_t startTime = clock();
	answer = obj->isValid(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	
	vector <int> p0;
	string p1;
	
	{
	// ----- test 0 -----
	int t0[] = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "YES";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "YES";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {3,6,9,1,9,5,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "YES";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1,2,3,2,1,2,3,2,1,2,3,2,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "NO";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {1,3,4,3,1,1,1,1,3,4,3,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "NO";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {6,1,6};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "NO";
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