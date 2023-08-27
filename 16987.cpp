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

vector<pair<int, int>> eggs;

int n;

int max_cnt;

void backtrack(int idx, int cnt, vector<pair<int, int>> eggs)
{
  if (idx == n || cnt == n)
  {
    max_cnt = max(max_cnt, cnt);
    return;
  }
  if (eggs[idx].first <= 0)
  {
    backtrack(idx + 1, cnt, eggs);
    return;
  }
  bool all_done = true;
  for (int i = 0; i < n; i++)
  {
    if (i == idx || eggs[i].first <= 0)
      continue;
    all_done = false;
    vector<pair<int, int>> eggs_c = eggs;
    int cnt_c = cnt;
    eggs_c[i].first -= eggs_c[idx].second;
    eggs_c[idx].first -= eggs_c[i].second;
    if (eggs_c[i].first <= 0)
    {
      cnt_c++;
    }
    if (eggs_c[idx].first <= 0)
    {
      cnt_c++;
    }
    backtrack(idx + 1, cnt_c, eggs_c);
  }
  if (all_done)
  {
    backtrack(idx + 1, cnt, eggs);
  }
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int d, w;
    cin >> d >> w;
    eggs.push_back({d, w});
  }

  backtrack(0, 0, eggs);
  cout << max_cnt << endl;
}
