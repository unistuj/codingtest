import java.io.*;
import java.util.*;

 class pair {
	int y;
	int x;
	public pair(int y, int x) {
		this.y = y;
		this.x = x;
	}
}

public class Main {
	static int n;
	static int m;
	static int map[][];
	static int visited[][];
	static int dx[] = {1, 0, -1, 0};
	static int dy[] = {0, -1, 0, 1};
	
	static void bfs() {
		Queue<pair> q = new ArrayDeque<>();
		q.add(new pair(0, 0));
		visited[0][0] = 1;
		while(q.size() != 0) {
			int y = q.peek().y;
			int x = q.peek().x;
			q.remove();
			for(int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(nx < 0 || nx >= m || ny < 0 || ny >= n)continue;
				if(map[ny][nx] == 0)continue;
				if(visited[ny][nx] != 0)continue;
				visited[ny][nx] = visited[y][x] + 1;
				q.add(new pair(ny, nx));
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		visited = new int[n][m];
		for (int i = 0; i < n; i++) {
			String temp = bf.readLine();
			for (int j = 0; j < m; j++) {
				map[i][j] = temp.charAt(j)-'0';
			}
		}
		bfs();
		StringBuilder sb = new StringBuilder();
		sb.append(visited[n-1][m-1]);
		System.out.println(sb.toString());
	}
}