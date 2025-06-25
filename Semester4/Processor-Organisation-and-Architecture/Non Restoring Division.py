import math

print("Name : Jash Parikh")
print("Roll number : C065")
print("SAP ID: 60004220080")
print("                  Non Restoring Division                   ")
def bin_to_int(a):
    n = len(a)
    ans = 0
    for i in range(n-1, -1, -1):
        ans += (1 << (n-i-1)) if a[i] == '1' else 0
    return ans

def twos_c_bin_add(a, b):
    carry = 0
    result = ""
    for i in range(len(a)-1, -1, -1):
        total = carry + int(a[i]) + int(b[i])
        result = str(total % 2) + result
        carry = total // 2
    return result

def ones_c(a):
    result = ""
    for bit in a:
        result += '0' if bit == '1' else '1'
    return result

def twos_c(a):
    a = ones_c(a)
    to_add = '0' * (len(a) - 1) + '1'
    return twos_c_bin_add(a, to_add)

def binary(a, pos, req_size):
    if not pos:
        a *= -1
    ans = ""
    zeros = '0' * (req_size - int(math.log2(a)) - 1)
    while a > 0:
        ans = str(a & 1) + ans
        a //= 2
    ans = zeros + ans
    if not pos:
        ans = twos_c(ans)
    return ans

def left_shift(a):
    return a[1:] + a[0]

def non_restoring_division(q_bin, plus_m_bin, minus_m_bin):
    print("ACCUMULATER     Q \t   M \t   ACTION")
    acc = '0' * len(plus_m_bin)
    print(acc, "\t\t", q_bin, "\t\t", plus_m_bin, "\t\t", " INITIAL STEP")
    print()
    n = len(q_bin)
    steps = n
    acc_prev = acc
    for step in range(steps):
        temp = acc + q_bin
        temp = left_shift(temp)
        acc = temp[:n+1]
        acc_prev = acc
        q_bin = temp[n+1:n*2+1]
        q_bin = q_bin[:-1] + '_'
        print(acc, "\t\t", q_bin, "\t\t", plus_m_bin, "\t\t", " LEFT SHIFT")
        print()
        if acc[0] == '0':
            acc = twos_c_bin_add(acc, minus_m_bin)
            print(acc, "\t\t", q_bin, "\t\t", plus_m_bin, "\t\t", " MSB OF A = 0 , A <- A-M")
            print()
        else:
            acc = twos_c_bin_add(acc, plus_m_bin)
            print(acc, "\t\t", q_bin, "\t\t", plus_m_bin, "\t\t", " MSB OF A = 1 , A <- A+M")
            print()
        if acc[0] == '0':
            q_bin = q_bin[:-1] + '1'
            print(acc, "\t\t", q_bin, "\t\t", plus_m_bin, "\t\t", " Q_0 = 0")
            print()
        else:
            q_bin = q_bin[:-1] + '0'
            acc = acc_prev
            print(acc, "\t\t", q_bin, "\t\t", plus_m_bin, "\t\t", " Q_0 = 1 AND RESTORE A")
            print()
    if acc[0] == '1':
        print("A < 0 , HENCE PERFORMING A<-A+M")
        acc = twos_c_bin_add(acc, plus_m_bin)
    print("ANSWER IS : \nQUOTIENT = (", q_bin, " ) IN BASE 2 = ", bin_to_int(q_bin), " IN BASE 10\nREMAINDER = (", acc, " ) IN BASE 2 = ", bin_to_int(acc), " IN BASE 10")

q, m = map(int, input("Enter Dividend(Q) and Divisor(M) : ").split())
q_size = int(math.log2(q)) + 1
q_bin = binary(q, q >= 0, q_size)
plus_m_bin = binary(m, m >= 0, q_size + 1)
minus_m_bin = binary(-1 * m, m < 0, q_size + 1)
non_restoring_division(q_bin, plus_m_bin, minus_m_bin)
