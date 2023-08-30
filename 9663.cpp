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
int v_check = 0;
int dr_check = 0;
int dl_check = 0;

int cnt = 0;

bool check_cell(int r, int c)
{
  if ((v_check & 1 << c) ||
      (dr_check & 1 << r + c) ||
      (dl_check & 1 << r - c + n - 1))
  {
    return false;
  }
  return true;
}

void backtrack(int r)
{
  if (r == n)
  {
    cnt++;
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (!check_cell(r, i))
      continue;
    v_check |= 1 << i;
    dr_check |= 1 << r + i;
    dl_check |= 1 << r - i + n - 1;
    backtrack(r + 1);
    v_check &= ~(1 << i);
    dr_check &= ~(1 << r + i);
    dl_check &= ~(1 << r - i + n - 1);
  }
}

int main()
{
  cin >> n;

  backtrack(0);
  cout << cnt << endl;
}