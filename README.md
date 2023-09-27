# Cryptography Algorithms in C++

This repository contains C++ implementations of three fundamental cryptography algorithms: DES (Data Encryption Standard), RSA (Rivest–Shamir–Adleman), and Caesar's Cipher. These algorithms are widely used in information security and encryption, and this repository provides simple yet functional implementations for educational and reference purposes.

## Table of Contents

- [DES (Data Encryption Standard)](#des-data-encryption-standard)
- [RSA (Rivest–Shamir–Adleman)](#rsa-rivestshamiradleman)
- [Caesar's Cipher](#caesars-cipher)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## DES (Data Encryption Standard)

The Data Encryption Standard (DES) is a symmetric-key algorithm for encrypting and decrypting data. It uses a 56-bit key to perform the encryption and decryption operations. In this repository, you can find a C++ implementation of the DES algorithm that allows you to encrypt and decrypt messages.

## RSA (Rivest–Shamir–Adleman)

RSA is a widely used asymmetric-key algorithm for secure data transmission. It is based on the mathematical properties of prime numbers and provides both encryption and digital signature capabilities. In this repository, you can find a C++ implementation of the RSA algorithm for key generation, encryption, and decryption.

## Caesar's Cipher

Caesar's Cipher is one of the simplest encryption techniques, also known as a substitution cipher. It involves shifting the letters of the alphabet by a fixed number of positions. In this repository, you can find a C++ implementation of Caesar's Cipher for both encryption and decryption.

## Getting Started

To get started with this project, follow these steps:

1. Clone this repository to your local machine:

   ```
   git clone https://github.com/your-username/cryptography-algorithms-cpp.git
   ```

2. Build the C++ programs for the desired cryptography algorithm using your preferred compiler (e.g., g++ or clang++).

3. Run the executable generated after building the program.

## Usage

Each cryptography algorithm has its own folder in the repository with separate C++ files for encryption and decryption. You can use the following commands to build and run the programs:

### DES

```bash
cd DES
g++ des.cpp -o des
./des
```

### RSA

```bash
cd RSA
g++ rsa.cpp -o rsa
./rsa
```

### Caesar's Cipher

```bash
cd CaesarsCipher
g++ caesars_cipher.cpp -o caesars_cipher
./caesars_cipher
```

Follow the on-screen instructions to interact with the programs and perform encryption and decryption operations.

## Contributing

If you would like to contribute to this project, please feel free to submit pull requests or open issues. Contributions, bug reports, and feature requests are welcome.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details. You are free to use, modify, and distribute this code for educational and non-commercial purposes.
