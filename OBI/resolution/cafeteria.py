A = int(input()) # min
B = int(input()) # max
C = int(input()) # Capacidade da xicara
D = int(input()) # Dose

def leite(A, B, C, D):
    control = C

    while control > 0:
        if A <= control and B >= control:
            return "S"
        
        control -= D
    
    return "N"

print(leite(A, B, C, D))