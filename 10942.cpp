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

vector<int> seq(2000);

vector<vector<int>> memo(2000, vector<int>(2000, -1));

int dp(int s, int e)
{
  if (memo[s][e] != -1)
    return memo[s][e];
  if (seq[s] != seq[e])
  {
    memo[s][e] = 0;
  }
  else
  {
    if (e - s > 1)
    {
      memo[s][e] = dp(s + 1, e - 1);
    }
    else
    {
      memo[s][e] = 1;
    }
  }
  return memo[s][e];
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &seq[i]);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++)
  {
    int s, e;
    scanf("%d %d", &s, &e);
    printf("%d\n", dp(s - 1, e - 1));
  }
}