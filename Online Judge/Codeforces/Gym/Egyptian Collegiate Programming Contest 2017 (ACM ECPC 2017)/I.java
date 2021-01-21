import java.io.*;
import java.util.*;


public class ThraxJudge {
    static int[][][] qsum = new int[201][201][4001];
    static int N, M, V;

    public static int getMedian(int A, int B, int C, int D) {
        int low, high;
        int cnt = (D - B + 1) * (C - A + 1);
        int cnt2 = cnt / 2;
        for (low = 0, high = V + 1; low + 1 < high; ) {
            int mid = (low + high) >> 1;
            if (rangeQuery(mid, A, B, C, D) <= cnt2) {
                low = mid;
            } else {
                high = mid;
            }
        }
        assert(low <= V);
        return low;
    }

    public static int rangeQuery(int v, int x1, int y1, int x2, int y2) {
        return query(v, x2, y2) + query(v, x1 - 1, y1 - 1) - query(v, x1 - 1, y2) - query(v, x2, y1 - 1);
    }

    public static int query(int v, int x, int y) {
        int res = 0;
        for (int vi = v; vi > 0; vi -= vi & -vi) {
            for (int xi = x; xi > 0; xi -= xi & -xi) {
                for (int yi = y; yi > 0; yi -= yi & -yi) {
                    res += qsum[yi][xi][vi];
                }
            }
        }
        return res;
    }
    public static void update(int val, int v, int x, int y) {
        for (int vi = v; vi <= V; vi += vi & -vi) {
            for (int xi = x; xi <= N; xi += xi & -xi) {
                for (int yi = y; yi <= M; yi += yi & -yi) {
                    qsum[yi][xi][vi] += val;
                }
            }
        }
    }

    public static void remove(int v, int x, int y) {
        update(-1, v, x, y);
    }

    public static void insert(int v, int x, int y) {
        update(1, v, x, y);
    }

    public static void main(String[] args) throws IOException {
        final Scanner sc = new Scanner();
        int T = sc.nextInt();

        PrintWriter out = new PrintWriter(System.out);
        for (int kase = 1; kase <= T; ++kase) {
            out.println("Case " + kase + ":");
            N = sc.nextInt();
            M = sc.nextInt();
            int Q = sc.nextInt();
            int[][] X = new int[N][M];
            assert(N <= 400 && M <= 400 && Q <= 100000);
            boolean[] unique = new boolean[2001];
            //final HashSet<Integer> unique = new HashSet<>();
            final ArrayList<Integer> rank = new ArrayList<>();
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    X[i][j] = sc.nextInt();
                    if (!unique[X[i][j]]) {
                        rank.add(X[i][j]);
                        unique[X[i][j]] = true;
                    }
                }
            }
            Integer[] ranks = rank.toArray(new Integer[]{});
            Arrays.sort(ranks);
            //final HashMap<Integer, Integer> rank_of = new HashMap<>();
            final int[] rank_of = new int[2500];
            for (int i = 0; i < ranks.length; ++i) {
                rank_of[ranks[i]] = i + 1;
            }
            V = ranks.length;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    insert(rank_of[X[i][j]], i + 1, j + 1);
                }
            }

            
            for (int i = 0; i < Q; ++i) {
                int A = sc.nextInt();
                int B = sc.nextInt();
                int C = sc.nextInt();
                int D = sc.nextInt();
                int r = getMedian(A, B, C, D);
                out.println(ranks[r]);
            }

            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    remove(rank_of[X[i][j]], i + 1, j + 1);
                }
            }
        }
        out.flush();
        out.close();
    }

    static class Scanner {
        final BufferedReader br;
        StringTokenizer tokens;
        public Scanner() throws IOException, FileNotFoundException {
            br = new BufferedReader(new FileReader("important.in"));
            tokens = new StringTokenizer("");
        }

        public void checkNext() throws IOException {
            if (!tokens.hasMoreTokens()) {
                tokens = new StringTokenizer(br.readLine());
            }
        }
        public int nextInt() throws IOException {
            checkNext();
            return Integer.parseInt(next());
        }
        public double nextDouble() throws IOException {
            checkNext();
            return Double.parseDouble(next());
        }
        public String next() throws IOException {
            checkNext();
            return tokens.nextToken();
        }
    }
}

