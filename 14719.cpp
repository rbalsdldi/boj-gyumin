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

int h, w;

vector<int> hs(500);

int solve()
{
  int cnt = 0;
  for (int i = 1; i < h + 1; i++)
  {
    int temp = 0;
    bool flag = false;
    for (int j = 0; j < w; j++)
    {
      if (flag)
      {
        if (hs[j] >= i)
        {
          cnt += temp;
          temp = 0;
        }
        else
        {
          temp++;
        }
      }
      else
      {
        if (hs[j] >= i)
        {
          flag = true;
        }
      }
    }
  }
  return cnt;
}

int main()
{
  cin >> h >> w;
  for (int i = 0; i < w; i++)
  {
    cin >> hs[i];
  }

  cout << solve() << endl;
}