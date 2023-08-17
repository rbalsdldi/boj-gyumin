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
vector<pair<int, int>> stores;
vector<pair<int, int>> homes;

int min_chicken_dist = 100000;

deque<int> store_queue;

int get_dist()
{
  int d_sum = 0;
  for (auto h : homes)
  {
    int d_temp = 10000;
    for (auto s : store_queue)
    {
      int d = abs(h.first - stores[s].first) + abs(h.second - stores[s].second);
      d_temp = min(d_temp, d);
    }
    d_sum += d_temp;
  }
  return d_sum;
}

void search(int depth)
{
  if (store_queue.size() > m)
  {
    return;
  }
  if (store_queue.size() > 0)
  {
    min_chicken_dist = min(min_chicken_dist, get_dist());
  }
  for (int i = depth + 1; i < stores.size(); i++)
  {
    store_queue.push_back(i);
    search(i);
    store_queue.pop_back();
  }
}

int main()
{
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int temp;
      cin >> temp;
      if (temp == 2)
      {
        stores.push_back(make_pair(i, j));
      }
      else if (temp == 1)
      {
        homes.push_back(make_pair(i, j));
      }
    }
  }

  search(-1);

  cout << min_chicken_dist << endl;
}
