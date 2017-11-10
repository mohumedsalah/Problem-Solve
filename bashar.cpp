#Beshoooooooooooooo

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);

}
//area of triangle (UxV)/2; nos el cross product bta3hm
//check lw el num da men mod3fat el 8 wala la2
if ( num % 8 == 0 )
{
	// num is multple of 8
}
//know the number of digits
int GetNumberOfDigits(int i) {
	return i > 0 ? (int) log10((double) i) + 1 : 1;
}

//string stream
string s;
getchar();
getline(cin, s);
istringstream iss(s);
while (iss >> m) {
	arr.push_back(m);
}
int x = *max_element(arr.begin(), arr.end());
printf("Case %d: %d\n", ++cnt, x);
arr.clear();

int permutation() {
	string str;
	cin >> str;
	do {
		cout << str << "\n";
	} while (next_permutation(str.begin(), str.end()));
}



int prim(int k) {
	for (int i = 2; i <= sqrt(k); i++) {
		if (k % i == 0) {
			return false;
		}
	}
	return true;
}
void sieve() {
	//memset(arr, 0, arr + n);
	for (int i = 2; i * i <= 1e6; i++) {
		if (!arr[i])
			for (int j = 2 * i; j <= 1e6; j += i) {
				arr[j] = 1;
			}
	}
}
long factorial(int n) {
	long fact = 1;
	for (int i = 1; i <= n; i++) {
		fact = fact * i;
	}
	return fact;
}
//mmken  fabs(hi - lo) > EPS  being trapped in an infinite loop.
double lo = 0.0, hi = 10000.0, mid = 0.0, ans = 0.0;
for (int i = 0; i < 50; i++) { // log_2 ((10000.0 - 0.0) / 1e-9) ~= 43
	mid = (lo + hi) / 2.0;// looping 50 times should be precise enough
	if (can(mid)) {ans = mid; hi = mid;}
	else lo = mid;
}








int binary_search_to_get_last(int x, int y, int tar) {
	while (x < y) {
		int mid = x + (y - x + 1) / 2; ////or min=x+(y-x)/2;  agarb el 2 w a4of men ele me4 hyd5lne fe INFL
		if (arr[mid] < tar)
			x = mid + 1;
		else if (arr[mid] > tar)
			y = mid - 1;
		else
			x = mid;
	}
	return x;
}
double BS_Doouble(double start, double end, dobule val) {
	while (fabs(end - start) > EPS) { //EPS=1e-10; rakam so8yr gedan
		double mid = start + (end - start) / 2;
		if (arr[mid] < val)
			start = mid;
		else
			end = mid;
	}
	return start;
}
//fe nas bt5af men el function  BS_Doouble 3a4an me4 ba3raf at7km fe el percision f b3mlha loop
double BS_Doouble(double start, double end, dobule val) {
	for (int i = 0; i < 100; i++) { //EPS=1e-10; rakam so8yr gedan
		double mid = start + (end - start) / 2;
		if (arr[mid] < val) //el if hena byb2a gowaha function
			start = mid;
		else
			end = mid;
	}
	return start;
}
/* lw 3nde bitonic sequnce w b2olk 3wz akbar value feha h3ml eh !
 * h3ml search l7d ema ala2e rakam howa akbar men ele 2ablo wl ele ba3do
 1 5 7 [15] 9 6 2
 */

double distanceBetweenTwoPoints(double x, double y, double a, double b) {
	return sqrt(pow(x - a, 2) + pow(y - b, 2));
}

// kam wa7ed men v[0] 3ande fe el arr;
//upper greater than only
//lower greater than or equal

ll cmax = upper_bound(v.begin(), v.end(), v[0]) - v.begin();

struct node {
	int v, c;
	node(int v, int c) :
			v(v), c(c) {
	}
	bool operator <(const node &e) const {
		return c > e.c;
	}
};
//7osan moves in chessboard
int dx[] = { 1, -1, 2, -2, 1, -1, 2, -2 };
int dy[] = { 2, 2, 1, 1, -2, -2, -1, -1 };
// direction in 2d array
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };

//search in map
for (map<char, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
	std::cout << it->first << " => " << it->second << '\n';}

//3a4an a7wl el negative mod l positive mod
int fix(int a) {
	return (a % k + k) % k;
	//k el rakam ele 3atehole 3a4an a4of da divisable wala la2
}

//count the number of divisors
int divisors(int x) {
	int limit = x;
	int numberOfDivisors = 0;

	if (x == 1)
		return 1;

	for (int i = 1; i < limit; ++i) {
		if (x % i == 0) {
			limit = x / i;
			if (limit != i) {
				numberOfDivisors++;
			}
			numberOfDivisors++;
		}
	}
	return numberOfDivisors;
}
// num of divisors in range
for (ll i = l; i <= r; i++) {
	ll lower = (l + i - 1) / i;
	ll upper = r / i;
	ll d = upper - lower + 1;
	sum += d;
}
//power to long long numbers
ll pwrtolonglongnumbers(int x, int y) {

	ll ret = 1;
	for (int i = 0; i < y; i++)
		ret = (ret * x);
	return ret;
}

//to check if the res is the power of 2
if ((res != 0) && ((res & (res - 1)) == 0));


//compare between 2 doubles
int compare_2doubles(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
	//btrg3 0 lw homa equa ,,  1 lw el awl akbar ,,-1 lw el tane akbar
}

//Geometry
const double EPS = (1e-10);
struct pointt {
	int x, y
	//functions el gam3 wl tar7 wl darb ektbha enta b2a
};
//area of triangle (UxV)/2; nos el cross product bta3hm
typedef complex<double> point;
typedef
#define X real()
#define Y imag()
#define angl(a) (atan2((a).imag(),(a).real()))
#define vec(a,b) ((b)-(a))
#define length(a) (hypot((a).imag(),(a).real()))
#define normalize(a) (a)/length(a)
//dp=a*b cos(T)
#define dotproduct(a,b) ((conj(a)*(b)).real())
// cp=a*b sin(T)
#define crossproduct(a,b) ((conj(a)*(b)).imag())
//rotate around (0,0)
#define rotate(p,ang) ((p)*exp(point(0,ang)))
#define rotatearound(p,ang,about) (rotate(vec(about,p),ang)+about)
#define reflect(v,m) (conj((v)/(m))*(m))
point reflectaboutpoint(point p, point p0, point p1) {
	point z = p - p0, w = p1 - p0;
	return conj((z) / (w)) * (w) + p0;
}
//3ala 5at wa7ed wala la2
bool is_collinear(pointt a, pointt b, pointt c) {
	return fabs(cp(b - a, c - a)) < EPS;
}


bool isPointOnRay(pointt a, pointt b, pointt c) {
	if (!is_collinear(a, b, c))
		return 0;
	return compare_2doubles(dotproduct(b - a, c - a), 0) == 1;
}

bool isPointOnTheSegemnt(pointt a, pointt b, pointt c) {
	return isPointOnRay(a, b, c) && isPointOnRay(b, a, c);

	//another way
	double acp = length(a - b), ac = length(a - c), cb = length(b - c);
	return compare_2doubles(acb - (ac + cb), 0) == 0;
}
double distancetoline(pointt a, pointt b, pointt c) {
	double dis = cp(b - a, c - a) / length(a - b);
	return fabs(dis);
}

//segment = ket3a mostkema
double distanceToSegment(pointt p0, point p1, point p2) {
	double d1, d2;
	pointt v1 = p1 - p0, v2 = p2 - p0;
	if ((d1 = dotproduct(v1, v2)) <= 0) {
		return length(p2 - p0);
	}
	if ((d2 = (dotproduct(v1, v2))) <= d1) {
		return length(p2 - p1);
	}

	double t = d1 / d2;
	return length(p2 - (p0 + v1 * t));
}







//(b^p)%m
int BigMod(int b, int p, int m) {
	if (p == 0)
		return 1;
	if (p % 2 == 0) {  //lw el os zwge
		int ret = BigMod(b, p / 2, m);
		return (ret * ret) % m;
	} else {  //lw el os farde
		int part1 = b % m;
		int part2 = BigMod(b, p - 1, m);
		return (part1 * part2) % m;
	}
}

//to convert all  string to upper or lower
transform(s.begin(), s.end(), s.begin(), ::tolower);

//to remove all punct from string  str is the string we have ,str2 the result;
remove_copy_if(str.begin(), str.end(), back_inserter(str2),ptr_fun<int, int>(::ispunct));

// atleast and at most
"At least two" is also "2 or more" , ">=2", "2,3,4,5, ..."
"At most two" is also "two or less", "<=2", "0,1,2".

abs(i-k) == abs(j-l).
abs(i+k)==abs(j+l)
/*This formula means that the vertical and horizontal distances between these two points are
equal, i.e. point A and B lie on one of each other’s two diagonal lines.*/

//in the same line or not this not in the same line
bool collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
	return (y1 - y2) * (x1 - x3) == (y1 - y3) * (x1 - x2);
}
//bitmask try all possible solutions
for (int i = 0; i < (1 << n) && !flag; i++) {
	for (int j = 0; j < n && !flag; j++) {
		if (i & (1 << j))
//kadane's algorithm to get the maximum sum range in array
int n = 9, A[] = { 4, -5, 4, -3, 4, 4, -4, 4, -5 };
int sum = 0, ans = 0;
for (int i = 0; i < n; i++) {
	sum += A[i];
	ans = max(ans, sum);
	if (sum < 0) sum = 0;
}
printf("Max 1D Range Sum = %d\n", ans);

//also in set_union,set_intersect
set_difference(vc.begin(), vc.end(), node.begin(), node.end(),
		inserter(diff, diff.begin()));

//search for string in another string c++
if (s1.find(s2) != std::string::npos) {
	printf("Found")
}


