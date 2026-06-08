# First try
""" E = int(input())
S = int(input())
L = int(input())

ESL = abs(E - S) + abs(S - L) + abs(L - E)
ELS = abs(E - L) + abs(L - S) + abs(S - E)

if ESL > ELS:
    print(ELS)
else:
    print(ESL) """

# Second try
E = int(input())
S = int(input())
L = int(input())

print(2*(max(E, S, L) - min(E, S, L)))