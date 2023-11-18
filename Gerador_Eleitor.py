import random

def generate_voters(n):
  """Gera uma lista de eleitores com n registros."""
  eleitor = []
  
  for i in range(n):
    titulo = random.randint(10000, 99999)
    nome = random.choice(["João", "Hugo", "Lele", "Marianna", "Pedro", "Lidson",
                          "Ellen", "Ricardo", "Leo", "Lucas", "Nicolas", "Thierry"])
    sobrenome = random.choice(["da Silva", "das Dores", "Pereira", "Ferreira", "de Jesus",
                               "Pinto", "Souza", "Santos", "Rodrigues", "Lima", "Oliveira", "Martins"])
    zona = random.randint(1, 5000)
    secao = random.randint(1, 5000)
    eleitor.append((titulo, nome + " " + sobrenome, zona, secao))
  return eleitor

eleitor = generate_voters(2000)

with open("eleitor.txt", "w") as f:
  for pessoa in eleitor:
    f.write("{},{},{},{}\n".format(*pessoa))
