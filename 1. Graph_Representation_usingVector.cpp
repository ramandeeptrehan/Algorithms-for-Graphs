//
//  main.cpp
//  1. Graph Representation
//
//  Created by Ramandeep Singh Trehan on 29/06/18.
//  Copyright © 2018 Ramandeep Singh Trehan. All rights reserved.
//

/*
 Vectors if passed by value to a function, makes a copy and do not reflect changes in actual vector.
 The above style of passing might also take a lot of time in cases of large vectors. So, it is a good idea
 to pass by reference.
 */

// Time complexity: O(n+e), which is nothing but O(e), since #edges(e) can reach max upto O(n^2)
#include <vector>
#include <iostream>
using namespace std;

// Time complexity: O(e)
void inputGraph(vector<vector<pair<int,int>>> &adjList, int e) //call by reference is needed.
{
    int u, v, weight;
    
    for(int i=1; i<=e; i++)
    {
        cout<<"Enter u and v(u-->v): ";
        cin>>u>>v;
        cout<<"Enter weight of edge ";
        cin>>weight;
        adjList[u].push_back(make_pair(v, weight));
    }
}

// Time complexity: O(n+e). This is simple traversal of a graph
void printGraph(vector<vector<pair<int, int>>> &adjList, int n)
//keeping call by reference since it saves time in general to not copy entire vector and just pass the base address
//call by value can also work here for printing: void printGraph(vector<vector<pair<int, int>>> adjList, int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<adjList[i].size(); j++)
        {
            cout<<"Edge is: "<<i<<"-->"<<adjList[i][j].first<<endl;
            cout<<"Weight of edge is "<<adjList[i][j].second<<endl;
        }
    }
}

int main(int argc, const char * argv[])
{
    int n, e;
    cout<<"Enter number of nodes(n) and number of edges(e) you want in the graph:"<<endl;
    cin>>n>>e;
    vector<vector<pair<int, int>>> adjList(n+1); //will access n nodes of a graph from 1 to n
    
    inputGraph(adjList, e);
    
    //Printing the graph
    printGraph(adjList, n);
    return 0;
}
