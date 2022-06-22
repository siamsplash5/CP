lld query(lld node, lld b, lld e, lld carry) {
	if (q<b or p>e) return 0;
	if (p <= b and e <= q) return tree[node].sum + (e - b + 1) * carry;
	lld left = 2 * node;
	lld right = 2 * node + 1;
	lld mid = (b + e) / 2;
	lld p1 = query(left, b, mid, carry + tree[node].prop);
	lld p2 = query(right, mid + 1, e, carry + tree[node].prop);
	return p1 + p2;
}

void update(lld node, lld b, lld e) {
	if (q<b or p>e) return;
	if (p <= b and e <= q) {
		tree[node].sum += ((e - b + 1) * v);
		tree[node].prop += v;
		return;
	}
	lld left = 2 * node;
	lld right = 2 * node + 1;
	lld mid = (b + e) / 2;
	update(left, b, mid);
	update(right, mid + 1, e);
	tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].prop;
}