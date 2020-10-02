#include <iostream>
 
#define I 32767  // Infinity
#define V 7  // # vertices in Graph
#define E 9  // # edges in Graph
 
using namespace std;

int s[8] = {-1,-1,-1,-1,-1,-1,-1,-1};

void myunion(int u, int v){
    if (s[u] < s[v]){
        s[u] += s[v];
        s[v] = u;
    } 
    else {
        s[v] += s[u];
        s[u] = v;
    }
}
 
int Find(int u){
    int x = u;
    int v = 0;
 
    while (s[x] > 0){
        x = s[x];
    }
 
    while (u != x){
        v = s[u];
        s[u] = x;
        u = v;
    }
    return x;
}

int edges[3][9] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                       { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};
                       
int included[9] = {0};
int t[2][6];

int main(){
    int i=0,j,k,u,v,min=I,n=7,e=9;
    
    while(i<n-1){
        min=I;
        for(j=0;j<e;j++){
            if(included[j]==0 && edges[2][j] < min){
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k=j;
            }
        }
        
        if(Find(u) != Find(v)){
            t[0][i]=u;
            t[1][i]=v;
            myunion(Find(u),Find(v));
            i++;
        }
        included[k] = 1;
        
    }
    
    for(i=0;i<n-1;i++){
        cout<<"("<<t[0][i]<<","<<t[1][i]<<")";
    }
    
    return 0;
}
