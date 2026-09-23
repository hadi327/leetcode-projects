class Solution {
    static constexpr int MAX_COLOR_BALLS = 8;

    int combs_cache[MAX_COLOR_BALLS+1][MAX_COLOR_BALLS+1] = {};
    vector<vector<vector<double>>> dp;
public:
    double factorial(int n){
        double result = 1;
        while(n) result *= n--;
        return result;
    }

    int comb(int n, int k){
        if (combs_cache[n][k] > 0) return combs_cache[n][k];
        return combs_cache[n][k] = factorial(n) / factorial(n-k) / factorial(k);
    }

    // Num possibilities to choose k balls out of all balls starting from color_start
    // And the the difference between number of colors of chosen and unchosen balls is diff
    double numPoss(vector<int>& balls,int k, int color_start, int diff, int num_colors){
        if (abs(diff) > num_colors - color_start) return 0; // Not enough colors left for diff
        if (k < diff) return 0; // Not enough balls for diff
        if (color_start == balls.size()) return k == 0; // All colors were explored

        double& result = dp[k][color_start][diff + num_colors];
        if (result >= 0) return result;

        int max_balls = balls[color_start];
        result = numPoss(balls, k, color_start+1, diff+1, num_colors);  // No balls chosen of current color
        for(int balls_taken = 1; balls_taken <= min(max_balls,k); balls_taken++){ // Choose up to k balls of current color
            result += comb(max_balls, balls_taken) * numPoss(balls, k-balls_taken,
                         color_start+1, diff - (balls_taken==max_balls), num_colors);
        }
        return result;
    }

    double getProbability(vector<int>& balls) {
        int num_balls = accumulate(balls.begin(), balls.end(),0);
        int n = num_balls / 2;
        int num_colors = balls.size();

        dp = vector<vector<vector<double>>> (n+1,
                vector<vector<double>>(num_colors, 
                    vector<double>(num_colors*2,-1.0)
            )
        );
        double all_poss =  factorial(2*n) / factorial(n) / factorial(n);
        
        return double(numPoss(balls,n,0,0, num_colors)) / all_poss;
    }
};