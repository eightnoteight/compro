import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

public class TestClass {
    public void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        UnionFind uf = new UnionFind(n);
        for (int i = 0; i < k; ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            uf.union(a, b);
        }
        out.println(uf.groupCount);
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
        new TestClass().run();
    }
}

class UnionFind {
    public int[] weights;
    public int[] roots;
    public int groupCount;
    public UnionFind(int n) {
        weights = new int[n];
        roots = new int[n];
        for (int i = 0; i < n; ++i) {
            weights[i] = 1;
            roots[i] = i;
        }
        groupCount = n;
    }

    public void union(int a, int b) {
        if (find(a) == find(b)) {
            return;
        }
        int aroot = find(a);
        int broot = find(b);
        if (weights[broot] > weights[aroot]) {
            int tmp = aroot;
            aroot = broot;
            broot = tmp;
        }
        roots[broot] = aroot;
        weights[aroot] += weights[broot];
        weights[broot] = 0;
        groupCount--;
    }

    public int find(int key) {
        while (key != roots[key]) {
            roots[key] = roots[roots[key]];
            key = roots[key];
        }
        return key;
    }
}
