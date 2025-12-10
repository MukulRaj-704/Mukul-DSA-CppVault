#include<iostream>
#include<vector>
using namespace std;
int main(){
    int v,e;
    cout<<"entrer no vertices and edges in your graph"<<endl;
    cin>>v>>e;
    cout<<"enter your edges in grapgh a,b"<<endl;
    
    vector<vector<int>> graph(v, vector<int>(v, 0));

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }
    for(int i=0;i<e;i++){
        int a,b,w;
        cin>>a>>b>>w;
        graph[a][b]=w;
        graph[b][a]=w;
        
    }
    cout<<"adjancency representation og graph:"<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
