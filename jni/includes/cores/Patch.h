#pragma once
#include "KittyMemory/MemoryPatch.h"

/*
Original by iAndyHD3, I just make it simple
so that it wont hard to do patches.
- ItzZyann
*/

using namespace std;

class Patch {
private:
 vector<MemoryPatch> patches;
 
public:
 void addPatch(const char* libraryName, uintptr_t address, std::string hex){
  patches.push_back(MemoryPatch::createWithHex(libraryName,address,hex));
 }

 void Modify(){
  for(int k = 0; k < patches.size(); k++){
   patches[k].Modify();
  }
 }

 void Restore(){
  for(int k = 0; k < patches.size(); k++){
   patches[k].Restore();
  }
 }
};

#define patchLib(libName, addr, patch) \
 Patch* ptr = new Patch(); \
 ptr->addPatch(libName, addr, patch); \
 ptr->Modify();