import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.Arrays;

public class StringQueriesKhalidJudge {

    static class Query implements Comparable<Query> {
        int left, right, idx;

        public Query(int l, int r, int i) {
            left = l;
            right = r;
            idx = i;
        }

        public int compareTo(Query q) {
            return left < q.left ? -1 : left > q.left ? 1 : right < q.right ? -1 :
                    right > q.right ? 1 : idx < q.idx ? -1 : idx > q.idx ? 1 : 0;
        }

        public String toString() {
            return left + " " + right;
        }
    }

    //static class SegmentTree {
        static int N;
        static long vals[];
        static long tree[];
        static long lazy[];

        /*public SegmentTree(long arr[]) {
            vals = arr.clone();
            nearest(vals.length);
            tree = new long[N << 1];
            lazy = new long[N << 1];
            buildRSQ(1, 0, N - 1, vals.length);
        }*/

        static void nearest(int n) {
            N = 1;
            while (N < n)
                N <<= 1;
        }

        static void buildRSQ(int node, int s, int e, int n) {
            if (s > e)
                return;
            if (s == e) {
                tree[node] = s >= n ? 0 : vals[s];
                return;
            }
            int leftNode = node << 1;
            int rightNode = leftNode | 1;
            int mid = s + ((e - s) >> 1);
            buildRSQ(leftNode, s, mid, n);
            buildRSQ(rightNode, mid + 1, e, n);
            tree[node] = tree[leftNode] + tree[rightNode];
        }

        static long RSQ(int s, int e) {
            return RSQquery(1, 0, N - 1, s, e);
        }

        static long RSQquery(int node, int s, int e, int i, int j) {
            if (s > e || s > j || e < i)
                return 0;
            push(node, s, e);
            if (s >= i && e <= j)
                return tree[node];
            int leftNode = node << 1;
            int rightNode = leftNode | 1;
            int mid = s + ((e - s) >> 1);
            long left = RSQquery(leftNode, s, mid, i, j);
            long right = RSQquery(rightNode, mid + 1, e, i, j);
            return left + right;
        }

        static void RSQUpdateRange(int s, int e, int inc) {
            updateRange(1, 0, N - 1, s, e, inc);
        }

        static void updateRange(int node, int s, int e, int i, int j, int inc) {
            if (s > e || s > j || e < i)
                return;
            push(node, s, e);
            if (s >= i && e <= j) {
                lazy[node] += inc;
                push(node, s, e);
                return;
            }
            int leftNode = node << 1;
            int rightNode = leftNode | 1;
            int mid = s + ((e - s) >> 1);
            updateRange(leftNode, s, mid, i, j, inc);
            updateRange(rightNode, mid + 1, e, i, j, inc);
            tree[node] = tree[leftNode] + tree[rightNode];
        }

        static void push(int node, int s, int e) {
            int leftNode = node << 1;
            int rightNode = leftNode | 1;
            if (lazy[node] != 0) {
                tree[node] += lazy[node] * (e - s + 1);
                if (s != e) {
                    lazy[leftNode] += lazy[node];
                    lazy[rightNode] += lazy[node];
                }
                lazy[node] = 0;
            }
        }
    //}


    static final int maxn = 210001;
    static int len[] = new int[maxn], link[] = new int[maxn];
    static HashMap<Character, Integer> to[] = new HashMap[maxn];
    static int size = 0, last;

    static void init() {
        for (int i = 0; i < size; i++) {
            to[i].clear();
            len[i] = link[i] = 0;
        }
        link[0] = -1;
        size = 1;
        last = 0;
    }

    static void addCharacter(Character c) {
        int p = last;
        last = size++;
        len[last] = len[p] + 1;
        for (; p != -1 && !to[p].containsKey(c); p = link[p])
            to[p].put(c, last);
        if (p == -1)
            return;
        int q = to[p].get(c);
        if (len[q] == len[p] + 1) {
            link[last] = q;
            return;
        }
        int cl = size++;
        to[cl].putAll(to[q]);
        link[cl] = link[q];
        len[cl] = len[p] + 1;
        link[last] = link[q] = cl;
        for (; p != -1 && to[p].containsKey(c) && to[p].get(c) == q; p = link[p])
            to[p].put(c, cl);
    }

    public static void main(String[] args) throws NumberFormatException, IOException, FileNotFoundException {
        for (int i = 0; i < maxn; i++)
            to[i] = new HashMap<Character, Integer>();
        BufferedReader bf = new BufferedReader(new FileReader("curse.in"));
        PrintWriter out = new PrintWriter(System.out);
        int T = Integer.parseInt(bf.readLine());
        assert T > 0 : "There is no test cases";
        for (int tc = 1; tc <= T; tc++) {
            String s1 = bf.readLine();
            assert s1 != null : "s1 is null";
            int s1Len = s1.length();
            assert s1Len != 0 : "s1 is empty";
            assert s1Len <= 100000 : "s1 is too long";
            String s2 = bf.readLine();
            assert s2 != null : "s2 is null";
            int s2Len = s2.length();
            assert s2Len != 0 : "s2 is empty";
            assert s2Len <= 100000 : "s2 is too long";
            int Q = Integer.parseInt(bf.readLine());
            assert Q <= 100000 : "Q is too long";
            Query queries[] = new Query[Q];
            for (int i = 0; i < Q; i++) {
                StringTokenizer st = new StringTokenizer(bf.readLine());
                int left = Integer.parseInt(st.nextToken()) - 1;
                assert left > 1 && left <= s1Len : "left is not withing the correct boundaries";
                int right = Integer.parseInt(st.nextToken()) - 1;
                assert right >= left : "right is less than left";
                assert right > 1 && right <= s1Len : "right is not withing the correct boundaries";
                queries[i] = new Query(left, right, i);
            }
            Arrays.sort(queries);

            init();
            for (int i = 0; i < s2Len; i++)
                addCharacter(s2.charAt(i));

            long maxLength[] = new long[s1Len + 1];
            long cnt[] = new long[s1Len + 1];
            int curLen = 0;
            int cur = 0;
            for (int i = 0; i < s1Len; i++) {
                char c = s1.charAt(i);
                while (curLen > 0 && !to[cur].containsKey(c)) {
                    cur = link[cur];
                    curLen = len[cur];
                }
                if (to[cur].containsKey(c)) {
                    curLen++;
                    cur = to[cur].get(c);
                }
                maxLength[i] = curLen;
                cnt[i - curLen + 1]++;
                cnt[i + 1]--;
            }
            for (int i = 1; i < s1Len; i++)
                cnt[i] += cnt[i - 1];

            //SegmentTree st = new SegmentTree(maxLength);
            vals = maxLength.clone();
            nearest(vals.length);
            tree = new long[N << 1];
            lazy = new long[N << 1];
            buildRSQ(1, 0, N - 1, vals.length);

            long output[] = new long[Q];
            int previousLeft = 0;
            for (int i = 0; i < Q; i++) {
                Query currentQuery = queries[i];
                while (previousLeft < currentQuery.left) {
                    if (cnt[previousLeft] > 0)
                        RSQUpdateRange(previousLeft, previousLeft + (int) cnt[previousLeft] - 1, -1);
                    previousLeft++;
                }
                output[currentQuery.idx] = RSQ(currentQuery.left, currentQuery.right);
            }
            out.println("Case " + tc + ":");
            for (int i = 0; i < Q; i++)
                out.println(output[i]);
        }
        out.flush();
        out.close();
    }
}