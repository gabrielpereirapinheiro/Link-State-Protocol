#TAD de grafos em python

#Victor Araujo Vieira - 14/0032801
#Gabriel Pereira Pinheiro - 14/0020764

#classe que implementa as funcionalidades dos vertices individuais do grafo
class Vertice:
	#construtor do vertice
	def __init__(self, chave):
		self.id = chave
		self.lista_adjacentes = {}

	#metodo que adiciona vizinhos ao vertice
	def adiciona_vizinhos(self, chave_vizinho, peso = 0):
	    self.lista_adjacentes[chave_vizinho] = peso

	#metodo que retorna todos os vizinhos do vertice
	def get_conexoes(self):
		return self.lista_adjacentes.keys()

	#metodo que retorna o identificador do vertice
	def get_id(self):
		return self.id

	#metodo que retorna o peso de uma aresta do vertice
	def get_peso(self, chave_vizinho):
		return self.lista_adjacentes[chave_vizinho]

#classe do grafo geral em si, ou seja, a topologia
class Grafo:
	#construtor do grafo
	def __init__(self):
		self.lista_vertices = {}
		self.num_vertices = 0

	#metodo que vai adicionar um vertice no grafo
	def adiciona_vertice(self, id_vertice):
		self.num_vertices = self.num_vertices + 1
		novo_vertice = Vertice(id_vertice)
		self.lista_vertices[id_vertice] = novo_vertice
		return novo_vertice

	#metodo que retorna um vertice do grafo
	def get_vertice(self, id_vertice):
		if id_vertice in self.lista_vertices:
			return self.lista_vertices[id_vertice]
		else:
			print "Nao existe o vertice no grafo!"
			return None

	#metodo que verifica se existe o vertice no grafo ou nao
	#retorna True or False
	def verifica_se_existe_no_grafo(self, id_vertice):
		return id_vertice in self.lista_vertices

	#metodo que adiciona uma aresta entre os vertices x e y no grafo
	#um grafo nao dirigido
	def adiciona_aresta(self, x, y, peso = 0):
		if x not in self.lista_vertices:
		    novo_vert = self.adiciona_vertice(self, x)
		if y not in self.lista_vertices:
			novo_vert = self.adiciona_vertice(self, y)
		    #grafo nao dirigido, ou seja, vai adicionar os vizinhos nos dois
		self.lista_vertices[x].adiciona_vizinhos(self.lista_vertices[y], peso)
		self.lista_vertices[y].adiciona_vizinhos(self.lista_vertices[x], peso)

	#metodo que retorna os vertices do grafo
	def get_vertices(self):
		return self.lista_vertices.keys()


g = Grafo()

g.adiciona_vertice('V0')
g.adiciona_vertice('V1')
g.adiciona_vertice('V2')
g.adiciona_vertice('V3')
g.adiciona_vertice('V4')
g.adiciona_vertice('V5')

g.adiciona_aresta('V0', 'V1', 5)
g.adiciona_aresta('V0', 'V4', 1)
g.adiciona_aresta('V0', 'V5', 2)
g.adiciona_aresta('V1', 'V2', 4)
g.adiciona_aresta('V2', 'V3', 9)
g.adiciona_aresta('V2', 'V5', 1)
g.adiciona_aresta('V3', 'V5', 3)
g.adiciona_aresta('V3', 'V4', 7)
g.adiciona_aresta('V4', 'V5', 8)

for v in g.lista_vertices:
	for w in g.get_vertice(v).get_conexoes():
		print ("(%s, %s)" % (g.get_vertice(v).get_id(), w.get_id()))