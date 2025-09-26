#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>
#include <stdexcept>

using namespace std;

map<char, vector<string>> get_correct_patterns() {
    map<char, vector<string>> patterns;
    patterns['0'] = {" _ ", "| |", "|_|"};
    patterns['1'] = {"   ", "  |", "  |"};
    patterns['2'] = {" _ ", " _|", "|_ "};
    patterns['3'] = {" _ ", " _|", " _|"};
    patterns['4'] = {"   ", "|_|", "  |"};
    patterns['5'] = {" _ ", "|_ ", " _|"};
    patterns['6'] = {" _ ", "|_ ", "|_|"};
    patterns['7'] = {" _ ", "  |", "  |"};
    patterns['8'] = {" _ ", "|_|", "|_|"};
    patterns['9'] = {" _ ", "|_|", " _|"};
    patterns['+'] = {"   ", " _ ", " _ "};
    patterns['-'] = {"   ", " _ ", "   "};
    patterns['*'] = {"   ", "|_ ", "|_ "};
    patterns['%'] = {"| |", " _ ", "|_|"};
    patterns['='] = {"   ", " _ ", " _ "};
    return patterns;
}

int count_diff(const vector<string>& s1, const vector<string>& s2) {
    int diff = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (s1[i][j] != s2[i][j]) {
                diff++;
            }
        }
    }
    return diff;
}

long long evaluate(const vector<char>& expression) {
    long long result = 0;
    long long current_num = 0;
    char op = '+';

    for (size_t i = 0; i < expression.size(); ++i) {
        if (isdigit(expression[i])) {
            current_num = current_num * 10 + (expression[i] - '0');
        } else {
            if (op == '+') result += current_num;
            else if (op == '-') result -= current_num;
            else if (op == '*') result *= current_num;
            else if (op == '%') result %= current_num;
            
            op = expression[i];
            current_num = 0;
        }
    }
    if (op == '+') result += current_num;
    else if (op == '-') result -= current_num;
    else if (op == '*') result *= current_num;
    else if (op == '%') result %= current_num;
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    cin.ignore();

    vector<string> lines(3);
    for (int i = 0; i < 3; ++i) {
        getline(cin, lines[i]);
    }

    map<char, vector<string>> correct_patterns = get_correct_patterns();
    vector<vector<string>> parsed_displays(N, vector<string>(3));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            parsed_displays[i][j] = lines[j].substr(i * 4, 3);
        }
    }

    vector<char> base_chars(N);
    vector<pair<int, char>> faulty_candidates;
    int equals_pos = -1;

    for (int i = 0; i < N; ++i) {
        bool found_match = false;
        for (auto const &(key val): correct_patterns) {
            if (count_diff(parsed_displays[i], val) == 0) {
                base_chars[i] = key;
                if (key == '=') equals_pos = i;
                found_match = true;
                break;
            }
        }
        if (!found_match) {
            for (auto const& [key, val] : correct_patterns) {
                if (count_diff(parsed_displays[i], val) == 1) {
                    faulty_candidates.push_back({i, key});
                }
            }
        }
    }

    string rhs_str;
    for (int i = equals_pos + 1; i < N; ++i) {
        rhs_str += base_chars[i];
    }
    long long rhs_val = stoll(rhs_str);

    for (const auto& candidate : faulty_candidates) {
        vector<char> temp_chars = base_chars;
        temp_chars[candidate.first] = candidate.second;

        vector<char> lhs_expr;
        for (int i = 0; i < equals_pos; ++i) {
            lhs_expr.push_back(temp_chars[i]);
        }

        if (evaluate(lhs_expr) == rhs_val) {
            cout << candidate.first + 1 << endl;
            return 0;
        }
    }

    return 0;
}