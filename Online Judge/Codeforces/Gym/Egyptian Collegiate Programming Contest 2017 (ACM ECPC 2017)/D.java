import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Conf_Java_Badry {
	static class UnionFind {
	int [] p;
	 int[] rank;
	    UnionFind(int N) { 
	    	rank=new int [N];
	        p=new int [N]; for (int i = 0; i < N; i++) p[i] = i; }
	    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	    boolean isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	    void unionSet(int i, int j) {
	        if (!isSameSet(i, j)) {
	            int x = findSet(i), y = findSet(j);
	            if (rank[x] > rank[y]) p[y] = x;
	            else { p[x] = y;
	                if (rank[x] == rank[y]) rank[y]++; }
	        } } };
	static int f [];
	static int val [];
	static int h=0;
	static int n;
	static long ans=0;
	static final int MAX=1000_00+1;
	public static void main(String[] args)throws Exception {
		Scanner sc = new Scanner("dream.in");
		PrintWriter out = new PrintWriter(System.out);
	int T=sc.nextInt();
	    for (int c=1;c<=T;c++){
	        f=new int [MAX];
	        val=new int [MAX];
	        Arrays.fill(val, -1);
	        ans=0;
	        n=sc.nextInt();
	        int x;
	        for (int i=0;i<n;i++){
	            x=sc.nextInt();
	            if (f[x]>0)ans+=x;
	            f[x]++;
	        }
	        h=0;
	        for (int i=1;i<MAX;i++){
	            if (f[i]>0)val[i]=h++;
	        }
	        UnionFind dsu=new UnionFind (h);
	        for (int i=MAX-1;i>0;i--){
	            int last=-1;
	            for (int j=i;j<MAX;j+=i){
	                if (f[j]==0)continue;
	                int v=val[j];
	                if (last==-1){
	                    last=v;
	                    continue;
	                }
	                if (!dsu.isSameSet(v,last)){
	                    dsu.unionSet(v,last);
	                    ans+=i;
	                }
	                last=v;
	            }
	        }
	        out.printf("Case %d: %d\n",c,ans);
	    }
	    out.flush();
	    out.close();
	}
	
}
class Scanner 
{
	StringTokenizer st;
	BufferedReader br;

	public Scanner(InputStream s){	br = new BufferedReader(new InputStreamReader(s));}

	public Scanner(String s) throws FileNotFoundException{	br = new BufferedReader(new FileReader(s));}

	public String next() throws IOException 
	{
		while (st == null || !st.hasMoreTokens()) 
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	public int nextInt() throws IOException {return Integer.parseInt(next());}

	public long nextLong() throws IOException {return Long.parseLong(next());}

	public String nextLine() throws IOException {return br.readLine();}

	public double nextDouble() throws IOException { return Double.parseDouble(next()); }

	public boolean ready() throws IOException {return br.ready();} 
}


