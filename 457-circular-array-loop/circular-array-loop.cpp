class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        auto nextIndex = [&](int i) {
            return ((i + nums[i]) % n + n) % n;
        };

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                continue;
            }

            bool direction = nums[i] > 0;
            int slow = i;
            int fast = i;

            while (true) {
                int nextSlow = nextIndex(slow);

                if (nums[nextSlow] == 0 ||
                    (nums[nextSlow] > 0) != direction) {
                    break;
                }

                int nextFast = nextIndex(fast);

                if (nums[nextFast] == 0 ||
                    (nums[nextFast] > 0) != direction) {
                    break;
                }

                nextFast = nextIndex(nextFast);

                if (nums[nextFast] == 0 ||
                    (nums[nextFast] > 0) != direction) {
                    break;
                }

                slow = nextSlow;
                fast = nextFast;

                if (slow == fast) {
                    if (slow == nextIndex(slow)) {
                        break;
                    }

                    return true;
                }
            }

            slow = i;

            while (nums[slow] != 0 &&
                   (nums[slow] > 0) == direction) {
                int next = nextIndex(slow);
                nums[slow] = 0;
                slow = next;
            }
        }

        return false;
    }
};