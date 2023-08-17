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

enum Color
{
  RED = 0,
  GREEN = 1,
  BLUE = 2
};

int n;
vector<vector<int>> cost;
vector<vector<int>> memo;

int dp(int cur, Color color)
{
  if (memo[cur][color] != 0)
  {
    return memo[cur][color];
  }
  vector<int> ls;
  for (int i = 0; i < 3; i++)
  {
    if (i == color)
    {
      continue;
    }
    ls.push_back(dp(cur - 1, static_cast<Color>(i)));
  }
  memo[cur][color] = cost[cur][color] + *min_element(ls.begin(), ls.end());
  return memo[cur][color];
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    vector<int> temp1(3, 0);
    memo.push_back(temp1);
    vector<int> temp2(3, 0);
    for (int j = 0; j < 3; j++)
    {
      cin >> temp2[j];
    }
    cost.push_back(temp2);
  }

  memo[0] = cost[0];

  cout << min(min(dp(n - 1, RED), dp(n - 1, GREEN)), dp(n - 1, BLUE));
}