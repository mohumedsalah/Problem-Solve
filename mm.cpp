BackTrack
/* 8 Queens Chess Problem */
#include <cstdlib>                       // we use the int version of 'abs'
#include <cstdio>
#include <cstring>
using namespace std;

int row[8], TC, a, b, lineCounter;            // ok to use global variables

bool place(int r, int c) {
  for (int prev = 0; prev < c; prev++)    // check previously placed queens
    if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
      return false;        // share same row or same diagonal -> infeasible
  return true; }

void backtrack(int c) {
  if (c == 8 && row[b] == a) {         // candidate sol, (a, b) has 1 queen
    printf("%2d      %d", ++lineCounter, row[0] + 1);
    for (int j = 1; j < 8; j++) printf(" %d", row[j] + 1);
    printf("\n"); }
  for (int r = 0; r < 8; r++)                       // try all possible row
    if (place(r, c)) {          // if can place a queen at this col and row
      row[c] = r; backtrack(c + 1);      // put this queen here and recurse
}   }

int main() {
  scanf("%d", &TC);
  while (TC--) {
    scanf("%d %d", &a, &b); a--; b--;         // switch to 0-based indexing
    memset(row, 0, sizeof row); lineCounter = 0;
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    backtrack(0);           // generate all possible 8! candidate solutions
    if (TC) printf("\n");
} } // return 0;



classic Dp
/* UVa 11450 - Wedding Shopping - Top Down */
// this code is similar to recursive backtracking code
// parts of the code specific to top-down DP are commented with: `TOP-DOWN'
// if these lines are commented, this top-down DP will become backtracking!
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int M, C, price[25][25];                 // price[g (<= 20)][model (<= 20)]
int memo[210][25];    // TOP-DOWN: dp table memo[money (<= 200)][g (<= 20)]
int shop(int money, int g) {
  if (money < 0) return -1000000000;     // fail, return a large -ve number
  if (g == C) return M - money;        // we have bought last garment, done
  if (memo[money][g] != -1) return memo[money][g]; // TOP-DOWN: memoization
  int ans = -1;   // start with a -ve number as all prices are non negative
  for (int model = 1; model <= price[g][0]; model++)      // try all models
    ans = max(ans, shop(money - price[g][model], g + 1));
  return memo[money][g] = ans; // TOP-DOWN: assign ans to table + return it
}

/*

int shop(int money, int g) {
  if (money < 0) return -1000000000;
  if (g == C) return M - money;
  int &ans = memo[money][g];                 // remember the memory address
  if (ans != -1) return ans;
  for (int model = 1; model <= price[g][0]; model++)
    ans = max(ans, shop(money - price[g][model], g + 1));
  return ans;                // ans (or memo[money][g]) is directly updated
}

void print_shop(int money, int g) { // this function does not return anything
  if (money < 0 || g == C) return;                      // similar base cases
  for (int model = 1; model <= price[g][0]; model++)   // which model is opt?
    if (shop(money - price[g][model], g + 1) == memo[money][g]) { // this one
      printf("%d - ", price[g][model]);
      print_shop(money - price[g][model], g + 1); // recurse to this one only
      break;
}   }

*/

int main() {            // easy to code if you are already familiar with it
  int i, j, TC, score;

  scanf("%d", &TC);
  while (TC--) {
    scanf("%d %d", &M, &C);
    for (i = 0; i < C; i++) {
      scanf("%d", &price[i][0]);                  // store K in price[i][0]
      for (j = 1; j <= price[i][0]; j++) scanf("%d", &price[i][j]);
    }
    memset(memo, -1, sizeof memo);    // TOP-DOWN: initialize DP memo table
    score = shop(M, 0);                            // start the top-down DP
    if (score < 0) printf("no solution\n");
    else           printf("%d\n", score);
} } // return 0;

max 1D
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  int n = 9, A[] = { 4, -5, 4, -3, 4, 4, -4, 4, -5 };   // a sample array A
  int running_sum = 0, ans = 0;
  for (int i = 0; i < n; i++)                                       // O(n)
    if (running_sum + A[i] >= 0) {  // the overall running sum is still +ve
      running_sum += A[i];
      ans = max(ans, running_sum);          // keep the largest RSQ overall
    }
    else        // the overall running sum is -ve, we greedily restart here
      running_sum = 0;      // because starting from 0 is better for future
                           // iterations than starting from -ve running sum
  printf("Max 1D Range Sum = %d\n", ans);                    // should be 9
} // return 0;

max 2D
// Maximum Sum

#include <algorithm>
#include <cstdio>
using namespace std;

int n, A[101][101], maxSubRect, subRect;

int main() {     // O(n^3) 1D DP + greedy (Kadane's) solution, 0.008 s in UVa
  scanf("%d", &n);                    // the dimension of input square matrix
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    scanf("%d", &A[i][j]);
    if (j > 0) A[i][j] += A[i][j - 1];      // only add columns of this row i
  }

  maxSubRect = -127*100*100;    // the lowest possible value for this problem
  for (int l = 0; l < n; l++) for (int r = l; r < n; r++) {
    subRect = 0;
    for (int row = 0; row < n; row++) {
      // Max 1D Range Sum on columns of this row i
      if (l > 0) subRect += A[row][r] - A[row][l - 1];
      else       subRect += A[row][r];

      // Kadane's algorithm on rows
      if (subRect < 0) subRect = 0;     // greedy, restart if running sum < 0
      maxSubRect = max(maxSubRect, subRect);
  } }

  printf("%d\n", maxSubRect);
  return 0;
}
        


/*
#include <algorithm>
#include <cstdio>
using namespace std;

int n, A[101][101], maxSubRect, subRect;

int main() {                            // O(n^4) DP solution, ~0.076s in UVa
  scanf("%d", &n);                    // the dimension of input square matrix
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    scanf("%d", &A[i][j]);
    if (i > 0) A[i][j] += A[i - 1][j];           // if possible, add from top
    if (j > 0) A[i][j] += A[i][j - 1];          // if possible, add from left
    if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];     // avoid double count
  }                                          // inclusion-exclusion principle

  maxSubRect = -127*100*100;    // the lowest possible value for this problem
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) // start coordinate
    for (int k = i; k < n; k++) for (int l = j; l < n; l++) {    // end coord
      subRect = A[k][l];      // sum of all items from (0, 0) to (k, l): O(1)
      if (i > 0) subRect -= A[i - 1][l];                              // O(1)
      if (j > 0) subRect -= A[k][j - 1];                              // O(1)
      if (i > 0 && j > 0) subRect += A[i - 1][j - 1];                 // O(1)
      maxSubRect = max(maxSubRect, subRect); }          // the answer is here

  printf("%d\n", maxSubRect);
  return 0;
}

*/



/*


int n, A[101][101], maxSubRect, subRect;

int main() {                // O(n^6) brute force solution, TLE (> 3s) in UVa
  scanf("%d", &n);
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    scanf("%d", &A[i][j]);

  maxSubRect = -127*100*100;    // the lowest possible value for this problem
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) // start coordinate
    for (int k = i; k < n; k++) for (int l = j; l < n; l++) {    // end coord
      subRect = 0;                         // sum items in this sub-rectangle
      for (int a = i; a <= k; a++) for (int b = j; b <= l; b++)
        subRect += A[a][b];
      maxSubRect = max(maxSubRect, subRect); }          // the answer is here

  printf("%d\n", maxSubRect);
  return 0;
}

*/
LIS
#define MAX_N 100000

void print_array(const char *s, int a[], int n) {
  for (int i = 0; i < n; ++i) {
    if (i) printf(", ");
    else printf("%s: [", s);
    printf("%d", a[i]);
  }
  printf("]\n");
}

void reconstruct_print(int end, int a[], int p[]) {
  int x = end;
  stack<int> s;
  for (; p[x] >= 0; x = p[x]) s.push(a[x]);
  printf("[%d", a[x]);
  for (; !s.empty(); s.pop()) printf(", %d", s.top());
  printf("]\n");
}

int main() {
  int n = 11, A[] = {-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4};
  int L[MAX_N], L_id[MAX_N], P[MAX_N];

  int lis = 0, lis_end = 0;
  for (int i = 0; i < n; ++i) {
    int pos = lower_bound(L, L + lis, A[i]) - L;
    L[pos] = A[i];
    L_id[pos] = i;
    P[i] = pos ? L_id[pos - 1] : -1;
    if (pos + 1 > lis) {
      lis = pos + 1;
      lis_end = i;
    }

    printf("Considering element A[%d] = %d\n", i, A[i]);
    printf("LIS ending at A[%d] is of length %d: ", i, pos + 1);
    reconstruct_print(i, A, P);
    print_array("L is now", L, lis);
    printf("\n");
  }

  printf("Final LIS is of length %d: ", lis);
  reconstruct_print(lis_end, A, P);
  return 0;
}

classic KnapSack
#define MAX_N 1010
#define MAX_W 40

int i, T, G, ans, N, MW, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int value(int id, int w) {
  if (id == N || w == 0) return 0;
  if (memo[id][w] != -1) return memo[id][w];
  if (W[id] > w)         return memo[id][w] = value(id + 1, w);
  return memo[id][w] = max(value(id + 1, w), V[id] + value(id + 1, w - W[id]));
}

int main() {
  scanf("%d", &T);
  while (T--) {
    memset(memo, -1, sizeof memo);

    scanf("%d", &N);
    for (i = 0; i < N; i++)
      scanf("%d %d", &V[i], &W[i]);

    ans = 0;
    scanf("%d", &G);
    while (G--) {
      scanf("%d", &MW);
      ans += value(0, MW);
    }

    printf("%d\n", ans);
  }

  return 0;
}

// 0-1 Knapsack DP (Bottom-Up)

#include <algorithm>
#include <cstdio>
using namespace std;

#define MAX_N 1010
#define MAX_W 40

int i, w, T, N, G, MW, V[MAX_N], W[MAX_N], C[MAX_N][MAX_W], ans;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (i = 1; i<= N; i++)
      scanf("%d %d", &V[i], &W[i]);

    ans = 0;
    scanf("%d", &G);
    while (G--) {
      scanf("%d", &MW);

      for (i = 0; i <= N;  i++) C[i][0] = 0;
      for (w = 0; w <= MW; w++) C[0][w] = 0;

      for (i = 1; i <= N; i++)
        for (w = 1; w <= MW; w++) {
          if (W[i] > w) C[i][w] = C[i - 1][w];
          else          C[i][w] = max(C[i - 1][w], V[i] + C[i - 1][w - W[i]]);
        }

      ans += C[N][MW];
    }

    printf("%d\n", ans);
  }

  return 0;
}

*/

Coin Change
/* Coin Change */

// O(NV) DP solution

#include <cstdio>
#include <cstring>
using namespace std;

int N = 5, V, coinValue[5] = {1, 5, 10, 25, 50}, memo[6][7500];
// N and coinValue are fixed for this problem, max V is 7489

int ways(int type, int value) {
  if (value == 0)              return 1;
  if (value < 0 || type == N)  return 0;
  if (memo[type][value] != -1) return memo[type][value];
  return memo[type][value] = ways(type + 1, value) + ways(type, value - coinValue[type]);
}

int main() {
  memset(memo, -1, sizeof memo); // we only need to initialize this once
  while (scanf("%d", &V) != EOF)
    printf("%d\n", ways(0, V));

  return 0;
}



Tsp
int i, j, TC, xsize, ysize, n, x[11], y[11], dist[11][11], memo[11][1 << 11]; // Karel + max 10 beepers

int tsp(int pos, int bitmask) { // bitmask stores the visited coordinates
  if (bitmask == (1 << (n + 1)) - 1)
    return dist[pos][0]; // return trip to close the loop
  if (memo[pos][bitmask] != -1)
    return memo[pos][bitmask];

  int ans = 2000000000;
  for (int nxt = 0; nxt <= n; nxt++) // O(n) here
    if (nxt != pos && !(bitmask & (1 << nxt))) // if coordinate nxt is not visited yet
      ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
  return memo[pos][bitmask] = ans;
}

int main() {
  scanf("%d", &TC);
  while (TC--) {
    scanf("%d %d", &xsize, &ysize); // these two values are not used
    scanf("%d %d", &x[0], &y[0]);
    scanf("%d", &n);
    for (i = 1; i <= n; i++) // karel's position is at index 0
      scanf("%d %d", &x[i], &y[i]);

    for (i = 0; i <= n; i++) // build distance table
      for (j = 0; j <= n; j++)
        dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]); // Manhattan distance

    memset(memo, -1, sizeof memo);
    printf("The shortest path has length %d\n", tsp(0, 1)); // DP-TSP
  }

  return 0;
}



Ways to Add?
/* How do you add? */

// top-down

/*
#include <cstdio>
#include <cstring>
using namespace std;

int N, K, memo[110][110];

int ways(int N, int K) {
  if (K == 1) // only can use 1 number to add up to N
    return 1; // the answer is definitely 1, that number itself
  else if (memo[N][K] != -1)
    return memo[N][K];

  // if K > 1, we can choose one number from [0..N] to be one of the number and recursively compute the rest
  int total_ways = 0;
  for (int split = 0; split <= N; split++)
    total_ways = (total_ways + ways(N - split, K - 1)) % 1000000; // we just need the modulo 1M
  return memo[N][K] = total_ways; // memoize them
}

int main() {
  memset(memo, -1, sizeof memo);
  while (scanf("%d %d", &N, &K), (N || K)) // some recursion formula + top down DP
    printf("%d\n", ways(N, K));
  return 0;
}
// bottom-up
  int i, j, split, dp[110][110], N, K;
  memset(dp, 0, sizeof dp);
  for (i = 0; i <= 100; i++) // these are the base cases
    dp[i][1] = 1;
  for (j = 1; j < 100; j++) // these three nested loops form the correct topological order
    for (i = 0; i <= 100; i++)
      for (split = 0; split <= 100 - i; split++) {
        dp[i + split][j + 1] += dp[i][j];
        dp[i + split][j + 1] %= 1000000;
      }

  while (scanf("%d %d", &N, &K), (N || K))
    printf("%d\n", dp[N][K]);

  return 0;
}

another classic
 Cutting Sticks
int l, n, A[55], memo[55][55];

int cut(int left, int right) {
  if (left + 1 == right)       return 0;
  if (memo[left][right] != -1) return memo[left][right];

  int ans = 2000000000;
  for (int i = left + 1; i < right; i++)
    ans = min(ans, cut(left, i) + cut(i, right) + (A[right]-A[left]));
  return memo[left][right] = ans;
}

int main() {
  while (scanf("%d", &l), l) {
    A[0] = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    A[n + 1] = l;

    memset(memo, -1, sizeof memo);
    printf("The minimum cutting is %d.\n", cut(0, n + 1)); // start with left = 0 and right = n + 1
  }


