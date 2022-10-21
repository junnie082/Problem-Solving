#include <stdio.h>
#define node_num 5

void Dijkstra()
{
   int s = 0;
   int d[node_num][node_num] = { {0,10, 0, 30, 100},{0,0,50,0,0},{0,0,0,0,10}, {0,0,20,0,60}, {0,0,0,0,0}};
   int ans[node_num] = { -1,-1,-1, -1, -1};
   int checked[node_num] = { 0, 0, 0, 0, 0};
   int w = -1;
   int current_v = 0;
   int min_w = 10000000;
   current_v = s;
   checked[s] = 1;
   for (int i = 0; i < node_num; i++)
   {
      ans[i] = d[s][i];
   }
   min_w = 10000000;
   for (int i = 0; i < node_num; i++)
   {
      for (int j = 0; j < node_num; j++)
      {
         if (j == s || d[current_v][j] == 0 || checked[j]==1)
         {
            continue;
         }
         if (ans[j] == 0 )
         {
            ans[j] = ans[current_v] + d[current_v][j];
         }
         else if((ans[current_v] + d[current_v][j]) < ans[j])
         {
            ans[j] = ans[current_v] + d[current_v][j];
         }
      }
      printf("%d : %d %d %d %d\n", current_v + 1, ans[1], ans[2], ans[3], ans[4]);
      min_w = 10000000;
      for (int j = 0; j < node_num; j++)
      {
         if (ans[j] != 0 && checked[j]!=1 && ans[j]<min_w)
         {
            if(ans[j]!=0)
            {  
               min_w = ans[j];
               current_v = j;
            }   
         }
      }
      checked[current_v] = 1;
   }
}
int main() 
{
   Dijkstra();
}