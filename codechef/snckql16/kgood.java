import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

class kgood {
    public void solve() {
        int t = in.nextInt();
        while(t-- > 0) {
            String w = in.next();
            int k = in.nextInt();
            int[] counter = new int[26];
            for (char x: w.toCharArray()) {
                ++counter[x - 'a'];
            }
            int answer = Integer.MAX_VALUE;
            for (int x = 0; x < 26; ++x) {
                int mval = counter[x];
                int loca = 0;
                for (int y = 0; y < 26; ++y) {
                    if (counter[y] < mval)
                        loca += counter[y];
                    else if (counter[y] > mval + k)
                        loca += counter[y] - mval - k;
                }
                answer = Math.min(loca, answer);
            }
            out.println(answer);
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
        new kgood().run();
    }
}

