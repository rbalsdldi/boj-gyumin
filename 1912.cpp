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

vector<int> ns;
vector<int> memo;

int max_s = INT_MIN;

void dp(int k)
{
  if (memo[k] == INT_MIN)
  {
    dp(k - 1);
    memo[k] = max({memo[k - 1] + ns[k], ns[k]});
  }
  max_s = max(max_s, memo[k]);
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    ns.push_back(temp);
    memo.push_back(INT_MIN);
  }

  memo[0] = ns[0];
  dp(n - 1);
  cout << max_s << endl;
}