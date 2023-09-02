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

vector<int> ns(10001);

// 0 for 00, 1 for 10, 2 for 11
vector<vector<int>> memo(10001, vector<int>(3, -1));

int dp(int a, int b)
{
  if (memo[a][b] != -1)
    return memo[a][b];
  if (b == 2)
  {
    memo[a][b] = dp(a - 1, 0);
  }
  else if (b == 1)
  {
    memo[a][b] = max(dp(a - 1, 0), dp(a - 1, 2) + ns[a]);
  }
  else if (b == 0)
  {
    memo[a][b] = max(dp(a - 1, 0), dp(a - 1, 1) + ns[a]);
  }
  return memo[a][b];
}

int main()
{
  cin >> n;
  for (int i = 1; i < n + 1; i++)
  {
    cin >> ns[i];
  }

  memo[1][0] = ns[1];
  memo[1][1] = ns[1];
  memo[1][2] = 0;

  cout << dp(n, 0) << endl;
}

// T(a, b) = T(a-1, 0) if b = 2
//           max(T(a-1, 0), T(a-1, 2) + ns[a]) if b = 1
//           max(T(a-1, 0), T(a-1, 1) + ns[a]) if b = 0
// T(1, 0) = ns[1], T(1, 1) = ns[1], T(1, 2) = 0
