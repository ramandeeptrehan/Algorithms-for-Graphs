////
////  1. Graph_Representation_usingVector.cpp
////     Graph Representation (using vector and pair)
////
////  Created by Ramandeep Singh Trehan on 22/08/16.
////  Copyright © 2016 Ramandeep Singh Trehan. All rights reserved.
////
//
#include<iostream>
#include<vector>

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
    
}
