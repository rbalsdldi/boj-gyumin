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

int t;

vector<int> ns;

vector<long long int> memo(101, 0);

long long int dp(int n)
{
  if (memo[n] == 0)
  {
    memo[n] = dp(n - 1) + dp(n - 5);
  }
  return memo[n];
}

int main()
{
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int temp;
    cin >> temp;
    ns.push_back(temp);
  }

  memo[1] = 1;
  memo[2] = 1;
  memo[3] = 1;
  memo[4] = 2;
  memo[5] = 2;

  for (auto i : ns)
  {
    cout << dp(i) << endl;
  }
}