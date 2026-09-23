class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int start = stoi(startTime.substr(0, 2)) * 60
                  + stoi(startTime.substr(3, 2));

        int finish = stoi(finishTime.substr(0, 2)) * 60
                   + stoi(finishTime.substr(3, 2));

        // Crossed midnight
        if (finish < start)
            finish += 24 * 60;

        // Round start UP to next 15-minute boundary
        start = ((start + 14) / 15) * 15;

        // Round finish DOWN to previous 15-minute boundary
        finish = (finish / 15) * 15;

        if (finish <= start)
            return 0;

        return (finish - start) / 15;
    }
};