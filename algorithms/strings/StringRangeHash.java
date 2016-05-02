public class StringRangeHash {
    private long[] hasharray;
    private static final long mul = 1637;
    private static final long mod = 1000000007;
    public StringRangeHash(String s, long seed) {
        hasharray = new long[s.length() + 1];
        hasharray[0] = seed;
        for (int i = 0, j = 1; i < s.length(); ++i, ++j) {
            hasharray[j] = mod_app(hasharray[i] * mul + (long)s.charAt(i));
        }
    }

    public static long mod_app(long x) {
        return (x % mod + mod) % mod;
    }

    public static long mod_pow(long base, long exp) {
        long y = 1;
        while(exp != 0) {
            if (base % 2 == 1)
                y = (y * x) % mod;
            x = (x * x) % mod;
            exp /= 2;
        }
        return y;
    }

    public static long range(int lo, int hi) {
        return mod_app(hasharray[hi] - hasharray[lo] * mod_pow(mul, hi - lo));
    }

}
