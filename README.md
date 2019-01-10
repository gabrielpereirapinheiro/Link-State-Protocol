# Link State Protocol (LSP)


### About :

- That code has the object to simulate the operation of the protcol ```LSP``` ([Link State Protocol](https://en.wikipedia.org/wiki/Link-state_routing_protocol)) using the C language, to do that was use the topology from National Science Foundation Network ([NSFNET](https://www.nsf.gov/news/news_summ.jsp?cntn_id=103050)) .

### How execute :

- Open the terminal inside the main folder and use the command:

``` $make ```

- After that, just use

``` $./lsp ```

- and the program will be executed.

### Methodology :

- The mode used to create the ```flooding``` was separete the program in functions, the more basci was responsable to send the message to all your neighbours. Other function will control wich neighbours will send the messages to your neighbours so the messase was propagate to all topology. In the code has other function will be responsable to send the cust on the actual node to wich direct neighbour and the more abragent function will control wich node will send to the function comment previoulesty, so that function will run all nodes from the graph to every node disseminate your cust with ther neighbour in all graph. In the end of the code was expected every node in the topology knows about all network, and when that happen means the end of the program.

### Result :

- Will be generated a txt file named ```estatistica.txt```, and in that file will exist all node from graph NSFNET, your table(database)
with all ways from the topology and the vector from distances to all other nodes, using the algorithm.
