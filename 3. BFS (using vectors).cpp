//
//  BFS(using vector).cpp
//  2. BFS
//
//  Created by Ramandeep Singh Trehan on 23/08/16.
//  Copyright © 2016 Ramandeep Singh Trehan. All rights reserved.
//

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

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

void BFS(int s, vector<vector<pair<int, int> > > & adjList, int n)
{
    bool * visited = new bool[n+1];
    
    for(int i=1;i<=n;i++)
        visited[i]=false;
    
    queue<int> myQueue;
    myQueue.push(s);
    
    while(myQueue.empty()==0)
    {
        int currentElement = myQueue.front();
        cout<<currentElement<<" ";
        myQueue.pop();
        
        for(int k = 0; k < adjList[currentElement].size(); k++)
        {
            myQueue.push(adjList[currentElement][k].first);
        }
    }
    
    
    
}


int main()
{
    int n, e, s;
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
    
    cout<<"Enter the vertex(1 to n) as a starting vertex for BFS: \n";
    cin>>s;
    BFS(s, adjList, n);
    
}