//b, e is array size range
//p, q is the query range
//mxs is the maxsize of the array
//build call: build(1, 1, n)
//query call: query(1, 1, n, p , q);
//update call: update(1, 1, n, pos, value);

#define mxs 1000005
lld tree[mxs * 3];
lld a[mxs + 3];

void build(int at, int b, int e) {
	if (b == e) {tree[at] = a[b]; return;}
	int l = at * 2, r = at * 2 + 1, m = (b + e) / 2;
	build(l, b, m);
	build(r, m + 1, e);
	tree[at] = tree[l] + tree[r];
}

lld query(int at, int b, int e, int p, int q) {
	if (q<b or p>e) return 0;
	if (p <= b and e <= q) return tree[at];
	int l = at * 2, r = at * 2 + 1, m = (b + e) / 2;
	lld p1 = query(l, b, m, p, q);
	lld p2 = query(r, m + 1, e, p, q);
	return p1 + p2;
}

void update(int at, int b, int e, int pos, lld value) {
	if (pos > e || pos < b)return;
	if (b >= pos && e <= pos) { tree[at] = value; return;}
	int l = at * 2, r = at * 2 + 1, m = (b + e) / 2;
	update(l, b, m, pos, value);
	update(r, m + 1, e, pos, value);
	tree[at] = tree[l] + tree[r];
}
