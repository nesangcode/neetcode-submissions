class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        int a=idx-1, b=idx;
        int c=a, d=b;
        while(a >= 0 && b < arr.size() && k > 0){
            if(x-arr[a] <= arr[b]-x){
                a--;
            } else {
                b++;
            }
            k--;
        }

        while(k>0&&a>=0){
            a--;
            k--;
        }

        while(k>0&&b<arr.size()){
            b++;
            k--;
        }

        vector<int> fin;

        for(int i = a+1; i <= c; i++){
            fin.emplace_back(arr[i]);
        }
        for(int i = d; i < b; i++){
            fin.emplace_back(arr[i]);
        }

        return fin;
    }
};