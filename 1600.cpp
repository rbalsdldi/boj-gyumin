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

int k, w, h;
vector<vector<int>> board;
vector<vector<vector<int>>> vis;

// (r, c, horse)
deque<tuple<int, int, int>> q;

int dr[] = {1, 0, -1, 0, -2, -1, 1, 2, 2, 1, -1, -2};
int dc[] = {0, 1, 0, -1, 1, 2, 2, 1, -1, -2, -2, -1};

bool oob(int r_size, int c_size, int r, int c)
{
  if (r_size > r && r >= 0 && c_size > c && c >= 0)
  {
    return false;
  }
  return true;
}

void bfs()
{
  while (q.size() > 0)
  {
    int cr = get<0>(q.front());
    int cc = get<1>(q.front());
    int horse = get<2>(q.front());
    q.pop_front();
    for (int i = 0; i < 12; i++)
    {
      int nr = cr + dr[i];
      int nc = cc + dc[i];
      if (oob(board.size(), board[0].size(), nr, nc) || board[nr][nc] == 1)
      {
        continue;
      }
      if (i > 3)
      {
        if (horse + 1 > k || vis[nr][nc][horse + 1] != -1)
        {
          continue;
        }
        q.push_back(make_tuple(nr, nc, horse + 1));
        vis[nr][nc][horse + 1] = vis[cr][cc][horse] + 1;
      }
      else
      {
        if (vis[nr][nc][horse] != -1)
        {
          continue;
        }
        q.push_back(make_tuple(nr, nc, horse));
        vis[nr][nc][horse] = vis[cr][cc][horse] + 1;
      }
    }
  }
}

void solution()
{
  q.push_back(make_tuple(0, 0, 0));
  vis[0][0][0] = 0;
  bfs();

  int min_move = INT_MAX;
  for (auto i : vis[h - 1][w - 1])
  {
    if (i == -1)
    {
      continue;
    }
    min_move = min(min_move, i);
  }
  if (min_move == INT_MAX)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << min_move << endl;
  }
}

int main()
{
  cin >> k >> w >> h;
  for (int i = 0; i < h; i++)
  {
    vector<int> row_temp;
    vector<vector<int>> vis_row_temp;
    for (int j = 0; j < w; j++)
    {
      int temp;
      cin >> temp;
      row_temp.push_back(temp);

      vector<int> vis_temp(k + 1, -1);
      vis_row_temp.push_back(vis_temp);
    }
    board.push_back(row_temp);
    vis.push_back(vis_row_temp);
  }

  solution();
}