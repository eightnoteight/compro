import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

public class DynamicArray {
    public void solve() {
        int n = in.nextInt();
        int q = in.nextInt();
        int lastans = 0;
        ArrayList<ArrayList<Integer>> nseqs = new ArrayList<ArrayList<Integer>>(n);
        for (int i = 0; i < n; ++i) {
            nseqs.add(new ArrayList<Integer>());
        }
        for (int i = 0; i < q; ++i) {
            int qtype = in.nextInt();
            int x = in.nextInt();
            int y = in.nextInt();
            if (qtype == 1) {
                nseqs.get((x ^ lastans) % n).add(y);
            }
            else {
                ArrayList<Integer> seqref = nseqs.get((x ^ lastans) % n);
                lastans = seqref.get(y % seqref.size());
                out.println(lastans);
            }
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
        new DynamicArray().run();
    }
}

