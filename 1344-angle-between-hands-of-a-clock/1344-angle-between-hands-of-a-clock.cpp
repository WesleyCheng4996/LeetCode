class Solution {
public:
    double angleClock(int hour, int minutes) {
        double edge2 = 6 * minutes, edge1 = hour * 30 + 0.5 * minutes;
        return fabs(edge1 - edge2) > 180 ? 360 - fabs(edge1 - edge2) : fabs(edge1 - edge2);
    }
};