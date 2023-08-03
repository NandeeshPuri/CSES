#include<bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++) 
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const int MAX_L = 20;
const int MAX_C = 26;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template <class T> struct Point {
    T x, y;
    Point() : x(0), y(0) {}
    Point(const T& _x, const T& _y) : x(_x), y(_y) {}

    friend std::ostream& operator<<(std::ostream& out, const Point& p) { return out << "(" << p.x << "," << p.y << ")"; }
    friend std::istream& operator>>(std::istream& in, Point& p) { return in >> p.x >> p.y; }

    friend bool operator==(const Point& a, const Point& b) { return tie(a.x, a.y) == tie(b.x, b.y); }
    friend bool operator!=(const Point& a, const Point& b) { return tie(a.x, a.y) != tie(b.x, b.y); }
    friend bool operator<(const Point& a, const Point& b) { return tie(a.x, a.y) < tie(b.x, b.y); }

    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(const T& d) const { return Point(x * d, y * d); }
    Point operator/(const T& d) const { return Point(x / d, y / d); }

    T dot(const Point& p) const { return x * p.x + y * p.y; }
    T cross(const Point& p) const { return x * p.y - y * p.x; }
    T cross(const Point& a, const Point& b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); } // [-pi, pi] to x-axis

    Point unit() const { return *this / dist(); } // unit vector
    Point perp() const { return P(-y, x); } // rotates +90 degrees
    Point normal() const { return perp().unit(); }
    Point rotate(const double& a) const { return P(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a)); } // ccw around (0,0)
};

using pt = Point<ll>;

template<class P> bool onSegment(P s, P e, P p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}
 
template<class P>
int inPolygon(vector<P>&p ,P a){
    int cnt=0,n=sz(p);
    rep(i,0,n){
        P q=p[(i+1)%n];
        if (onSegment(p[i],q,a))return 2;
        cnt^=((a.y<p[i].y)-(a.y<q.y))*a.cross(p[i],q)>0;
    }
    return !!cnt;
}

void solve(int tc=0){
    int n,q;cin>>n>>q;
    vector<pt>a(n);
    for(pt &p:a)cin>>p;
    while(q--){
        pt p;cin>>p;
        int ans =inPolygon(a,p);
        if(ans==0){
            cout<<"OUTSIDE\n";
        }else if(ans==1){
            cout<<"INSIDE\n";
        }else{
            cout<<"BOUNDARY\n";
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }
}