class Solution{
public:
	int minStepToDeleteString(string str) 
	{ 
	    int N = str.length();

        int dp[N + 1][N + 1];
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++)
                dp[i][j] = 0;
     
        // loop for substring length we are considering
        for (int len = 1; len <= N; len++)
        {
            // loop with two variables i and j, denoting
            // starting and ending of substrings
            for (int i = 0, j = len - 1; j < N; i++, j++)
            {
                // If substring length is 1, then 1 step will be needed
                if (len == 1)
                    dp[i][j] = 1;
                else
                {
                    // delete the ith char individually
                    // and assign result for subproblem (i+1,j)
                    dp[i][j] = 1 + dp[i + 1][j];
     
                    // if current and next char are same,
                    // choose min from current and subproblem (i+2,j)
                    if (str[i] == str[i + 1])
                        dp[i][j] = min(1 + dp[i + 2][j], dp[i][j]);
     
                    /*  loop over all right characters and suppose
                        Kth char is same as ith character then
                        choose minimum from current and two
                        substring after ignoring ith and Kth char */
                    for (int K = i + 2; K <= j; K++)
                        if (str[i] == str[K])
                            dp[i][j] = min(dp[i+1][K-1] + dp[K+1][j], dp[i][j]);
                }
            }
        }
        return dp[0][N - 1];
	} 
 };
