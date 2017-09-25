// A C++ program to check if two given line segments intersect
#include <bits/stdc++.h>
#define EPS -1e9
using namespace std;

struct Point {
	double x, y;
};
struct line {
	double a, b, c;
};
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

void pointsToLine(Point p1, Point p2, line &l) {
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
// Driver program to test above functions

bool areParallel(line l1, line l2) {
// check coefficients a & b
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
bool areSame(line l1, line l2) {
// also check coefficient c
	return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, Point &p) {
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
int main() {
	double x1, y1, x2, y2, a, b, c;

	int n;
	cin >> x1 >> y1 >> x2 >> y2;

	Point p1, p2;
	p1.x = x1, p1.y = y1;
	p2.x = x2, p2.y = y2;
	line l;
	pointsToLine(p1, p2, l);
	cin >> n;
	Point ch;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		line xx;
		xx.a = a, xx.b = b, xx.c = c;
		if (areIntersect(l, xx, ch) && onSegment(p1, ch, p2)) {
			ret++;
		}

	}
	cout << ret << endl;

	return 0;
}
