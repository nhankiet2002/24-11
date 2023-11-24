#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class QMax {
private:
    vector<int> seg;
    vector<int> add;
    int size;

public:
    QMax(int n) : size(n), seg(4 * n), add(4 * n) {}

    void update(int k, int l, int r, int u, int v, int value) {
        if (l > r || v < l || u > r) return;
        if (u <= l && r <= v) {
            seg[k] += value;
            add[k] += value;
            return;
        }
        update(k * 2, l, (l + r) / 2, u, v, value);
        update(k * 2 + 1, (l + r) / 2 + 1, r, u, v, value);
        seg[k] = max(seg[k * 2], seg[k * 2 + 1]) + add[k];
    }

    int get(int k, int l, int r, int u, int v) {
        if (l > r || v < l || u > r) return INT_MIN;
        if (u <= l && r <= v) return seg[k];
        return max(get(k * 2, l, (l + r) / 2, u, v), get(k * 2 + 1, (l + r) / 2 + 1, r, u, v)) + add[k];
    }

    void update(int u, int v, int value) {
        update(1, 1, size, u, v, value);
    }

    int query(int u, int v) {
        return get(1, 1, size, u, v);
    }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    QMax Q(n);

    for (int i = 0; i < m; ++i) {
        int u, v, k;
        scanf("%d%d%d", &u, &v, &k);
        Q.update(u, v, k);
    }

    int p;
    scanf("%d", &p);

    for (int i = 0; i < p; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", Q.query(u, v));
    }

    return 0;
}

