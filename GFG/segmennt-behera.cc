
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    auto calc = [](const int& x, const int& y){ return max(x, y);};

    vector<int> seg_tree(4 * n, INT_MIN);
    auto build = [&calc, &seg_tree, &arr](const auto& build, const int& idx, const int& lo, const int& hi){
        if(lo == hi) {
            seg_tree[idx] = arr[lo];
            return;
        }

        int mid = lo + (hi - lo) / 2;
        build(build, 2 * idx + 1, lo, mid);
        build(build, 2 * idx + 2, mid + 1, hi);

        seg_tree[idx] = calc(seg_tree[2 * idx + 1], seg_tree[2 * idx + 2]);
    };

    auto query = [&calc, &seg_tree](const auto& query, const int& idx, const int& a, const int& b, const int& lo, const int& hi){
        if(lo > b || hi < a) {
            return INT_MIN;
        }

        if(lo >= a && hi <= b) {
            return seg_tree[idx];
        }

        int mid = lo + (hi - lo) / 2;
        return calc(query(query, 2 * idx + 1, a, b, lo, mid), 
                                query(query, 2 * idx + 2, a, b, mid + 1, hi));
    };

    build(build, 0, 0, n - 1);
    while(q--) {
        int l, r;
        cin >> l >> r;

        --l, --r;
        cout << max(query(query, 0, 0, l - 1, 0, n - 1), query(query, 0, r + 1, n - 1, 0, n - 1)) << '\n';
    }
}
