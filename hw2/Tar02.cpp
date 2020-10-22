#include <iostream>
#include <string>

using namespace std;

int ZerosOnes(int length, string &str){
  int zeros=0, ones=0;
  for(int i = 0; i < length; i++){
    if(str[i] == '0'){
      zeros++;
    }else{
      ones++;
    } 
  }

  if(zeros == ones){
    length = length - zeros*2;
  } else if(zeros>ones){
    length = length - ones*2;
  } else{
    length = length - zeros*2;
  }
  return length;
}

int main() {
  int iLength;
  string sLine;
  cin>>iLength>>sLine;
  cout <<ZerosOnes(iLength, sLine);
}