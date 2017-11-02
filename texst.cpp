/// strong connected component *************************************************






vi arr[1000];
vector<vi> comps;
int dfsnum[1000], comp[1000], dfslow[1000], instk[1000];
stack<int> stk;
int cntd = 0;
void scc(int inx) {
	dfslow[inx] = dfsnum[inx] = cntd++;
	stk.push(inx);
	instk[inx] = 1;
	repi(i, 0, sz(arr[inx]))
	{
		int v = arr[inx][i];
		if (dfsnum[v] == -1) {
			scc(v);
			dfslow[inx] = min(dfslow[v], dfslow[inx]);
		} else if (instk[v]) {
			dfslow[inx] = min(dfslow[v], dfslow[inx]);
		}
	}
	if (dfslow[inx] == dfsnum[inx]) {
		comps.push_back(vector<int>());
		int x = -1;
		while (x != inx) {
			x = stk.top();
			stk.pop();
			comps.back().push_back(x);
			comp[x] = sz(comps) - 1;
		}
	}
	instk[inx] = 0;
}
/********************************************************************************************************
 *
 *segment line and point oreintation ********************************************************************************************/

struct Point {
	double x;
	double y;
	Point(double _x, double _y) :
			x(_x), y(_y) {

	}
};
vector<pair<Point, Point> > vp;
// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r) {
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y)
			&& q.y >= min(p.y, r.y))
		return true;

	return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r) {
	// See http://www.geeksforgeeks.org/orientation-3-ordered-points/
	// for details of below formula.
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if (val == 0)
		return 0;  // colinear

	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
	// Find the four orientations needed for general and
	// special cases
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	// General case
	if (o1 != o2 && o3 != o4)
		return true;

	// Special Cases
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1
	if (o1 == 0 && onSegment(p1, p2, q1))
		return true;

	// p1, q1 and p2 are colinear and q2 lies on segment p1q1
	if (o2 == 0 && onSegment(p1, q2, q1))
		return true;

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2
	if (o3 == 0 && onSegment(p2, p1, q2))
		return true;

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2
	if (o4 == 0 && onSegment(p2, q1, q2))
		return true;

	return false; // Doesn't fall in any of the above cases
}


/*****point and lines *****************************************************************************************************************************
 */

double  DEG_to_RAD​(double​ ​ d)​ ​ {​return​​ (d​*​ ​PI​ ​ /​ ​180.0);}
double ​ ​​ RAD_to_DEG​(double​ ​ r)​ ​ { return​​ (r​ ​*​ ​180.0​ ​/​ ​PI);​ ​}
double
struct point {
	double x, y;
	point() {
		x = y = 0.0;
	}
	point(double _x, double _y) :
			x(_x), y(_y) {
	}
	bool operator <(point other) const {
		if (fabs(other.x - x) < EPS) {
			return y < other.y;
		} else {
			return x < other.x;
		}
	}
	bool operator ==(point other) const {
		return (fabs(other.x - x) < EPS) && (fabs(y - other.y) < EPS);
	}

};

struct line {
	double a, b, c;
};

double dist(point p1, point p2) {
// Euclidean distance
// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) {
	double rad = DEG_to_RAD(theta);
// multiply theta with PI / 180.0
	return point(p.x * cos(rad) - p.y * sin(rad),
			p.x * sin(rad) + p.y * cos(rad));
}

void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) {
// vertical line is fine
		l.a = 1.0;
		l.b = 0.0;
		l.c = -p1.x;
// default values
	} else {
		l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
// IMPORTANT: we fix the value of b to 1.0
		l.c = -(double) (l.a * p1.x) - p1.y;
	}
}

bool areParallel(line l1, line l2) {
// check coefficients a & b
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
bool areSame(line l1, line l2) {
// also check coefficient c
	return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
	if (areParallel(l1, l2))
		return false;
// no intersection
// solve system of 2 linear algebraic equations with 2 unknowns
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
// special case: test for vertical line to avoid division by zero
	if (fabs(l1.b) > EPS)
		p.y = -(l1.a * p.x + l1.c);
	else
		p.y = -(l2.a * p.x + l2.c);
	return true;
}

/******************************************compination with canselation*************************************/


int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
long long unsigned solve(int n, int k) {
	vector<int> a;
	vector<int> b;
	int ln = (k < n - k) ? (n - k) : k;
	int ld = (k < n - k) ? k : n - k;
	for (int i = ln + 1; i <= n; i++)
		a.push_back(i);
	for (int i = 1; i <= ld; i++)
		b.push_back(i);
	for (int i = 0; i < ld; i++)
		for (int j = 0; j < a.size(); j++) {
			int g = gcd(b[i], a[j]);
			b[i] /= g;
			a[j] /= g;
			if (b[i] == 1)
				break;
		}
	long long unsigned ret = 1;
	for (int i = 0; i < a.size(); i++) {
		ret *= a[i];
	}
	return ret;

}



/*******************************triel tree ***************************************************************************************/
using namespace std;


const int MAX_CHAR = 26;

struct trie {
	trie* child[MAX_CHAR];
	bool isLeaf;

	trie() {
		memset(child, 0, sizeof(child));
		isLeaf = 0;
	}

	void insert(char *str) {
		if(*str == '\0')
			isLeaf = 1;
		else {
			int cur = *str - 'a';
			if(child[cur] == 0 )
				child[cur] = new trie();
			child[cur]->insert(str+1);
		}
	}

	bool wordExist(char* str) {
		if(*str == '\0')
			return isLeaf;

		int cur = *str - 'a';
		if(child[cur] == 0 )
			return false;	// such path don't exist

		return child[cur]->wordExist(str+1);
	}

	bool prefixExist(char* str) {
		if(*str == '\0')
			return true;

		int cur = *str - 'a';
		if(child[cur] == 0 )
			return false;	// such path don't exist

		return child[cur]->prefixExist(str+1);
	}
};


int main()
{
	trie root;

	root.insert("abcd");
	root.insert("xyz");
	root.insert("abf");
	root.insert("xn");
	root.insert("ab");
	root.insert("bcd");

	cout<<root.wordExist("xyz")<<"\n";
	cout<<root.wordExist("xy")<<"\n";
	cout<<root.prefixExist("xyz")<<"\n";

	return 0;
}


/*************************************define for bitmask******************************************************************************/
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
//*********************************************define for readprint***********************************************/

#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define rln() getchar()
#define rint(n) scanf("%d",&n)
#define rs(n) scanf("%s",n)
#define rc(n) scanf("%c",&n)
#define rf(n) scanf("%lf",&n)
#define rl(n) scanf("%lld",&n)
#define pint(x) printf("%d", x)
#define psp() printf(" ")
#define ps(x) printf("%s", x)
#define pc(x) printf("%c", x)
#define pnl() printf("\n")
#define pl(x) printf("%lld", x)
#define pf(x) printf("%.6lf", x)


/****************************************************DSU*****************************************************************/


int p[30010], r[30010], sxz[30010];
int findSet(int i) {
	return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int i, int j) {
	return findSet(i) == findSet(j);
}
void unionSet(int i, int j) {
	if (!isSameSet(i, j)) {
		int x = findSet(i), y = findSet(j);
		if (r[x] > r[y]) {
			p[y] = x;
			sxz[x] += sxz[y];
		} else {
			p[x] = y;
			if (r[x] == r[y])
				r[y]++;
			sxz[y] += sxz[x];
		}
	}
}


/*********************floyd buildpath****************************************************************************************************/
void build_pah(int src, int des) {
	if (pth[src][des] == -1) {
		printf("%s ", str[src].c_str());
		return;
	}
	build_pah(src, pth[src][des]);
	build_pah(pth[src][des], des);

}


repi(i,1, n + 1)
			repi(j,1, n + 1)
				rint(yy), (yy == -1) ? arr[i][j] = INF : arr[i][j] = yy;
		repi(k,1, n + 1)
			repi(i,1, n+1)
				repi(j,1, n+2)
				{
					if (arr[i][j] <= arr[i][k] + arr[k][j]) {
						continue;
					}
					arr[i][j] = arr[i][k] + arr[k][j];
					pth[i][j] = k;
				}



/*********************************************************************************bellman ford's *****************/
#define INF 1000000000
int main() {
	int V, E, s, a, b, w;
	vector<vii> AdjList;
	freopen("in_06.txt", "r", stdin);

	scanf("%d %d %d", &V, &E, &s);

	AdjList.assign(V, vii()); // assign blank vectors of pair<int, int>s to AdjList
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &w);
		AdjList[a].push_back(ii(b, w));
	}

	// Bellman Ford routine
	vi dist(V, INF);
	dist[s] = 0;
	for (int i = 0; i < V - 1; i++) // relax all E edges V-1 times, overall O(VE)
		for (int u = 0; u < V; u++)                    // these two loops = O(E)
			for (int j = 0; j < (int) AdjList[u].size(); j++) {
				ii v = AdjList[u][j]; // we can record SP spanning here if needed
				dist[v.first] = min(dist[v.first], dist[u] + v.second); // relax
			}

	bool hasNegativeCycle = false;
	for (int u = 0; u < V; u++)                        // one more pass to check
		for (int j = 0; j < (int) AdjList[u].size(); j++) {
			ii v = AdjList[u][j];
			if (dist[v.first] > dist[u] + v.second)           // should be false
				hasNegativeCycle = true; // but if true, then negative cycle exists!
		}
	printf("Negative Cycle Exist? %s\n", hasNegativeCycle ? "Yes" : "No");

	if (!hasNegativeCycle)
		for (int i = 0; i < V; i++)
			printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);

	return 0;
}



/******************************************************************************************************************/

