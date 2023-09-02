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
vector<vector<long long int>> memo(101, vector<long long int>(10, -1));

long long int dp(int a, int b)
{
  if (memo[a][b] != -1)
    return memo[a][b];
  if (b == 0)
  {
    memo[a][b] = dp(a - 1, 1) % 1000000000;
  }
  else if (b == 9)
  {
    memo[a][b] = dp(a - 1, 8) % 1000000000;
  }
  else
  {
    memo[a][b] = (dp(a - 1, b - 1) + dp(a - 1, b + 1)) % 1000000000;
  }
  return memo[a][b];
}

int main()
{
  cin >> n;

  memo[1][0] = 0;
  for (int i = 1; i < 10; i++)
  {
    memo[1][i] = 1;
  }

  long long int temp = 0;
  for (int i = 0; i < 10; i++)
  {
    temp += dp(n, i);
  }
  cout << temp % 1000000000 << endl;
}

// T(a, b): 현재 수가 b 일때, a 번째 까지 계단수의 개수
// T(a, b) = T(a-1, 8) if b = 9
//           T(a-1, 1) if b = 0
//           T(a-1, b-1) + T(a-1, b+1) if 0 < b < 9
// T(1, 0) = 0, T(1, 9) = T(1,1) = T(1, 2) = ... = T(1, 8) = 1