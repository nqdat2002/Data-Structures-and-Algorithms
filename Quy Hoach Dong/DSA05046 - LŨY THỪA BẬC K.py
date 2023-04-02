
mod = int(1000 * 1000 * 1000 + 7)
# inverse Module
x, y = 0, 1
def gcdExtended(a, b):
	global x, y
	if (a == 0):
		x = 0
		y = 1
		return b
	gcd = gcdExtended(b % a, a)
	x1 = x
	y1 = y
	x = y1 - (b // a) * x1
	y = x1
	return gcd

def inv(a):
    if gcdExtended(a, mod) == 1:
        res = (x % mod + mod) % mod
        return res
    return -1
    
def normal(n):
    n %= mod
    while n < 0:
        n += mod
    return n % mod

def add(a, b):
    if a + b >= mod:
        return a + b - mod
    return a + b
def sub(a, b):
    if a - b < 0:
        return a - b + mod
    return a - b
def mul(a, b):
    return a * b % mod

def div(a, b):
    if inv(b) != -1:
        return mul(a, inv(b))

def Powerx(n, k):
    ans = 1
    while k > 0:
        if k & 1:
            ans = mul(ans, n)
        n = mul(n, n)
        k >>= 1
    return ans
def calc(a, z):
    ans = 0
    k = 1
    for i in range(1, len(a)):
        k = mul(k, normal(z - i))
        k = div(k, normal(0 - i))
    for i in range(len(a)):
        ans = add(ans, mul(a[i], k))
        if i + 1 >= len(a):
            break
        k = mul(k, div(normal(z - i), normal(z - i - 1)))
        k = mul(k, div(normal(i - (len(a) - 1)), normal(i + 1)))
    return ans

def Load(n, k):
    b = []
    sum = 0
    b.append(sum)
    for i in range (k + 1):
        sum = add(sum, Powerx(i + 1, k))
        b.append(sum)
    if n < len(b):
        return b[n]
    return calc(b, n)

t = int(input())
while t > 0:
    t -= 1
    n, k = map(int, input().split())
    res = Load(n, k)
    print(res)
