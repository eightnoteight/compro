import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

class mmsum {
    public void solve() {
        int t = in.nextInt();
        while(t-- > 0) {
            int n = in.nextInt();
            long[] arr = new long[n];
            long[] arrps = new long[n];
            boolean posflag = false;
            for (int i = 0; i < arr.length; ++i) {
                arr[i] = in.nextLong();
                if (arr[i] > 0)
                    posflag = true;
            }
            LongSummaryStatistics arrstat = Arrays.stream(arr).summaryStatistics();
            if (!posflag || arr.length == 1) {
                out.println(arrstat.getMax());
                continue;
            }
            // TODO: handle if all nums are negative, handle for size 1
            // handle answer no element removed.
            arrps[0] = arr[0];
            for (int i = 1; i < arrps.length; ++i) {
                arrps[i] = arr[i] + arrps[i - 1];
            }
            long[] leftsegs = new long[n];
            long minarrps = 0;
            for (int i = 0; i < arrps.length; ++i) {
                minarrps = Math.min(arrps[i], minarrps);
                leftsegs[i] = arrps[i] - minarrps;
            }
            long[] rightsegs = new long[n];
            long maxarrps = arrps[n - 1];
            for (int i = n - 1; i >= 0; --i) {
                maxarrps = Math.max(arrps[i], maxarrps);
                rightsegs[i] = maxarrps - arrps[i];
            }
            long answer = Math.max(maxarrps,
                              Math.max(rightsegs[0],
                                  Math.max(leftsegs[n - 1], arrps[n - 1])));
            for (int i = 1; i < arr.length; ++i) {
                answer = Math.max(answer,
                             Math.max(leftsegs[i] + rightsegs[i],
                                 leftsegs[i - 1] + rightsegs[i]));
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
        new mmsum().run();
    }
}

