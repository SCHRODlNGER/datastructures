
def inverse_matrix(q):
    n = len(q)
    I = [[(0, 1) for _ in range(n)] for _ in range(n)]

    for i in range(n):
        I[i][i] = (1, 1)

    for i in range(n):
        div = q[i][i]

        for j in range(n):
            q[i][j] = div_2_frac( q[i][j] , div)
            I[i][j] = div_2_frac( I[i][j] , div)


        

        for j in range(n):
            if j == i:
                continue
            mul = q[j][i]
            for k in range(n):
                q[j][k] = sub_2_frac( q[j][k] ,  mul_2_frac( mul , q[i][k]))
                I[j][k] = sub_2_frac( I[j][k] , mul_2_frac (mul , I[i][k]) )
    
    return I