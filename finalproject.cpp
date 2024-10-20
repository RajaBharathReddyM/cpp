#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <sstream>


typedef unsigned int WORD;
typedef unsigned char BYTE;

// Define round constants (random values for this example)
static const WORD hash_constants[64] = {
    0x11223344, 0x22334455, 0x33445566, 0x44556677, 0x55667788, 0x66778899, 0x778899AA, 0x8899AABB,
    0x99AABBCC, 0xAABBCCDD, 0xBBCCDDEE, 0xCCDDEEFF, 0xDDEEFF00, 0xEEFF0011, 0xFF001122, 0x00112233,
    0x11223344, 0x22334455, 0x33445566, 0x44556677, 0x55667788, 0x66778899, 0x778899AA, 0x8899AABB,
    0x99AABBCC, 0xAABBCCDD, 0xBBCCDDEE, 0xCCDDEEFF, 0xDDEEFF00, 0xEEFF0011, 0xFF001122, 0x00112233,
    0x11223344, 0x22334455, 0x33445566, 0x44556677, 0x55667788, 0x66778899, 0x778899AA, 0x8899AABB,
    0x99AABBCC, 0xAABBCCDD, 0xBBCCDDEE, 0xCCDDEEFF, 0xDDEEFF00, 0xEEFF0011, 0xFF001122, 0x00112233,
    0x11223344, 0x22334455, 0x33445566, 0x44556677, 0x55667788, 0x66778899, 0x778899AA, 0x8899AABB,
    0x99AABBCC, 0xAABBCCDD, 0xBBCCDDEE, 0xCCDDEEFF, 0xDDEEFF00, 0xEEFF0011, 0xFF001122, 0x00112233
};

WORD rotate_right(WORD value, WORD bits) {
    return (value >> bits) | (value << (32 - bits));
}

void process_compression(const BYTE input[], WORD hash_state[8]) {
    WORD message_schedule[64];  // Message schedule array
    WORD a, b, c, d, e, f, g, h;

    for (int i = 0; i < 16; i++) {
        message_schedule[i] = (input[i * 4] << 24) | (input[i * 4 + 1] << 16) | (input[i * 4 + 2] << 8) | input[i * 4 + 3];
    }

    for (int i = 16; i < 64; i++) {
        message_schedule[i] = message_schedule[i - 16] + message_schedule[i - 7] + rotate_right(message_schedule[i - 15], 7) + rotate_right(message_schedule[i - 2], 17);
    }

    a = hash_state[0];
    b = hash_state[1];
    c = hash_state[2];
    d = hash_state[3];
    e = hash_state[4];
    f = hash_state[5];
    g = hash_state[6];
    h = hash_state[7];

    for (int i = 0; i < 64; i++) {
        WORD temp_epsilon = rotate_right(e, 6) ^ rotate_right(e, 11) ^ rotate_right(e, 25);
        WORD choice = (e & f) ^ (~e & g);
        WORD temp1 = h + temp_epsilon + choice + hash_constants[i] + message_schedule[i];
        WORD temp_alpha = rotate_right(a, 2) ^ rotate_right(a, 13) ^ rotate_right(a, 22);
        WORD majority = (a & b) ^ (a & c) ^ (b & c);
        WORD temp2 = temp_alpha + majority;

        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    hash_state[0] += a;
    hash_state[1] += b;
    hash_state[2] += c;
    hash_state[3] += d;
    hash_state[4] += e;
    hash_state[5] += f;
    hash_state[6] += g;
    hash_state[7] += h;
}

void string_to_bytes(const std::string &input, BYTE output[64]) {
    memset(output, 0, 64);
    size_t copy_length = input.length() < 64 ? input.length() : 64;
    memcpy(output, input.c_str(), copy_length);
}

std::string format_hash_result(WORD hash_state[8]) {
    std::stringstream ss;
    for (int i = 0; i < 8; i++) {
        ss << std::hex << std::setw(8) << std::setfill('0') << hash_state[i];
    }
    return ss.str();
}

int main() {
    std::string user_input;


    std::cout << "Input: ";
    std::getline(std::cin, user_input);

    BYTE data[64];
    string_to_bytes(user_input, data);

    WORD current_state[8] = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19}; // Initial hash values

    process_compression(data, current_state);

    std::string hash_result = format_hash_result(current_state);
    std::cout << "SHA-256 Hash: " << hash_result << std::endl;

    return 0;
}
