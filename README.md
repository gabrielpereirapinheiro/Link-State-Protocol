# Protocolo Link State Protocol (LSP)

### Autores:

- Gabriel Pereira Pinheiro 

- Victor Araujo Vieira  

### Email :

- gabriel.pereira.pinheiro@gmail.com

- icevct@gmail.com


### COMO EXECUTAR O PROGRAMA :

- Abra o terminal na pasta principal do programa, e digite o comando:

> $make

- Feito o make, basta digitar

> $./lsp 

- que sera executado o programa.

### INTRODUÇÃO :

- O código gerado tem como objetivo simular o funcionamento do protocolo ```LSP``` ([Link State Protocol](https://en.wikipedia.org/wiki/Link-state_routing_protocol)), para isso foi utilizado a topologia da National Science Foundation Network ([NSFNET](https://www.nsf.gov/news/news_summ.jsp?cntn_id=103050)) .

### METODOLOGIA :

- O modo que o grupo pensou de realizar o ```flooding``` foi separar o programa em funções, a mais básica iria enviara mensagem para todos os seus vizinhos, outra iria controlar quais seriam os nós que iriam enviar as mensagem para os seus vizinhos de modo que a mensagem fosse propagada por toda a topologia. Uma outra funçao irá ser a responsavel por enviar o custo do nó atual para cada vizinho direto dele para todos os nós da topologia. E a função mais abrangente irá controlar qual será o nó que ira ser enviado para a ultima funcao comentada, isto é, essa funcao resumidademnte iŕa peccorrer todos os nós do grafo para que assim, todo nó dissemine os seus custos com seus vizinhos para todos os nós do grafo. No final é esperado que cada nó presente na topologia conheça tenha informação completa da rede, quando isso acontecer,é quando o convergiu. 

### RESULTADO :

- Será gerado, ao executar o código, um arquivo txt chamado ```estatistica.txt```, que terá para cada nó do grafo NFSNET, a sua tabela (database) com todos os caminhos da topologia e o vetor de distâncias para todos os outros nós, calculado usando o algoritmo de [Dijkstra](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm).

### CONCLUSÃO :

- Após a execução do programa e a analise do arquivo txt com as tabelas foi possivel notar que as tabelas convegiram, isto é, cada nó tem a mesma tabela da topologia, mostrando que as informações foram enviadas com sucesso a todos na rede.

