import java.io.*;
import java.util.*;
import java.text.DecimalFormat;
import java.util.function.Predicate;
import java.lang.reflect.Method;

public class ImagePreview {
    public interface BsearchPredicate {
        public boolean run(int x);
    }
    public static int bsearch(int lo, int hi, BsearchPredicate check) {
        while (lo < hi) {
            int mid = lo + ((hi - lo) / 2);
            if (check.run(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    public void solve() {
        int n = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();
        int t = in.nextInt();
        String s = in.next();
        int startCost = 0;
        if (s.charAt(0) == 'w') {
            startCost += b + 1;
        }
        else {
            startCost += 1;
        }
        if (startCost > t) {
            out.println(0);
            return;
        }
        String forward = s.substring(1);
        String bacward = (new StringBuffer(s.substring(1))).reverse().toString();
        int[] forwardCosts = new int[forward.length()];
        int[] bacwardCosts = new int[bacward.length()];
        if (forward.charAt(0) == 'w') {
            forwardCosts[0] = a + b + 1;
        }
        else {
            forwardCosts[0] = a + 1;
        }
        if (bacward.charAt(0) == 'w') {
            bacwardCosts[0] = a + b + 1;
        }
        else {
            bacwardCosts[0] = a + 1;
        }
        for (int i = 1; i < forward.length(); ++i) {
            if (forward.charAt(i) == 'w') {
                forwardCosts[i] = forwardCosts[i - 1] + a + b + 1;
            }
            else {
                forwardCosts[i] = forwardCosts[i - 1] + a + 1;
            }
        }
        for (int i = 1; i < bacward.length(); ++i) {
            if (bacward.charAt(i) == 'w') {
                bacwardCosts[i] = bacwardCosts[i - 1] + a + b + 1;
            }
            else {
                bacwardCosts[i] = bacwardCosts[i - 1] + a + 1;
            }
        }
        int t1 = t - startCost;
        int curCount = bsearch(0, bacward.length(), x -> bacwardCosts[x] > t1);
        for (int i = 0; i < forward.length(); ++i) {
            if (forwardCosts[i] > t1) {
                continue;
            }
            int c = t1 - forwardCosts[i] - (i + 1) * a;
            int k = bsearch(0, bacward.length(), x -> bacwardCosts[x] > c);
            curCount = Math.min(n - 1, Math.max(curCount, i + 1 + k));
        }
        for (int i = 0; i < bacward.length(); ++i) {
            if (bacwardCosts[i] > t1) {
                continue;
            }
            int c = t1 - bacwardCosts[i] - (i + 1) * a;
            int k = bsearch(0, forward.length(), x -> forwardCosts[x] > c);
            curCount = Math.min(n - 1, Math.max(curCount, i + 1 + k));
        }
        out.println(curCount + 1);
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
        new ImagePreview().run();
    }
}

