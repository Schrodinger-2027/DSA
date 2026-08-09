class Solution {
public:
    int reverse(int x) {
        vector<int> v;
        while(x != 0 ){
            v.push_back(x % 10);
            x = x / 10;
        }
        long output = 0;
        for(int i = 0 ; i < v.size() ; ++i){
            output = output + v[i] * pow(10, v.size() - 1 - i);
        }
        if(output >INT_MAX || output <INT_MIN){
            return 0;
        }
        else{
            return (int)output;
        }
    }
};