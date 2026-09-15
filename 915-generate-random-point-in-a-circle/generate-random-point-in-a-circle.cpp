class Solution {
    double radius, x_center, y_center;

public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }

    vector<double> randPoint() {
        double angle = 2 * M_PI *
                       ((double)rand() / RAND_MAX);

        double r = radius *
                   sqrt((double)rand() / RAND_MAX);

        return {
            x_center + r * cos(angle),
            y_center + r * sin(angle)
        };
    }
};