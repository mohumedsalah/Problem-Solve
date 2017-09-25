int _sc;
int p[200010];
//vector<pair<int, ii> > edgelist;
void initSet(int N) {
	repi(i,0, N)
		p[i] = i;
	_sc = N + 1;
}
int findSet(int i) {
	return p[i] == i ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int i, int j) {
	return findSet(i) == findSet(j);
}
void unionSet(int i, int j) {
	if (!isSameSet(i, j))
		p[findSet(i)] = findSet(j), _sc--;
}
