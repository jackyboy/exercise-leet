class CustomStack:

    def __init__(self, maxSize: int):
        self.maxSize = maxSize
        self.stack = []

    def push(self, x: int) -> None:
        if len(self.stack)<self.maxSize:
            self.stack.append(x)

    def pop(self) -> int:
        if len(self.stack)<=0:
            return -1
        else:
            return self.stack.pop()
        

    def increment(self, k: int, val: int) -> None:
        if k>=len(self.stack):
            r = len(self.stack)
        else:
            r = k
        for x in range(r):
            self.stack[x] = self.stack[x] + val 
        


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)