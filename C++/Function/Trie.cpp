struct TrieNode {
    int next[26];
    int freq;
    TrieNode() {
        for (int i = 0; i < 26; i++)next[i] = -1;
        freq = 0;
    }
};

std::vector<TrieNode> tree;

void insert(string s) {
    int now = 0;
    tree[now].freq++;
    for (auto it : s) {
        if (tree[now].next[it - 'a'] == -1) {
            tree.push_back(TrieNode());
            tree[now].next[it - 'a'] = tree.size() - 1;
        }
        now = tree[now].next[it - 'a'];
        tree[now].freq++;
    }
}

lld search(string s) {
    lld now = 0;
    for (auto it : s) {
        if (tree[now].next[it - 'a'] == -1)return 0;
        now = tree[now].next[it - 'a'];
    }
    return tree[now].freq;
}