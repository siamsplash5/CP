class BIG_INTEGER
{
public:
    string add(string s1, string s2) {
        string s;
        int n = s1.size();
        int m = s2.size();
        if (n > m)for (int i = 0; i < abs(n - m); i++)s2 = '0' + s2;
        else if (n < m)for (int i = 0; i < abs(n - m); i++)s1 = '0' + s1;
        int sum, carry = 0, len = s2.size();
        for (int i = len - 1; i >= 0; i--) {
            s += ((s1[i] - '0' + s2[i] - '0' + carry) % 10) + '0';
            carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
        }
        while (carry) {
            s += carry + '0';
            carry /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    string substract(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        string s;
        if (n < m)swap(s1, s2);
        else if (n == m && s1 < s2)swap(s1, s2);
        if (s1 == s2)return "0";
        if (n > m) for (int i = 0; i < abs(n - m); i++)s2 = '0' + s2;
        for (int i = n - 1; i >= 0; i--) {
            if (s1[i] >= s2[i])s += s1[i] - s2[i] + '0';
            else {
                s += (s1[i] - '0' + 10 - (s2[i] - '0') + '0');
                s2[i - 1] = (s2[i - 1] - '0' + 1) + '0';
            }
        }
        while (s.back() == '0') s.pop_back();
        reverse(s.begin(), s.end());
        return s;
    }

    string multiply(string s1, string s2) {
        int n = s2.size();
        int m = s1.size();
        string s;
        reverse(s1.begin(), s1.end());
        int carry = 0, d = stoi(s2);
        for (int j = 0; j < m; j++) {
            s += (((s1[j] - '0') * d + carry) % 10) + '0';
            carry = ((s1[j] - '0') * d + carry) / 10;
        }
        while (carry) {
            s += (carry % 10) + '0';
            carry /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    string division(string number, int divisor) {
        string ans;
        int idx = 0, temp = number[idx] - '0', len = number.size();
        while (temp < divisor)temp = temp * 10 + (number[++idx] - '0');
        number += "0";
        while (len > idx) {
            ans += (temp / divisor) + '0';
            temp = (temp % divisor) * 10 + number[++idx] - '0';

        }
        // temp variable is the reminder (mod value)
        if (ans.length() == 0)return "0";
        return ans;
    }
};