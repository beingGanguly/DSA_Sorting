#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int max_sum = 0, min_sum = A[0] + A[1];

    for (int i = 0; i < n - 1; i += 2) {
        int s = A[i] + A[i + 1];
        if (s > max_sum) {
            max_sum = s;
        }
        if (s < min_sum) {
            min_sum = s;
        }
    }
    cout << min_sum << " " << max_sum << endl;
    return 0;
}

