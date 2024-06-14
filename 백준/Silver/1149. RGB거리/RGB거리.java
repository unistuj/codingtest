
import java.io.*;
import java.util.*;

public class Main {
	
	static int n;
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[][] memo = new int[n][3];
		for(int i = 0; i < 3; i++) {
			memo[0][i] = Integer.parseInt(st.nextToken());
		}
		for(int i= 0; i < n-1; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < 3; j++) {
				int color = Integer.parseInt(st.nextToken());
				if(j == 0) {
					int a = memo[i][1] + color;
					int b = memo[i][2] + color;
					memo[i+1][0] = Math.min(a, b);
				}else if(j == 1) {
					int a = memo[i][0] + color;
					int b = memo[i][2] + color;
					memo[i+1][1] = Math.min(a, b);
				}else {
					int a = memo[i][0] + color;
					int b = memo[i][1] + color;
					memo[i+1][2] = Math.min(a, b);
				}
			}
		}
		int ans = Integer.MAX_VALUE;
		for(int i = 0; i < 3; i++) {
			ans = Math.min(ans, memo[n-1][i]);
		}
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(Integer.toString(ans));
		bw.flush();
		bw.close();
		

	}

}
