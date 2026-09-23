class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        auto distSum = [&](double x, double y) {
            double sum = 0;

            for (auto &p : positions) {
                double dx = x - p[0];
                double dy = y - p[1];

                sum += sqrt(dx * dx + dy * dy);
            }

            return sum;
        };

        double x = 0, y = 0;

        for (auto &p : positions) {
            x += p[0];
            y += p[1];
        }

        x /= positions.size();
        y /= positions.size();

        double step = 100.0;

        while (step > 1e-7) {
            bool improved = true;

            while (improved) {
                improved = false;

                double current = distSum(x, y);

                const int dx[] = {1, -1, 0, 0};
                const int dy[] = {0, 0, 1, -1};

                for (int d = 0; d < 4; d++) {
                    double nx = x + dx[d] * step;
                    double ny = y + dy[d] * step;

                    double next = distSum(nx, ny);

                    if (next < current) {
                        x = nx;
                        y = ny;
                        improved = true;
                        break;
                    }
                }
            }

            step *= 0.5;
        }

        return distSum(x, y);
    }
};