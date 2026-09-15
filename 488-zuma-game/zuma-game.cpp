class Solution {
private:
    int mask = 0;
    vector<unordered_map<string, int>> dp;

    string updatedBoard(string board){
        int i = 0;

        while(i < board.length()){
            int j = i;

            while(j < board.length() && board[j] == board[i]){
                j++;
            }
            
            if(j - i >= 3){
                return updatedBoard(board.substr(0, i) + board.substr(j));
            }

            i = j;
        }

        return board;
    }
    int solve(string board, const string& hand){
        int m = board.length();
        int n = hand.length();

        if(m == 0) return 0;

        if(dp[mask].count(board)) return dp[mask][board];
        
        int ans = 1e9;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                bool worthTrying = false;
                if(board[i] == hand[j]) worthTrying = true;
                else if(i > 0 && board[i] == board[i - 1] && board[i] != hand[j]) worthTrying = true;
                if(!worthTrying) continue;

                bool isUsedCurrHandIdx = mask & (1 << j);

                // checking if we had used this hand index previously or not.. 
                if(isUsedCurrHandIdx) continue; 

                int oldMask = mask; // Storing used hand Index..
                mask = mask | (1 << j); // Updating mask so, we will not use same hand index again..

                // Constructiong new Board..
                string newBoard = board.substr(0, i) + hand[j] + board.substr(i);

                // cheking if we can do operation on our new Board or not. So, we can upadte it again..
                string updateNewBoard = updatedBoard(newBoard);

                int next = solve(updateNewBoard, hand);
                ans = min(ans, 1 + next);

                mask = oldMask; // Backtracking, so we can use this hand index in future..
            }
        }

        return dp[mask][board] = ans;
    }
public:
    int findMinStep(string board, string hand) {
        dp.resize(1 << hand.size());

        int ans = solve(board, hand);
        return ans >= 1e9 ? -1 : ans;
    }
};