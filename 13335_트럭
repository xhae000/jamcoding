#include <iostream>
#include <queue>

using namespace std;

int main() 
{
    int n,w,l;
    cin >> n >> l >> w;
    int trucks[n];
    
    for(int i=0;i<n;i++) cin >> trucks[i];
    
    int time = 0;
    
    int currentIdx = 0;
    int currentWeight = 0;
    // 무게  ,  다리 위에 진입한 Time
    queue<pair<int, int>> weightsANDmove;
    
    while(1) {
      if( currentIdx == n && weightsANDmove.empty() ) break;
      time ++;


    if(!weightsANDmove.empty() && time - weightsANDmove.front().second == l) { 
        currentWeight -= weightsANDmove.front().first;
        weightsANDmove.pop();
    }
  
    if(currentIdx < n && currentWeight + trucks[currentIdx] <= w){
        currentWeight += trucks[currentIdx];
        weightsANDmove.push(pair<int,int>(trucks[currentIdx ++], time));
    }
      
      // cout << currentWeight;

    }
    
    cout << time;
    
    return 0;
}
