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

vector<int> seq(500000, INT_MAX);
vector<int> ms(500000);

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
    scanf("%d", &ms[i]);
  }
  sort(seq.begin(), seq.end());

  for (int i = 0; i < m; i++)
  {
    int st = 0;
    int en = n;
    int md;
    int lower, upper;
    while (st < en)
    {
      md = (st + en) / 2;
      if (seq[md] >= ms[i])
      {
        en = md;
      }
      else
      {
        st = md + 1;
      }
    }
    lower = st;
    st = 0;
    en = n;
    while (st < en)
    {
      md = (st + en) / 2;
      if (seq[md] > ms[i])
      {
        en = md;
      }
      else
      {
        st = md + 1;
      }
    }
    upper = st;
    printf("%d ", upper - lower);
  }
}