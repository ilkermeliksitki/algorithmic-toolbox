#!/usr/bin/env python3

def sweep_line(data, points):
    """
    consider the following example:
    2 3
    0 5
    1 1 <--- 
    7 10
    1 2 6 
    let us denote the following symbols
    opening gate: <(1), closing gate: >(3), point: .(2)

    sort all data
    <----->
      <>
              <-->
    0 1 2 5 6 7 10
      . .   .
    apply sweep line algorithm.
    =================================================
    < <       <
      >   >     >
      . .   .
    0 1 2 5 6 7 10
    1 2 1 0 0 1 0  <---- counter value.
    """
    points_dict = {}
    counter = 0
    for i in range(len(data)):
        if data[i][1] == 1:
            "open gate condition"
            counter += 1
        if data[i][1] == 2:
            "the location of the point"
            points_dict[data[i][0]] = counter
        if data[i][1] == 3:
            "close gate condition"
            counter -= 1

            
    for i in points:
        print(points_dict[i], end=' ')
    print()

if __name__ == '__main__':
    """
    Points and Segments Problem
    Given a set of points and a set of segments on a line, compute, for each point, 
    the number of segment it is contained in,

    Input: A list of `n` segments and a list of `m` points.
    Output: The number of segments containing each point.

    Input Format: The first line contains two non-negative integer `n` and `m` 
        defining the number of segments and the number of points on a line, 
        respectively. The next `n` lines contain two integers l_i, r_i defining
        the i-th segment [l_i, r_i]. The next line contains `m` integers defining
        points p_1, p_2, ... , p_m.
    Output Format: `m` non negative integers k_1, k_2, ... , k_p where k_i is the
    number of segments that contain p_i.

    Constraints: 1 <= n,m <= 50000; -10^8 <= l_i, r_i <= 10^8 for all 1 <= i <=n;
        -10^8 <= p_j <= 10^8 for all 1 <= j <= m

    Samples:
        Input 1:
        2 3
        0 5
        7 10
        1 6 11
        Output 1:
        1 0 0

        Input 2:
        1 3
        -10 10 
        -100 100 0
        Output 2:
        0 0 1

        Input 3:
        3 2
        0 5
        -3 2
        7 10
        1 6
        Output 3:
        2 0
    """
    n, m = [int(i) for i in input().split()]
    open_gates, close_gates = [[0, 1] for _ in range(n)], [[0, 3] for _ in range(n)]
    for i in range(n):
        o_str, c_str = input().split()
        open_gates[i][0] = int(o_str)
        close_gates[i][0] = int(c_str)

    points = [[0, 2] for _ in range(m)]
    raw_points = [int(j) for j in input().split()]
    for i, item in enumerate(raw_points):
        points[i][0] = item

    whole_data = open_gates + close_gates + points

    # sort with respect to 0th element.
    whole_data.sort(key= lambda item: (item[0], item[1]))
    sweep_line(whole_data, raw_points)


