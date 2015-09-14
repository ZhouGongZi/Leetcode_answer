class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        map<int, int> bar;
        int n = citations.size();
        int ptr = 0;
        
        for(int i = 1; i<=n; ++i){
            while(citations[ptr] < i) ptr ++;
            bar[i] = n - ptr;
        }
        int result = 0;
        for(map<int, int>::iterator it = bar.begin(); it != bar.end(); ++it){
            if(it -> first <= it -> second){
                result = it -> first;
            }
        }
        return result;
    }
};