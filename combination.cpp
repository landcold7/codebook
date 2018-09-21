
int comb(int n, int k){
  if (k > n) return 0;
  if (k * 2 > n) k = n - k;
  if (k == 0) return 1;

  int result = n;
  for (int i = 2; i <= k; ++i ) {
    result *= (n - i + 1);
    result /= i;
  }
  return result;
}


int cnk[MAX][MAX];
void comb() {
  for (int i = 0; i < MAX; ++i) {
    cnk[i][0] = cnk[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      cnk[i][j] = cnk[i - 1][j - 1] + cnk[i - 1][j];
      if (cnk[i][j] >= MOD)
        cnk[i][j] -= MOD;
    }
  }
}