#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main(){
  int distance, numStations;
  pair<int, int> stations[10000];

  while(true){
    scanf("%d %d", &distance, &numStations);

    if(distance == 0) break;

    for(int i = 0, x, r; i < numStations; ++i){
      scanf("%d %d", &x, &r);
      stations[i] = make_pair(x - r, x + r);
    }

    sort(stations, stations + numStations);

    int position = 0, aux, i = 0, answer = numStations;

    while(position < distance){
      aux = position;

      while(i < numStations && stations[i].first <= position)
        aux = max(aux, stations[i++].second);

      if(aux == position) break;

      position = aux;
      --answer;
    }

    printf("%d\n", position < distance ? -1 : answer);
  }

  return 0;
}