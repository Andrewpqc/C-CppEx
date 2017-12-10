#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include<iomanip>
using namespace std;

typedef struct Node{
    int count;
    string word;
    struct Node* next;
}Word;
int main(void){
    Word*head=new Word;
    head->count=0;
    head->next=NULL;
    Word*rear=head;
    FILE*f=fopen("/home/andrew/test.txt","r");
    char c=fgetc(f);

    while(true){
        if(c==EOF){
            cout<<"本文不含任何单词"<<endl;
            return 0;
        }
        else{
            if(!isalpha(c)){
                c=fgetc(f);
            }
            else{
                break;
            }
        }
    }

    string temp="";

    //这里的第一个字符一定是一个字母
    while(c!=EOF){
        temp+=tolower(c);//忽略大小写
        c=fgetc(f);
        if(!isalpha(c)){
            Word*head2=head;//保存头指针
            head2=head2->next;

            bool flag=true;//用于判断是否找到相同单词的标志

            while(head2!=NULL){
                //该节点存储的就是该单词
                if(head2->word==temp){
                head2->count+=1;
                head->count+=1;
                flag=false;//这里找到之后要改变标志
                break;
                }
                //在该节点中没找到，找下一个节点
                head2=head2->next;

            }
            //整个链表没有相同的单词
            if(flag){
                head->count+=1;
                //开辟内存
                Word*tmp=new Word;
                //为成员赋值
                tmp->count=1;
                tmp->next=NULL;
                tmp->word=temp;
                //连接
                rear->next=tmp;
                rear=rear->next;
            }
            temp="";//清空
            c=fgetc(f);
        }

        }

    //打印结果
    int sumcount=head->count;//头结点中存储着这篇文章总共的单词数
    head=head->next;
    cout<<"全文总共的单词数："<<sumcount<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"各个单词及其出现的数量："<<endl;
    while(head!=NULL){
    cout<<std::left<<setw(20)<<head->word<<" "<<setw(20)<<head->count<<endl;
    head=head->next;
    }

    return 0;
}
