#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define REP(i, j) for (int i=0 ; i<j ; i++)

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vi p(1000);
int _sc;
void initSet(int N) {
    REP(i, N) p[i] = i; _sc=N;}
int findSet(int i) { return p[i] == i ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) { if (!isSameSet(i, j)) p[findSet(i)] = findSet(j), _sc--; }

vector< pair<double, ii> > EdgeList;
int T, x, y, N, M;
int cx[750], cy[750];

int main() {
    scanf("%d\n", &T);
    while (T--) {
        EdgeList.clear();
        scanf("%d", &N);
        REP(i, N) {
            scanf("%d %d", &x, &y);
            cx[i] = x;
            cy[i] = y;
        }

        REP(i, N) {
            for (int j=i+1 ; j<N ; j++) {
                double dist = hypot((double)(cx[i] - cx[j]), (double)(cy[i] - cy[j]));
                EdgeList.push_back(make_pair(dist, ii(i, j)));
            }
        }
        sort(EdgeList.begin(), EdgeList.end());
        initSet(N);
        scanf("%d", &M);
        while (M--) {
            scanf("%d %d", &x, &y);
            unionSet(x-1, y-1);
        }

        int y=0;


        for (int i=0 ; i<EdgeList.size() && _sc > 1 ; i++) {
            pair<double, ii> front = EdgeList[i];
            if (!isSameSet(front.second.first, front.second.second)) {
                printf("%d %d\n", front.second.first+1, front.second.second+1);
                y++;
                unionSet(front.second.first, front.second.second);
            }
        }
        if (y == 0) printf("No new highways need\n");

        if (T) printf("\n");
    }
}
