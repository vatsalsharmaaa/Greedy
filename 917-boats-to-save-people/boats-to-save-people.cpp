class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int i=0;int j=n-1;
        sort(begin(people),end(people));
        int boat=0;
        int k=limit;
        while(n>0 && i<=j){
            if(limit>=people[j]){
                limit-=people[j];
                boat++;
                j--;
                n--;
                if(limit>=people[i]){
                    i++;
                    n--;
                }
            }
            limit=k;
        }
        return boat;
    }
};