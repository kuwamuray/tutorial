import itertools
import random
import time

T1 = time.time()

A = [[0 for i in range(3)] for j in range(8)]

def score_sum(T):
        global A
        N = 0
        for i in range(8):
                N += A[i][int(T[i])]
        return N

print()
for i in range(8):
        B = A[i][0] + A[i][1]
        while B == 0 or B > 100 :
                A[i][0] = random.randrange(101)
                A[i][1] = random.randrange(101)
                B = A[i][0] + A[i][1]
        A[i][2] = 100 - B
        print("SCORE LIST " + str(i+1) + " : " + str(A[i]))
print()

C = list(map(lambda x : [score_sum(x), x], list(set(itertools.permutations("00011122")))))
C.sort(reverse=True) 

i = 0
D = int(C[0][0])
while True :
        print("MAX SCORE = " + str(D) + " : INDEX = " + str(C[i][1]))
        i += 1
        if D != C[i][0] :
                break

T2 = time.time()

print()
print("TIME : " + str(T2-T1))
print()
