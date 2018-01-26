/**
 * 输入输出真的好烦人
 **/
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct question_info{
    int full_score;
    int choice_count;
    int right_choice_count;
    char right_choice[5];
};

struct answer_info{
    int persional_choice_count;
    char choice[5];
};

int main(void){
    vector<question_info> question_vector;
    // vector<answer_info> answer_vector;
    int student_count, question_count;
    cin >> student_count >> question_count;
    for (int i = 0; i < question_count; i++){
        struct question_info q;
        cin >> q.full_score >> q.choice_count >> q.right_choice_count;
        for (int i = 0; i < q.right_choice_count; i++){
            cin >> q.right_choice[i];
        }
        question_vector.push_back(q);
    }
    vector<vector<answer_info>> student_answer;
    for (int i = 0; i < student_count; i++){
        vector<answer_info> answer_vector;
        cout << (char)getchar(); //处理换行符
        for (int j = 0; j < question_count; j++){
            struct answer_info ans;
            cout << (char)getchar() << endl; //处理(
            cin >> ans.persional_choice_count;
            for (int k = 0; k < ans.persional_choice_count; k++){
                char tmp_ch;
                cout << tmp_ch << endl;
                cin >> tmp_ch;
                ans.choice[k] = tmp_ch;
            }
            cout << (char)getchar() << endl; //处理)
            if (j != question_count - 1)
                cout << (char)getchar() << "|空格"; //处理空格
            answer_vector.push_back(ans);
        }
        student_answer.push_back(answer_vector);
    }

    return 0;
}