import java.io.*;
import java.util.*;

public class Main {
	//배열의 가로 세로 회전 횟수
	static int n;
	static int m;
	static int t;
	//배열
	static int box[][];
	//r, c, s
	static int r[];
	static int c[];
	static int s[];
	//최솟값을 받을 변수
	static int mi;
	
	//좌표를 받고 회전할 함수
	static void rot(int y1, int x1, int y2, int x2, int iloveyou[][]) {
		int ga = x2 - x1 + 1;
		int se = y2 - y1 + 1;
		//깊이에 따라 가로가 양쪽으로 1 세로가 양쪽으로 1줄어들기 때문에 ss로 조정
		int round = Math.min(ga, se);
		for(int ss = 0; ss < round/2; ss++) {
			//회전하며 사라지는 값을 보전하기 위해 temp사용
			int temp = iloveyou[y1+ss][x1+ss];
			//위에서아래
			for(int j = y1+ss; j <= y2-ss-1; j++) {
				iloveyou[j][x1+ss] = iloveyou[j+1][x1+ss];
			}
			//오른쪽에서 왼쪽으로
			for(int j = x1+ss; j <= x2-ss-1; j++) {
				 iloveyou[y2-ss][j] = iloveyou[y2-ss][j+1];
			}
			//아래서 위로
			for(int j = y2-ss; j >= y1+ss+1; j--) {
				iloveyou[j][x2-ss] = iloveyou[j-1][x2-ss];
			}
			//좌에서 우로
			for(int j = x2-ss; j >= x1+ss+1; j--) {
				iloveyou[y1+ss][j] = iloveyou[y1+ss][j-1];
			}
			//temp값 입력
			iloveyou[y1+ss][x1+ss+1] = temp;
		}
	}
	
	private static boolean np(int[] p) {// p : 다음 순열을 원하는 기존 순열의 배열
		//맨뒤쪽부터 탐색하며 꼭대기 찾기
		int N = p.length;
		int i = N-1;
		while(i > 0 && p[i-1] >= p[i])--i;
		
		if(i== 0) return false; // 다음 순열 없음(가장 큰 순열의 형태)
		
		//꼭대기 직전(i-1)위치에 교환할 한 단계 큰 수 뒤쪽부터 찾기
		int j = N-1;
		while(p[i-1] >= p[j])--j;
		
		
		//꼭대기 직전(i-1)위치의 수와 한단계 큰 수를 교환하기
		swap(p, i-1, j);
		
		//꼭대기자리부터 맨 뒤까지의 수를 오름차순의 형태로 바꿈
		int k = N-1;
		while(i < k) {
			swap(p, i++, k--);
		}
		
		return true;
	}
	
	private static void swap(int[] p, int a, int b) {
		int temp = p[a];
		p[a] = p[b];
		p[b] = temp;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine());
		//배열의 가로, 세로, 회전 횟수를 받는다.
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		t = Integer.parseInt(st.nextToken());
		//t값을 기반으로   r, c, s 크기조정
		r = new int[t];
		c = new int[t];
		s = new int[t];
		//배열 문제에서 시작점이 1번부터 이므로 각각 길이를 +1 해서 생성
		box = new int[n+1][m+1];
		//배열에 값 입력
		for(int i = 1; i <= n; i++) {
			st = new StringTokenizer(bf.readLine());
			for(int j = 1; j <= m; j++) {
				box[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		//r, c, s 받고 회전 함수 실행, permutation을 실행할 배열 plz생성
		int plz[] = new int[t];
		for(int i = 0; i < t; i++) {
			st = new StringTokenizer(bf.readLine());
			r[i] = Integer.parseInt(st.nextToken());
			c[i] = Integer.parseInt(st.nextToken());
			s[i] = Integer.parseInt(st.nextToken());
			plz[i] = i;
		}
		//최솟값을 찾기위해 max값으로 고정
		int mi = Integer.MAX_VALUE;
		int[][] maru = new int[n+1][m+1];
		do {
			for(int i = 1; i <= n; i++ ) {
				for(int j = 1; j <= m; j++) {
					maru[i][j] = box[i][j];
				}
			}
			for(int u = 0; u < t; u++) {
				rot(r[plz[u]]-s[plz[u]], c[plz[u]]-s[plz[u]], r[plz[u]]+s[plz[u]], c[plz[u]]+s[plz[u]], maru);
			}
			for(int i = 1; i <= n; i++ ) {
				int temp = 0;
				for(int j = 1; j <= m; j++) {
					temp += maru[i][j];
				}
				mi = Math.min(temp, mi);
			}
		}while(np(plz));
		
		StringBuilder sb = new StringBuilder();
		sb.append(mi);
		System.out.println(sb.toString());
	}
	
}