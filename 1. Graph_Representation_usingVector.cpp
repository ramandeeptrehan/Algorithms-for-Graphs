////
////  main.cpp
////  1. Graph Representation (using vector and pair)
////
////  Created by Ramandeep Singh Trehan on 22/08/16.
////  Copyright © 2016 Ramandeep Singh Trehan. All rights reserved.
////
//
// Time complexity: O(n+e), which is nothing but O(e), since #edges(e) can reach max upto O(n^2)
#include<iostream>
#include<vector>

using namespace std;

// Time complexity: O(e)
void inputGraph(int numberOfEdges, vector<vector<pair<int, int> > > & adjList) // adjList was passed, which is base address of data structure
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

// Time complexity: O(n+e). This is simple traversal of a graph
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


int main()
{
    int n, e;
    cout<<"Enter the number of nodes(n) and edges(e) you want in the graph: \n";
    cin>>n>>e;
    vector<vector<pair<int, int>>> adjList(n+1); //will access n nodes from 1 to n
    
    inputGraph(e, adjList); //passing adjList implies the base address of adjList data structure
    
    
    printGraph(n, e, adjList);
    
}
