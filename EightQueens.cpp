// EightQueens.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。//
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace placeholders;

const int sz = 8;
vector<vector<int>> board;
int board_curr[sz];


void perm(int start, int end, int a[], vector<vector<int>>& board);
void find(vector<int>& board, unsigned& cnt_solu);
void printboard(vector<int>& board);

int main()
{
    // 生成初始棋盘 / 排列所有可能
    for (auto i = 0; i != 8; ++i)
        board_curr[i] = i + 1;
    perm(0, sz, board_curr, board);

    //寻找每种可能
    unsigned cnt_solu = 0;
    for_each(board.begin(), board.end(), bind(find, _1, cnt_solu));
    return 0;
}

void perm(int start, int end, int a[], vector<vector<int>>& board)
{
    if (start == end)
    {
        vector<int> curr;
        curr.reserve(sz);
        for (auto i = 0; i != sz; ++i)
            curr.push_back(a[i]);
        board.push_back(curr);
        return;
    }

    for (int i = start; i < end; i++)
    {
        swap(a[start], a[i]);
        perm(start + 1, end, a, board);
        swap(a[i], a[start]);
    }
}

void find(vector<int>& board, unsigned& cnt_solu)
{
    for (auto i = 0; i != board.size() - 1; ++i)
    {
        auto x1 = i + 1, y1 = board[i];
        for (auto j = i + 1; j != board.size(); ++j)
        {
            auto x2 = j + 1, y2 = board[j];
            double slope = abs(static_cast<double>((y2 - y1)) / (x2 - x1));
            if (x1 == x2 || y1 == y2 || slope == 1)
            {
                return;
            }
        }
    }

    cout << "第" << ++cnt_solu << "解法:" << endl;
    printboard(board);
    cout << endl;
}

void printboard(vector<int>& board)
{

    for (auto i : board)
    {
        for (auto j = 0; j != sz; ++j)
        {
            if (j + 1 != i)
                cout << 0 << " ";
            else
                cout << 1 << " ";
        }
        cout << endl;
    }
}