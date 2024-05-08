#include <iostream>
#include <string>
#include <random>
#include <ctime>
std::string generate_key(int plaintext_length)
{
    std::string key;
    static const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < plaintext_length; ++i)
    {
        key += charset[rand() % (sizeof(charset) - 1)];
    }
    return key;
}
std::string encrypt(const std::string &plaintext, const std::string &key)
{
    std::string ciphertext;
    for (size_t i = 0; i < plaintext.length(); ++i)
    {
        ciphertext += plaintext[i] ^ key[i];
    }
    return ciphertext;
}
std::string decrypt(const std::string &ciphertext, const std::string &key)
{
    std::string decrypted_text;
    for (size_t i = 0; i < ciphertext.length(); ++i)
    {
        decrypted_text += ciphertext[i] ^ key[i];
    }
    return decrypted_text;
}
int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    std::string plaintext = "HELLO";
    std::string key = generate_key(plaintext.length());
    std::cout << "Plaintext: " << plaintext << std::endl;
    std::cout << "Key: " << key << std::endl;
    std::string ciphertext = encrypt(plaintext, key);
    std::cout << "Ciphertext: " << ciphertext << std::endl;
    std::string decrypted_text = decrypt(ciphertext, key);
    std::cout << "Decrypted Text: " << decrypted_text << std::endl;
    return 0;
}