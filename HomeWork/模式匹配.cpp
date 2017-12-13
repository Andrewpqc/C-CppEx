/**
 * 模式匹配　作业３,判断一个字符串是否是另一个字符串的子串
 * 如果是找出首次出现的索引值+1；如果不是的话，返回０
 */

/**
 * 母串s1 长度n1
 * 子串s2 长度n2
 * 先找s2[0]在s1中出现的位置所有位置，
 * 将他们存在一个vector中，然后依次考
 * 察每一个位置，看从该位置起(包括该位
 * 置所对应的字符)往后的n2个字符组成的
 * 字符串是否就是s2
 */ 
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> s0_position;

int index(char *s1, char *s2){
    int inde;
    int pnt_len = strlen(s1);
    int cid_len = strlen(s2);
    //母串比子串长，直接返回０
    if (pnt_len < cid_len)
        return 0;
    else{
        //在母串中找到子串中第一个字符出现的所有位置，放到s0_position中存储起来
        for(int j=0;j<pnt_len;j++){
            if(s1[j]!=s2[0])
                continue;
            else
            s0_position.push_back(j);
        }
        
        vector<int>::iterator iter;
        for(iter=s0_position.begin();iter!=s0_position.end();iter++){
            inde=*iter;
            //比较母串中从*iter开始到*iter+cid_len着一段字符串是否是子串
            if(pnt_len-inde>=cid_len){//余下的长度够一个子串才有往下看的必要
                bool flag=true;
                for(int i=1;i<cid_len;i++)
                    if(s2[i]!=s1[++(*iter)]){//如果有字符不与子串对应的字符相等的话，就改变标志位
                        flag=false;
                        break;
                    }
                if(flag)//标志位没变，说明找到了，就是它,返回开始时j的值
                    return inde+1;
                
                //标志位改变,没找到，找下一个         
            }
        
        }      
         //没找到
        return 0;
    }

}

int main(void)
{
    char s1[100];
    char s2[100];
    cin >> s1 >> s2;
    cout << index(s1, s2) << endl;
    return 0;
}