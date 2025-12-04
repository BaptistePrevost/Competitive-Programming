M = []
with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    for line in f.readlines():
        M.append(line.strip())

# ans = 0
# for i in range(len(M)):
#     for j in range(len(M[0])):
#         for di in (-1, 0, 1):
#             for dj in (-1, 0, 1):
#                 if i+3*di < len(M) and i+3*di >= 0 and j+3*dj < len(M[0]) and j+3*dj >= 0:
#                     if M[i][j] == 'X' and M[i+di][j+dj] == 'M' and M[i+2*di][j+2*dj] == 'A' and M[i+3*di][j+3*dj] == 'S':
#                         ans += 1
#                     if M[i][j] == 'S' and M[i+di][j+dj] == 'A' and M[i+2*di][j+2*dj] == 'M' and M[i+3*di][j+3*dj] == 'X':
#                         ans += 1
# print(ans//2)
        
ans = 0
for i in range(1, len(M)-1):
    for j in range(1, len(M[0])-1):
        s = M[i-1][j-1]+M[i][j]+M[i+1][j+1]
        t = M[i+1][j-1]+M[i][j]+M[i-1][j+1]
        if (s == "MAS" or s == "SAM") and (t == "MAS" or t == "SAM"): ans += 1

print(ans)