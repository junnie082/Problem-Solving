N = int(input())
dp = [ dict() for _ in range(N+1) ]

if N == 1:
    print(1)
elif N == 2:
    print(1)
else:
    dp[1][0], dp[1][1] = 0, 1
    dp[2][0], dp[2][1] = 1, 0

    for i in range(3, N+1):
        dp[i][0] = dp[i-1][0] + dp[i-1][1]
        dp[i][1] = dp[i-1][0]

    print(dp[N][0] + dp[N][1])
