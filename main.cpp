#include <iostream>
#include<vector>
using namespace std;
vector<vector<int> > p;
int MAX = 20;
   void TreeAncestor(int n, vector<int>& parent)
{
    MAX = ceil(log2(n));
    cout<<MAX<<endl;
       p.resize(n+1,vector<int>(MAX,-1));
       for(int i=0;i<n;i++)
       {
           p[i][0]=parent[i];
       }
       for(int i=1;i<MAX;i++)
       {
           for(int j=1;j<n;j++)
           {
               
               if(p[j][i-1]!=-1){
                   p[j][i]=p[p[j][i-1]][i-1];
                   
               }
           }
       }
   }
   
   int getKthAncestor(int node, int k) {
       for(int i=0;i<MAX;i++)
       {
           int l = 1<<i;
           cout<<l<<endl;
           if(k&l)
               node=p[node][i];
           
           if(node==-1)
               return -1;
       }
       return node;
   }

int main(int argc, const char * argv[]) {
    vector<int> v = {-1,0,0,1,1,2,2};
    TreeAncestor(7, v);
    cout<<getKthAncestor(6, 2)<<endl;
    
    return 0;
}
