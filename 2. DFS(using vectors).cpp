//
//  main.cpp
//  2. DFS
//
//  Created by Ramandeep Singh Trehan on 31/07/18.
//  Copyright © 2018 Ramandeep Singh Trehan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void inputGraph(vector<vector<pair<int, int>>> &graph, int e)
{
    int u, v, weight;
    
    for(int i=0; i<e; i++)
    {
        cout<<"Enter edge: u-->v\n";
        cin>>u>>v;
        cout<<"Enter weight of edge:\n";
        cin>>weight;
        
        graph[u].push_back(make_pair(v, weight));
    }
}

void DFSUtil(vector<vector<pair<int, int>>> &graph, bool *visited, int s)
{
    visited[s] = true;
    cout<<s<<" ";
    
    for(int i=0; i<graph[s].size(); i++)
    {
        if(visited[graph[s][i].first] == false)
            DFSUtil(graph, visited , graph[s][i].first);
    }
}

void DFS(vector<vector<pair<int, int>>> &graph, int n, int s)
{
    bool *visited = new bool[n+1]; //1 to n
    
    for(int i=1; i<=n; i++)
        visited[i] = false;
    
    DFSUtil(graph, visited, s);
}

int main(int argc, const char * argv[]) {
    int n, e;
    int s;
    
    cout<<"Enter number of nodes(n) and edges(e) in the graph:\n";
    cin>>n>>e;
    
    vector<vector<pair<int, int>>> graph(n+1);
    
    inputGraph(graph, e);
    
    cout<<"Enter starting vertex(s) for Depth First Search: ";
    cin>>s;
    DFS(graph, n, s);
    return 0;
}
