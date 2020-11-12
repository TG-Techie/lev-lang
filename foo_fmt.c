
int ref_int(int g) { return g; }

typedef struct barsct {
  int x;
  int y;
  int z;
} barsct;

barsct get_barsct(barsct self) {
  return (barsct){
      ref_int(self.x),
      ref_int(self.y),
      ref_int(self.z),
  };
}
