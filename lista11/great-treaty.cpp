#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct Point {
  ll x, y;
  Point() { x = y = 0.0; }
  Point(ll _x, ll _y) : x(_x), y(_y) {}

  bool operator < (Point other) const {
    if (x != other.x)
      return x < other.x;
    return y < other.y;
  }

  bool operator == (Point other) const {
    return (x == other.x && y == other.y);
  }
};

struct Vec {
  ll x, y;
  Vec(ll _x, ll _y) : x(_x), y(_y) {}
};

Vec toVec(const Point &a, const Point &b) {
  return Vec(b.x - a.x, b.y - a.y);
}

ll cross(Vec a, Vec b) {
  return a.x * b.y - a.y * b.x;
}

bool ccw(Point p, Point q, Point r) {
  return cross(toVec(p, q), toVec(p, r)) >= 0;
}

vector<pair<Point, int>> convexHullAndrew(vector<pair<Point, int>> &points) {
  int n = points.size(), k = 0;
  vector<pair<Point, int>> hull(2 * n);
  sort(points.begin(), points.end());

  for (int i = 0; i < n; ++i) {
    while ((k >= 2) && !ccw(hull[k - 2].first, hull[k - 1].first, points[i].first))
      --k;
    hull[k].second = points[i].second;
    hull[k++].first = points[i].first;
  }

  for (int i = n - 2, t = k + 1; i >= 0; --i) {
    while ((k >= t) && !ccw(hull[k - 2].first, hull[k - 1].first, points[i].first))
      --k;
    hull[k].second = points[i].second;
    hull[k++].first = points[i].first;
  }

  hull.resize(k);
  return hull;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<pair<Point, int>> points;

  int n;
  cin >> n;

  for (int k = 0; k < n; k++) {
    ll x, y;
    cin >> x >> y;
    points.push_back({Point(x, y), k + 1});
  }

  vector<pair<Point, int>> hull = convexHullAndrew(points);

  set<int> result;
  for (int k = 0; k < (int)hull.size() - 1; k++) {
    result.insert(hull[k].second);
  }

  bool space = false;
  for (int x : result) {
    if (!space) {
      space = true;
    } else {
      cout << " ";
    }
    cout << x;
  }
  cout << "\n";

  return 0;
}
