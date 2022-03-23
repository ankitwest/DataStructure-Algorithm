

// Greedy
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int k=0;
        while(target>startValue){
            if(target%2==0)
                target /=2;
            else
                target +=1;
            k++;
        }
        if(target<startValue) return k+startValue-target;
        return k;
    }
};

Example 1:

Input: startValue = 2, target = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.
Example 2:

Input: startValue = 5, target = 8
Output: 2
Explanation: Use decrement and then double {5 -> 4 -> 8}.
