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

// (연속, 불연속)
vector<pair<int, int>> memo;
vector<int> score(300, 0);

int dp(int last, int cur)
{
  if (cur >= n)
  {
    return 0;
  }
  if (last == cur - 1)
  {
    if (memo[cur].first != -1)
    {
      return score[cur] + memo[cur].first;
    }
    memo[cur].first = dp(cur, cur + 2);
    return score[cur] + memo[cur].first;
  }
  if (memo[cur].second != -1)
  {
    return score[cur] + memo[cur].second;
  }

  memo[cur].second = max(dp(cur, cur + 1), dp(cur, cur + 2));
  return score[cur] + memo[cur].second;
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> score[i];
    memo.push_back(make_pair(-1, -1));
  }

  if (n > 1)
  {
    memo[n - 2].first = 0;
    memo[n - 2].second = score[n - 1];
  }
  if (n > 2)
  {
    memo[n - 3].first = score[n - 1];
    memo[n - 3].second = score[n - 1];
  }

  cout << max(dp(-2, 0), dp(-2, 1));
}