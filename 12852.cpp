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

int n;

int memo[1000001] = {0};
vector<int> r_memo;

int dp(int k)
{
  if (memo[k] == 0 && k > 1)
  {
    vector<pair<int, int>> temp;
    if (k % 3 == 0)
    {
      temp.push_back({dp(k / 3), k / 3});
    }
    if (k % 2 == 0)
    {
      temp.push_back({dp(k / 2), k / 2});
    }
    temp.push_back({dp(k - 1), k - 1});

    auto itr = min_element(temp.begin(), temp.end());
    memo[k] = (*itr).first + 1;
    r_memo[k] = (*itr).second;
  }
  return memo[k];
}

int main()
{
  cin >> n;
  vector<int> temp(n + 1, 0);
  r_memo = temp;

  memo[1] = 0;
  r_memo[1] = 1;
  cout << dp(n) << endl;

  int cur = n;
  while (true)
  {
    cout << cur << ' ';
    if (cur == 1)
    {
      break;
    }
    cur = r_memo[cur];
  }
  cout << endl;
}