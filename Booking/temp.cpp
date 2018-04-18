 //  C++ code to check if cyclic order is possible among strings
//  under given constrainsts
#include <bits/stdc++.h>
using namespace std;
#define M 26
 
//  Utility method for a depth first search among vertices
void dfs(vector<int> g[], int u, vector<bool> &visit)
{
    visit[u] = true;
    for (int i = 0; i < g[u].size(); ++i)
        if(!visit[g[u][i]])
            dfs(g, g[u][i], visit);
}
 
//  Returns true if all vertices are strongly connected
// i.e. can be made as loop
bool isConnected(vector<int> g[], vector<bool> &mark, int s)
{
    // Initialize all vertices as not visited
    vector<bool> visit(M, false);
 
    //  perform a dfs from s
    dfs(g, s, visit);
 
    //  now loop through all characters
    for (int i = 0; i < M; i++)
    {
        /*  I character is marked (i.e. it was first or last
            character of some string) then it should be
            visited in last dfs (as for looping, graph
            should be strongly connected) */
        if (mark[i] && !visit[i])
            return false;
    }
 
    //  If we reach that means graph is connected
    return true;
}
 
//  return true if an order among strings is possible
bool possibleOrderAmongString(string arr[], int N)
{
    // Create an empty graph
    vector<int> g[M];
 
    // Initialize all vertices as not marked
    vector<bool> mark(M, false);
 
    // Initialize indegree and outdegree of every
    // vertex as 0.
    vector<int> in(M, 0), out(M, 0);
 
    // Process all strings one by one
    for (int i = 0; i < N; i++)
    {
        // Find first and last characters
        int f = arr[i].front() - 'a';
        int l = arr[i].back() - 'a';
 
        // Mark the characters
        mark[f] = mark[l] = true;
 
        //  increase indegree and outdegree count
        in[f]++;
        out[l]++;
 
        // Add an edge in graph
        g[f].push_back(l);
    }
 
    // If for any character indegree is not equal to
    // outdegree then ordering is not possible
    for (int i = 0; i < M; i++)
        if (in[i] != out[i])
            return false;
 
    return isConnected(g, mark, arr[0].front() - 'a');
}
 
//  Driver code to test above methods
int main()
{
    // string arr[] = {"abc", "efg", "cde", "ghi", "ija"};

    //"Luis","Hector","Selena","Emmanuel","Amish";
    string arr[] = {"luis","hector","selena","emmanuel","amish"};
    int N = sizeof(arr) / sizeof(arr[0]);
 
    if (possibleOrderAmongString(arr, N) == false)
        cout << "Ordering not possible\n";
    else
        cout << "Ordering is possible\n";
    return 0;
}
