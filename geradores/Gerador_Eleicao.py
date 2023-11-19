import random

eleitores = []
# titulo e numero
vereadores = []
numVereadores = []
# titulo e numero
prefeitos = []
numPrefeitos = []

with open("geradores/eleitor.txt", "r") as f:
    while True:
        linha = f.readline()
        if linha == "":
            break
        eleitor = linha.split(",")[0]
        eleitores.append(eleitor)

with open("geradores/vereador.txt ", "r") as f:
    while True:
        linha = f.readline()

        if linha == "":
            break

        vereador = linha.split(",")[0]
        numVereador = linha.split(",")[6]
        vereadores.append(vereador)
        numVereadores.append(numVereador)

with open("geradores/prefeito.txt", "r") as f:
    while True:
        linha = f.readline()

        if linha == "":
            break

        prefeito = linha.split(",")[0]
        numPrefeito = linha.split(",")[6]
        prefeitos.append(prefeito)
        numPrefeitos.append(numPrefeito)

with open("geradores/votosVereador.txt", "w") as f:
    for eleitor in eleitores:
        voto = random.choice(numVereadores)
        f.write("{},{}".format(eleitor, voto))
    
    for prefeito in prefeitos:
        voto = random.choice(numVereadores)
        f.write("{},{}".format(prefeito, voto))

    for i in range(len(vereadores)):
        # vereador vota em si mesmo
        f.write("{},{}".format(vereadores[i], numVereadores[i]))

with open("geradores/votosPrefeito.txt", "w") as f:
    for eleitor in eleitores:
        voto = random.choice(numPrefeitos)
        f.write("{},{}".format(eleitor, voto))

    for vereador in vereadores:
        voto = random.choice(numPrefeitos)
        f.write("{},{}".format(vereador, voto))
    
    for i in range(len(prefeitos)):
        # prefeito vota em si mesmo
        f.write("{},{}".format(prefeitos[i], numPrefeitos[i]))