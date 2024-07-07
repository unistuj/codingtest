import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static char[][] room = new char[301][301];
	static int ty, tx, jy, jx;
	static int n, m;
	static int[] dy = {1, 0, -1, 0};
	static int[] dx = {0, 1, 0, -1};
	static int ans = 0;
	static int visited[][] = new int[301][301];
	
	static class Pair{
		int y;
		int x;
		public Pair(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}
	
	static void bfs() {
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(jy, jx));
		while(!q.isEmpty()) {
			int y = q.peek().y;
			int x = q.poll().x;
			for(int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny <= 0 || ny > n || nx <= 0 || nx > m)continue;
				if(visited[ny][nx] == 1)continue;
				visited[ny][nx] = 1;
				if(room[ny][nx] != '0') {
					room[ny][nx] = '0';
					continue;
				}
				q.add(new Pair(ny, nx));
			}
		}
	}
	
	
	public static void main(String[] args) throws IOException {
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		jy = Integer.parseInt(st.nextToken());
		jx = Integer.parseInt(st.nextToken());
		ty = Integer.parseInt(st.nextToken());
		tx = Integer.parseInt(st.nextToken());
		for(int i = 1; i <= n; i++) {
			String temp = br.readLine();
			for(int j = 1; j <= m; j++) {
				room[i][j] = temp.charAt(j-1);
			}
		}
		while(room[ty][tx] == '#') {
			for(int i = 1; i <= n; i++) {
				Arrays.fill(visited[i], 0);
			}
			visited[jy][jx] = 1;
			bfs();
			ans++;
		}
		bw.write(Integer.toString(ans));
		bw.flush();
		bw.close();
		br.close();
	}

}