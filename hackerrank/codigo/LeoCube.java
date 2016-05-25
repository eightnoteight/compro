import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

public class LeoCube {
    public void solve() {
        int a = in.nextInt();
        int b = in.nextInt();
        if (b < a) {
            int t = a;
            a = b;
            b = t;
        }
        int avg = 0;
        int cnt = 0;
        for (int i = 1; i < 22; ++i) {
            int cube = i * i * i;
            if (cube <= b && cube >= a) {
                avg += cube;
                cnt += 1;
            }
        }
        out.println((avg / (double)cnt) + "");
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
        new LeoCube().run();
    }
}

