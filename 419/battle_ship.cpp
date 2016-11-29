// the botton right of battle ship will have no neighbor x in right and down direction.
int dr[] = {1, 0};
int dc[] = {0, 1};
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int h = board.size(), w = board[0].size();
        int cnt = 0;
        for (int r=0;r<h;++r) {
            for (int c=0;c<w;++c) {
                if (board[r][c] == 'X') {
                    bool has_x_neighbor = false;
                    for (int d=0;d<2;++d) {
                        int nr = r + dr[d], nc = c + dc[d];
                        if (0<=nr && nr<h && 0<=nc && nc<w && board[nr][nc] == 'X') {
                            has_x_neighbor = true;
                        }
                    }
                    if (!has_x_neighbor) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
