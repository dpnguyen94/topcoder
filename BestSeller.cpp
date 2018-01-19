#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <math.h>
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
typedef unsigned long long 	ULL;
typedef vector<int> 	vi;
typedef vector<vi> 		vvi;
typedef vector<string> 	vs;
typedef pair<int, int> 	pii;
typedef pair<pii, int> 	piii;

class BestSeller {
public:
	string findBestSeller(vector <string> items);
};

string BestSeller::findBestSeller(vector <string> a) {
	int n = sz(a);
	int count[55];
	memset(count,0,sizeof(count));
	REPF(i,0,n)
		REPF(k,0,n) 
			if (a[i] == a[k]) count[i] ++;
	int best = 0;
	string res = "";
	REPF(i,0,n) 
		if (count[i] > best) {
			best = count[i];
			res = a[i];
		}
		else if (count[i] == best && a[i] < res) 
			res = a[i];
			
	return res;
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	BestSeller *obj;
	string answer;
	obj = new BestSeller();
	clock_t startTime = clock();
	answer = obj->findBestSeller(p0);
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
	
	vector <string> p0;
	string p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"table","chair","table","table","lamp","door","lamp","table","chair"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "table";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"a","a","a","b","b","b"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "a";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"icecream","peanuts","peanuts","chocolate","candy","chocolate","icecream","apple"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "chocolate";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"soul"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "soul";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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