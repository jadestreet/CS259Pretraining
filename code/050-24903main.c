#define DUMBCOPY for(i=0;i<65536; ++i) \
  destination[i] = source[i]

#define SMARTCOPY memcpy(destination, source, 65536)

int main(int argc, char * argv[]) {
  char source[65536], destination[65536];
  int i, j;
  for (j =0;j< 100; ++j) {
    // 选择以下两行之一进行测试
    SMARTCOPY;
    // DUMBCOPY
  }
}