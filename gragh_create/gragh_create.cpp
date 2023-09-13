#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
    string name;
    vector<node>neighbor;
    vector<int>cost;
};
const int Node_num = 7;
vector<node> creat_Graph(){
    vector<node>Node_list;
    node f;
    f.name="null";
    Node_list.push_back(f);
    for (int i=1;i<=Node_num;i++){
        node v;
        v.name="v"+to_string(i);
        Node_list.push_back(v);
    }
    Node_list[1].neighbor.push_back(Node_list[2]);
    Node_list[1].neighbor.push_back(Node_list[3]);
    Node_list[1].neighbor.push_back(Node_list[4]);
    Node_list[1].cost.push_back(3);
    Node_list[1].cost.push_back(4);
    Node_list[1].cost.push_back(2);

    Node_list[2].neighbor.push_back(Node_list[1]);
    Node_list[2].neighbor.push_back(Node_list[4]);
    Node_list[2].neighbor.push_back(Node_list[5]);
    Node_list[2].cost.push_back(3);
    Node_list[2].cost.push_back(1);
    Node_list[2].cost.push_back(3);

    Node_list[3].neighbor.push_back(Node_list[1]);
    Node_list[3].neighbor.push_back(Node_list[4]);
    Node_list[3].neighbor.push_back(Node_list[6]);
    Node_list[3].cost.push_back(4);
    Node_list[3].cost.push_back(2);
    Node_list[3].cost.push_back(6);

    Node_list[4].neighbor.push_back(Node_list[1]);
    Node_list[4].neighbor.push_back(Node_list[2]);
    Node_list[4].neighbor.push_back(Node_list[5]);
    Node_list[4].neighbor.push_back(Node_list[7]);
    Node_list[4].neighbor.push_back(Node_list[6]);
    Node_list[4].neighbor.push_back(Node_list[3]);
    Node_list[4].cost.push_back(2);
    Node_list[4].cost.push_back(1);
    Node_list[4].cost.push_back(4);
    Node_list[4].cost.push_back(3);
    Node_list[4].cost.push_back(1);
    Node_list[4].cost.push_back(2);

    Node_list[5].neighbor.push_back(Node_list[2]);
    Node_list[5].neighbor.push_back(Node_list[4]);
    Node_list[5].neighbor.push_back(Node_list[7]);
    Node_list[5].cost.push_back(3);
    Node_list[5].cost.push_back(4);
    Node_list[5].cost.push_back(1);

    Node_list[6].neighbor.push_back(Node_list[3]);
    Node_list[6].neighbor.push_back(Node_list[4]);
    Node_list[6].neighbor.push_back(Node_list[7]);
    Node_list[6].cost.push_back(6);
    Node_list[6].cost.push_back(1);
    Node_list[6].cost.push_back(4);

    Node_list[7].neighbor.push_back(Node_list[5]);
    Node_list[7].neighbor.push_back(Node_list[4]);
    Node_list[7].neighbor.push_back(Node_list[6]);
    Node_list[7].cost.push_back(1);
    Node_list[7].cost.push_back(3);
    Node_list[7].cost.push_back(4);
    return Node_list;
}
int main(){
    cout<<creat_Graph()[5].neighbor.size();
}