/*

https://leetcode.com/problems/n-queens/

Same approch using bitmask
https://leetcode.com/problems/n-queens/discuss/19808/Accepted-4ms-c%2B%2B-solution-use-backtracking-and-bitmask-easy-understand.

*/
int getDigonal1(int n, int x, int y)
{
    int t = min(x, y);
    x -= t;
    y -= t;
    
    return x ? n - x: y ? n + y : n;
}
 
int getDigonal2(int x, int y)
{
    return x + y;
}
 
void Recursion(vector<vector<string>>& res,
    vector<string>& board,
    vector<bool>& col,
    vector<bool>& D1, 
    vector<bool>& D2, int currRow, const int& N)
{
    if(currRow == N)
    {
        res.push_back(board);
        return;
    }

    for(int each = 0; each < N; ++each)
    {
        int d1 = getDigonal1(N-1, currRow, each);
        int d2 = getDigonal2(currRow, each);

        if(!col[each] && !D1[d1] && !D2[d2])
        {
            col[each] = D1[d1] = D2[d2] = true;
            board[currRow][each] = 'Q';

            Recursion(res, board, col, D1, D2, currRow + 1, N);

            col[each] = D1[d1] = D2[d2] = false;
            board[currRow][each] = '.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int N) {
    vector<vector<string>> res;
    vector<string> board(N, string(N, '.'));

    vector<bool> col(N, false);
    vector<bool> D1(N*2 - 1, false);
    vector<bool> D2(N*2 - 1, false);

    Recursion(res, board, col, D1, D2, 0, N);

    return res;
}
