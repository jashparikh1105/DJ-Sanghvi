import random 
import struct 
from sympy import nextprime 
 
# Custom SHA-1 Hash Function 
def left_rotate(n, b): 
    return ((n << b) | (n >> (32 - b))) & 0xFFFFFFFF 
 
def sha1(data): 
    if isinstance(data, str): 
        data = data.encode() 
 
    h0, h1, h2, h3, h4 = ( 
        0x67452301, 
        0xEFCDAB89, 
        0x98BADCFE, 
        0x10325476, 
        0xC3D2E1F0, 
    ) 
 
    original_byte_len = len(data) 
    original_bit_len = original_byte_len * 8 
    data += b'\x80' 
 
    while (len(data) * 8) % 512 != 448: 
        data += b'\x00' 
 
    data += struct.pack('>Q', original_bit_len) 
 
    for i in range(0, len(data), 64): 
        w = [0] * 80 
        chunk = data[i:i+64] 
 
        for j in range(16): 
            w[j] = struct.unpack('>I', chunk[j*4:j*4+4])[0] 
 
        for j in range(16, 80): 
            w[j] = left_rotate(w[j-3] ^ w[j-8] ^ w[j-14] ^ w[j-16], 1) 
 
        a, b, c, d, e = h0, h1, h2, h3, h4 
 
        for j in range(80): 
            if 0 <= j <= 19: 
                f = (b & c) | (~b & d) 
                k = 0x5A827999 
            elif 20 <= j <= 39: 
                f = b ^ c ^ d 
                k = 0x6ED9EBA1 
            elif 40 <= j <= 59: 
                f = (b & c) | (b & d) | (c & d) 
                k = 0x8F1BBCDC 
            else: 
                f = b ^ c ^ d 
                k = 0xCA62C1D6 
 
            temp = (left_rotate(a, 5) + f + e + k + w[j]) & 0xFFFFFFFF 
            e, d, c, b, a = d, c, left_rotate(b, 30), a, temp 
 
        h0 = (h0 + a) & 0xFFFFFFFF 
        h1 = (h1 + b) & 0xFFFFFFFF 
        h2 = (h2 + c) & 0xFFFFFFFF 
        h3 = (h3 + d) & 0xFFFFFFFF 
        h4 = (h4 + e) & 0xFFFFFFFF 
 
    return '%08x%08x%08x%08x%08x' % (h0, h1, h2, h3, h4) 
 
# RSA Utilities 
def gcd(a, b): 
    while b: 
        a, b = b, a % b 
    return a 
 
def modinv(a, m): 
    m0, x0, x1 = m, 0, 1 
    while a > 1: 
        q = a // m 
        a, m = m, a % m 
        x0, x1 = x1 - q * x0, x0 
    return x1 % m0 
 
def rsa_keygen(bits=512): 
    p = nextprime(random.getrandbits(bits)) 
    q = nextprime(random.getrandbits(bits)) 
    n = p * q 
    phi = (p - 1) * (q - 1) 
    e = 65537 
    while gcd(e, phi) != 1: 
        e = nextprime(e) 
    d = modinv(e, phi) 
    return (e, n), (d, n) 
 
def rsa_sign(message, private_key): 
    d, n = private_key 
    h = int(sha1(message), 16) 
    return pow(h, d, n) 
 
def rsa_verify(message, signature, public_key): 
    e, n = public_key 
    h = int(sha1(message), 16) 
    return pow(signature, e, n) == h 
 
# --- Demo --- 
print("\n=== RSA Digital Signature ===") 
public_key, private_key = rsa_keygen() 
message = input("Enter message to sign: ") 
signature = rsa_sign(message, private_key) 
print("Signature:", signature) 
valid = rsa_verify(message, signature, public_key) 
print("Signature valid?", valid) 