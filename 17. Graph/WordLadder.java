package Graphs;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class WordLadder {
	public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Queue<String> q = new LinkedList<>();
        HashSet<String> set = new HashSet<>();
        boolean isPresent = false;
        for(String word: wordList){
            if(word.compareTo(endWord)==0) {
                isPresent = true;
            }
            set.add(word);
        }
        if(!isPresent) return 0;
        int changes = 0;
        q.add(beginWord);
        while(!q.isEmpty()){
            int size = q.size();
            changes++;
            while(size-->0){
                String curr = q.poll();
                for(int i=0;i<curr.length();i++){
                    StringBuilder temp1 = new StringBuilder(curr);
                    for(char c='a';c<='z';c++){
                        temp1.setCharAt(i,c);
                        String temp = temp1.toString();
                            if(curr.compareTo(temp)==0){
                                continue;
                            }
                            if(endWord.compareTo(temp)==0){
                                return changes+1;
                            }
                            if(set.contains(temp)){
                                q.add(temp);
                                set.remove(temp);//to avoid confusion
                            }
                    }
                }
                
            }
        }
        return 0;
    }
}

