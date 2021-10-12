#include<bits/stdc++.h>
using namespace std;
#define SpeedForce               \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                    \
    cout.tie(0);

class Point{
public:
    long long x,y,z;

    Point(long long x, long long y, long long z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    bool operator == (Point p){
        return (this->x==p.x && this->y==p.y && this->z==p.z);
    }

    Point operator - (Point b){
        return Point(this->x-b.x,this->y-b.y,this->z-b.z);
    }

};

Point cross(Point a, Point b){
    return Point(a.y*b.z-a.z*b.y,a.z*b.x-b.z*a.x,a.x*b.y-b.x*a.y);
}

long long signedAreaOfParallelogram(Point a, Point b,Point c){
    // a->b 2nd edge b->c
    //cout << "Difference; " << (b-a).x << " " << (b-a).y << " " << (b-a).z << endl;
    long long val = cross(b-a,c-b).z;
    return val;
}

int orientation(Point a,Point b,Point c){
    long long v = signedAreaOfParallelogram(a,b,c);
    //cout << "orientation: " << v << endl;
    if(v<0) return -1;
    if(v>0) return 1;
    return 0;
}

long long dot(Point a,Point b){
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

vector<Point> convexHullJarvisMarch(vector<Point>& a){
    int n = a.size();
    int st = 0;
    for(int i=1;i<n;i++){
        if(a[i].x<a[st].x || (a[i].x==a[st].x && a[i].y<a[st].y)){
            st = i;
        }
    }

    vector<int> vis(n,0);
    // vis maintained so that same pt is not covered again because of going back again
    // otherwise not required
    vector<Point> ans;
    int p = st, q;
    ans.push_back(a[p]); 
    vis[p] = 1;
    while(1){
        q = (p+1)%n;
        for(int i=0;i<n;i++){
            if(orientation(a[p],a[q],a[i])==-1 || (orientation(a[p],a[q],a[i])==0 && (dot(a[i]-a[p],a[i]-a[p])>dot(a[q]-a[p],a[q]-a[p])))){
                q = i;
            }
        }
        int curp = p;
        p = q;
        for(int i=0;i<n;i++){
            if(!vis[i] && i!=curp && i!=q && orientation(a[curp],a[q],a[i])==0){
                ans.push_back(a[i]);
                vis[i] = 1;
            }
        }
        if(a[p]==a[st]){
            break;
        }
        else{
            ans.push_back(a[p]);
            vis[p] = 1;
        }
    }
    return ans;
}

int32_t main(){
    vector<Point> pt;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long a,b;
        cin >> a >> b;
        pt.push_back(Point(a,b,0));
    }

    vector<Point> conHull = convexHullJarvisMarch(pt);
    for(auto v:conHull){
        cout << v.x << " " << v.y << endl;
    }
    
    // Point a(4,2,0),b(3,3,0),c(2,4,0);
    // cout << orientation(a,b,c) << endl;
    // cout << dot(b-a,b-a) << endl;
    // cout << dot(c-a,c-a) << endl;
}

