
import random

DG = nx.DiGraph()

def create_node(totalNodes) :
    """
    Parameter: totalNodes: integer representing the total number of nodes in the graph
    Returns: None
    """
    for node in range(totalNodes):
        DG.add_node(node)


def create_edge(node_exists, node1, node2):
    """
    Parameter: node_exists: boolean representing if the edge between two nodes exists
    Parameter: node1: 
    Parameter: node1: 
    Returns: None
    """
    if node_exists is True and node1 != node2:
        DG.add_edge(node1, node2)
        print('Created edge between ', node1, ' and ', node2)
    else:
        print('Did not create edge between ', node1, ' and ', node2)