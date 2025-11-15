#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int N;
    cin >> N;

    int good_word_count = 0;

    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;

        stack<char> s;

        for (char c : word) {
            if (s.empty()) {
                // 스택이 비어있으면 무조건 문자 넣기 (비교할 수가 없음)
                s.push(c);
            } else {
                // 스택의 top이 현재 문자와 같으면
                if (s.top() == c) {
                    // 짝이 맞으므로 스택에서 제거
                    s.pop();
                } else {
                    // 짝이 맞지 않으면 스택에 추가
                    s.push(c);
                }
            }
        }

        // 모든 문자 순회가 끝난 후 스택이 비어있다면
        // 모든 짝이 맞았다는 뜻이므로 좋은 단어 이다
        if (s.empty()) {
            good_word_count++;
        }
    }

    cout << good_word_count << "\n";

    return 0;
}
