package CodeSnippets;

public class SegTree
{
    int tree[];
    int n;

    SegTree(int a[])
    {
        tree = new int[a.length*2];
        for(int i=0;i<a.length;i++)
        {
            tree[i+a.length] = a[i];
        }
        for(int i=a.length-1;i>0;i--)
        {
            tree[i] = Math.max(tree[i*2],tree[i*2+1]);
        }
        n = a.length;
    }

    void update(int p,int v)
    {
        tree[p+n] = v; 
        p+=n;
        for (int i = p; i > 1; i=i/2)
            tree[i/2] = Math.max(tree[i] , tree[i^1]);
    }

    // [l , r)
    int query(int l, int r) 
    { 
        int res = Integer.MIN_VALUE;

        for (l=l+n,r=r+n; l<r ; l=l/2, r=r/2)
        {
            if ((l & 1) > 0) 
                res = Math.max(res,tree[l++]);
          
            if ((r & 1) > 0) 
                res += Math.max(res,tree[--r]);
        }
          
        return res;
    }

}
