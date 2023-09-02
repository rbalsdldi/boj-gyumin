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

int t, n, k;

vector<int> ns(20);

vector<vector<int>> memo(10001, vector<int>(20, -1));

int dp(int a, int b)
{
  if (memo[a][b] != -1)
    return memo[a][b];
  int sum = 0;
  for (int i = b; i < n; i++)
  {
    if (a - ns[i] < 0)
      continue;
    sum += dp(a - ns[i], i);
  }
  memo[a][b] = sum;
  return memo[a][b];
}

int main()
{
  cin >> t;
  for (int i = 0; i < 20; i++)
  {
    memo[0][i] = 1;
  }
  for (int i = 0; i < t; i++)
  {
    cin >> n;
    for (int j = 0; j < n; j++)
    {
      cin >> ns[j];
    }
    cin >> k;
    auto temp = memo;
    cout << dp(k, 0) << endl;
    memo = temp;
  }
}

// T(a, b) = T(a-ns[b], b) + T(a-ns[b+1], b+1) + ... + T(a-ns[n], n)