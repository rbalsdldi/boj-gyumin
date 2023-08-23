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

int f, s, g, u, d;

vector<int> vis;
// (x, dist)
deque<pair<int, int>> q;

bool oob(int x_size, int x)
{
  if (x_size > x && x >= 0)
  {
    return false;
  }
  return true;
}

int bfs()
{
  while (q.size() > 0)
  {
    int cx = q.front().first;
    int dist = q.front().second;
    q.pop_front();
    if (cx == g-1)
    {
      return dist;
    }
    // up
    int ux = cx + u;
    if (!oob(f, ux) && vis[ux] == -1)
    {
      q.push_back(make_pair(ux, dist + 1));
      vis[ux] = vis[cx] + 1;
    }
    // down
    int dx = cx - d;
    if (!oob(f, dx) && vis[dx] == -1)
    {
      q.push_back(make_pair(dx, dist + 1));
      vis[dx] = vis[cx] + 1;
    }
  }

  return -1;
}

void solution()
{
  q.push_back(make_pair(s-1, 0));
  int result = bfs();
  if (result == -1)
  {
    cout << "use the stairs" << endl;
  }
  else
  {
    cout << result << endl;
  }
}

int main()
{
  cin >> f >> s >> g >> u >> d;
  for (int i = 0; i < f; i++)
  {
    vis.push_back(-1);
  }

  solution();
}