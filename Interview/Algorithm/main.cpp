#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

int main() {

    vector<int> v = {4, 7, 1, 6, 7, 8, 2, 4};
    sort(v.begin(), v.end());
    for (const auto& e: v){
        cout << e << " " << flush;
    }
    cout << endl;

    int mx = *max_element(v.begin(), v.end());
    int mn = *min_element(v.begin(), v.end());
    cout << mx << " " << mn << endl;

    nth_element(v.begin(), v.begin() + 2, v.end(), std::greater{});
    cout << "Largest element: " << v[0] << endl;
    cout << "2nd Largest element: " << v[1] << endl;
    cout << "3rd Largest element: " << v[2] << endl;

    int sum = accumulate(v.begin(), v.end(), 0);
    cout << boolalpha << sum << endl;

    int prod = accumulate(v.begin(), v.end(), 1, multiplies<>());
    cout << prod << endl;

    long cnt = count(v.begin(), v.end(), 7);
    cout << cnt << endl;

    auto it = find(v.begin(), v.end(), 7);
    cout << it - v.begin() << endl;

    bool state = binary_search(v.begin(), v.end(), 7);
    cout << state << endl;
    state = binary_search(v.begin(), v.end(), 9);
    cout << state << endl;

    vector<int> u = {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12};
    auto lb = lower_bound(u.begin(), u.end(), 10);  // First element not less than x
    cout << lb - u.begin() << endl;

    auto ub = upper_bound(u.begin(), u.end(), 10); // First element greater than x
    cout << ub - u.begin() << endl;

    // First index where element x lies
    long idx = lower_bound(u.begin(), u.end(), 15) - u.begin();
    if (idx != u.size() && u[idx] == 15){
        cout << "15 found at: " << idx << endl;
    } else {
        cout << "15 Not found" << endl;
    }

    // Last occurrence of x
    idx = upper_bound(u.begin(), u.end(), 10) - u.begin() - 1;
    if (idx >= 0 && u[idx] == 10){
        cout << "Last 10 found at: " << idx << endl;
    } else {
        cout << "Not found" << endl;
    }

    // Count the number of times x appears
    int x = 10;
    long lidx = lower_bound(u.begin(), u.end(), x) - u.begin();
    long uidx = upper_bound(u.begin(), u.end(), x) - u.begin() - 1;

    if (lidx != u.size() && u[lidx] == x && uidx >= 0 && u[uidx] == x){
        cout << "Count of " << x << ": " << uidx - lidx + 1<< endl;
    } else {
        cout << "Not found" << endl;
    }

    // Next permutation: s = "abc", permutations of s are [abc, acb, bac, bca, cab, cba]
    string s = "OfMonstersAndMen";
    state = next_permutation(s.begin(), s.end());
    cout << "Next permutation: " << s << endl;

    // Previous permutation
    state = prev_permutation(s.begin(), s.end());
    cout << "Previous permutation: " << s << endl;

    return 0;
}