#include<Windows.h>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
std::vector<std::string> __cdecl sub_414DC0_list(DWORD *a1 )
{ 
  int i; // esi 
  if ( *a1 != 1179664707 )  //CAPF
    return {};  
  std::vector<std::string> save;
  for ( i = a1[3] >> 1; i>-1; i-- )
  { 
    std::cout<< (const char *)&a1[10 * i + 10]<<std::endl;
    save.push_back((const char *)&a1[10 * i + 10]); 
  } 
  return save;
}
int __cdecl sub_414DC0(DWORD *a1, char *String1, DWORD *a3, DWORD *a4)
{
  int v5; // edi
  int v6; // ebx
  int i; // esi
  int v8; // eax
  unsigned int v9; // esi
  int v11; // [esp+14h] [ebp+4h]

  if ( *a1 != 1179664707 )  //CAPF
    return 0;
  if ( a3 )
    *a3 = 0;
  if ( a4 )
    *a4 = 0;
  v5 = a1[3];
  v6 = 0;
  v11 = -1;
  for ( i = a1[3] >> 1; ; v11 = i )
  {
    v8 = _strcmpi(String1, (const char *)&a1[10 * i + 10]);
    if ( !v8 )
      break;
    if ( v8 >= 0 )
    {
      v6 = i;
      v9 = v5 + i;
    }
    else
    {
      v5 = i;
      v9 = v6 + i;
    }
    i = v9 >> 1;
    if ( i == v11 )
      return 0;
  }
  if ( a3 )
    *a3 = a1[10 * i + 8];
  if ( a4 )
    *a4 = a1[10 * i + 9];
  return 1;
}
char* readfb(const char* f){
  std::ifstream file(f, std::ios::binary);  
    if (file) {
        file.seekg(0, std::ios::end);  
        std::streampos fileSize = file.tellg(); 
        file.seekg(0, std::ios::beg);  

        char* buffer = new char[(unsigned) fileSize];  
        file.read(buffer, fileSize);  

        return buffer;
    } else {
        return 0;
    }
} 
void writeToFile(const char* filename, const char* data, int start, int length) {
    std::ofstream file(filename, std::ios::binary); 
    if (!file) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return;
    }   
    file.write(data+start, length); 
    file.close(); 
}
int __cdecl sub_412D70(int a1, DWORD *a2)
{
  DWORD *v2; // eax
  unsigned int v3; // edi
  char *v4; // esi
  char v6; // cl
  int v7; // edx
  int v8; // ebp
  int v9; // ecx
  char v10; // [esp+Bh] [ebp-9h]
  char *v11; // [esp+Ch] [ebp-8h]
  int v12; // [esp+10h] [ebp-4h]

  v2 = a2;
  v3 = 0;
  v4 = (char *)(a2 + 4);
  v10 = 0;
  v12 = 0;
  if ( *a2 != 1280974880 )
    return 0;
  if ( a2[1] )
  {
    v11 = (char *)(a2 + 4);
    do
    {
      if ( v12 <= 0 )
      {
        v6 = *v4++;
        v10 = v6;
        v11 = v4;
        v12 = 8;
      }
      if ( v10 >= 0 )
      {
        v7 = 0;
        v8 = (*(WORD *)v4 & 0xF) + 2;
        v9 = (*(unsigned __int16 *)v4 >> 4) + 1;
        if ( v8 > 0 )
        {
          do
          {
            *(BYTE *)(v7 + v3 + a1) = *(BYTE *)(v3 + v7 - v9 + a1);
            if ( v7 + v3 >= a2[1] )
              break;
            ++v7;
          }
          while ( v7 < v8 );
          v4 = v11;
        }
        v2 = a2;
        v3 += v8;
        v4 += 2;
        v11 = v4;
      }
      else
      {
        *(BYTE *)(v3 + a1) = *v4;
        ++v3;
        v11 = ++v4;
      }
      v10 *= 2;
      --v12;
    }
    while ( v3 < v2[1] );
  }
  return v2[1];
}
int dword_4810F8=0;UINT uValue=0;
int __cdecl sub_4137D0(HGLOBAL *a1, DWORD *a2)
{
  if ( !*a1 || !*a2 || (--uValue, dword_4810F8 -= GlobalSize(*a1), GlobalUnlock(*a1)) || GlobalFree(*a1) )
    ExitProcess(0);
  *a1 = 0;
  *a2 = 0;
  return 1;
}
int __cdecl sub_413700(int a1, HGLOBAL *a2, DWORD *a3, int a4)
{
  HGLOBAL v4; // eax
  LPVOID v5; // eax
  SIZE_T v6; // ecx
  int result; // eax

  if ( *a2 || *a3 || (v4 = GlobalAlloc(0x42u, a4 + 8), (*a2 = v4) == 0) || (v5 = GlobalLock(v4), (*a3 =(DWORD) v5) == 0) )
    ExitProcess(0);
  //++uValue;
  v6 = GlobalSize(*a2) + dword_4810F8;
  result = 1;
  dword_4810F8 = v6;
  return result;
}
int sub_439A90(DWORD* v7,const char* String2){ 
  int v1; // eax
  int v2; // eax
  int result; // eax
  int v4; // ebx
  int v5; // eax
  int v6; // esi 
  HGLOBAL v8; // [esp+14h] [ebp-118h] BYREF
  char *v9; // [esp+18h] [ebp-114h] BYREF
  HGLOBAL v10; // [esp+1Ch] [ebp-110h] BYREF
  int v11; // [esp+20h] [ebp-10Ch] BYREF
  DWORD *v12; // [esp+24h] [ebp-108h]
  CHAR Text[260]; // [esp+28h] [ebp-104h] BYREF
  //std::cout<<String2<<std::endl;
  if ( *v7 != 1396920864 )
  { 
    MessageBoxA(0,String2,"error1",0); return 0;
  }
  if ( v7[1] != 1 )
  {
    MessageBoxA(0,String2,"error2",0); return 0;
  }
  if ( (v7[2] & 1) != 0 )
  {
    
    v10 = 0;
    v9 = 0;
    v4 = v7[4] + 128;
    v12 = v7 + 4;
    sub_413700((int)String2, &v10,(DWORD*) &v9, v4);
    memcpy(v9, v7, 0x80u);
    v5 = sub_412D70((int)(v9 + 128), v7 + 32);
    //std::cout<<v5<<" "<<*v12<<std::endl;
    if ( v5 != *v12 )
    {
      auto byte_465174="ｽｸﾘﾌﾟﾄﾌｧｲﾙ%sの解凍に失敗しました";
      sprintf(Text,  byte_465174, String2);
      MessageBoxA(0, Text, 0, 0x2000u);
      //sub_4137D0(&v8, (DWORD*)&v7);
      //sub_4137D0(&v10, (DWORD*)&v9);
      return 0;
    }

    //sub_4137D0(&v8, (DWORD*)&v7);
    v8 = v10;
    v7 =(DWORD*) v9;
    std::string basedir=R"(C:\Users\wcy\Documents\GitHub\MaichiruSakura\BIN\)";
    writeToFile((basedir+String2).c_str(),(const char*)v7,0,v5);
    v11 = v4;
  }
  return 1;
}
int main(){
  auto scriptpac=readfb(R"(C:\Users\wcy\Documents\GitHub\MaichiruSakura\Script.pac)");
  
  DWORD lDistanceToMove,a6;
  auto scripts=sub_414DC0_list((DWORD *)scriptpac);
  for(auto sc:scripts){
    sub_414DC0((DWORD *)scriptpac,( char* )(sc.c_str()),&lDistanceToMove,&a6);
    
    
    //std::cout<<sc.c_str()<<" "<<std::hex<<lDistanceToMove<<" "<<a6<<std::endl;
    //std::string basedir=R"(C:\Users\wcy\Documents\GitHub\MaichiruSakura\text\)";
    //writeToFile((basedir+sc).c_str(),scriptpac,lDistanceToMove,a6);
    DWORD* v7=(DWORD*)(scriptpac+lDistanceToMove);
    sub_439A90(v7,sc.c_str());
  } 

}