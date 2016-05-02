import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

public class GoodSubstrings {
    public void solve() {
        String s = in.next();
        String f = in.next();
        int k = in.nextInt();
        int[] arr = new int[s.length()];
        StringRangeHash rhs = new StringRangeHash(s, 0);
        arr[0] = (f.charAt(s.charAt(0) - 'a') == '1') ? 0 : 1;
        for (int i = 1; i < s.length(); ++i) {
            arr[i] = arr[i - 1] + ((f.charAt(s.charAt(i) - 'a') == '1') ? 0 : 1);
        }
        HashSet<Integer> good = new HashSet<Integer>();
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i + 1; j <= s.length(); ++j) {
                if ((i == 0 && arr[j - 1] <= k) || (i != 0 && arr[j - 1] - arr[i - 1] <= k)) {
                    good.add(rhs.range(i, j));
                }
            }
        }
        out.println(good.size());
    }

    class StringRangeHash {
        private int[] hasharray;
        private int[] pmodarray;
        private static final int mul = 101;
        private static final int mod = 1000000007;
        public StringRangeHash(String s, int seed) {
            hasharray = new int[s.length() + 1];
            pmodarray = new int[s.length() + 1];
            hasharray[0] = seed;
            pmodarray[0] = 1;
            for (int i = 0, j = 1; i < s.length(); ++i, ++j) {
                hasharray[j] = mod_app(1L * hasharray[i] * mul + s.charAt(i));
                pmodarray[j] = mod_app(1L * pmodarray[i] * 101);
            }
        }

        int mod_app(long x) {
            return (int)((x % mod + mod) % mod);
        }

        public int range(int lo, int hi) {
            return mod_app(1L * hasharray[hi] + mod_app(-1L * hasharray[lo] * pmodarray[hi - lo]));
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
        new GoodSubstrings().run();
    }
}

