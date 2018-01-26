#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int student_count, question_count;
    int temp;
    vector<int> score_table;
    vector<int> right_answer;
    vector<int> student_score;
    cin >> student_count >> question_count;
    for (int i = 0; i < question_count; i++){
        cin >> temp;
        score_table.push_back(temp);
    }
    for (int i = 0; i < question_count; i++){
        cin >> temp;
        right_answer.push_back(temp);
    }
    for (int i = 0; i < student_count; i++){
        int score = 0;
        for (int j = 0; j < question_count; j++){
            cin >> temp;
            if (temp == right_answer[j]){
                score += score_table[j];
            }
        }
        student_score.push_back(score);
    }

    for (int i = 0; i < student_count; i++){
        cout << student_score[i] << endl;
    }
    return 0;
}