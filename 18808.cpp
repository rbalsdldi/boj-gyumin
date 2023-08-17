#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<vector<vector<int>>> stickers;
int n, m, k;

bool is_available(int start_r, int start_c, vector<vector<int>> &sticker)
{
  for (int r = 0; r < sticker.size(); ++r)
  {
    for (int c = 0; c < sticker[0].size(); ++c)
    {
      int cur_r = start_r + r;
      int cur_c = start_c + c;
      if (cur_r >= 0 && cur_r < board.size() && cur_c >= 0 && cur_c < board[0].size())
      {
        if (sticker[r][c] == 1 && board[cur_r][cur_c] == 1)
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
  }
  return true;
}

void fill_board(int start_r, int start_c, vector<vector<int>> &sticker)
{
  for (int r = 0; r < sticker.size(); ++r)
  {
    for (int c = 0; c < sticker[0].size(); ++c)
    {
      if (sticker[r][c] == 1)
      {
        board[start_r + r][start_c + c] = 1;
      }
    }
  }
}

void rotate(vector<vector<int>> &sticker)
{
  vector<vector<int>> temp = sticker;
  sticker.clear();
  for (int c = 0; c < temp[0].size(); ++c)
  {
    vector<int> rotated_r;
    for (int r = temp.size() - 1; r >= 0; --r)
    {
      rotated_r.push_back(temp[r][c]);
    }
    sticker.push_back(rotated_r);
  }
}

int solution()
{
  for (auto &s : stickers)
  {
    bool is_done = false;
    for (int rot = 0; rot < 4; ++rot)
    {
      for (int r = 0; r <= n - static_cast<int>(s.size()); ++r)
      {

        for (int c = 0; c <= m - static_cast<int>(s[0].size()); ++c)
        {
          if (is_available(r, c, s))
          {
            fill_board(r, c, s);
            is_done = true;
            break;
          }
        }
        if (is_done)
        {
          break;
        }
      }
      if (is_done)
      {
        break;
      }
      rotate(s);
    }
  }

  int cnt = 0;
  for (auto i : board)
  {
    for (auto j : i)
    {
      if (j == 1)
      {
        cnt++;
      }
    }
  }

  return cnt;
}

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> n >> m >> k;

  for (int i = 0; i < n; i++)
  {
    vector<int> b_r;
    for (int j = 0; j < m; j++)
    {
      b_r.push_back(0);
    }
    board.push_back(b_r);
  }

  int r, c;
  for (int i = 0; i < k; i++)
  {
    cin >> r >> c;
    vector<vector<int>> s_temp;
    for (int j = 0; j < r; j++)
    {
      vector<int> row_temp;
      for (int k = 0; k < c; k++)
      {
        int temp;
        cin >> temp;
        row_temp.push_back(temp);
      }
      s_temp.push_back(row_temp);
    }
    stickers.push_back(s_temp);
  }

  cout << solution();
}