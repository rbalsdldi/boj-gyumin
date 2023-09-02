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

int n, m;

vector<bool> ms(41, false);

// 0 for +1, 1 for 0, 2 for -1
vector<vector<int>> memo(41, vector<int>(3, -1));

int dp(int a, int b)
{
  if (memo[a][b] != -1)
    return memo[a][b];
  if (ms[a])
  {
    memo[a][b] = dp(a - 1, 1);
  }
  else if (b == 2)
  {
    memo[a][b] = dp(a - 1, 0);
  }
  else
  {
    if (ms[a - 1])
    {
      memo[a][b] = dp(a - 1, 1);
    }
    else
    {
      memo[a][b] = dp(a - 1, 2) + dp(a - 1, 1);
    }
  }
  return memo[a][b];
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int temp;
    cin >> temp;
    ms[temp] = true;
  }

  memo[1][0] = memo[1][1] = memo[1][2] = 1;

  cout << dp(n, 1) << endl;
}

// T(a, b) = T(a-1, 2) + T(a-1, 1) if b = 0
//           T(a-1, 2) + T(a-1, 1) if b = 1
//           T(a-1, 0) if b = 2