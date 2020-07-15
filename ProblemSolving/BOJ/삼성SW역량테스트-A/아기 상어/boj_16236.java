import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class boj_16236 {
	public static boolean[][] visited;
	public static int N, baby_r, baby_c,baby_size,baby_exp;
	public static int[][] map;
	public static int[] dr= {-1,0,1,0};
	public static int[] dc= {0,1,0,-1};
	public static void main(String[] args) {
		
		init();
		int time = 0;
		while(true) {
			ArrayList<Fish> list = bfs();
			if(list.isEmpty()) break;
			Fish f = list.get(0);
			if(list.size() == 1) {
				eatFish(f);
			}
			else {
				Collections.sort(list);
				f = list.get(0);
				eatFish(f);
			}
			time += f.dist;
		}
		System.out.println(time);
	}
	public static void init() {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		visited = new boolean[N][N];
		map = new int[N][N];
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				map[i][j] = sc.nextInt();
				if(map[i][j] == 9) {
					map[i][j] = 0;
					baby_r = i;
					baby_c = j;
				}
			}
		}
		baby_size = 2;
		baby_exp = 0;
	}
	public static void eatFish(Fish f) {
		baby_r = f.r;
		baby_c = f.c;
		baby_exp += 1;
		if(baby_exp == baby_size) {
			baby_size += 1;
			baby_exp = 0;
		}
		map[f.r][f.c]= 0; 
	}

	public static ArrayList<Fish> bfs() {
		// 먹을 수 있는 물고기 list를 반환
		Queue<Fish> Q = new LinkedList<Fish>();
		ArrayList<Fish> ret = new ArrayList<Fish>();
		boolean[][] visited = new boolean[N][N];

        int maxDist = 987654321;
		visited[baby_r][baby_c] = true;
		Q.add(new Fish(baby_r,baby_c,0));

		while(!Q.isEmpty()) {
			Fish nowF = Q.poll();
            
            if(maxDist < nowF.dist)
               continue;
            
			if(map[nowF.r][nowF.c] != 0 && map[nowF.r][nowF.c]<baby_size) {
				ret.add(new Fish(nowF.r, nowF.c, nowF.dist));
                if(maxDist >= nowF.dist)
                    maxDist = nowF.dist;
			}
            
			for(int i=0; i<4; i++) {
				int nextR = nowF.r + dr[i];
				int nextC = nowF.c + dc[i];
				if(!(0<=nextR&&nextR<N && 0<=nextC&&nextC<N)) continue;
				if(baby_size < map[nextR][nextC]) continue;
				if(visited[nextR][nextC]) continue;
				
				visited[nextR][nextC] = true;
				Q.add(new Fish(nextR,nextC,nowF.dist+1));
			}
		}
		return ret;
	}
}
class Fish implements Comparable<Fish>{
	public int r,c,dist;
	Fish(int r, int c, int dist){
		this.r = r;
		this.c = c;
		this.dist = dist;
	}
	@Override
	public int compareTo(Fish f) {
		if(this.dist > f.dist) {
			return 1;
		}
		else if(this.dist == f.dist) {
			if(this.r > f.r) {
				return 1;
			}
			else if(this.r == f.r) {
				if(this.c > f.c){
                    return 1;
                }
				else if(this.c == f.c){
                    return 0;
                }
				else 
                    return -1;
			}
			else 
				return -1;
		}
		else
			return -1;
	}
}