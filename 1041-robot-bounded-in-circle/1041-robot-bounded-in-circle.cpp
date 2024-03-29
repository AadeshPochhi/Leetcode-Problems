class Solution {
public:
    bool isRobotBounded(string instructions) {
      vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0;
        int idx = 0;

        for (char i : instructions) {
            if (i == 'L') {
                idx = (idx + 3) % 4;
            } else if (i == 'R') {
                idx = (idx + 1) % 4;
            } else {
                x += directions[idx][0];
                y += directions[idx][1];
            }
        }
        return (x == 0 && y == 0) || idx != 0;  
    }
};