import struct 
def left_rotate(n, b): 
return ((n << b) | (n >> (32 - b))) & 0xFFFFFFFF 
def sha1(data): 
if isinstance(data, str): 
data = data.encode() 
# Initial hash values 
    h0 = 0x67452301 
    h1 = 0xEFCDAB89 
    h2 = 0x98BADCFE 
    h3 = 0x10325476 
    h4 = 0xC3D2E1F0 
 
    # Pre-processing 
    original_byte_len = len(data) 
    original_bit_len = original_byte_len * 8 
    data += b'\x80' 
     
    while (len(data) * 8) % 512 != 448: 
        data += b'\x00' 
 
    data += struct.pack('>Q', original_bit_len) 
 
    # Process in 512-bit chunks 
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
            e = d 
            d = c 
            c = left_rotate(b, 30) 
            b = a 
            a = temp 
 
        h0 = (h0 + a) & 0xFFFFFFFF 
        h1 = (h1 + b) & 0xFFFFFFFF 
        h2 = (h2 + c) & 0xFFFFFFFF 
        h3 = (h3 + d) & 0xFFFFFFFF 
        h4 = (h4 + e) & 0xFFFFFFFF 
 
    return '%08x%08x%08x%08x%08x' % (h0, h1, h2, h3, h4) 
 
# Take input from user 
message = input("Enter the message to hash using SHA-1: ") 
hash_val = sha1(message) 
print("SHA-1:", hash_val)