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

int n, m, p;

vector<int> s;
vector<vector<char>> board;

vector<deque<tuple<int, int, int>>> pq;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool oob(int r, int c)
{
  if (n > r && r >= 0 && m > c && c >= 0)
  {
    return false;
  }
  return true;
}

void bfs(int round, int p)
{
  while (pq[p - 1].size() > 0)
  {
    int cr = get<0>(pq[p - 1].front());
    int cc = get<1>(pq[p - 1].front());
    int d = get<2>(pq[p - 1].front());
    if (d == round * s[p - 1])
    {
      return;
    }
    pq[p - 1].pop_front();
    for (int i = 0; i < 4; i++)
    {
      int nr = cr + dr[i];
      int nc = cc + dc[i];
      if (oob(nr, nc) || board[nr][nc] != '.')
      {
        continue;
      }
      pq[p - 1].push_back(make_tuple(nr, nc, d + 1));
      board[nr][nc] = p + '0';
    }
  }
}

void solution()
{
  int round = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] == '.' || board[i][j] == '#')
      {
        continue;
      }
      int player = board[i][j] - '0';
      pq[player - 1].push_back(make_tuple(i, j, 0));
    }
  }
  while (true)
  {
    round++;
    bool is_completed = true;
    for (int i = 0; i < p; i++)
    {
      bfs(round, i + 1);
    }
    for (int i = 0; i < p; i++)
    {
      if (pq[i].size() != 0)
      {
        is_completed = false;
      }
    }
    if (is_completed)
    {
      break;
    }
  }
  for (int i = 0; i < p; i++)
  {
    int cnt = 0;
    for (auto j : board)
    {
      for (auto k : j)
      {
        if (k - '0' == i + 1)
        {
          cnt++;
        }
      }
    }
    cout << cnt << ' ';
  }
}

int main()
{
  cin >> n >> m >> p;
  for (int i = 0; i < p; i++)
  {
    int temp;
    cin >> temp;
    s.push_back(temp);
    deque<tuple<int, int, int>> q_temp;
    pq.push_back(q_temp);
  }
  for (int i = 0; i < n; i++)
  {
    string temp;
    cin >> temp;
    vector<char> row_temp(temp.begin(), temp.end());
    board.push_back(row_temp);
  }

  solution();
}
