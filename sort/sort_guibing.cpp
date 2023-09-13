//7 3 10 5 4 1 8 2
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>input;
void init(){
    int num;
    cout<<"num:"<<endl;
    cin>>num;
    cout<<"input:"<<endl;
    for(int i=0;i<num;i++){
        int tmp;
        cin>>tmp;
        input.push_back(tmp);
    }
}
void show_vector(vector<int>in){
    for(int i=0;i<in.size();i++){
        cout<<in[i]<<" ";
    }
    cout<<endl;
}
vector<int> sort_gb(vector<int>in){
    if(in.size()==2){
        if(in[0]>=in[1]){
            swap(in[0],in[1]);
        }
        return in;
    }
    if(in.size()==1){
        return in;
    }
    if(in.size()!=1&&in.size()!=2){
        //前n/2个元素放入in_f,后n/2个元素放入in_b
        vector<int>in_f;
        vector<int>in_b;
        int mid=in.size()/2;
        for(int i=0;i<in.size();i++){
            if(i<mid){
                in_f.push_back(in[i]);
            }
            else{
                in_b.push_back(in[i]);
            }
        }
        vector<int>in_f_s=sort_gb(in_f);
        vector<int>in_b_s=sort_gb(in_b);
        vector<int>re;
        merge(in_f_s.begin(), in_f_s.end(), in_b_s.begin(), in_b_s.end(), back_inserter(re));
        return re;
    }
    return in;
}
int main(){
    init();
    show_vector(input);
    vector<int>result=sort_gb(input);
    show_vector(result);
}