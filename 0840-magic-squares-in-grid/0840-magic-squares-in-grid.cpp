class Solution {
public:
    bool isAll(int i, int j, vector<vector<int>>& grid) {
        map<int, int> mp;
        for (int x = i; x < i + 3; x++) {
            for (int y = j; y < j + 3; y++) {
                mp[grid[x][y]]++;
            }
        }
        for (int i = 1; i < 10; i++) {
            if (mp[i] != 1) {
                return false;
            }
        }
        return true;
    }

    bool check(int i, int j, vector<vector<int>>& grid) {
        int r1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        int r2 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
        int r3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];

        int c1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
        int c2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
        int c3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];

        int d1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        int d2 = grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2];

        return (r1 == 15 && r2 == 15 && r3 == 15 && c1 == 15 && c2 == 15 && c3 == 15 && d1 == 15 && d2 == 15);
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n < 3 || m < 3) {
            return 0;
        }
        
        int cnt = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                if (check(i, j, grid) && isAll(i, j, grid)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};