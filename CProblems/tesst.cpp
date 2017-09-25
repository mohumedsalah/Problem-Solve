
long long unsigned compination(int n , int m){
	int temp1 = max(m,n-m);
	int temp2 = min(m , n - m);
	vector<int> a, b;
	for (int i = 1; i <= temp2 ; i++)
		b.push_back(i);
	for(int i = temp1 + 1  ; i <= n  ; i++)
		a.push_back(i);
	for(int i  = 0 ; i < b.size(); i++){
		for(int j = 0 ; j < a.size(); j++){
			int g = __gcd(b[i], a[j]);
			b[i] /= g;
			a[j] /= g;
			if(b[i] == 1)
				break;
		}
	}
	long long unsigned ret = 1;
	for(int i = 0; i < a.size(); i++)
		ret *= a[i];
	return ret;

}
poweeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeer
inline ll p(ll x,ll a){
	if(!a)	return 1LL;
	ll b = p(x,a/2LL);
	b = (b * b)%mod;
	if(a % 2LL)
		b = (b * x)%mod;
	return b;
}


disjoin set



int _sc;
void initSet(int N) {
    REP(i, N) p[i] = i; _sc=N;}
int findSet(int i) { return p[i] == i ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) { if (!isSameSet(i, j)) p[findSet(i)] = findSet(j), _sc--; }




// replacing in a string
#include <iostream>
#include <string>

int main ()
{
  std::string base="this is a test string.";
  std::string str2="n example";
  std::string str3="sample phrase";
  std::string str4="useful.";

  // replace signatures used in the same order as described above:

  // Using positions:                 0123456789*123456789*12345
  std::string str=base;           // "this is a test string."
  str.replace(9,5,str2);          // "this is an example string." (1)
  str.replace(19,6,str3,7,6);     // "this is an example phrase." (2)
  str.replace(8,10,"just a");     // "this is just a phrase."     (3)
  str.replace(8,6,"a shorty",7);  // "this is a short phrase."    (4)
  str.replace(22,1,3,'!');        // "this is a short phrase!!!"  (5)

  // Using iterators:                                               0123456789*123456789*
  str.replace(str.begin(),str.end()-3,str3);                    // "sample phrase!!!"      (1)
  str.replace(str.begin(),str.begin()+6,"replace");             // "replace phrase!!!"     (3)
  str.replace(str.begin()+8,str.begin()+14,"is coolness",7);    // "replace is cool!!!"    (4)
  str.replace(str.begin()+12,str.end()-4,4,'o');                // "replace is cooool!!!"  (5)
  str.replace(str.begin()+11,str.end(),str4.begin(),str4.end());// "replace is useful."    (6)
  std::cout << str << '\n';
  return 0;
}





// string::find
#include <iostream>       // std::cout
#include <string>         // std::string

int main ()
{
  std::string str ("There are two needles in this haystack with needles.");
  std::string str2 ("needle");

  // different member versions of find in the same order as above:
  std::size_t found = str.find(str2);
  if (found!=std::string::npos)
    std::cout << "first 'needle' found at: " << found << '\n';

  found=str.find("needles are small",found+1,6);
  if (found!=std::string::npos)
    std::cout << "second 'needle' found at: " << found << '\n';

  found=str.find("haystack");
  if (found!=std::string::npos)
    std::cout << "'haystack' also found at: " << found << '\n';

  found=str.find('.');
  if (found!=std::string::npos)
    std::cout << "Period found at: " << found << '\n';

  // let's replace the first needle:
  str.replace(str.find(str2),str2.length(),"preposition");
  std::cout << str << '\n';

  return 0;
}














