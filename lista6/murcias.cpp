#include <stdio.h>

int main() {
  int t, casos = 0, n, i, j;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    int altura[10000], largura[10000];
    int dpCrescente[10000], dpDecrescente[10000];
    for(i = 0; i < n; i++)
      scanf("%d", &altura[i]);
    for(i = 0; i < n; i++) {
      scanf("%d", &largura[i]);
      dpCrescente[i] = dpDecrescente[i] = largura[i];
    }
    for(i = 0; i < n; i++) {
      for(j = i+1; j < n; j++) {
        if(altura[i] < altura[j] && dpCrescente[i]+largura[j] > dpCrescente[j]) {
          dpCrescente[j] = dpCrescente[i]+largura[j];
        }
        if(altura[i] > altura[j] && dpDecrescente[i]+largura[j] > dpDecrescente[j]) {
          dpDecrescente[j] = dpDecrescente[i]+largura[j];
        }
      }
    }
    int respostaCrescente = 0, respostaDecrescente = 0;
    for(i = 0; i < n; i++) {
      if(dpCrescente[i] > respostaCrescente)   respostaCrescente = dpCrescente[i];
      if(dpDecrescente[i] > respostaDecrescente)   respostaDecrescente = dpDecrescente[i];
    }
    if(respostaDecrescente <= respostaCrescente)
      printf("Case %d. Increasing (%d). Decreasing (%d).\n", ++casos, respostaCrescente, respostaDecrescente);
    else
      printf("Case %d. Decreasing (%d). Increasing (%d).\n", ++casos, respostaDecrescente, respostaCrescente);
  }
  return 0;
}