class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        int score=0;
        int j=n-1;
        int i=0;
        int maxScore=0;
        sort(begin(tokens),end(tokens));
        while(i<=j){
            if(power>=tokens[i]){
            score+=1;
            power-=tokens[i];
            i++;
            maxScore=max(maxScore,score);
            }
            else if(score>=1){
                power+=tokens[j];
                j--;
                score-=1;
            }
            else{
                return maxScore;
            }

        }
        return maxScore;
    }
};