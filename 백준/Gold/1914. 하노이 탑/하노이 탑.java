import java.util.*;
import java.io.*;
import java.math.*;
public class Main{

    static int n;
	 static StringBuilder sb = new StringBuilder();

	    public static void hanoi(int now, int to, int then ,int n){
	        if(n == 1) {
	        	sb.append(Integer.toString(now) + " " + Integer.toString(to) +"\n");
	        	return;
	        }
	        hanoi(now, then, to, n-1);
	        sb.append(Integer.toString(now) + " " + Integer.toString(to) +"\n");
	        hanoi(then, to, now, n-1);
	    }

	    public static void main(String[] args) throws IOException
	    {
	        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
	        n = Integer.parseInt(bf.readLine());
	        BigInteger t = new BigInteger("2");
	        sb.append(t.pow(n).subtract(new BigInteger("1"))+"\n");
	        if(n <= 20) {
	        	hanoi(1, 3, 2, n);
	        }
	        System.out.print(sb.toString());
	    }
}