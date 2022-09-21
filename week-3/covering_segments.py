# input part.
n = int(input())

coordinates_ls = []
for i in range(n):
    inp = [int(i) for i in input().split()]
    coordinates_ls.append(inp)

# list is sorted according to the second element of inner array.
coordinates_ls.sort(key=lambda x: x[1])

# most right is the selection points of the segments.
most_right = coordinates_ls[0][1]
point_ls = [most_right]
count = 1
for i in range(n):
    # if most right point is not in the stated range, meaning that
    # that line segment is not selected, so we select it by updating
    # most right value.
    if not (coordinates_ls[i][0]) <= most_right <= (coordinates_ls[i][1]):
        most_right = coordinates_ls[i][1]
        point_ls.append(most_right)
        count += 1

print(count)
for i in point_ls:
    print(i, end=" ")
print()

