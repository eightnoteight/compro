import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

class kttable {
    public void solve() {
        int t = in.nextInt();
        while (t-- > 0) {
            int n = in.nextInt();
            int[] arra = new int[n];
            int[] arrb = new int[n];
            for (int i = 0; i < n; ++i) {
                arra[i] = in.nextInt();
            }
            for (int i = 0; i < n; ++i) {
                arrb[i] = in.nextInt();
            }
            int count = (arra[0] >= arrb[0])?1:0;
            for (int i = 1; i < n; ++i) {
                if (arra[i] - arra[i - 1] >= arrb[i])
                    count++;
            }
            out.println(count);
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
        new kttable().run();
    }
}

