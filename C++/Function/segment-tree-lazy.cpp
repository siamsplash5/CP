//b, e is array size range
//p, q is the query/update range
//mxs is the maxsize of the array
//build call: build(1, 1, n)
//query call: query(1, 1, n, query_l, query_r, 0);
//update call: update(1, 1, n, update_l, update_r, value);

#define mxs 1000005
struct lazy {
	lld sum = 0, prop = 0;
};
lazy tree[mxs * 3];
lld a[mxs + 3];

void build(int at, int b, int e) {
	if (b == e) {tree[at].sum = a[b]; return;}
	int l = at * 2, r = at * 2 + 1, m = (b + e) / 2;
	build(l, b, m);
	build(r, m + 1, e);
	tree[at].sum = tree[l].sum + tree[r].sum;
}

void update(int at, int b, int e, int p, int q, lld value) {
	if (q<b or p>e) return;
	if (p <= b and e <= q) {
		tree[at].sum += ((e - b + 1) * value);
		tree[at].prop += value;
		return;
	}
	int l = at * 2, r = at * 2 + 1, m = (b + e) / 2;
	update(l, b, m, p, q, value);
	update(r, m + 1, e, p, q, value);
	tree[at].sum = tree[l].sum + tree[r].sum + (e - b + 1) * tree[at].prop;
}

lld query(int at, int b, int e, int p, int q, lld carry) {
	if (q<b or p>e) return 0;
	if (p <= b and e <= q) return tree[at].sum + (e - b + 1) * carry;
	int l = at * 2, r = at * 2 + 1, m = (b + e) / 2;
	lld p1 = query(l, b, m, p, q, carry + tree[at].prop);
	lld p2 = query(r, m + 1, e, p, q, carry + tree[at].prop);
	return p1 + p2;
}
