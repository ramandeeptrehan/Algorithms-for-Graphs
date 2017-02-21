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

	int *visited;
	visited = (int*)malloc(sizeof(int)*(nodes+1));

	while(q.empty()==0)
	{
		int element = q.front();
		q.pop();
		visited[element]=1;


		cout<<element<<endl;

		

		//IDEA of algorithm:
		//Traverse list of this node (from queue) and reduce it's list's elements indegree by 1 and mark this node from queue as visited=1 and then push 0 indegree nodes to queue
		
		/*
		Good logic: As to why we don't need visited array.
		Agar koi node 0 indegree ka mila hai, iska matlab vo kisi ki list me right side p ho he nai sakta, so each node will be added to queue for atmost once only
		
		*/

		for(int i=0; i<graph[element].size(); i++)
		{
			inDegree[graph[element][i].first]--;
		}

		int i;
		for(i=1; i<=nodes; i++)
			if(inDegree[i]==0 && visited[i]==0)
				q.push(i);

		if(i==nodes+1 && q.empty()==1)
			cout<<"Cycl encountered\n";
		
	}
}

int main()
{
	int n, e;
	cin>>n>>e;

	vector<vector<pair<int, int> > > graph(n+1);

	inputGraph(graph, e);

	printGraph(graph, n, e);

	cout<<"Topological Sorting Order in the Graph is: "<<endl;
	topologicalSorting(graph, n, e);

	return 1;
}