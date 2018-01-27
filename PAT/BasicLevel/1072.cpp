#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_in_or_not(string temp, vector<string> t){
    vector<string>::iterator it;
    for (it = t.begin(); it != t.end(); it++){
        if (temp == *it){
            return true;
        }     
    }
    return false;
}

int main(void){
    int problem_student = 0, problem_stuff = 0;
    int student_count, stuff_count;
    cin >> student_count >> stuff_count;
    vector<string> stuff_vector;
    vector<vector<string> > student_stuff_vector;
    vector<string> student_vector;
    
    string temp;
    string name;
    string stuff;
    for (int i = 0; i < stuff_count; i++){
        cin >> temp;
        stuff_vector.push_back(temp);
    }
    for (int i = 0; i < student_count; i++){
        vector<string> tmp_vector;
        int count;
        cin >> name;
        student_vector.push_back(name);
        cin >> count;
        for (int i = 0; i < count; i++){
            cin >> stuff;
            tmp_vector.push_back(stuff);
        }
        student_stuff_vector.push_back(tmp_vector);
    }
    bool flag = false;
    for (int i = 0; i < student_count; i++){
        flag = false;
        for (int j = 0; j < student_stuff_vector[i].size(); j++){
            if (is_in_or_not(student_stuff_vector[i][j], stuff_vector)){           
                //该物品违禁
                problem_stuff++;
                flag = true;
            }
            else{
                //该物品不违禁
                student_stuff_vector[i].erase(student_stuff_vector[i].begin() + j);
                j--;//特别注意这里删除之后，j需要减少1
            }
        }
        if (flag){
            problem_student++;
        }
    }
    for (int i = 0; i < student_count; i++){
        if (student_stuff_vector[i].size()!=0){
            cout << student_vector[i] << ": ";
            for (int j = 0; j < student_stuff_vector[i].size() - 1; j++)
                cout << student_stuff_vector[i][j] << " ";
            cout << student_stuff_vector[i][student_stuff_vector[i].size() - 1] << endl;
        }
    }
    cout << problem_student << " " << problem_stuff << endl;
    return 0;
}