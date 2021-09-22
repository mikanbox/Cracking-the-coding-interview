from graphviz import Graph
from graphviz import Digraph

g = Graph(format='png')
dg = Digraph(format='png')



# 無向グラフ
# nodeを追加
g.node('1')
g.node('2')
g.node('3')
# edgeを追加
g.edge('1', '2')
g.edge('2', '3')
g.edge('3', '1')

# 有向グラフ
dg.node('1')
dg.node('2')
dg.node('3')
dg.edge('1', '2')  # 1 -> 2
dg.edge('2', '3')  # 2 -> 3
dg.edge('3', '1')  # 3 -> 1


g.view()
dg.view()