import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

public class Solution {
    public void solve() {
        int n = in.nextInt();
        if (n % 2 == 1 || (n % 2 == 0 && n >= 6 && n <= 20)) {
            out.println("Weird");
        }
        else {
            out.println("Not Weird");
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
        new Solution().run();
    }
}

