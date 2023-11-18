import random

def generate_mayor(n):
  """Gera uma lista de eleitores com n registros."""
  prefeito = []
  
  for i in range(n):
    titulo = random.randint(10000, 99999)
    numero = random.randint(1, 99)
    nome = random.choice(["João", "Hugo", "Lele", "Marianna", "Pedro", "Lidson",
                          "Ellen", "Ricardo", "Leo", "Lucas", "Nicolas", "Thierry"])
    sobrenome = random.choice(["da Silva", "das Dores", "Pereira", "Ferreira", "de Jesus",
                               "Pinto", "Souza", "Santos", "Rodrigues", "Lima", "Oliveira", "Martins"])
    partido = random.choice(["PSDB", "PL", "PT", "PCdoB", "PCB", "NOVO", "PP", "PSOL", "PSTU", "PDT", "PSB", "PSC"])
    cidade = random.choice(["Viçosa", "Ponte Nova", "Coimbra", "Belo Horizonte", "Vitória", "Vila Velha",
                            "São Paulo", "Rio de Janeiro", "Curitiba", "Brasília", "Salvador", "Recife"])
    zona = random.randint(1, 5000)
    secao = random.randint(1, 5000)
    prefeito.append((titulo, nome + " " + sobrenome, zona, secao, partido, cidade, numero))
  return prefeito

prefeito = generate_mayor(5)

with open("prefeito.txt", "w") as f:
  for pessoa in prefeito:
    f.write("{},{},{},{},{},{},{}\n".format(*pessoa))
# titulo, num, nome, zona, secao, partido, cidade 
