class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0;

        for (int players = 2; players <= n; players++) {
            winner = (winner + k) % players;
        }

        return winner + 1;
    }
};