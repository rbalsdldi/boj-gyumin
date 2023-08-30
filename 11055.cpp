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
vector<int> ns(1000, 0);

vector<int> memo(1000, 0);

int max_sum = 0;

void dp(int k)
{
  if (memo[k] == 0)
  {
    for (int i = 0; i < k; i++)
    {
      dp(i);
    }
    int temp = 0;
    for (int i = 0; i < k; i++)
    {
      if (ns[i] >= ns[k])
        continue;
      temp = max(temp, memo[i]);
    }
    memo[k] = temp + 1;
  }
  max_sum = max(max_sum, memo[k]);
}

int main()
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> ns[i];
  }

  memo[0] = 1;
  dp(n - 1);
  cout << max_sum << endl;
}