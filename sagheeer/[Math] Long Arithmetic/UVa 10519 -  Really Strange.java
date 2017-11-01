import java.util.Scanner;
import java.math.BigInteger;

class Main {

	public static void main(String[] args)  {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) {
			BigInteger xx = new BigInteger(sc.next());
			if (xx.equals(BigInteger.ZERO)) {
				System.out.println(1);
			} else {
				BigInteger ret = xx.multiply(xx.subtract(BigInteger.ONE)).add(BigInteger.valueOf(2));
				System.out.println(ret);
			}
		}
	}

}
