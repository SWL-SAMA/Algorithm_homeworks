//Kruskal
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct edge{
    //连接的两个点
    int u;
    int v;
    //权重
    int weight;
};
vector<int>father_node;
vector<edge>result_edge;
vector<edge>map;
struct edge tmp={1,2,3};
void init_map(int num_edge){
    struct edge tmp1={1,2,3};
    struct edge tmp2={1,3,4};
    struct edge tmp3={2,5,3};
    struct edge tmp4={3,6,6};
    struct edge tmp5={5,7,1};
    struct edge tmp6={6,7,4};
    struct edge tmp7={1,4,2};
    struct edge tmp8={2,4,1};
    struct edge tmp9={3,4,2};
    struct edge tmp10={5,4,4};
    struct edge tmp11={6,4,1};
    struct edge tmp12={7,4,3};
    map.push_back(tmp1);
    map.push_back(tmp2);
    map.push_back(tmp3);
    map.push_back(tmp4);
    map.push_back(tmp5);
    map.push_back(tmp6);
    map.push_back(tmp7);
    map.push_back(tmp8);
    map.push_back(tmp9);
    map.push_back(tmp10);
    map.push_back(tmp11);
    map.push_back(tmp12);
}
bool compare(edge a, edge b){
    return a.weight < b.weight;
}
int findfather(int a)
{
	while (a != father_node[a]){
		a = father_node[a];
	}
	return a;
}
void kruskal(vector<edge>map,int k){
    sort(map.begin(),map.end(),compare);
    //初始化集合
    for(int i=0;i<7;i++){
        father_node.push_back(i);
    }
    for(int j=0;j<map.size() && result_edge.size()<7-k;j++){
        int u=map[j].u;
        int v=map[j].v;
        int w=map[j].weight;
        if(findfather(u)!=findfather(v)){
            result_edge.push_back(map[j]);
            father_node[findfather(v)]=father_node[findfather(u)];
        }
    }
}
void disp_result(){
    vector<int>clustera;
    vector<int>clusterb;
    vector<int>clusterc;
    vector<int>num_cluster;
    for (int j=1;j<8;j++){
        cout<<"node "<<j<<" belongs to "<<findfather(j)<<endl;
        num_cluster.push_back(findfather(j));
    }
    sort(num_cluster.begin(),num_cluster.end());
    num_cluster.erase(unique(num_cluster.begin(),num_cluster.end()),num_cluster.end());
    for (int i=1;i<8;i++){
        if(findfather(i)==num_cluster[0]){
            clustera.push_back(i);
        }
        if(findfather(i)==num_cluster[1]){
            clusterb.push_back(i);
        }
        if(findfather(i)==num_cluster[2]){
            clusterc.push_back(i);
        }
    }
    cout<<"cluster_a:"<<endl;
    for(int a=0;a<clustera.size();a++){
        cout<<clustera[a]<<" ";
    }
    cout<<endl;
    cout<<"cluster_b:"<<endl;
    for(int a=0;a<clusterb.size();a++){
        cout<<clusterb[a]<<" ";
    }
    cout<<endl;
    cout<<"cluster_a:"<<endl;
    for(int a=0;a<clusterc.size();a++){
        cout<<clusterc[a]<<" ";
    }
    cout<<endl;
}
int main()
{
    init_map(12);
    kruskal(map,3);
    cout<<"result_edge_num:"<<result_edge.size()<<endl;
    disp_result();
    return 0;
}
