public class FastStringRangeHash {
    private long[] hasharray;
    private static final long mul = 101;
    public FastStringRangeHash(String s, long seed) {
        hasharray = new long[s.length() + 1];
        hasharray[0] = seed;
        for (int i = 0, j = 1; i < s.length(); ++i, ++j) {
            hasharray[j] = hasharray[i] * mul + (long)s.charAt(i);
        }
    }

    public static long mod_pow(long base, long exp) {
        long y = 1;
        while(exp != 0) {
            if (base % 2 == 1)
                y *= x;
            x *= x;
            exp /= 2;
        }
        return y;
    }

    public static long range(int lo, int hi) {
        return hasharray[hi] - hasharray[lo] * mod_pow(mul, hi - lo);
    }

}
