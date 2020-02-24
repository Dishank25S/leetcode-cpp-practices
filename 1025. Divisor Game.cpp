//make all_divisors an array of array
//Runtime: 20 ms, faster than 6.95% of C++ online submissions for Divisor Game.
//Memory Usage: 10.6 MB, less than 6.90% of C++ online submissions for Divisor Game.
class Solution {
public:
    vector<vector<int>> all_divisors;
        
    vector<int> getDivisors(int x){
        vector<int> divisors;
        
        for(int divisor = x/2; divisor >= 1; divisor--){
            if(x % divisor == 0){
                if(divisor == 1){
                    divisors.push_back(divisor);
                }else{
                    if(divisor == x / divisor){
                        divisors = all_divisors[divisor];
                        divisors.push_back(divisor);
                    }else{
                        vector<int> a = all_divisors[divisor];
                        vector<int> b = all_divisors[x / divisor];
                        sort(a.begin(), a.end());
                        sort(b.begin(), b.end());
                        divisors = vector<int>(a.size() + b.size());
                        std::vector<int>::iterator it = std::set_union(a.begin(), a.end(), b.begin(), b.end(), divisors.begin());
                        divisors.resize(it - divisors.begin());
                        divisors.push_back(divisor);
                        divisors.push_back(x / divisor);
                    }
                    
                }
                break;
            }
        }
        return divisors;
    }
    
    bool divisorGame(int N) {
        vector<bool> win(N+1, false);
        all_divisors = vector<vector<int>>(N+1);
        
        win[1] = false;
        
        for(int i = 2; i <= N; i++){
            cout << "i: " << i << endl;
            all_divisors[i] = getDivisors(i);
            copy(all_divisors[i].begin(), all_divisors[i].end(), ostream_iterator<int>(cout, " "));
            cout << endl;
            // cout << "win: " << win[i] << endl;
            //if it can find a divisor so that win[i-divisor] is false, i will win
            for(int divisor : all_divisors[i]){
                if(!win[i - divisor]){
                    win[i] = true;
                    break;
                }
            }
            // cout << "win: " << win[i] << endl;
        }
        
        return win[N];
    }
};