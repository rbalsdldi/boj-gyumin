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

int n, m, g, r;

// 3 for red, 4 for green
vector<vector<int>> board;

// (state, color): 0 for red, 1 for green
vector<vector<pair<int, int>>> vis;

// (r, c, r:0 or g:1)
deque<tuple<int, int, int>> q;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int max_cnt = 0;

bool oob(int r, int c)
{
  if (n > r && r >= 0 && m > c && c >= 0)
  {
    return false;
  }
  return true;
}

int spread(vector<vector<pair<int, int>>> visited)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] == 3)
      {
        q.push_back({i, j, 0});
        visited[i][j] = {0, 0};
      }
      else if (board[i][j] == 4)
      {
        q.push_back({i, j, 1});
        visited[i][j] = {0, 1};
      }
    }
  }

  int cnt = 0;
  while (q.size() > 0)
  {
    auto [cr, cc, color] = q.front();
    q.pop_front();
    if (visited[cr][cc].first == -2)
      continue;
    else if (visited[cr][cc].first != -1 && visited[cr][cc].second != color)
      continue;
    for (int i = 0; i < 4; i++)
    {
      int nr = cr + dr[i], nc = cc + dc[i];
      if (oob(nr, nc) || board[nr][nc] == 0)
        continue;
      if (visited[nr][nc].first == -1)
      {
        q.push_back({nr, nc, color});
        visited[nr][nc] = {visited[cr][cc].first + 1, color};
      }
      else if (visited[nr][nc].first == -2)
      {
        continue;
      }
      else if (visited[nr][nc].first == visited[cr][cc].first + 1 && visited[nr][nc].second != color)
      {
        visited[nr][nc] = {-2, 0};
        cnt++;
      }
    }
  }

  return cnt;
}

void plant(int r, int c, int red_remain, int green_remain, int soil_remain)
{
  if (red_remain + green_remain == 0)
  {
    max_cnt = max(max_cnt, spread(vis));
    return;
  }
  else if (r == n - 1 && c == m - 1)
  {
    return;
  }
  else if (red_remain + green_remain > soil_remain)
  {
    return;
  }
  int nr = r, nc = c + 1;
  if (nc == m)
  {
    nc = 0;
    nr++;
  }
  if (board[nr][nc] != 2)
  {
    plant(nr, nc, red_remain, green_remain, soil_remain);
    return;
  }
  plant(nr, nc, red_remain, green_remain, soil_remain - 1);
  if (red_remain > 0)
  {
    board[nr][nc] = 3;
    plant(nr, nc, red_remain - 1, green_remain, soil_remain - 1);
  }
  if (green_remain > 0)
  {
    board[nr][nc] = 4;
    plant(nr, nc, red_remain, green_remain - 1, soil_remain - 1);
  }
  board[nr][nc] = 2;
}

void solution()
{
  int soil_cnt = 0;
  for (auto i : board)
  {
    for (auto j : i)
    {
      if (j == 2)
      {
        soil_cnt++;
      }
    }
  }

  plant(0, -1, r, g, soil_cnt);
  cout << max_cnt << endl;
}

int main()
{
  cin >> n >> m >> g >> r;
  for (int i = 0; i < n; i++)
  {
    vector<int> row_temp;
    vector<pair<int, int>> vis_row_temp;
    for (int j = 0; j < m; j++)
    {
      int temp;
      cin >> temp;
      row_temp.push_back(temp);
      vis_row_temp.push_back({-1, 0});
    }
    board.push_back(row_temp);
    vis.push_back(vis_row_temp);
  }

  solution();
}