class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = SumofSquares(n);

        while (fast != 1 && slow != fast) {
            slow = SumofSquares(slow);
            fast = SumofSquares(SumofSquares(fast));
        }

        return fast == 1;
    }

private:

    int SumofSquares(int n) {
        int sum = 0;

        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }

        return sum;
    }
};