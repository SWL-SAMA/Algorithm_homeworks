#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int node_num=7;
const int edge_num=12;
int gragh[node_num+1][node_num+1];
int dist[node_num+1];//各个节点到集合s的距离
bool book[node_num+1];//节点是否加入到s中
int res=0;
void init_gragh(){
    for (int i=0;i<node_num+1;i++){
        dist[i] = INF;
        book[i]=false;
    }//初始化所有点到集合S的距离都是正无穷
    for(int i=0;i<node_num+1;i++){
        for(int j=0;j<node_num+1;j++){
            gragh[i][j]=INF;
        }
    }
    for(int i=1;i<node_num+1;i++){
        for(int j=1;j<node_num+1;j++){
            if(i==1&&j==2){
                gragh[i][j]=gragh[j][i]=3;
            }
            if(i==1&&j==4){
                gragh[i][j]=gragh[j][i]=2;
            }
            if(i==1&&j==3){
                gragh[i][j]=gragh[j][i]=4;
            }
            if(i==2&&j==4){
                gragh[i][j]=gragh[j][i]=1;
            }
            if(i==3&&j==4){
                gragh[i][j]=gragh[j][i]=2;
            }
            if(i==2&&j==5){
                gragh[i][j]=gragh[j][i]=3;
            }
            if(i==3&&j==6){
                gragh[i][j]=gragh[j][i]=6;
            }
            if(i==4&&j==5){
                gragh[i][j]=gragh[j][i]=4;
            }
            if(i==4&&j==6){
                gragh[i][j]=gragh[j][i]=1;
            }
            if(i==7&&j==4){
                gragh[i][j]=gragh[j][i]=3;
            }
            if(i==7&&j==5){
                gragh[i][j]=gragh[j][i]=1;
            }
            if(i==7&&j==6){
                gragh[i][j]=gragh[j][i]=4;
            }
        }
    }
}
void Prim()
{
    dist[1] = 0;//把点1加入集合S，点1在集合S中，将它到集合的距离初始化为0
    book[1] = true;//表示点1已经加入到了S集合中
    for(int i = 2 ; i <= node_num ;i++)dist[i] = min(dist[i],gragh[1][i]);//用点1去更新dist[]
    for(int i = 2 ; i <= node_num ; i++)
    {
        int temp = INF;//初始化距离
        int t = -1;//接下来去寻找离集合S最近的点加入到集合中，用t记录这个点的下标。
        for(int j = 2 ; j <= node_num; j++)
        {
            if(!book[j]&&dist[j]<temp)//如果这个点没有加入集合S，而且这个点到集合的距离小于temp就将下标赋给t
            {
                temp = dist[j];//更新集合V到集合S的最小值
                t = j;//把点赋给t
            }
        }
        if(t==-1){res = INF ; return ;}
        //如果t==-1，意味着在集合V找不到边连向集合S，生成树构建失败，将res赋值正无穷表示构建失败，结束函数
        book[t] = true;//如果找到了这个点，就把它加入集合S
        res+=dist[t];//加上这个点到集合S的距离
        for(int j = 2 ; j <= node_num ; j++){
            dist[j] = min(dist[j],gragh[t][j]);
        };//用新加入的点更新dist[]
    }
}
int main(){
    init_gragh();
    Prim();
    for(int i=1;i<node_num+1;i++){
        cout<<dist[i]<<" ";
    }
    cout<<res;
}