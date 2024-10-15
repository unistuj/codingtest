import java.io.*;
import java.util.*;

public class Main {
	
	static int r;
	static int c;
	static int k;
	static char[][] g = new char[6][6];
	static int visited[][] = new int[6][6];
	static int answer = 0;
	static int dy[] = {1, 0, -1, 0};
	static int dx[] = {0, 1, 0, -1};
	public static void goHome(int y, int x, int count) {
		if(y == 0 && x == c-1) {
			if(k == count)answer++;
			return;
		}
		visited[y][x] = 1;
		for(int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= r || nx < 0 || nx >= c)continue;
			if(visited[ny][nx] == 1)continue;
			if(g[ny][nx] == 'T')continue;
			goHome(ny, nx, count+1);
		}
		visited[y][x] = 0;
		
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		for(int i = 0; i < r; i++) {
			String temp = bf.readLine();
			for(int j = 0; j < c; j++) {
				g[i][j] = temp.charAt(j);
			}
		}
		goHome(r-1, 0, 1);
		System.out.println(answer);
		
	}

}