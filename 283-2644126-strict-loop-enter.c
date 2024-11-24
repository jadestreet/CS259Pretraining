//PARAM: --disable ana.int.def_exc --enable ana.int.interval --sets solver slr3tp --enable dbg.debug
// dbg.debug manually enabled since update_suite only enables it when it sees normal assertion (without NOWARN)
#include <assert.h>

int g = 0;

int main() {
  int x;

  for(x=0; x < 50; x++){
    g = 1;
  }
  // x = [50, 50] after narrow
  if(x>50){ // live after widen, but dead after narrow
    // node after Pos(x>50) is marked dead at the end
    // but the loop is not with x = [51,2147483647]
    for(int i=0; i<=0; i--){
      g = 57;
    }
    assert(1); // NOWARN (unreachable)
  }
}