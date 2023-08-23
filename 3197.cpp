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

// 7:05

int r, c;

vector<vector<char>> board;
vector<vector<int>> swan_vis;

deque<tuple<int, int, int>> water_q;
deque<pair<int, int>> swan_q;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool oob(int r, int c)
{
  if (board.size() > r && r >= 0 && board[0].size() > c && c >= 0)
  {
    return false;
  }
  return true;
}

void melt(int day)
{
  while (water_q.size() > 0)
  {
    int cr = get<0>(water_q.front());
    int cc = get<1>(water_q.front());
    int d = get<2>(water_q.front());
    if (day == d)
    {
      return;
    }
    water_q.pop_front();
    for (int i = 0; i < 4; i++)
    {
      int nr = cr + dr[i];
      int nc = cc + dc[i];
      if (oob(nr, nc) || board[nr][nc] == '.' || board[nr][nc] == 'L')
      {
        continue;
      }
      water_q.push_back(make_tuple(nr, nc, d + 1));
      board[nr][nc] = '.';
    }
  }
}

bool find_path()
{
  while (swan_q.size() > 0)
  {
    int cr = swan_q.front().first;
    int cc = swan_q.front().second;
    if (board[cr][cc] == 'X')
    {
      return false;
    }
    swan_q.pop_front();
    for (int i = 0; i < 4; i++)
    {
      int nr = cr + dr[i];
      int nc = cc + dc[i];
      if (oob(nr, nc) || swan_vis[nr][nc] == 1)
      {
        continue;
      }
      if (board[nr][nc] == 'L')
      {
        return true;
      }
      if (board[nr][nc] == '.')
      {
        swan_q.push_front(make_pair(nr, nc));
      }
      else if (board[nr][nc] == 'X' || board[nr][nc] == 'L')
      {
        swan_q.push_back(make_pair(nr, nc));
      }
      swan_vis[nr][nc] = 1;
    }
  }
  return false;
}

int solution()
{
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[0].size(); j++)
    {
      if (board[i][j] == '.' || board[i][j] == 'L')
      {
        water_q.push_back(make_tuple(i, j, 0));
      }
      if (swan_q.size() == 0 && board[i][j] == 'L')
      {
        swan_q.push_back(make_pair(i, j));
        swan_vis[i][j] = 1;
        board[i][j] = '.';
      }
    }
  }
  int cnt = 0;
  if (find_path())
  {
    return 0;
  }
  while (true)
  {
    cnt++;
    melt(cnt);
    if (find_path())
    {
      return cnt;
    }
  }
}

int main()
{
  cin >> r >> c;
  for (int i = 0; i < r; i++)
  {
    string temp;
    cin >> temp;
    vector<char> row_temp(temp.begin(), temp.end());
    board.push_back(row_temp);
    vector<int> swan_vis_temp(c, 0);
    swan_vis.push_back(swan_vis_temp);
  }

  cout << solution() << endl;
}