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

vector<pair<int, int>> cc(1500001, {0, 0});

vector<long long int> memo(1500051, -1);

long long int dp(int k)
{
  if (memo[k] == -1)
  {
    memo[k] = max(dp(k + cc[k].first) + cc[k].second, dp(k + 1));
  }
  return memo[k];
}

int main()
{
  cin >> n;
  for (int i = 1; i < n + 1; i++)
  {
    cin >> cc[i].first >> cc[i].second;
  }

  if (cc[n].first == 1)
  {
    memo[n] = cc[n].second;
  }
  else
  {
    memo[n] = 0;
  }
  memo[n + 1] = 0;

  for (int i = n + 2; i < n + 51; i++)
  {
    memo[i] = INT_MIN;
  }

  cout << dp(1) << endl;
}