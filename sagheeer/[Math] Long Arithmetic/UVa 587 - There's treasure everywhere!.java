import java.io.*;
import java.util.*;
import java.math.BigInteger;

class A {

	public static void main(String[] args)  {
		MyScanner sc=new MyScanner();
		PrintWriter pw=new PrintWriter(System.out);
		int t = sc.nextInt();
		while(t-- > 0) {
			String a = sc.next();
			StringBuffer nc = new StringBuffer(a);
			a = nc.reverse().toString();

			//System.out.println(a);

			String b = sc.next();
			StringBuffer bc = new StringBuffer(b);
			b = bc.reverse().toString();

			//System.out.println(b);

			BigInteger xx = new BigInteger(a).add(new BigInteger(b));

			String ret = xx.toString();
			StringBuffer cret = new StringBuffer(ret);

			pw.println(new BigInteger(cret.reverse().toString()));
		}
	}

	static class MyScanner {
		BufferedReader br;
		StringTokenizer st;
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {while (st == null || !st.hasMoreElements()) {
			try {st = new StringTokenizer(br.readLine());}
			catch (IOException e) {e.printStackTrace();}}
		return st.nextToken();}
		int nextInt() {return Integer.parseInt(next());}
		long nextLong() {return Long.parseLong(next());}
		double nextDouble() {return Double.parseDouble(next());}
		String nextLine(){String str = "";
		try {str = br.readLine();}
		catch (IOException e) {e.printStackTrace();}
		return str;}
	}

}
