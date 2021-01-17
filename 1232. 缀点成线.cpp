class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) {
            return true;
        }
        if (coordinates[0][0] == coordinates[1][0]) {
            for (auto i = 2; i < coordinates.size(); ++i) {
                if (coordinates[i][0] != coordinates[0][0]) return false;
            }
            return true;
        }
        else {
            double a = (double)(coordinates[1][1]-coordinates[0][1]) / (coordinates[1][0]-coordinates[0][0]);
            double b = coordinates[0][1] - a * coordinates[0][0];
            for (auto i = 2; i < coordinates.size(); ++i) {
                if (coordinates[i][1] != a*coordinates[i][0] + b) return false;
            } 
            return true;
        }
        return false;
    }
};