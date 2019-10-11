#code
class Stack:
    def __init__(self):
        self.stack = []
        
    def push(self,data):
        self.stack.append(data)
        
    def pop(self):
        if not self.isEmpty():
            return self.stack.pop(len(self.stack)-1)
        
    def isEmpty(self):
        return len(self.stack) == 0
        
for _ in range(int(input())):
    def is_match(a,b):
        if a=="{" and b=="}":
            return True
        elif a=="(" and b==")":
            return True
        elif a=="[" and b=="]":
            return True
        else:
            return False
    bracks = str(input().strip())
    brackets = Stack()
    ans = True
    for i in bracks:
        if i in '{[(':
            brackets.push(i)
        else:
            if brackets.isEmpty():
                ans = False
            else:
                top = brackets.pop()
                if not is_match(top,i):
                    ans = False

    if brackets.isEmpty() and ans:
        print("balanced")
    else:
        print("not balanced")