#include <bits/stdc++.h>
using namespace std;

void get_prime(vector<int>& p, int d, int x) {
	for(int i = d + x; ; i++) { // start from d + either 1 or p (so that the difference will be d)
		bool checker = true;
		for(int j = 2; j * j <= i; j++) { // check if the number is prime
			if (i % j == 0) {
				checker = false;
				break;
			}
		}
		if(checker) {
			p.push_back(i);
			break;
		}
	}
}

void perform_test() {
	int d;
	cin >> d;
	vector<int> p;
	// to be able to solve this, we need to have divisors that are prime numbers
	// because they cannot be divided anymore and in order to to this, there are
	// two possible sets of prime divisors to be compared with:
	
	// 1st set: {1, p, q, pq}
	// where p >= 1 + d, q >= p + d, and pq = which will be our answer
	
	// 2nd set: {1, p, p^2, p^3}
	// where p >= 1 + d, p^2 and p^3 satisfies the condition in the problem statement
	// since p + 1 >= d, then p^3 - p^2 > p^2 - p > p - 1
	
	get_prime(p, d, 1 // this will be p
	get_prime(p, d, p.back()); // this will be q or p^3
	cout << min(1LL * p[0] * p[1], 1LL * p[0] * p[0] * p[0]) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for(int t = 0; t < tc; t++) {
		perform_test();
	}
	return 0;
}
