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

vector<int> memo(1001, -1);

int dp(int k)
{
  if (memo[k] == -1)
  {
    memo[k] = (dp(k - 1) + dp(k - 2) * 2) % 10007;
  }
  return memo[k];
}

int main()
{
  cin >> n;
  memo[1] = 1;
  memo[2] = 3;

  cout << dp(n) << endl;
}