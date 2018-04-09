/*
 * =====================================================================================
 *
 *       Filename:  campus.cpp
 *
 *    Description:  Find the campus that is not on any shortest path
 *
 *        Version:  1.0
 *        Created:  04/04/18 15:23:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int Answer;
int numVertices, numEdges;

struct Edge {
    unsigned int dst;
    unsigned long weight;

    Edge(unsigned int dst, unsigned long weight):dst(dst),weight(weight){
    }
};

struct Attribute {
    bool visited;
    bool isPath;
    unsigned long dist;
};

vector<Edge> vertices[1001];
Attribute vAttr[1001];
set<int> result;

class CompareDist {
    public:
        bool operator() (pair<int,unsigned long> n1, pair<int,unsigned long> n2) {
            return n1.second > n2.second;
        }
};

void dijkstra(int src) {
    //TODO : Implement Dijkstra with min heap
    priority_queue<pair<int,unsigned long>,
                   vector<pair<int,unsigned long> >,
                   CompareDist> activeQueue;
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;

        cin >> numVertices >> numEdges;

        // Initialization 
        result.clear();
        for(int i = 1; i <= numVertices; i++) {
            vertices[i].clear();
            vAttr[i].isPath= false;
        }

        // Add edges to vertices
        for(int i = 0; i < numEdges; i++) {
            int vid1, vid2, weight;
            cin >> vid1 >> vid2 >> weight;
            vertices[vid1].push_back(Edge(vid2,weight));
            vertices[vid2].push_back(Edge(vid1,weight));
        }

        // Run dijkstra for all vertices
        for(int src = 1; src <= numVertices; src++) {
            dijkstra(src);
        }

        // Check if the vertex is on path or not
        for(int i = 1; i <= numVertices; i++) {
            if(!vAttr[i].isPath) {
                result.insert(i);
            }
        }

        Answer = result.size();
		cout << "Case #" << test_case+1 << endl;
		cout << Answer;

        std::set<int>::iterator it;
        for(it = result.begin(); it != result.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
	}

	return 0;
}
