
// Problem: Digit Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2431
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const uint64_t pow_10[20] = {
    UINT64_C(1),
    UINT64_C(10),
    UINT64_C(100),
    UINT64_C(1000),
    UINT64_C(10000),
    UINT64_C(100000),
    UINT64_C(1000000),
    UINT64_C(10000000),
    UINT64_C(100000000),
    UINT64_C(1000000000),
    UINT64_C(10000000000),
    UINT64_C(100000000000),
    UINT64_C(1000000000000),
    UINT64_C(10000000000000),
    UINT64_C(100000000000000),
    UINT64_C(1000000000000000),
    UINT64_C(10000000000000000),
    UINT64_C(100000000000000000),
    UINT64_C(1000000000000000000),
    UINT64_C(10000000000000000000)
};

int A007376(uint64_t i)
{
    uint64_t     digits = 1U;
    uint64_t     value  = 1U;
    uint64_t     limit  = 9U;

    /* The sequence starts at index 1. Shift to zero. */
    if (!i--)
        return 0;

    /* Find the number of digits in each number
       in the region of index i. */
    while (i/limit >= digits) {
        const uint64_t old_limit = limit;

        i -= digits * limit;

        digits++;
        value *= 10U;
        limit *= 10U;

        /* If limit overflows, we are in the correct, final region. */
        if (limit <= old_limit)
            break;
    }

    /* We know the desired digit is i'th digit
       in a string formed by concatenating the
       9*10^(digits-1) numbers starting at 10^(digits-1).
       The value of this number is pow10(digits-1) + i/digits: */
    value += i / digits;


    /* Move the desired digit into the ones position. */
    value /= pow_10[(digits - 1) - (i % digits)];

    return value % 10U;
}

int main() {
	int N;
	cin >> N;
	string str;
	while (N--) {
		uint64_t idx;
		cin >> idx;
		cout << A007376(idx) << endl;
	}
	return 0;
}
