def change(a):
    for i in range(10):
        for j in range(10):
            a[i][j]=0 if a[i][j]==0 else 1


import numpy as np;
lingjie=np.array([
        [1,0,0,0,0,0,0,0,0,0],
        [1,0,0,0,0,0,0,0,0,0],
        [0,1,0,0,0,0,0,0,0,0],
        [0,1,1,0,0,0,1,0,0,0],
        [0,0,0,0,0,0,0,0,0,0],
        [0,0,1,0,0,0,0,0,0,0],
        [0,0,0,1,0,0,0,0,0,0],
        [0,0,0,0,1,1,1,0,0,0],
        [0,0,0,0,0,0,1,1,0,0],
        [0,0,0,0,0,0,0,0,1,0]
]);
E=np.array(
    [
        [1,0,0,0,0,0,0,0,0,0],
        [0,1,0,0,0,0,0,0,0,0],
        [0,0,1,0,0,0,0,0,0,0],
        [0,0,0,1,0,0,0,0,0,0],
        [0,0,0,0,1,0,0,0,0,0],
        [0,0,0,0,0,1,0,0,0,0],
        [0,0,0,0,0,0,1,0,0,0],
        [0,0,0,0,0,0,0,1,0,0],
        [0,0,0,0,0,0,0,0,1,0],
        [0,0,0,0,0,0,0,0,0,1],
    ]
)

M=lingjie+E
change(M)
mat1=np.mat(M)
count=1
while True:
    mat_pre=mat1**(count)
    mat_aft=mat1**(count+1)
    mat_pre_arr=np.array(mat_pre)
    mat_aft_arr=np.array(mat_aft)
    change(mat_pre_arr)
    change(mat_aft_arr)
    count=count+1
    if (np.mat(mat_pre_arr)==np.mat(mat_aft_arr)).all():
        print(count-1,"次可以计算出可达矩阵")
        print("可达矩阵为:")
        print(np.mat(mat_aft_arr))
        break





