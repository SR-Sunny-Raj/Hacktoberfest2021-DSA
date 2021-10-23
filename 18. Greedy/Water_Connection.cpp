/*
 * Question -
 Every house in the colony has at most one pipe going into it and at most
 one pipe going out of it. Tanks and taps are to be installed in a manner
 such that every house with one outgoing pipe but no incoming pipe gets a
 tank installed on its roof and every house with only an incoming pipe and
 no outgoing pipe gets a tap.
 Given two integers n and p denoting the number of houses and the number of
 pipes. The connections of pipe among the houses contain three input values:
 ai, bi, di denoting the pipe of diameter di from house ai to house bi. Find
 the efficient way for the construction of the network of pipes.
 The output will contain the number of pairs of tanks and taps t installed
 in first line and the next t lines contain three integers: house number of
 tank, house number of tap and the minimum diameter of pipe between them.
 */


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int dfs(int k, int &ans, vector<int> &pipe_ends_at, vector<int> &pipe_receives_from, vector<int> &pipe_diameter){
        if(pipe_ends_at[k] == 0){
            return k;
        }
        if(pipe_diameter[k] < ans){
            ans = pipe_diameter[k];
        }
        return dfs(pipe_ends_at[k], ans, pipe_ends_at, pipe_receives_from, pipe_diameter);
    }

    vector<vector<int>> water_connection(int n, int p, vector<int> a, vector<int> b, vector<int> d){
        vector<vector<int>> result;
        vector<int> result2;
        vector<int> pipe_ends_at(n+1, 0);
        vector<int> pipe_receives_from(n+1, 0);
        vector<int> pipe_diameter(n+1, 0);

        for(int i=0; i<p; i++){
            int x = a[i];
            int y = b[i];
            int z = d[i];

            pipe_ends_at[x] = y;
            pipe_receives_from[y] = x;
            pipe_diameter[x] = z;
        }


        for(int j=1; j<n+1; j++){
            if((pipe_receives_from[j] == 0) && (pipe_ends_at[j])){
                int ans = INT_MAX;
                int w = dfs(j, ans, pipe_ends_at, pipe_receives_from, pipe_diameter);

                result2.clear();
                result2.push_back(j);
                result2.push_back(w);
                result2.push_back(ans);

                result.push_back(result2);
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    int n, p;
    cout<<"Enter number of houses: ";
    cin>>n;

    cout<<endl<<"Enter number of pipes: ";
    cin>>p;
    cout<<endl;

    vector<int> a(p, 0);
    vector<int> b(p, 0);
    vector<int> d(p, 0);

    //Input Example:
    //a[6]={7, 5, 4, 2, 9, 3}
    //b[6]={4, 9, 6, 8, 7, 1}
    //d[6]={98, 72, 10, 22, 17, 66}
    //So here,
    // 7 -> 4, diameter = 98
    //4 -> 9, diameter = 72
    // 4 -> 6, diameter = 10
    // 2-> 8, diameter = 22
    // 9 -> 7 , diameter = 17
    // and so on

    cout<<"Enter house numbers which has outgoing pipe: ";
    for(int i=0; i<p; i++){
        cin>>a[i];
    }
    cout<<endl;

    cout<<"Enter house numbers which has incoming pipe: ";
    for(int i=0; i<p; i++){
        cin>>b[i];
    }
    cout<<endl;

    cout<<"Enter pipe diameters: ";
    for(int i=0; i<p; i++){
        cin>>d[i];
    }
    cout<<endl;

    vector<vector<int>> ans = obj.water_connection(n, p, a, b, d);
    int size = ans.size();

    //
    cout<<"Answer is: "<<size<<endl;
    for(int i=0; i<size; i++){

        for(auto it: ans[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}
