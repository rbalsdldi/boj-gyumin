#include <algorithm>
#include <bitset>
#include <complex>
#include <climits>
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

vector<vector<char>> board;

vector<vector<bool>> check;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int group_cnt = 0;

deque<pair<int, int>> q;

bool oob(int r, int c)
{
  if (5 > r && r >= 0 && 5 > c && c >= 0)
  {
    return false;
  }
  return true;
}

bool adj_bfs(vector<vector<bool>> c)
{
  bool is_picked = false;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (c[i][j])
      {
        q.push_back({i, j});
        c[i][j] = false;
        is_picked = true;
      }
      if (is_picked)
      {
        break;
      }
    }
    if (is_picked)
    {
      break;
    }
  }
  int cnt = 0;
  while (q.size() > 0)
  {
    auto [cr, cc] = q.front();
    q.pop_front();
    cnt++;
    for (int i = 0; i < 4; i++)
    {
      int nr = cr + dr[i], nc = cc + dc[i];
      if (oob(nr, nc) || !c[nr][nc])
        continue;
      q.push_back({nr, nc});
      c[nr][nc] = false;
    }
  }
  if (cnt == 7)
  {
    return true;
  }
  return false;
}

void group(int r, int c, int s, int cnt)
{
  if (cnt == 7)
  {
    if (s >= 4)
    {
      if (adj_bfs(check))
      {
        group_cnt++;
      }
    }
    return;
  }
  if (7 - cnt < 4 - s)
  {
    return;
  }
  if (r == 5)
  {
    return;
  }
  int nr = r, nc = c + 1;
  if (nc == 5)
  {
    nr++;
    nc = 0;
  }
  check[r][c] = true;
  if (board[r][c] == 'S')
  {
    group(nr, nc, s + 1, cnt + 1);
  }
  else
  {
    group(nr, nc, s, cnt + 1);
  }
  check[r][c] = false;
  group(nr, nc, s, cnt);
}

int main()
{
  for (int i = 0; i < 5; i++)
  {
    string temp;
    cin >> temp;
    vector<char> row_temp(temp.begin(), temp.end());
    board.push_back(row_temp);
    vector<bool> check_row_temp(5, false);
    check.push_back(check_row_temp);
  }

  group(0, 0, 0, 0);
  cout << group_cnt << endl;
}