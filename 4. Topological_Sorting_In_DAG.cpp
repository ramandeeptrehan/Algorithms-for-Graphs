//
//  topologicalSorting.cpp
//  4. Topological Sorting
//
//  Created by Ramandeep Singh Trehan on 25/08/16.
//  Copyright © 2016 Ramandeep Singh Trehan. All rights reserved.
//
//  Note that a vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) are already in stack.

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

stack<int> myStack;

void inputGraph(int numberOfEdges, vector<vector<pair<int, int> > > & adjList)
{
    int u, v, weight;
    
    for(int i=0; i<numberOfEdges; i++)
    {
        cout<<"Enter u and v (u-->v)\n";
        cin>>u>>v;
        cout<<"Enter weight of edge: \n";
        cin>>weight;
        adjList[u].push_back(make_pair(v, weight));
    }
    
}


void printGraph(int numberOfNodes, int numberOfEdges, vector<vector<pair<int, int> > > & adjList)
{
    for(int i=1; i<=numberOfNodes; i++)
    {
        for(int j=0; j<adjList[i].size(); j++)
        {
            cout<<"Edge is: " <<i<< "-->" << adjList[i][j].first<<endl;
            cout<<"Weight is: "<< adjList[i][j].second<<endl;
            
        }
    }
}

void topologicalSortingUtil(int s, vector<vector<pair<int, int> > > & adjList, bool * visited)
{
    visited[s]=true;
    
    for(int i=0; i<adjList[s].size(); i++)
    {
        if(visited[adjList[s][i].first]==false)
            topologicalSortingUtil(adjList[s][i].first, adjList, visited); //note: in u->v...passing the v
    }
    
    myStack.push(s);
    
}

void topologicalSorting(vector<vector<pair<int, int> > > & adjList, int n) // n is number of nodes in graph
{
    bool * visited = new bool[n+1]; //vertices from 1 to n
    
    for(int i=1; i<=n; i++)
    {
        visited[i]=false;
    }
    
    
    
    for(int i=1; i<=n; i++)
    {
        if(visited[i]==false)
            topologicalSortingUtil(i, adjList, visited);
    }
    
    while(myStack.empty()==0)
    {
        cout<<myStack.top()<<" "<<endl;
        myStack.pop();
    }
}

int main()
{
    int n, e;
    cout<<"Enter the number of nodes(n) and edges(e) you want in the graph: \n";
    cin>>n>>e;
    vector<vector<pair<int, int>>> adjList(n+1); //will access n nodes from 1 to n
    
    inputGraph(e, adjList);
    
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<(int)adjList[i].size(); j++)
        {
            cout<<"Edge is: " <<i<< "-->" << adjList[i][j].first<<endl;
            cout<<"Weight is: "<< adjList[i][j].second<<endl;
            
        }
    }
    cout<<"Printing the graph: "<<endl;
    printGraph(n, e, adjList);
    
    cout<<"Topological sort of the directed acyclic graph (DAG) is: "<<endl;
    
    topologicalSorting(adjList, n);
    
}