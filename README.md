# LinkStateProt_TR2


Implementação do protocolo Link State Protocol

Autores : Gabriel Pereira Pinheiro - 14/0020764

Victor Araujo Vieira - 14/0032801

email : gabriel.pereira.pinheiro@hotmail.com

icevct@gmail.com

Universida de Brasilia - UnB

Departamento de Ciencia da Computação

COMO EXECUTAR O PROGRAMA :

Abra o terminal na pasta principal do programa, e digite o comando make. Feito o make, basta digitar ./lsp que sera executado o programa.

INTRODUCAO :

O código gerado tem como objetivo simular o funcionamento do protocolo LSP (Link State Protocol), para isso foi utilizado a topologia da National Science Foundation Network (NSFNET) .

METODOLOGIA :

O modo que o grupo pensou de realizar o flooding foi separar o programa em funcoes, a mais básica iria enviara mensagem para todos os seus vizinhos, outra iria controlar quais seriam os nós que iriam enviar as mensagem para os seus vizinhos de modo que a mensagem fosse propagada por toda a topologia

RESULTADO:

Será gerado, ao executar o código, um arquivo txt chamado estatistica.txt, que terá para cada nó do grafo NFSNET, a sua tabela (database) com todos os caminhos da topologia e o vetor de distâncias para todos os outros nós, calculado usando o algoritmo de Dijkstra.

