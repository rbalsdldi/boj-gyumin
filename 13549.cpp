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

#define LIMIT 100001

int n, k;

vector<int> vis(LIMIT, -1);

deque<int> q;

int dx[] = {1, -1};

bool oob(int x)
{
  if (x > LIMIT || x < 0)
  {
    return true;
  }
  return false;
}

int bfs()
{
  while (q.size() > 0)
  {
    int cx = q.front();
    q.pop_front();
    if (cx == k)
    {
      return vis[cx];
    }
    for (int i = 2; i >= 0; i--)
    {
      int nx;
      if (i == 2)
      {
        nx = cx * 2;
        if (oob(nx) || vis[nx] != -1)
        {
          continue;
        }
        q.push_front(nx);
        vis[nx] = vis[cx];
      }
      else
      {
        nx = cx + dx[i];
        if (oob(nx) || vis[nx] != -1)
        {
          continue;
        }
        q.push_back(nx);
        vis[nx] = vis[cx] + 1;
      }
    }
  }
  return -1;
}

int main()
{
  cin >> n >> k;

  q.push_back(n);
  vis[n] = 0;

  cout << bfs() << endl;
}
