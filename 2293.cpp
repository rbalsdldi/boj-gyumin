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

int n, k;

vector<int> coins(100);

vector<int> memo(10001);

int main()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }

  memo[0] = 1;

  for (int i = 0; i < n; i++)
  {
    for (int j = coins[i]; j < k + 1; j++)
    {
      memo[j] += memo[j - coins[i]];
    }
  }

  cout << memo[k] << endl;
}