class Solution {
public:
    vector<int> getans(vector<int>& arr , int x){
        int maxi = -1e9 , mini = 1e9;
        int i = -1 , j = -1;

        for(int k = 0 ; k < arr.size() ; ++k){

            if(k == x) continue;

            if(arr[k] > maxi){
                maxi = max(maxi , arr[k]);
                i = k;
            }
            if(arr[k] < mini){
                mini = min(mini , arr[k]);
                j = k;
            }
        }

        return {abs(maxi - mini) , i , j};
    }
    int minimumDistance(vector<vector<int>>& points) {
        
        vector<int> sum , diff ;

        for(int i = 0 ; i < points.size() ; ++i){
            int x = points[i][0];
            int y = points[i][1];

            sum.push_back(x + y);
            diff.push_back(x - y);
        }

        vector<int> first = getans(sum , -1);
        vector<int> second = getans(diff , -1);

        int i = -1 , j = -1;

        if(first[0] >= second[0]){
            i = first[1];
            j = first[2];
        }
        else{
            i = second[1];
            j = second[2];
        }

        vector<int> ans1 = getans(sum , i);
        vector<int> ans2 = getans(diff , i);
        vector<int> ans3 = getans(sum , j);
        vector<int> ans4 = getans(diff , j);
    
        return min(max(ans1[0] , ans2[0]) , max(ans3[0] , ans4[0]));
    }
};