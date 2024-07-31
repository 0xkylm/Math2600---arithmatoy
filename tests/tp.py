# Aucun n'import ne doit être fait dans ce fichier


def nombre_entier(n: int) -> str:
    return "S" * n + "0"


def S(n: str) -> str:
    return "S" + n


def addition(a: str, b: str) -> str:
    if a == "0":
        return b
    if b == "0":
        return a
    return S(addition(a, b[1:]))


def multiplication(a: str, b: str) -> str:
    if b == "0" or a == "0":
        return "0"
    if b == "S0":
        return a
    if a == "S0":
        return b
    return addition(a, multiplication(a, b[1:]))


def facto_ite(n: int) -> int:
    res = 1
    for i in range(1, n + 1):
        res *= i
    return res


def facto_rec(n: int) -> int:
    if n == 0:
        return 1
    return n * facto_ite(n - 1)


def fibo_rec(n: int) -> int:
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fibo_rec(n - 1) + fibo_rec(n - 2)


def fibo_ite(n: int) -> int:
    a, b = 0, 1
    for _ in range(n):
        a, b = b, a + b
    return a


def golden_phi(n: int) -> int:
    a, b = 1, 1
    for _ in range(n):
        a, b = a + b, a
    return a / b


def sqrt5(n: int) -> int:
    return golden_phi(n) * 2 - 1


def pow(a: float, n: int) -> float:
    res = 1.0
    for _ in range(n):
        res *= a
    return res
