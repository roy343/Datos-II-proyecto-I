#ifndef BZF_MD5_H
#define BZF_MD5_H
 
#include <cstring>
#include <iostream>
 
class MD5{
public:
    typedef unsigned int size_type; // Debe ser de 32bits
 
    MD5();
    MD5(const std::string& text);
    void update(const unsigned char *buf, size_type length);
    void update(const char *buf, size_type length);
    MD5& finalize();
    std::string hexdigest() const;
    friend std::ostream& operator<<(std::ostream&, MD5 md5);
private:
    void init();
    typedef unsigned char uint1; //  8bits
    typedef unsigned int uint4;  // 32bits
    enum {blocksize = 64};
 
    void transform(const uint1 block[blocksize]);
    static void decode(uint4 output[], const uint1 input[], size_type len);
    static void encode(uint1 output[], const uint4 input[], size_type len);
 
    bool finalized;
    uint1 buffer[blocksize]; // bytes que no cupieron en el ultimo bloque de 64 bytes
    uint4 count[2];   // contador de 64 bytes para el numero de bits
    uint4 state[4];
    uint1 digest[16];
 
  // Operaciones logicas de bajo nivel
    static inline uint4 F(uint4 x, uint4 y, uint4 z);
    static inline uint4 G(uint4 x, uint4 y, uint4 z);
    static inline uint4 H(uint4 x, uint4 y, uint4 z);
    static inline uint4 I(uint4 x, uint4 y, uint4 z);
    static inline uint4 rotate_left(uint4 x, int n);
    static inline void FF(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
    static inline void GG(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
    static inline void HH(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
    static inline void II(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
};
 
std::string md5(const std::string str);
 #endif