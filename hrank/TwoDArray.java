import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

public class TwoDArray {
    public void solve() {
        int[][] arr = new int[6][6];
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                arr[i][j] = in.nextInt();
            }
        }
        int ans = 0;
        for (int i = 1; i < 5; ++i) {
            for (int j = 1; j < 5; ++j) {
                ans = Math.max(
                    ans, arr[i][j] +
                    arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1] +
                    arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1]);
            }
        }
        out.println(ans);
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
        new TwoDArray().run();
    }
}

