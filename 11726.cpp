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
vector<int> memo(1000, 0);

int dp(int cur)
{
  if (memo[cur] != 0)
  {
    return memo[cur];
  }
  memo[cur] = (dp(cur - 1) + dp(cur - 2)) % 10007;
  return memo[cur];
}

int main()
{
  cin >> n;

  memo[0] = 1;
  memo[1] = 2;

  cout << dp(n - 1) << endl;
}