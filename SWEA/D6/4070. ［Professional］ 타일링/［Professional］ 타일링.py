

arr = [0] * 251

arr[1] = 1
arr[2] = 3

for i in range(3, 251):
    arr[i] = arr[i - 1] + arr[i - 2] * 2

T = int(input())

for test_case in range(1, T + 1):
    n = int(input())

    print(f"#{test_case} {arr[n]}")