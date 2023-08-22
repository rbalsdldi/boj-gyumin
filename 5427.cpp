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

int t;
vector<vector<vector<char>>> cases;

deque<pair<int, pair<int, int>>> q;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool oob(int r_size, int c_size, int r, int c)
{
  if (r < r_size && r >= 0 && c < c_size && c >= 0)
  {
    return false;
  }
  return true;
}

void bfs(vector<vector<char>> &board)
{

  vector<vector<int>> fire_vis;
  vector<vector<int>> p_vis;
  for (auto i : board)
  {
    vector<int> row_temp;
    for (auto j : i)
    {
      row_temp.push_back(1000000);
    }
    fire_vis.push_back(row_temp);
  }
  p_vis = fire_vis;

  // for fire
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[0].size(); j++)
    {
      if (board[i][j] == '*')
      {
        q.push_back(make_pair(0, make_pair(i, j)));
        fire_vis[i][j] = 0;
      }
    }
  }

  while (q.size() > 0)
  {
    int c_r = q.front().second.first;
    int c_c = q.front().second.second;
    int dist = q.front().first;
    q.pop_front();
    for (int i = 0; i < 4; i++)
    {
      int n_r = c_r + dr[i];
      int n_c = c_c + dc[i];
      if (oob(board.size(), board[0].size(), n_r, n_c) || board[n_r][n_c] == '#' || fire_vis[n_r][n_c] != 1000000)
      {
        continue;
      }
      q.push_back(make_pair(dist + 1, make_pair(n_r, n_c)));
      fire_vis[n_r][n_c] = dist + 1;
    }
  }

  // for p
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[0].size(); j++)
    {
      if (board[i][j] == '@')
      {
        q.push_back(make_pair(0, make_pair(i, j)));
        p_vis[i][j] = 0;
        break;
      }
    }
  }

  while (q.size() > 0)
  {
    int c_r = q.front().second.first;
    int c_c = q.front().second.second;
    int dist = q.front().first;
    q.pop_front();
    for (int i = 0; i < 4; i++)
    {
      int n_r = c_r + dr[i];
      int n_c = c_c + dc[i];
      if (oob(board.size(), board[0].size(), n_r, n_c) || board[n_r][n_c] == '#' || p_vis[n_r][n_c] != 1000000)
      {
        continue;
      }
      q.push_back(make_pair(dist + 1, make_pair(n_r, n_c)));
      p_vis[n_r][n_c] = dist + 1;
    }
  }

  bool is_impossible = true;
  int min_t = 1000000;

  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[0].size(); j++)
    {
      if (p_vis[i][j] < fire_vis[i][j])
      {
        if (i == 0 || i + 1 == board.size() || j == 0 || j + 1 == board[0].size())
        {
          is_impossible = false;
          min_t = min(min_t, p_vis[i][j]);
        }
      }
    }
  }

  if (is_impossible)
  {
    cout << "IMPOSSIBLE" << endl;
  }
  else
  {
    cout << min_t + 1 << endl;
  }
}

void solution()
{
  for (int i = 0; i < t; i++)
  {
    bfs(cases[i]);
  }
}

int main()
{
  cin >> t;
  int w, h;
  for (int i = 0; i < t; i++)
  {
    cin >> w >> h;
    vector<vector<char>> board_temp;
    for (int j = 0; j < h; j++)
    {
      string temp;
      cin >> temp;
      vector<char> row_temp(temp.begin(), temp.end());

      board_temp.push_back(row_temp);
    }
    cases.push_back(board_temp);
  }

  solution();
}