#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

struct Point {
  double x, y;
  bool operator<(const Point &a) const {
    if(x != a.x)
      return x < a.x;
    return y < a.y;
  }
};

#define EPS 1e-8

double cross(Point o, Point a, Point b) {
  return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

int onSegment(Point a, Point b, Point p) {
  if(min(a.x, b.x)-EPS <= p.x && p.x <= max(a.x, b.x)+EPS &&
     min(a.y, b.y)-EPS <= p.y && p.y <= max(a.y, b.x)+EPS &&
     fabs(cross(a, b, p)) < EPS)
     return 1;
  return 0;
}

int inPolygon(Point p[], int n, Point q) {
  int i, j, k = 0;
  for(i = 0, j = n-1; i < n; j = i++) {
    if(p[i].y > q.y != p[j].y > q.y &&
       q.x < (p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y)+p[i].x)
       k++;
    if(onSegment(p[i], p[j], q))
      return 1;
  }
  return k&1;
}

int monotone(Point p[], int n, Point ch[]) {
  sort(p, p+n);
  int i, m = 0, t;
  for(i = 0; i < n; i++) {
    while(m >= 2 && cross(ch[m-2], ch[m-1], p[i]) <= 0)
      m--;
    ch[m++] = p[i];
  }
  for(i = n-1, t = m+1; i >= 0; i--) {
    while(m >= t && cross(ch[m-2], ch[m-1], p[i]) <= 0)
      m--;
    ch[m++] = p[i];
  }
  return m-1;
}

int main() {
  int cases = 0;
  int numCops, numRobbers, numCitizens;
  Point cops[205], robbers[205], citizen;
  Point hullCops[205], hullRobbers[205];
  int i, j, k;
  while(scanf("%d %d %d", &numCops, &numRobbers, &numCitizens) == 3) {
    if(numCops == 0 && numRobbers == 0 && numCitizens == 0)
      break;
    for(i = 0; i < numCops; i++)
      scanf("%lf %lf", &cops[i].x, &cops[i].y);
    for(i = 0; i < numRobbers; i++)
      scanf("%lf %lf", &robbers[i].x, &robbers[i].y);
    int numHullCops, numHullRobbers;
    numHullCops = monotone(cops, numCops, hullCops);
    numHullRobbers = monotone(robbers, numRobbers, hullRobbers);
    printf("Data set %d:\n", ++cases);
    while(numCitizens--) {
      scanf("%lf %lf", &citizen.x, &citizen.y);
      printf("     Citizen at (%.0lf,%.0lf) is ", citizen.x, citizen.y);
      int isSafe = inPolygon(hullCops, numHullCops, citizen);
      if(isSafe && numCops >= 3)
        puts("safe.");
      else {
        int isRobbed = inPolygon(hullRobbers, numHullRobbers, citizen);
        if(isRobbed && numRobbers >= 3)
          puts("robbed.");
        else
          puts("neither.");
      }
    }
    puts("");
  }
  return 0;
}