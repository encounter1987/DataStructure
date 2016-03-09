/*************************************************************************************/
//#define WINDOWS                           // If working with console or using redirect operator for file input, then comment this macro
#define INPUT_FILE "E:\\INPUT\\input.txt" // Choose your input File.
#ifdef WINDOWS
#define FILE_IN\
	FILE *fp = NULL;\
	fp = freopen(INPUT_FILE, "r", stdin);\
	if(fp == NULL)\
	{\
		cout << "ERROR: file open failed!!\n";\
	}

#define FILE_CLOSE\
	if(fp)\
	{\
		fclose(fp);\
	}
#else
#define FILE_IN
#define FILE_CLOSE
#endif
//***********************************************************************************/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

#define FOR(i,a,b) for( int i = (a); i < (b); ++i)
typedef vector< int > Ivec;
typedef vector< Ivec > Graph;

/* Return the 
 *
*/
int getMinIndex(vector< bool >& Done, Ivec& Dist, int source)
{
	int minIndex = source;
	int min = INT_MAX;

	FOR(i,1,Dist.size())
	{
		if(!Done[i] && min >= Dist[i])
		{
			min = Dist[i];
			minIndex = i;
		}
	}

	return minIndex;
}

void Dijkstra(const Graph& g, const int source, const int V)
{
	Ivec Dist(V+1, INT_MAX);
	vector< bool > Done(V+1, false);
	Dist[source] = 0;

	FOR(i,1,V+1)
	{
		int currMinIndex = getMinIndex(Done, Dist, source);
		Done[currMinIndex] = true;

		FOR(j,1,V+1)
		{
			if(!Done[j] && g[currMinIndex][j] && Dist[currMinIndex] != INT_MAX && 
				Dist[currMinIndex] + g[currMinIndex][j] < Dist[j])
			{
				Dist[j] = Dist[currMinIndex] + g[currMinIndex][j];
			}
		}
	}	

	FOR(i,1,V+1)
		printf("Distance from %d -> %d = %d\n", source, i, Dist[i]);
}

int main ()
{
	FILE_IN

	int V;
	scanf("%d", &V);
	Graph g(V+1, Ivec(V+1));

	FOR(i,1,V+1)
	{
		FOR(j,1,V+1)
		{
			scanf("%d", &g[i][j]);
		}
	}

	Dijkstra(g, 1, V);

	FILE_CLOSE

	return(0);
}
