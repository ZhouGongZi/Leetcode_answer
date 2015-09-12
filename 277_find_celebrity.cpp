bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        map<int, bool> bar;
        
        for(int i=0; i<n; ++i){
            bar[i] = 1;  //all are possible
        }
        
        for(int i=0; i<n; ++i){
            if(!bar[i]) continue;
            for(int j=0; j<n; ++j){
                if(i == j) continue;
                if(knows(i, j)) {
                    bar[i] = 0;
                }
                else bar[j] = 0;
                
                if(knows(j, i)) bar[j] = 0;
                else bar[i] = 0;
            }
        }
        for(int i=0; i<bar.size(); ++i){
            if(!bar[i]) continue;
            else return i;
        }
        return -1;
    }
};