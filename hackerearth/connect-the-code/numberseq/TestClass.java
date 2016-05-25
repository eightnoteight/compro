import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

public class TestClass {
    public void solve() {
        int n = in.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = in.nextInt();
        }
        for (int i = 0; i < n; ++i) {
            arr[i] *= i + 1;
        }
        for (int i = n - 1; i > 0; --i) {
            arr[i] -= arr[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            out.print(arr[i] + " ");
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
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
        new TestClass().run();
    }
}
