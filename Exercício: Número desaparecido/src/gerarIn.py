import random

# "Digite N: "
N = int(input())
# "1) Crescente 2) Decrescente 3) Aleatório :: "
modo = int(input())
# N = 10
# modo = 3

vetor = []
if modo == 1:
    for i in range(1,N+1):
        vetor.append(i)
    vetor.remove(random.choice(vetor))

elif modo == 2:
    for i in range(N,0,-1):
        vetor.append(i)
    vetor.remove(random.choice(vetor)) 
    
elif modo == 3:
    for i in range(1,N+1):
        vetor.append(i)
    vetor.remove(random.choice(vetor)) 
    random.shuffle(vetor)
        
elif modo == 4:
    for i in range(1,N+1):
        vetor.append(i)
    vetor.remove(N) 
    # random.shuffle(vetor)

# Imprimir no arquivo
# print(vetor)
print(N)
for i in vetor:
    print(i, end=' ')