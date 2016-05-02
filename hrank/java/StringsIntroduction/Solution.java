import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

public class Solution {
    public void solve() {
        String a = in.next();
        String b = in.next();
        out.println(a.length() + b.length());
        if (a.compareTo(b) > 0) {
            out.println("Yes");
        }
        else {
            out.println("No");
        }
        out.println(a.substring(0, 1).toUpperCase() +
                    a.substring(1) + " " +
                    b.substring(0, 1).toUpperCase() +
                    b.substring(1));
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

