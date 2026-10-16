/**
 * @file Lazy Propagation.cpp
 * @brief Segment Tree with Lazy Propagation (Range Update & Range Sum Query)
 * 
 * Supports:
 *   - Range Add Update: a[l..r] += x in O(log n)
 *   - Range Sum Query:  sum(a[l..r]) in O(log n)
 * 
 * Time Complexity:  O(n) build, O(log n) per range query / update
 * Space Complexity: O(4 * n)
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define mx 100010
#define ll long long int

struct Node {
    ll prop;
    ll sum;
};

Node tree[4 * mx + 10];
ll arr[mx + 10];

void build(int node, int start, int eend) {
    if (start == eend) {
        tree[node].sum = arr[start];
        tree[node].prop = 0;
        return;
    }
    int mid = (start + eend) >> 1;
    int l = node << 1;
    int r = l + 1;

    build(l, start, mid);
    build(r, mid + 1, eend);

    tree[node].sum = tree[l].sum + tree[r].sum;
    tree[node].prop = 0;
}

ll query(int node, int start, int eend, int st, int ed, ll car) {
    if (eend < st || start > ed)
        return 0;
    if (start >= st && eend <= ed) {
        return tree[node].sum + (eend - start + 1) * car;
    }
    int mid = (start + eend) >> 1;
    int l = node << 1;
    int r = l + 1;

    ll p1 = query(l, start, mid, st, ed, car + tree[node].prop);
    ll p2 = query(r, mid + 1, eend, st, ed, car + tree[node].prop);

    return p1 + p2;
}

void update(int node, int start, int eend, int st, int en, ll x) {
    if (eend < st || start > en)
        return;
    if (start >= st && eend <= en) {
        tree[node].prop += x;
        tree[node].sum += (ll)(eend - start + 1) * x;
        return;
    }

    int mid = (start + eend) >> 1;
    int l = node << 1;
    int r = l + 1;

    update(l, start, mid, st, en, x);
    update(r, mid + 1, eend, st, en, x);
    tree[node].sum = tree[l].sum + tree[r].sum + tree[node].prop * (eend - start + 1);
}

int main() {
    int test, n, qur, st, en, p;
    ll x;

    if (cin >> test) {
        for (int Case = 1; Case <= test; Case++) {
            for (int i = 0; i <= 4 * mx; i++) {
                tree[i].sum = 0;
                tree[i].prop = 0;
            }
            for (int i = 0; i < mx; i++)
                arr[i] = 0;

            if (scanf("%d %d", &n, &qur) != 2) break;
            build(1, 1, n);

            printf("Case %d:\n", Case);
            for (int i = 0; i < qur; i++) {
                scanf("%d", &p);
                if (p == 0) {
                    scanf("%d %d %lld", &st, &en, &x);
                    st++;
                    en++;
                    update(1, 1, n, st, en, x);
                } else {
                    scanf("%d %d", &st, &en);
                    st++;
                    en++;
                    printf("%lld\n", query(1, 1, n, st, en, 0));
                }
            }
        }
    }
    return 0;
}
