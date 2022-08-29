class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        //not possible for case where size<4
        
        if(nums.size()<4)
            return 0;
        //declare map and put the 1st entry/
        unordered_map<int,int>m;
        m.insert({1,0});
        
        
        //now we need to map the product with how many times will it Occur in the array
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                int pr=nums[i]*nums[j];
                m[pr]++;  //increment in map
            }
        }
        int ways=0;   //the final ans
        
        
        //iterating in the map->
        
        for(auto i:m){
            int p=nums[0]*nums[1];  
            //checking for the product if same is present in the map, then add the ways
            if(m.find(p)!=m.end()){
            int x=i.second;
            //x here is the number of entries with same prodcut
            //formula for permutations..  add ways acc to number of entries.
            ways+=(4*x*(x-1));
           }
        }
        return ways;
    }
};