class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "+" && tokens[i] != "*"
            && tokens[i] != "/" && tokens[i] != "-"){
                s.push(tokens[i]);
            }else if(tokens[i] == "+"){
                int second = stoi(s.top());
                s.pop();
                int first = stoi(s.top());
                s.pop();
                int temp = first + second;
                string tempResult = to_string(temp);
                s.push(tempResult);
            }else if(tokens[i] == "/"){
                int second = stoi(s.top());
                s.pop();
                int first = stoi(s.top());
                s.pop();
                int temp = first / second;
                string tempResult = to_string(temp);
                s.push(tempResult);
            }else if(tokens[i] == "*"){
                int second = stoi(s.top());
                s.pop();
                int first = stoi(s.top());
                s.pop();
                int temp = first * second;
                string tempResult = to_string(temp);
                s.push(tempResult);
            }else if(tokens[i] == "-"){
                int second = stoi(s.top());
                s.pop();
                int first = stoi(s.top());
                s.pop();
                int temp = first - second;
                string tempResult = to_string(temp);
                s.push(tempResult);
            }
        }
        return stoi(s.top());
    }
};
