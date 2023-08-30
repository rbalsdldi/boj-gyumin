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

vector<vector<long long int>> memo(91, {-1, -1});

long long int dp(int k, int last)
{
  if (memo[k][last] == -1)
  {
    if (last == 0)
    {
      memo[k][last] = dp(k - 1, 0) + dp(k - 1, 1);
    }
    else if (last == 1)
    {
      memo[k][last] = dp(k - 1, 0);
    }
  }
  return memo[k][last];
}

int main()
{
  cin >> n;
  memo[1][0] = 1;
  memo[1][1] = 0;

  cout << dp(n, 0) << endl;
}