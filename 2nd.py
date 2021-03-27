class Node:
    def __init__(self, x, nextNode = None):
        self.val = x
        self.next = nextNode
 
def printList(l):
    value = []
    while(l):
        value.append(l.val)
        l = l.next
    print(' -> '.join(map(str, value)))
 
def addTwoNumbers(l1, l2):
    """
    :type l1: Node
    :type l2: Node
    :rtype: Node
    """
    sum = l1.val + l2.val
    carry = int(sum / 10)
 
    l3 = Node(sum%10)
    p1 = l1.next
    p2 = l2.next
    p3 = l3
    while(p1 != None or p2 != None):
        sum = carry + ( p1.val if p1 else 0) + ( p2.val if p2 else 0)
        carry = int(sum/10)
        p3.next = Node(sum % 10)
        p3 = p3.next
        p1 = p1.next if p1 else None
        p2 = p2.next if p2 else None
 
    if(carry > 0):
        p3.next = Node(carry)
 
    return l3
 
#789
l1 = Node(9, Node(8, Node(7)))
printList(l1)
#478
l2 = Node(8, Node(7, Node(4)))
printList(l2)
l3 = addTwoNumbers(l1, l2)
printList(l3)   
print()   
#342
l1 = Node(2, Node(4, Node(3)))
printList(l1)
#465
l2 = Node(5, Node(6, Node(4)))
printList(l2)
l3 = addTwoNumbers(l1, l2)
printList(l3)
