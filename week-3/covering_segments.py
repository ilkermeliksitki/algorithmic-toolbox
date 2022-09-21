# input part.
n = int(input())

coordinates_ls = []
for i in range(n):
    inp = [int(i) for i in input().split()]
    coordinates_ls.append(inp)

# list is sorted according to the second element of inner array.
coordinates_ls.sort(key=lambda x: x[1])

# rightmost is the selection points of the segments.
rightmost = coordinates_ls[0][1]
point_ls = [rightmost]
count = 1
for i in range(n):
    # if rightmost point is not in the stated range, meaning that
    # that line segment is not selected, so we select it by updating
    # rightmost value.
    if not (coordinates_ls[i][0]) <= rightmost <= (coordinates_ls[i][1]):
        rightmost = coordinates_ls[i][1]
        point_ls.append(rightmost)
        count += 1

print(count)
for i in point_ls:
    print(i, end=" ")
print()

