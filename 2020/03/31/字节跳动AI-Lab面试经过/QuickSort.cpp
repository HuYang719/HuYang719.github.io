
#include <iostream>  
#include <cstdio>  
#include <fstream>  
#include <algorithm>  
#include <cmath>  
#include <deque>  
#include <vector>  
#include <queue>  
#include <string>  
#include <cstring>  
#include <map>  
#include <stack>  
#include <set>
using namespace std;
void vec_print(const vector<int>& L){
     for(auto i:L){
          cout<<i<<" ";
     }
}
int partition(vector<int>& LS, vector<int>& LM, int left, int right) {
     int pivot = LM[right];
     int pos = left;
     int LS_pivot_pos = 0;
     // 根据螺母处理螺丝的情况
     for(int i = left; i <= right; i++){
          if(LS[i] < pivot){
               swap(LS[i], LS[pos]);
               pos++;
          }
          if(LS[i] == pivot) // 必须放在swap的后面，这样才能保证获得经过交换后的LS中pivot的位置
               LS_pivot_pos = i;
     }
     swap(LS[LS_pivot_pos],LS[pos]);
     LS_pivot_pos = pos;

     //根据螺丝处理螺母的情况
     pivot = LS[LS_pivot_pos];
     pos = left;
     for(int i = left; i <= right; i++){
          if(LM[i] <= pivot) { // 由于pivot是LM最后一个，因此会直接swap到分界点
               swap(LM[i],LM[pos]);
               pos++;
          }
     }

     //螺丝和螺母的pivot停在的相对位置是一样的
     return LS_pivot_pos;
}

void quicksort(vector<int>& LS, vector<int>& LM, int left, int right) {
     if(left < right){
          int pi = partition(LS, LM, left, right);
          quicksort(LS, LM, left, pi-1);
          quicksort(LS, LM, pi+1, right);
     }
}

int main(){
     vector<int> LS = {4,5,6,7,8,1,2,3,9,10};
     vector<int> LM = {3,2,1,8,6,7,5,4,10,9};
     int left = 0;
     int right = LS.size()-1;
     quicksort(LS, LM, left, right);
     vec_print(LS);
     cout<<endl;
     vec_print(LM);
     return 0;
}