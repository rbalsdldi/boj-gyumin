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

int n, m;
vector<vector<int>> maze;
int vis[100][100];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

deque<pair<int, int>> q;

int bfs()
{
  q.push_back(make_pair(0, 0));
  vis[0][0] = 1;

  int cur_r, cur_c;
  while (q.size() > 0)
  {
    tie(cur_r, cur_c) = q.front();
    q.pop_front();

    if (cur_r == n - 1 && cur_c == m - 1)
    {
      return vis[cur_r][cur_c];
    }
    int next_r, next_c;
    for (int i = 0; i < 4; i++)
    {
      next_r = cur_r + dr[i];
      next_c = cur_c + dc[i];

      if (n > next_r && 0 <= next_r && m > next_c && 0 <= next_c && vis[next_r][next_c] == 0)
      {
        q.push_back(make_pair(next_r, next_c));
        vis[next_r][next_c] = vis[cur_r][cur_c] + 1;
      }
    }
  }
  return -1;
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    vector<int> row_temp;
    for (int j = 0; j < m; j++)
    {
      int temp;
      scanf("%1d", &temp);
      if (temp == 0)
      {
        vis[i][j] = -1;
      }
      else
      {
        vis[i][j] = 0;
      }
      row_temp.push_back(temp);
    }
    maze.push_back(row_temp);
  }

  cout << bfs() << endl;
}