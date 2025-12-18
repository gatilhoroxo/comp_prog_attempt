#include <bits/stdc++.h>
using namespace std;

#define vec(n) vector<n>
#define FOR(i,start,n, op) for(int i=start; i op n; i++)

void INPUT() {}
template<typename T, typename... Targs>
void INPUT(T&& value, Targs&&... Fargs){
    cin >> value; 
    INPUT(forward<Targs>(Fargs)...);
}

class BigInt {
private:
    vector<int> digits;
    bool negative;
    
    void remove_leading_zeros() {
        while(digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if(digits.size() == 1 && digits[0] == 0) {
            negative = false;
        }
    }
    
public:
    BigInt() : digits(1, 0), negative(false) {}
    
    BigInt(long long num) {
        negative = num < 0;
        num = abs(num);
        if(num == 0) {
            digits.push_back(0);
        } else {
            while(num > 0) {
                digits.push_back(num % 10);
                num /= 10;
            }
        }
    }
    
    BigInt(string s) {
        negative = false;
        if(s[0] == '-') {
            negative = true;
            s = s.substr(1);
        }
        for(int i = s.size() - 1; i >= 0; i--) {
            digits.push_back(s[i] - '0');
        }
        remove_leading_zeros();
    }
    
    string to_string() const {
        string result = "";
        if(negative) result += "-";
        for(int i = digits.size() - 1; i >= 0; i--) {
            result += char('0' + digits[i]);
        }
        return result;
    }
    
    double to_double() const {
        double result = 0;
        double base = 1;
        for(int digit : digits) {
            result += digit * base;
            base *= 10;
        }
        return negative ? -result : result;
    }
    
    bool operator<(const BigInt& other) const {
        if(negative != other.negative) return negative;
        if(digits.size() != other.digits.size()) {
            return negative ? digits.size() > other.digits.size() 
                           : digits.size() < other.digits.size();
        }
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] != other.digits[i]) {
                return negative ? digits[i] > other.digits[i]
                               : digits[i] < other.digits[i];
            }
        }
        return false;
    }
    
    bool operator==(const BigInt& other) const {
        return negative == other.negative && digits == other.digits;
    }
    
    bool operator<=(const BigInt& other) const {
        return *this < other || *this == other;
    }
    
    bool operator>(const BigInt& other) const {
        return !(*this <= other);
    }
    
    bool operator>=(const BigInt& other) const {
        return !(*this < other);
    }
    
    BigInt add(const BigInt& other) const {
        BigInt result;
        result.digits.clear();
        int carry = 0;
        size_t max_size = max(digits.size(), other.digits.size());
        
        for(size_t i = 0; i < max_size || carry; i++) {
            int sum = carry;
            if(i < digits.size()) sum += digits[i];
            if(i < other.digits.size()) sum += other.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        return result;
    }
    
    BigInt subtract(const BigInt& other) const {
        BigInt result;
        result.digits.clear();
        int borrow = 0;
        
        for(size_t i = 0; i < digits.size(); i++) {
            int diff = digits[i] - borrow;
            if(i < other.digits.size()) diff -= other.digits[i];
            
            if(diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(diff);
        }
        result.remove_leading_zeros();
        return result;
    }
    
    BigInt operator+(const BigInt& other) const {
        if(negative == other.negative) {
            BigInt result = add(other);
            result.negative = negative;
            return result;
        } else {
            if(*this >= other) {
                BigInt result = subtract(other);
                result.negative = negative;
                return result;
            } else {
                BigInt result = other.subtract(*this);
                result.negative = other.negative;
                return result;
            }
        }
    }
    
    BigInt operator-(const BigInt& other) const {
        BigInt neg_other = other;
        neg_other.negative = !neg_other.negative;
        return *this + neg_other;
    }
    
    BigInt operator*(const BigInt& other) const {
        BigInt result;
        result.digits.assign(digits.size() + other.digits.size(), 0);
        
        for(size_t i = 0; i < digits.size(); i++) {
            int carry = 0;
            for(size_t j = 0; j < other.digits.size() || carry; j++) {
                long long cur = result.digits[i + j] + 
                               digits[i] * 1LL * (j < other.digits.size() ? other.digits[j] : 0) + 
                               carry;
                result.digits[i + j] = cur % 10;
                carry = cur / 10;
            }
        }
        
        result.remove_leading_zeros();
        result.negative = (negative != other.negative);
        return result;
    }
    
    BigInt operator/(int divisor) const {
        BigInt result;
        result.digits.clear();
        long long remainder = 0;
        
        for(int i = digits.size() - 1; i >= 0; i--) {
            remainder = remainder * 10 + digits[i];
            result.digits.push_back(remainder / divisor);
            remainder %= divisor;
        }
        
        reverse(result.digits.begin(), result.digits.end());
        result.remove_leading_zeros();
        result.negative = negative;
        return result;
    }
    
    BigInt pow(int exp) const {
        if(exp == 0) return BigInt(1);
        if(exp == 1) return *this;
        
        BigInt half = pow(exp / 2);
        BigInt result = half * half;
        
        if(exp % 2 == 1) {
            result = result * (*this);
        }
        
        return result;
    }
    
    friend ostream& operator<<(ostream& os, const BigInt& num) {
        os << num.to_string();
        return os;
    }

};


// === === === === === === === === === === === === === === === === === === === 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,a,b;
    INPUT(n,a,b);

    vec(vec(BigInt)) dp(n+1, vec(BigInt)(6*n+1, BigInt(0)));
    dp[0][0] = BigInt(1);

    FOR(i, 1, n, <=) {
        FOR(j, i, 6*i, <=) { 
            FOR(face, 1, 6, <=) {
                if(j - face >= 0) {
                    dp[i][j] = dp[i][j] + dp[i-1][j-face];
                }
            }
        }
    }
    
    BigInt fav(0);
    for(int sum = a; sum <= b; sum++) {
        fav = fav + dp[n][sum];
    }
    
    BigInt total = BigInt(6).pow(n);
    
    double ans = fav.to_double() / total.to_double();
    
    printf("%.6f\n", ans);
    

    return 0;
}
