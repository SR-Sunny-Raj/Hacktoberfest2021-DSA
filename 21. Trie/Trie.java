public class Trie {
    
    static class TrieNode
    {
        HashMap<Character,TrieNode> map;
        TrieNode()
        {
            map = new HashMap<>();
        }

        public String toString()
        {
            return map.toString();    
        }
    }
    
   
    TrieNode root=new TrieNode();
    
    public void insert(String s)
    {
        TrieNode cur = root;
        for(int i=0;i<s.length();i++)
        {
            char x = s.charAt(i);
            if(!cur.map.containsKey(x))
            {
                cur.map.put(x,new TrieNode());
            }
            cur = cur.map.get(x);
        }
        cur.map.put('*',null);
    }

    public boolean search(String s)
    {
        TrieNode cur = root;
        for(int i=0;i<s.length();i++)
        {
            char x = s.charAt(i);
            if(!cur.map.containsKey(x)) return false;
            cur = cur.map.get(x);
        }
        return cur.map.containsKey('*');
    }

    public String toString()
    {
        return root.toString();    
    }
    
}
