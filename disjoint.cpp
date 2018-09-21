class Disjoint {

private:
  vector<int> p, rank, setSizes;
  int numSets;

public:
  Disjoint(int N) {
    numSets = N;
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++)
      p[i] = i;
    setSizes.assign(N, 1);
  }
  
  int find(int i) {
    return (p[i] == i) ? i : p[i] = find(p[i]);
  }

  bool same(int i, int j) {
    return find(i) == find(j);
  }

  void joint(int i, int j) {
    if (!same(i, j)) {
      int x = find(i), y = find(j);
      if (rank[x] > rank[y]) {
        setSizes[find(x)] += setSizes[find(y)];
        p[y] = x;
      } else {
        setSizes[find(y)] += setSizes[find(x)];
        p[x] = y;
        if (rank[x] == rank[y])
          rank[y]++;
      }
      numSets--;
    }
  }

  int setSize(int i) {
    return setSizes[find(i)];
  }

  int size() {
    return numSets;
  }
};