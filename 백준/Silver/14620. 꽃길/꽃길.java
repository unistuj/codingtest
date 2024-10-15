

import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static int g[][] = new int[11][11];
	static int visited[][] = new int[11][11];
	static int answer = Integer.MAX_VALUE;
	static int dy[] = {-1, 0, 1, 0};
	static int dx[] = {0, 1, 0, -1};
	
	public static void seed(int y, int x, int count, int value) {
		if(count == 3) {
			if(answer > value) {
				answer = value;
			}
			return; 
		}
		
		boolean first = true;
		for(int i = 1; i < n-1; i++) {
			for(int j = 1; j < n-1; j++) {
				if(first) {
					i = y;
					j = x;
					first = false;
				}
				if(visited[i][j] == 1)continue;
				boolean isFlower = false;
				for(int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if(visited[ny][nx] == 1) {
						isFlower = true;
					}
				}
				if(isFlower)continue;
				for(int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					visited[ny][nx] = 1;
				}
				visited[i][j] = 1;
				seed(i, j, count+1, value+g[i][j]+g[i-1][j]+g[i+1][j]+g[i][j-1]+g[i][j+1]);
				visited[i][j] = 0;
				for(int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					visited[ny][nx] = 0;
				}
			}
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(bf.readLine());
		
		for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(bf.readLine());
			for(int j = 0; j < n; j++) {
				g[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		seed(1, 1, 0, 0);
		System.out.println(answer);
	}

}
