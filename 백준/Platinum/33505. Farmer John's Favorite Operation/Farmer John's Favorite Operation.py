T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    A = sorted([x % M for x in map(int, input().split())])
    A += [x + M for x in A]
    
    cum = [0]
    for x in A:
        cum.append(cum[-1] + x)

    ans = float('inf')
    for i in range(N):
        mid_sum = cum[i + N] - cum[i + N - N // 2]
        other_sum = cum[i + N // 2] - cum[i]
        ans = min(ans, mid_sum - other_sum)
    print(ans)