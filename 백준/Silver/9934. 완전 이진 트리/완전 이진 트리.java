import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
	static int k;
	static int n;
	static Queue<Integer> q = new LinkedList<>();
	static List<List<Integer>> level = new ArrayList<>();
	
	public static void goNode(int now) {
		if(now == k)return;
		goNode(now+1);
		level.get(now).add(q.poll());
		goNode(now+1);
	}
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		k = Integer.parseInt(bf.readLine());
		StringTokenizer st = new StringTokenizer(bf.readLine());
		double count = Math.pow(2, k)-1;
		n = (int)count;
		for(int i = 0; i < n; i++) {
			q.add(Integer.parseInt(st.nextToken()));
		}
		for(int i = 0; i < k; i++) {
			level.add(new ArrayList<>());
		}
		goNode(0);
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < k; i++) {
			for(int j = 0; j < level.get(i).size(); j++) {
				sb.append(level.get(i).get(j)).append(" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}

}