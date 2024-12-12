
def fibonacci(n):
    n1= 0
    n2= 1
    count =0
    
    if n <=0:
        print("Give Positive int")
        
    elif n==1:
        print(n1)
        
    else:
       
        while count < n:
            print(n1, end=" ")
            new_number= n1+n2
            n1= n2
            n2= new_number
            count = count+1
            
def factorial(n):
    fact =1
    
    for i in range(1,n+1):
        fact = fact*i
        
    print(fact)
    
def reccursive_fabonacci(i):
    
    if i<=1:
        return i
        
    else:
        return reccursive_fabonacci(i-1) + reccursive_fabonacci(i-2)


def reccursive_factorial(n):
    
    if n==1:
        return n
    
    else:
        return n* reccursive_factorial(n-1)
       

def reverse_string_method1(string):
    string_list = list(string)
    s=0
    e= len(string_list)-1
    
    while s<e:
        string_list[s], string_list[e]= string_list[e], string_list[s]
        s=s+1
        e=e-1
        
    string = ''.join(string_list)
    # can be reversed back by shortcut: string = ''.join(reversed(string_list))
    print(string)

def reverse_string_method2(string):
    reversed_string = string[::-1]
    print(reversed_string)




#nterms = int(input("Enter the number: "))

# ----NORMAL ITERATIVE FIBONACCI-------

# print("Fibonacci: ", end="")
# fibonacci(nterms)
# print(end=" ")

# ----NORMAL ITERATIVE FACTORIAL-------

# print("Factorial: ", end="")
# factorial(nterms)

# ----RECCURSIVE FIBONACCI-------

# if nterms<=0:
#     print("give positive number")

# else:
#     for i in range(nterms):
#        print(reccursive_fabonacci(i), end=" ")

# ----RECCURSIVE FACTORIAL-------

# if nterms <0:
#     print("give positive number")

# elif nterms ==0:
#     print("factorial of 0 is 1")

# else:
#     print(reccursive_factorial(nterms), end=" ")

# ----REVERSE A STRING-------

string = "Hello World !"

#reverse_string_method1(string)
reverse_string_method2(string)
        

