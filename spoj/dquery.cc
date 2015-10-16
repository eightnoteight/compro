#include <bits/stdc++.h>
using namespace std;
#define builtin_gcd __gcd


static struct IO {
    char tmp[1 << 10];
    // fast input routines
    char cur;

    // #define nextChar() (cur = getc_unlocked(stdin))
    // #define peekChar() (cur)
    inline char nextChar() {
        return cur = getc_unlocked(stdin);
    }
    inline char peekChar() {
        return cur;
    }

    inline operator bool() {
        return peekChar();
    }
    inline static bool isBlank(char c) {
        return (c < '-' && c > 0);
    }
    inline bool skipBlanks() {
        while (isBlank(nextChar()));
        return peekChar() > 0;
    }

    inline IO& operator >> (char & c) {
        c = nextChar();
        return *this;
    }

    inline IO& operator >> (char * buf) {
        if (skipBlanks()) {
            if (peekChar()) {
                *(buf++) = peekChar();
                while (!isBlank(nextChar()))
                    *(buf++) = peekChar();
            }
            *(buf++) = 0;
        }
        return *this;
    }

    inline IO& operator >> (string & s) {
        if (skipBlanks()) {
            s.clear();
            s += peekChar();
            while (!isBlank(nextChar()))
                s += peekChar();
        }
        return *this;
    }

    inline IO& operator >> (double & d) {
        if ((*this) >> tmp)
            sscanf(tmp, "%lf", &d);
        return *this;
    }

    #define defineInFor(intType) \
        inline IO& operator >>(intType & n) { \
            if (skipBlanks()) { \
                int sign = +1; \
                if (peekChar() == '-') { \
                    sign = -1; \
                    n = nextChar() - '0'; \
                } else \
                    n = peekChar() - '0'; \
                while (!isBlank(nextChar())) { \
                    n += n + (n << 3) + peekChar() - 48; \
                } \
                n *= sign; \
            } \
            return *this; \
        }

    defineInFor(int)
    defineInFor(unsigned int)
    defineInFor(long long)

        // fast output routines

        //#define putChar(c) putc_unlocked((c), stdout)
        inline void putChar(char c) {
            putc_unlocked(c, stdout);
        }
        inline IO& operator << (char c) {
            putChar(c);
            return *this;
        }
        inline IO& operator << (const char * s) {
            while (*s) putChar(*s++);
            return *this;
        }

        inline IO& operator << (const string & s) {
            for (int i = 0; i < (int)s.size(); ++i)
                putChar(s[i]);
            return *this;
        }

        char * toString(double d) {
            sprintf(tmp, "%lf%c", d, '\0');
            return tmp;
        }
        inline IO& operator << (double d) {
            return (*this) << toString(d);
        }


    #define defineOutFor(intType) \
        inline char * toString(intType n) { \
            char * p = (tmp + 30); \
            if (n) { \
                bool isNeg = 0; \
                if (n < 0) isNeg = 1, n = -n; \
                while (n) \
                    *--p = (n % 10) + '0', n /= 10; \
                if (isNeg) *--p = '-'; \
            } else *--p = '0'; \
            return p; \
        } \
        inline IO& operator << (intType n) { return (*this) << toString(n); }

    defineOutFor(int)
    defineOutFor(long long)

    #define endl ('\n')
    #define cout __io__
    #define cin __io__

    // dict output
    template<class T, class U>
    inline IO& operator << (map<T, U>& p) {
        (*this) << "{";
        for (typename map<T, U>::iterator it = p.begin(); it != p.end(); it++) {
            (*this) << it->first << ": " << it->second << ", ";
        }
        (*this) << "}";
        return *this;
    }

    // pair input
    template<class T, class U>
    inline IO& operator >> (pair<T, U>& p) {
        (*this) >> p.first >> p.second;
        return *this;
    }
    // pair output
    template<class T, class U>
    inline IO& operator << (pair<T, U>& p) {
        (*this) << '(' << p.first << ", " << p.second << ')';
        return *this;
    }
    // pair input
    template<class T, class U>
    inline IO& operator >> (const pair<T, U>& p) {
        (*this) >> p.first >> p.second;
        return *this;
    }
    // pair output
    template<class T, class U>
    inline IO& operator << (const pair<T, U>& p) {
        (*this) << '(' << p.first << ", " << p.second << ')';
        return *this;
    }
    // vector input
    template<class T>
    inline IO& operator >> (vector<T>& d) {
        for (size_t i = 0; i < d.size(); ++i)
            (*this) >> d[i];
        return *this;
    }
    // vector output
    template<class T>
    inline IO& operator << (vector<T>& d) {
        (*this) << "[";
        for (size_t i = 0; i < d.size(); ++i)
            (*this) << d[i] << ", ";
        (*this) << "]";
        return *this;
    }

} __io__;

bool cmpPairFunc(const pair<int32_t, int32_t>& i, const pair<int32_t, int32_t>& j) {
    return i.second < j.second;
}

template<class T>
class Cumulator {
private:
public:
};

// offline algorithm
void getAnswers(vector<int32_t>& arr, vector<pair<int32_t, int32_t> > queries, map<pair<int32_t, int32_t>, int32_t>& answers) {
    map<int32_t, int32_t> lastPos;
    Cumulator<int32_t> cum(arr.size());
    sort(queries.begin(), queries.end(), cmpPairFunc);
    vector< pair<int32_t, int32_t> >::iterator curQuery = queries.begin();
    for (int32_t i = 0; i < arr.size(); i++) {
        int32_t x = arr[i];
        map<int32_t, int32_t>::iterator it = lastPos.find(x);
        if(it != lastPos.end())
            cum[it->second]++;  // Cumulator Class Operation
        lastPos[x] = i;
        while(curQuery->second - 1 == i){
            answers[*curQuery] = cum.cumulativeSumUpto(curQuery-first);  // Cumulator Class Operation
            curQuery++;
        }
    }
}

int main() {
    int32_t n;
    cin >> n;
    vector<int32_t> arr(n);
    cin >> arr;
    int32_t q;
    cin >> q;
    vector<pair<int32_t, int32_t> > queries(q);
    cin >> queries;
    map<pair<int32_t, int32_t>, int32_t> answers;
    getAnswers(arr, queries, answers);
    cout << queries << endl << answers << endl;
    return 0;
}
