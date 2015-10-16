#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <algorithm>
#include <climits>


#include <inttypes.h>
template<typename INT>
INT binary_gcd(INT  u, INT  v)
{
  INT shl = 0;

  while ( u>0 && v>0 && u!=v ) {
    // even numbers?
    bool eu = (u & 1) == 0;
    bool ev = (v & 1) == 0;

    if ( eu && ev ) {
      ++shl;
      u /= 2;
      v /= 2;
    }
    else if ( eu && !ev ) u /= 2;
    else if ( !eu && ev ) v /= 2;
    else if ( u>=v ) u = (u-v)/2;
    else {
      INT tmp = u;
      u = (v-u)/2;
      v = tmp;
    }
  }

  return u==0? v<<shl : u<<shl;
}
template<typename INT = uint64_t, size_t PRIMES = 1000000>
class prime_sieve
{
public:
  std::bitset<PRIMES> p;
  std::vector<INT> v;

  prime_sieve()
  {
    rebuild();
  }

  void rebuild()
  {
    p.reset();
    p.flip();

    p[0] = p[1] = 1;

    for ( size_t n=2; n < PRIMES; ++n )
      if ( p[n] ) {
        v.push_back(n);

        for ( size_t m=n<<1; m < PRIMES; m += n )
          p[m] = 0;
      }
  }

  inline bool isprime(const INT& n) const
  {
    return p[static_cast<size_t>(n)];
  }

  inline bool isprime_safe(const INT& n) const
  {
    return p.at(static_cast<size_t>(n));
  }

  inline size_t size() const
  {
    return v.size();
  }

  inline typename std::vector<INT>::const_iterator first() const
  {
    return v.begin();
  }

  inline typename std::vector<INT>::const_iterator last() const
  {
    return v.end();
  }

  inline typename std::vector<INT>::const_iterator find(const INT& n) const
  {
    return std::equal_range(v.begin(), v.end(), n).second;
  }
};

template<typename INT>
static bool less(const INT& n, const size_t& primes)
{
  return sizeof(n) < sizeof(size_t)?
    static_cast<size_t>(n) <= primes :
    n <= static_cast<INT>(primes);
}

template<size_t PRIMES, typename INT>
INT phi(const INT& n)
{
  static prime_sieve<INT, PRIMES> primes;

  // Negative numbers
  if ( n < 0 )
    return phi<PRIMES, INT>(-n);

  // By definition
  if ( n == 1 )
    return 1;

  // Base case
  if ( n < 2 )
    return 0;

  // Lehmer's conjecture
  if ( less(n, primes.size()) && primes.isprime(n) )
    return n-1;

  // Even number?
  if ( (n & 1) == 0 ) {
    INT m = n / 2;
    return (m & 1) == 0 ?
      2*phi<PRIMES, INT>(m)
      : phi<PRIMES, INT>(m);
  }

  // For all primes less than n ...
  const INT sqrt_n = 1+sqrt(n);
  for ( typename std::vector<INT>::const_iterator p = primes.first();
        p != primes.last() && *p <= sqrt_n; ++p )
  {
    INT m = *p;

    // Is m not a factor?
    if ( (n % m) != 0 )
      continue;

    // Phi is multiplicative
    INT o = n/m;
    INT d = binary_gcd<INT>(m, o);

    return d==1?
        phi<PRIMES, INT>(m) * phi<PRIMES, INT>(o)
      : phi<PRIMES, INT>(m) * phi<PRIMES, INT>(o) * d / phi<PRIMES, INT>(d);
  }

  // Find out if n is really prime
  INT p;
  for ( p=2+*(primes.last()-1); p < n && (n % p) != 0; p += 2 )
    ; // loop

  // If n is prime, use Lehmer's conjecture
  if ( p >= n )
    return n-1;

  // n must be composite, so divide up and recurse
  INT o = n/p;
  INT d = binary_gcd<INT>(p, o);

  return d==1?
      phi<PRIMES, INT>(p) * phi<PRIMES, INT>(o)
    : phi<PRIMES, INT>(p) * phi<PRIMES, INT>(o) * d / phi<PRIMES, INT>(d);
}


 
inline int get_int(int n=0)
{   
    int sign=1;
    char c=0;
    while(c<33)
        c=getchar_unlocked();
    if (c=='-')
    {
        sign=-1;
        c=getchar_unlocked();                                                
    }
    while(c>='0'&&c<='9')
    {
        n=(n<<3)+(n<<1)+(c-'0');
        c=getchar_unlocked();                                                        
    }
return n*sign;
}

int main(int argc, const char *argv[])
{
    int n;
    n = get_int();
    int t = 0;
    int ans[100001];
    ans[0] = 0;
    for (int i = 1; i < 100001; i++) {
        /* code */
        int tmp = phi<100001>(i);
        t += i - tmp;
        ans[i] = t;
    }
    for (int i = 0; i < n; i++) {
        /* code */
        int k = get_int();
        printf("Case %d: %d\n", i + 1, ans[k]);
    }
    return 0;
}
