#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <fstream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

#define INFINITY 0x0fffffff

struct Edge{
    int linkID;
    int start;
    int end;
    int cost;

    Edge(){
        this->linkID=0;
        this->start=0;
        this->end=0;
        this->cost=0;
    }

    Edge(int linkID,int start,int end,int cost){
        this->linkID=linkID;
        this->start=start;
        this->end=end;
        this->cost=cost;
    }
    bool operator==(const Edge& edge) const{
        return edge.start==start && edge.end == end;//这里可以自定匹配个数
    }
};


/**************************************************
func:求给定终点的最短路径以及路径长度
para:matrix:图的邻接矩阵;startID:起点;endID:终点;shortestTwoNode:两点间的最短路径;shortestPath:起点到其它所有节点的最短路径;minWeight:两点间最短路径长度
retu:成功返回0,失败返回-1
**************************************************/
int getShortestPath(int* (*matrix),int startID,int endID,list<int>& shortestTwoNode,map<int,int>& shortestPath,int& minWeight){
    if(startID==endID||startID<0||endID<0)
        return -1;
    std::stack<int> nodeS; 
    map<int,int>::iterator it=shortestPath.find(endID);
    while(it!=shortestPath.end()){
        nodeS.push((*it).first);
        if(it->first==startID)
            break;
        it=shortestPath.find(it->second);
    }
    while(!nodeS.empty()){
        int topEle=nodeS.top();
        nodeS.pop();
        shortestTwoNode.push_back(topEle);
        if(!nodeS.empty())
            minWeight+=matrix[topEle][nodeS.top()];
    }
    return 0;
}


//qsort函数需要的比较函数，按照升序排序
int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

//按指定分隔符分割字符串
//src:源字符串 delimiter:分隔符集合
vector<string> split(const string& src,const string& delimiter) 
{
    vector<string> strRes;
    if(src=="")
        return strRes;

    int maxSubstrNum=src.size();
    int* pos=new int[maxSubstrNum];
    memset(pos,NULL,maxSubstrNum*sizeof(int));

    int j=0;
    for(int i=0;i<delimiter.size();++i)
    {
        string::size_type index=src.find(delimiter[i]);
        while(index!=string::npos)
        {
            pos[j++]=index;
            index=src.find(delimiter[i],index+1);
        }       
    }
    //排序
    qsort(pos,j,sizeof(int),comp);
    //取出第一个子串
    string substrFir=src.substr(0,pos[0]);
    if(substrFir!="")
        strRes.push_back(substrFir);
    //取出中间j-1个子串
    for(int i=0;i<j-1;++i)
    {
        string substr=src.substr(pos[i]+1,pos[i+1]-pos[i]-1);
        if(substr!="")
            strRes.push_back(substr);
    }
    //取出最后一个子串
    string substrLast=src.substr(pos[j-1]+1,src.size()-pos[j-1]-1);
    if(substrLast!="")
        strRes.push_back(substrLast);   
    delete[] pos;
    return strRes;
}

//根据输入文件读取图的边信息
int getEdge(char* filePath,vector<Edge>& edgeVec){
    if(filePath==NULL||*filePath=='\0')
        return -1;
    char buffer[32]="";
    Edge edgeTemp;
    memset(&edgeTemp,0,sizeof(Edge));
    ifstream graph(filePath);
    if(graph.is_open()){
        while(graph.peek()!=EOF){
            graph.getline(buffer,32,'\n');
            vector<string> edgeInfo=split(buffer,",");
            if(edgeInfo.size()!=4)
                return -1;
            edgeTemp.linkID=atoi(edgeInfo[0].c_str());
            edgeTemp.start=atoi(edgeInfo[1].c_str());
            edgeTemp.end=atoi(edgeInfo[2].c_str());
            edgeTemp.cost=atoi(edgeInfo[3].c_str());
            edgeVec.push_back(edgeTemp);
        }
        graph.close();
        return 0;
    }else 
        return -1;
}

//根据图的边信息构造邻接矩阵
int getMatrix(vector<Edge>& edgeVec,int* (*&matrix),int& nodeNum){
    set<int> nodeSet;
    for(int i=0;i<edgeVec.size();++i){
        nodeSet.insert(edgeVec[i].start);
        nodeSet.insert(edgeVec[i].end);
    }
    nodeNum=nodeSet.size();
    matrix=new int*[nodeNum];
    memset(matrix,0,nodeNum*sizeof(int*));
    for(int i=0;i<nodeNum;++i){
        matrix[i]=new int[nodeNum];
        memset(matrix[i],0,sizeof(int)*nodeNum);
    }
    //为关系矩阵赋值
    for(int row=0;row<nodeNum;++row){
        for(int colum=0;colum<nodeNum;++colum){
            if(row==colum)
                matrix[row][colum]=0;
            else{   
                vector<Edge>::iterator it=find(edgeVec.begin(),edgeVec.end(),Edge(0,row,colum,0));
                if(it!=edgeVec.end()){
                    matrix[row][colum]=it->cost;
                }else{
                    matrix[row][colum]=INFINITY;
                }
            }
        }
    }
    return 0;
}


/**************************************************
func:求带权有向图的单源最短路径;
para:matrix:图的邻接矩阵;nodeNum:图的节点数;startID:起始节点;shortestPath:最短路径;
retu:0:成功;-1:失败，表明从起点出发有不可到达的节点
**************************************************/
int djkstra(int* (*matrix),int nodeNum,int startID,map<int,int>& shortestPath){
    if(matrix==NULL||nodeNum<1||startID<0||startID>nodeNum-1)
        return -1;
    shortestPath.insert(make_pair(startID,-1));//startID为路径起点，进入容器
    matrix[startID][startID]=1;//表示顶点startID在集合U中

    pair<int,int>* distance=new pair<int,int>[nodeNum];//顶点startID到其它定点距离,后一个int表示当前节点的前一个节点
    memset(distance,0,nodeNum*sizeof(pair<int,int>));
    //初始化startID到集合Y中顶点的距离值
    for(int i=0;i<nodeNum;++i){
        if(i==startID) continue;
        distance[i]=make_pair(matrix[startID][i],-1);
        if(matrix[startID][i]!=INFINITY)
            distance[i].second=startID;
    }

    //循环的次数是Y集合中的定点数，去除起点，只有nodeNum-1个
    for(int i=0;i<nodeNum-1;++i){
        int minID=0,minWeight=INFINITY;
        for(int j=0;j<nodeNum;++j){
            if(j==startID) continue;
            if(matrix[j][j]!=1&&distance[j].first<minWeight){
                minWeight=distance[j].first;
                minID=j;
            }
        }
        if(minWeight==INFINITY) return -1; //从startID=0到集合V-U中没有路径
        shortestPath.insert(make_pair(minID,distance[minID].second));
        matrix[minID][minID]=1;  //设置为已访问

        //更新顶点startID通过顶点minID到集合V-U中的定点的最短距离
        for(int j=0;j<nodeNum;++j){
            if(matrix[j][j]!=1){
                if(distance[j].first>distance[minID].first+matrix[minID][j]){
                    distance[j].first=distance[minID].first+matrix[minID][j];
                    distance[j].second=minID;
                }
            }
        }
    }
    delete[] distance;
    return 0;
}

vector<Edge> edgeVec; //带权有向图边的集合

int main(int argc,char* argv[]){
    
    if(argc!=2)
        return -1;
    vector<Edge> edgeVec;
    getEdge(argv[1],edgeVec);

    int* (*matrix)=NULL;
    int nodeNum=0;
    getMatrix(edgeVec,matrix,nodeNum);//构造关系矩阵

    map<int,int> shortestPath;  //起点到所有其他节点的最短路径
    list<int> shortestTwoNode;  //起点到终点的最短路径
    int shortestTwoNodeWeight=0; 
    int startID=0,endID=0;

    cout<<"input startID endID"<<endl;
    cin>>startID>>endID;
    int res=djkstra(matrix,nodeNum,startID,shortestPath);
    if(res==-1)
        cout<<"get shortest path start from "<<startID<<" failed "<<endl;
    else
        getShortestPath(matrix,startID,endID,shortestTwoNode,shortestPath,shortestTwoNodeWeight);
    cout<<startID<<" to "<<endID<<":";
    for(list<int>::iterator it=shortestTwoNode.begin();it!=shortestTwoNode.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"weight:"<<shortestTwoNodeWeight<<endl;
    getchar();
    return 0;
}