/*
  Nama  : Ridho Emir Fajar Alam
  NPM   : 140810190044
  Kelas : B
*/

#include<iostream>
#define clear system("cls")
std::string shift_chiper_encrypt(std::string plainteks, int key) {
  char temp;
  bool isSpace;
  for(int i = 0; i < plainteks.length() ; i++) {
    temp = plainteks[i];
    if(int(temp) == 32){
      isSpace = true;
    }else {
      isSpace = false;
    }

    if(isSpace){
      plainteks[i] = ' ';
    } else {
      if(int(temp) >= 97){
      temp = (int(temp - 97) + key) % 26;
      temp = char(temp + 97);
      } else {
        temp = (int(temp - 65) + key) % 26;
        temp = char(temp + 65);
      }
      plainteks[i] = temp;
    }
  }
  return plainteks;
}

std::string shift_chiper_decrypt(std::string chiperteks, int key) {
  char temp;
  bool isSpace;
  for(int i = 0; i < chiperteks.length() ; i++) {
    temp = chiperteks[i];
    if(int(temp) == 32){
      isSpace = true;
    } else {
      isSpace = false;
    }
    if(isSpace){
      chiperteks[i] = ' ';
    } else {
      if(int(temp) <= 97) {
        temp = (int(temp - 65) - key) % 26;
        if(int(temp + 65) < 65){
          temp = char(temp + 65 + 26);
        } else  {
          temp = char(temp + 65);
        }
      } else {
        temp = (int(temp - 97) - key) % 26;
        if(int(temp + 97) < 97){
          temp = char(temp + 97 + 26);
        } else  {
          temp = char(temp + 97);
        }
      }
      chiperteks[i] = temp;
    }
  }
  return chiperteks;
}

int main() {
  char loop;
  std::string plainteks, chiperteks;
  int key;
  do{
  clear;
  std::cout << "Program Shift Cipher\nNama\t\t: ";getline(std::cin>>std::ws, plainteks);
  std::cout << "Key\t\t: ";std::cin >> key;

  chiperteks =  shift_chiper_encrypt(plainteks, key);
  std::cout << "Hasil Enkripsi (Chiperteks)\t: " << chiperteks << std::endl;

  plainteks =  shift_chiper_decrypt(chiperteks, key);
  std::cout << "Hasil Dekripsi (Plainteks)\t: " << plainteks << std::endl;

  std::cout << "Apakah anda ingin mengulang? (Y/N) ->";std::cin >> loop;
  }while(loop == 'Y' | loop == 'y' );
  return 0;
}