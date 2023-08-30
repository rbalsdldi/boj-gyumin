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

int n, m, a, b, temp;
int memo[100001];

int main()
{
  cin >> n >> m;
  memo[0] = 0;
  for (int i = 1; i < n + 1; i++)
  {
    scanf("%d", &temp);
    memo[i] = memo[i - 1] + temp;
  }
  for (int i = 0; i < m; i++)
  {
    scanf("%d %d", &a, &b);
    printf("%d\n", memo[b] - memo[a - 1]);
  }
}
