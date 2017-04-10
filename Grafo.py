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
    def __init__:
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
    def verifica_se_existe_no_grafo(self, 	id_vertice):
    	return n in self.lista_vertices

    #metodo que adiciona uma aresta entre os vertices x e y no grafo
    #um grafo nao dirigido
	def adiciona_vertice(self, x, y, peso = 0):
		if x not in self.lista_vertices:
		    novo_vert_x = self.adiciona_vertice(self, x)
		if y not in self.lista_vertices:
		    novo_vert_y = self.adiciona_vertice(self, y)

		#grafo nao dirigido, ou seja, vai adicionar os vizinhos nos dois
		self.lista_vertices[x].adiciona_vizinhos(self.lista_vertices[y], peso)
		self.lista_vertices[y].adiciona_vizinhos(self.lista_vertices[x], peso)

	#metodo que retorna os vertices do grafo
	def get_vertices(self):
		return self.lista_vertices.keys()

	
	def __iter__(self):
		return iter(self.lista_vertices.values())