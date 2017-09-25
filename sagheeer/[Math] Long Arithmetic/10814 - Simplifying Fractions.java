import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Hello {
	public static void main(String[] args) throws Throwable {
		MyScanner sc = new MyScanner();
		PrintWriter pw = new PrintWriter(System.out);
		int t = sc.nextInt();
		while (t != 0) {
			t--;
			String a = sc.next();
			BigInteger b1 = new BigInteger(a);
			String b = sc.next();
			b = sc.next();
			BigInteger b2 = new BigInteger(b);
			BigInteger b3 = b1.gcd(b2);
			pw.print(b1.divide(b3));
			pw.print(" / ");
			pw.print(b2.divide(b3));
			pw.print("\n");
		}

		pw.flush();
		pw.close();
		// System.out.print("Hello jave");
	}

	static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
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
}
