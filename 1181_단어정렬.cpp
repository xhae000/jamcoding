#include <iostream>
#include <string>
#include <vector>
#include <set>       // 1. 중복 제거용
#include <algorithm> // 2. sort 함수용
#include <utility>   // 3. pair 자료형용

// std 네임스페이스 사용
using namespace std;

int main() {
    int N;
    cin >> N; // 단어 개수 입력

    // 1단계: set을 사용해 중복을 제거하며 단어를 입력받음
    set<string> unique_words;
    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        unique_words.insert(word);
    }

    // 2단계: vector<pair<int, string>>에 {길이, 단어} 형태로 저장
    vector<pair<int, string>> words_with_length;
    
    // set에 있는 중복 제거된 단어들을 vector로 옮김
    for (const string& word : unique_words) {
        // {길이, 단어} 형태로 묶어서 vector에 추가
        words_with_length.push_back({word.length(), word});
    }

    // 3단계: vector를 기본 sort 함수로 정렬
    // pair의 기본 정렬 기준:
    // 1. pair의 first (길이) 기준으로 오름차순 정렬
    // 2. 길이가 같으면, pair의 second (단어) 기준으로 사전 순 정렬
    // 문제의 요구사항과 정확히 일치합니다.
    sort(words_with_length.begin(), words_with_length.end());

    // 4단계: 정렬된 pair에서 단어(second) 부분만 출력
    for (const auto& p : words_with_length) {
        cout << p.second << '\n'; // pair의 두 번째 값(단어)을 출력
    }

    return 0;
}
