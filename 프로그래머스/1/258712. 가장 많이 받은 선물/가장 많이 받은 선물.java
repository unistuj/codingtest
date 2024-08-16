import java.util.*;
import java.io.*;

class Solution {
    int[][] gift = new int[50][50];
    int[] nextGift = new int[50];
    Map<String, Integer> mp = new HashMap<>();
    public int solution(String[] friends, String[] gifts) {
        int num = friends.length;
        for(int i = 0; i < num; i++){
            mp.put(friends[i], i);
        }
        for(int i = 0; i < gifts.length; i++){
            StringTokenizer st = new StringTokenizer(gifts[i]);
            int from = mp.get(st.nextToken());
            int to = mp.get(st.nextToken());
            gift[from][to] += 1;
        }
        for(int i = 0; i < num; i++){
            for(int j = i+1; j < num; j++){
                int start = gift[i][j];
                int end = gift[j][i];
                if(start > end){
                    nextGift[i]++;
                }else if (end > start){
                    nextGift[j]++;
                }else{
                    int getStart = 0;
                    int giveStart = 0;
                    int getEnd = 0; 
                    int giveEnd = 0;
                    for(int u = 0; u < num; u++){
                        giveStart += gift[i][u];
                        getStart += gift[u][i];
                        giveEnd += gift[j][u];
                        getEnd += gift[u][j];
                    }
                    int startPoint = giveStart-getStart;
                    int endPoint = giveEnd-getEnd;
                    if(startPoint > endPoint){
                        nextGift[i]++;
                    }else if(startPoint < endPoint){
                        nextGift[j]++;
                    }
                }
            }
        }
        int answer = 0;
        for(int i = 0; i < num; i++){
            if(answer < nextGift[i]){
                answer = nextGift[i];
            }
        }
        System.out.println(answer);
        return answer;
    }
}