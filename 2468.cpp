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

int n;

vector<vector<int>> board;

deque<pair<int, int>> q;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool oob(int r_size, int c_size, int r, int c)
{
  if (r_size > r && r >= 0 && c_size > c && c >= 0)
  {
    return false;
  }
  return true;
}

void bfs(vector<vector<int>> &board, int level)
{
  while (q.size() > 0)
  {
    int cr = q.front().first;
    int cc = q.front().second;
    q.pop_front();
    for (int i = 0; i < 4; i++)
    {
      int nr = cr + dr[i];
      int nc = cc + dc[i];
      if (oob(board.size(), board[0].size(), nr, nc) || board[nr][nc] == -1 || board[nr][nc] <= level)
      {
        continue;
      }
      q.push_back(make_pair(nr, nc));
      board[nr][nc] = -1;
    }
  }
}

int check_level(vector<vector<int>> board, int level)
{
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (level >= board[i][j])
      {
        continue;
      }
      q.push_back(make_pair(i, j));
      bfs(board, level);
      cnt++;
    }
  }
  return cnt;
}

void solution()
{
  int max_cnt = 0;
  for (int i = 0; i < 100; i++)
  {
    max_cnt = max(max_cnt, check_level(board, i));
  }
  cout << max_cnt << endl;
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    vector<int> row_temp;
    for (int j = 0; j < n; j++)
    {
      int temp;
      cin >> temp;
      row_temp.push_back(temp);
    }
    board.push_back(row_temp);
  }

  solution();
}