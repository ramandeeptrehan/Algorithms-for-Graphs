//
//  main.cpp
//  5. Topological Sorting Using Indegree
//
//  Created by Ramandeep Singh Trehan on 16/09/17.
//  Copyright © 2017 Ramandeep Singh Trehan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void inputGraph(vector<vector<pair<int, int> > > &graph, int edges)
{
    int u, v;
    int weight;
    
    for(int i=0; i<edges; i++)
    {
        cout<<"Enter u->v:\n";
        cin>>u>>v;
        cout<<"Enter the weight of the graph:\n";
        cin>>weight;
        
        graph[u].push_back(make_pair(v, weight));
    }
}

void printGraph(vector<vector<pair<int, int> > > &graph, int nodes, int edges)
{
    for(int i=1; i<=nodes; i++)
        for(int j=0; j<graph[i].size(); j++)
        {
            cout<<"Edge " << i <<"-->" <<graph[i][j].first<<endl;
            cout<<"Weight of edge is " <<graph[i][j].second<<endl;
        }
}

int* calculateIndegree(vector<vector<pair<int, int> > > &graph, int nodes)
{
    int *inDegree;
    inDegree = (int*)malloc(sizeof(int)*(nodes+1));
    
    for(int i=1; i<=nodes; i++)
        for(int j=0; j<graph[i].size(); j++)
        {
            inDegree[graph[i][j].first]++;
        }
    
    return inDegree;
}

int findZeroIndegreeNode(int *inDegree, int nodes)
{
    for(int i=1; i<=nodes; i++)
    {
        if(inDegree[i]==0)
        {
            return i;
        }
        
    }
    return -1; //case of DAG
}

void topologicalSorting(vector<vector<pair<int, int> > > &graph, int nodes, int edges)
{
    int count = 0;
    int *inDegree;
    inDegree = calculateIndegree(graph, nodes);
    
    int firstNode = findZeroIndegreeNode(inDegree, nodes);
    
    if(firstNode==-1)
    {
        cout<<"This graph has a cycle\n";
        return;
    }
    
    //Push this node to queue
    queue<int> q;
    q.push(firstNode);
    count++;  //increment whenever node pushed to queue
    
    int *visited;
    visited = (int*)malloc(sizeof(int)*(nodes+1));
    
    while(q.empty()==0)
    {
        int element = q.front();
        q.pop();
        visited[element]=1;
        
        cout<<element<<endl;
        
        int vertex;
        for(int i=0; i<graph[element].size(); i++)
        {
            vertex = graph[element][i].first;
            inDegree[vertex]--;
            if(inDegree[vertex] == 0 && visited[vertex]==0)
            {
                q.push(vertex);
                count++;
            }
        }
        
    }
    
    // check if all nodes went to queue. Incremented count whenver a node was pushed to queue. Each nodes goes to
    // queue atmost once.
    if(count!=nodes)
        cout<<"Cycle encountered";
        
}

int main()
{
    int n, e;
    
    cout<<"Enter number of nodes and edges in graph:"<<endl;
    
    cin>>n>>e;
    
    vector<vector<pair<int, int> > > graph(n+1);
    
    inputGraph(graph, e);
    
    printGraph(graph, n, e);
    
    cout<<"Topological Sorting Order in the Graph is: "<<endl;
    topologicalSorting(graph, n, e);
    
    return 1;
}
