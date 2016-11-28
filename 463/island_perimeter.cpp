// TRAP: perimeter counts when 1) enighbor is water 2) neighbor out of bound
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        int perimeter = 0;
        vector<vector<bool>> visit(h, vector<bool>(w, false));
        for (int i=0;i<h;++i) {
            for (int j=0;j<w;++j) {
                if (grid[i][j]) {
                    for (int d=0;d<4;++d) {
                        int ni = i+di[d], nj = j+dj[d];
                        if (0<=ni&&ni<h && 0<=nj&&nj<w && grid[ni][nj]) {
                            ;
                        } else {
                            perimeter++;
                        }
                    }

                }
            }
        }
        return perimeter;
    }
};
