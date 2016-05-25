import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

public class ProblemB {
    public void solve() {
        int t = in.nextInt();
        while(t-- > 0) {
            String a = in.next();
            String b = in.next();
            FastStringRangeHash rha = new FastStringRangeHash(a, 0);
            FastStringRangeHash rhb = new FastStringRangeHash(b, 0);
            int m = 0;
            for (int x = 1; x <= a.length() && x <= b.length(); ++x) {
                if (rhb.range(0, x) == rha.range(a.length() - x, a.length())) {
                    m = Math.max(m, x);
                }
            }
            out.println(a + b.substring(m));
        }
    }

    class FastStringRangeHash {
        private int[] hasharray;
        private static final int mul = 101;
        public FastStringRangeHash(String s, int seed) {
            hasharray = new int[s.length() + 1];
            hasharray[0] = seed;
            for (int i = 0, j = 1; i < s.length(); ++i, ++j) {
                hasharray[j] = (int)((long)hasharray[i] * (long)mul + (long)s.charAt(i));
            }

        }

        public int mod_pow(int base, int exp) {
            int ans = 1;
            while(exp != 0) {
                if (exp % 2 == 1)
                    ans = (int)((long)ans * (long)base);
                base = (int)((long)base * (long)base);
                exp /= 2;
            }
            return ans;
        }

        public int range(int lo, int hi) {
            return (int)((long)hasharray[hi] - (long)hasharray[lo] * (long)mod_pow(mul, hi - lo));
        }

    }


    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
            st = new StringTokenizer("");
        }

        String next() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    FastScanner in;
    PrintWriter out;


    public void run() {
        in = new FastScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        solve();
        out.close();
    }


    public static void main(String[] arg) {
        new ProblemB().run();
    }
}

