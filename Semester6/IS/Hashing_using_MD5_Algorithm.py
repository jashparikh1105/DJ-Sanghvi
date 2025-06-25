import struct 
# Helper functions 
def left_rotate(x, amount): 
x &= 0xFFFFFFFF 
return ((x << amount) | (x >> (32 - amount))) & 0xFFFFFFFF 
# Initialize MD5 buffer 
A = 0x67452301 
B = 0xefcdab89 
C = 0x98badcfe 
D = 0x10325476 
# Constants for MD5 
T = [int(4294967296 * abs(__import__('math').sin(i + 1))) & 0xFFFFFFFF for i in range(64)] 
# Shift amounts 
S = [7, 12, 17, 22] * 4 + [5, 9, 14, 20] * 4 + [4, 11, 16, 23] * 4 + [6, 10, 15, 21] * 4 
# Take input from user 
msg = input("Enter the message to hash using MD5: ") 
msg_bytes = bytearray(msg, 'utf-8') 
original_len_bits = (8 * len(msg_bytes)) & 0xffffffffffffffff 
# Padding 
msg_bytes.append(0x80) 
while len(msg_bytes) % 64 != 56: 
msg_bytes.append(0) 
msg_bytes += struct.pack('<Q', original_len_bits) 
# Process in 512-bit (64-byte) chunks 
for chunk_ofs in range(0, len(msg_bytes), 64): 
a, b, c, d = A, B, C, D 
chunk = msg_bytes[chunk_ofs:chunk_ofs+64] 
M = list(struct.unpack('<16I', chunk)) 
for i in range(64): 
if 0 <= i <= 15: 
            f = (b & c) | (~b & d) 
            g = i 
        elif 16 <= i <= 31: 
            f = (d & b) | (~d & c) 
            g = (5 * i + 1) % 16 
        elif 32 <= i <= 47: 
            f = b ^ c ^ d 
            g = (3 * i + 5) % 16 
        elif 48 <= i <= 63: 
            f = c ^ (b | ~d) 
            g = (7 * i) % 16 
         
        f = (f + a + T[i] + M[g]) & 0xFFFFFFFF 
        a, d, c, b = d, c, b, (b + left_rotate(f, S[i])) & 0xFFFFFFFF 
     
    A = (A + a) & 0xFFFFFFFF 
    B = (B + b) & 0xFFFFFFFF 
    C = (C + c) & 0xFFFFFFFF 
    D = (D + d) & 0xFFFFFFFF 
 
# Output final hash 
digest = struct.pack('<4I', A, B, C, D) 
print("MD5:", ''.join(f'{byte:02x}' for byte in digest))